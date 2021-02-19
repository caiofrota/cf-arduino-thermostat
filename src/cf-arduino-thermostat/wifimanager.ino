/**
 * Start WiFiManager.
 */
void wifiManagerBegin() {
    // Load Wi-Fi custom parameters.
    loadWiFiCustomParameters();
    
    // Add params.
    for (int i = 0; i < wifiManagerCustomParametersSize; i++) {
        wifiManager.addParameter(&wifiManagerCustomParameters[i]);
    }
    
    // Start WifiManager.
    wifiManager.setSaveConfigCallback(saveWiFiCustomParameters);
    wifiManager.autoConnect();
    wifiManager.startWebPortal();
    wifiServer.begin();
}

/**
 * WiFiManager loop.
 */
void wifiManagerLoop() {
    wifiManager.process();
}

/**
 * Load Wi-Fi Custom Parameters.
 */
void loadWiFiCustomParameters() {
    Logger::notice("Mount FS.");
    if (SPIFFS.begin()) {
        Logger::notice("Loading Wi-Fi custom parameters.");
        
        // Open file for reading.
        String filePath = "/config.json";
        if (SPIFFS.exists(filePath)) {
            Logger::notice("Open file for reading.");
            File file = SPIFFS.open(filePath, "r");
            if (file) {
                // Create JSON objects.
                DynamicJsonDocument doc(1024);
                
                // Deserialize file into JSON object.
                DeserializationError error = deserializeJson(doc, file);
                if (error) {
                    Logger::error(String("Fail deserializing file. Code: ") + error.c_str());
                }
                
                // Set custom parameters.
                for (int i = 0; i < wifiManagerCustomParametersSize; i++) {
                    String key = wifiManagerCustomParameters[i].getID();
                    if (doc.containsKey(key)) {
                        String value = doc[key];
                        wifiManagerCustomParameters[i].setValue(value.c_str(), wifiManagerCustomParameters[i].getValueLength());
                    }
                }
                Logger::notice("Custom parameters loaded.");
                
                // Close file.
                file.close();
            } else {
                Logger::error("Fail opening file.");
            }
        }
    } else {
        Logger::error("Fail mounting FS.");
    }
}

/**
 * Save Wi-Fi Custom Parameters.
 */
void saveWiFiCustomParameters() {
    // Load values from Wi-Fi Manager form.
    Logger::notice("Saving Wi-Fi custom parameters.");
    
    // Open file for writing.
    String filePath = "/config.json";
    Logger::notice("Open file for writing.");
    File file = SPIFFS.open(filePath, "w");
    if (file) {
        // Create JSON objects.
        DynamicJsonDocument doc(1024);
        
        // Set custom pameters.
        for (int i = 0; i < wifiManagerCustomParametersSize; i++) {
            doc[wifiManagerCustomParameters[i].getID()] = wifiManagerCustomParameters[i].getValue();
        }
        
        if (serializeJson(doc, file) == 0) {
            Logger::error("Fail serializing file.");
        } else {
            Logger::notice("Custom parameters saved.");
        }
        
        // Close file.
        file.close();
    } else {
        Logger::notice("Fail opening file.");
    }
}
