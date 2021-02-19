/**
 * CF Wi-Fi Thermostat.
 * 
 * IoT - Configurable thermostat using ESP8266 (ESP01 or NodeMCU 1.0 ESP-12E), DHT (11 or 22) and ThingsBoard as server.
 * 
 * @author  Caio Frota <contact@cftechsol.com>
 * @version 1.0.0
 * @since   Feb, 2021
 */

// Libraries.
#include "ArduinoJson.h"                                                                            // Arduino JSON.
#include "DHT.h"                                                                                    // DHT.
#include "Logger.h"                                                                                 // Logger.
#include "ThingsBoard.h"                                                                            // ThingsBoard.
#include "WiFiManager.h"                                                                            // Wi-Fi Manager.

// Application attributes.
const char* appSketch = "cf-arduino-thermostat";                                                    // Application sketch.
const char* appVersion = "1.0.0";                                                                   // Application version.

//DHT dht(2,  DHT11);                                                                                 // DHT11 on ESP01 Module.
//DHT dht(D2, DHT11);                                                                                 // DHT11 on NodeMCU ESP-12E Module.
DHT dht(2,  DHT22);                                                                                 // DHT22 on ESP01 Module.
//DHT dht(D2, DHT22);                                                                                 // DHT22 on NodeMCU ESP-12E Module.

WiFiClient wifiClient;                                                                              // Wi-Fi.
WiFiServer wifiServer(80);                                                                          // Wi-Fi.
WiFiManager wifiManager;                                                                            // Wi-Fi Manager.
ThingsBoard thingsBoard(wifiClient);                                                                // ThingsBoard.

// Custom Parameters.
WiFiManagerParameter wifiManagerCustomParameters[] = {                                              // Custom paramaters array.
    { "devicename", "Device Name", "", 50 },
    { "serverurl", "Server URL", "", 50 },
    { "token", "Token", "", 50 }
};
int wifiManagerCustomParametersSize = 3;                                                            // Custom parameters array size.

#define P_DEVICE_NAME                  0                                                            // Custom parameter index.
#define P_SERVER_URL                   1                                                            // Custom parameter index.
#define P_TOKEN                        2                                                            // Custom parameter index.

void setup() {
    // Start Serial Monitor.
    Serial.begin(9600);
    //Logger::setLogLevel(Logger::VERBOSE);
    
    // Start DHT.
    dht.begin();
    
    // Start WiFiManager.
    wifiManagerBegin();
}

void loop() {
    wifiManagerLoop();                                                                              // Wi-Fi Manager loop.
    thingsBoardLoop();                                                                              // ThingsBoard loop.
    
    delay(1000);
}
