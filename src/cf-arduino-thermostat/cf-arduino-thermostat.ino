/**
 * CF Wi-Fi Thermostat.
 * 
 * IoT - Configurable thermostat using ESP8266 (ESP01 or NodeMCU 1.0 ESP-12E), DHT (11 or 22) and ThingsBoard as server.
 * 
 * @author  Caio Frota <caiofrota@gmail.com>
 * @version 2.0.0
 * @since   Feb, 2021
 */

//#define USE_DISPLAY                                                                                 // Comment this line if you won't use display.

// Libraries.
#include <ArduinoJson.h>                                                                            // Arduino JSON.
#include <DHT.h>                                                                                    // DHT.
#include <Logger.h>                                                                                 // Logger.
#include <SPI.h>                                                                                    // SPI.
#include <ThingsBoard.h>                                                                            // Things Board.
#include <WiFiManager.h>                                                                            // Wi-Fi Manager.
#include <Wire.h>                                                                                   // Wire.

// Libraries Display.
#ifdef USE_DISPLAY
    #include <Adafruit_GFX.h>                                                                       // Adafruit GFX.
    #include <Adafruit_SSD1306.h>                                                                   // Adafruit display.
#endif

// Application attributes.
const char* appSketch = "cf-arduino-thermostat";                                                    // Application sketch.
const char* appVersion = "2.0.0";                                                                   // Application version.

void setup() {
    // Start Serial Monitor.
    Serial.begin(9600);
    //Logger::setLogLevel(Logger::VERBOSE);
    
    // Start display, if declared.
    #ifdef USE_DISPLAY
        displayBegin();
    #endif
    
    dhtBegin();
    wifiManagerBegin();
}

void loop() {
    dhtLoop();                                                                                      // DHT Loop.
    wifiManagerLoop();                                                                              // Wi-Fi Manager loop.
    tbLoop();                                                                                       // Things Board loop.
    
    #ifdef USE_DISPLAY
        displayLoop();                                                                              // Display loop.
    #endif
    
    delay(1000);
}
