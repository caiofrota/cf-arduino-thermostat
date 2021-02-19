// Attributes.
bool rpcSubscribed = false;                                                                         // True if application is subscribed with RPC.
bool attrSubscribed = false;                                                                        // True if application is subscribed with attributes.
long thingsBoardTimeToSend = 1000;                                                                  // ThingsBoard minimum frequency to send data.
long thingsBoardTimeToRetry = 5000;                                                                 // ThingsBoard minimum frequency to retry connecting.
long lastSentMillis = 0;                                                                            // Store last time data was sent to server.

/**
 * Send data to ThingsBoard.
 */
void sendTBData() {
    // JSON Data.
    DynamicJsonDocument json(64);
    
    // Sending soil moisture data.
    json = readDHTData(dht, "dht");
    char dht[64]; serializeJson(json, dht);
    
    thingsBoard.sendTelemetryJson(dht);
}

/**
 * Send attributes to ThingsBoard.
 */
void sendTBAttrData() {
    thingsBoard.sendAttributeString("attr_device_name", ((String) wifiManagerCustomParameters[P_DEVICE_NAME].getValue()).c_str());
}

/** 
 * ThingsBoard attribute change callback.
 */
void receiveAttrCallback(const RPC_Data &data) {
    Logger::notice("Received the set delay ATTR method.");
    
    // Process data.
    String key;
    
    // Device Name.
    key = wifiManagerCustomParameters[P_DEVICE_NAME].getID();
    if (data.containsKey(key)) {
        String value = data[key];
        wifiManagerCustomParameters[P_DEVICE_NAME].setValue(value.c_str(), wifiManagerCustomParameters[P_DEVICE_NAME].getValueLength());
    }
    
    // Save attributes.
    Logger::notice("Call save param.");

    // Call save parameters.
    saveWiFiCustomParameters();
}

/** 
 * ThingsBoard Default RPC method callback.
 */
void receiveRPCDefaultCallback(const RPC_Data &data, RPC_Response &resp) {
    Logger::notice("Received the set delay RPC method.");
    
    // Process data.
    StaticJsonDocument<200> doc;
    deserializeJson(doc, data);
    
    int value = doc["value"];
    
    // Return value.
    JsonObject r  = resp.to<JsonObject>();
    r["value"] = value;
}

// ThingsBoard RPC callback method list.
int receiveRPCCallbackListSize = 1;
RPC_Callback receiveRPCCallbackList[] = {
    { "default",              receiveRPCDefaultCallback }
};

/**
 * ThingsBoard loop.
 */
void thingsBoardLoop() {
    if (!thingsBoard.connected()) {
        rpcSubscribed = false;
        attrSubscribed = false;
        char serverURL[50]; strcpy(serverURL, wifiManagerCustomParameters[P_SERVER_URL].getValue());
        char token[50]; strcpy(token, wifiManagerCustomParameters[P_TOKEN].getValue());
        
        Logger::notice("Connecting to ThingsBoard node.");
        if (thingsBoard.connect(serverURL, token)) {
            // Processing data.
            char espChipId[6];
            sprintf(espChipId, "%06X", ESP.getChipId());
            
            // Send application attributes.
            thingsBoard.sendAttributeString("app_sketch", appSketch);
            thingsBoard.sendAttributeString("app_version", appVersion);
            thingsBoard.sendAttributeString("device_chip_id", espChipId);
            thingsBoard.sendAttributeString("device_local_ip", WiFi.localIP().toString().c_str());
            thingsBoard.sendAttributeString("attr_device_name", ((String) wifiManagerCustomParameters[P_DEVICE_NAME].getValue()).c_str());
        } else {
            Logger::warning("Fail connecting ThingsBoard. Retrying in " + String(thingsBoardTimeToRetry / 1000) + " second(s).");
            delay(thingsBoardTimeToRetry);
            return;
        }
    }
    
    if (millis() - lastSentMillis > thingsBoardTimeToSend) {
        Logger::notice("Sending data to ThingsBoard.");
        sendTBData();
        Logger::notice("Sending attribute data to ThingsBoard.");
        sendTBAttrData();
        lastSentMillis = millis();
    }
    
    // RPC subscription.
    if (!rpcSubscribed) {
        Logger::notice("Subscribing for RPC.");
        if (!thingsBoard.RPC_Subscribe(receiveRPCCallbackList, receiveRPCCallbackListSize)) {
          Logger::error("Fail subscribing for RPC.");
          return;
        }
        rpcSubscribed = true;
    }
    
    // Attribute subscription.
    if (!attrSubscribed) {
        Logger::notice("Subscribing for attributes.");
        if (!thingsBoard.Attr_Subscribe(receiveAttrCallback)) {
          Logger::error("Fail subscribing for attributes.");
          return;
        }
        attrSubscribed = true;
    }

    // Call ThingsBoard loop.
    thingsBoard.loop();
}
