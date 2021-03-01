//DHT dht(2,  DHT11);                                                                                 // DHT11. (D4/GPIO2)
DHT dht(2,  DHT22);                                                                                 // DHT22. (D4/GPIO2)

float dhtTemperatureC = 0;                                                                          // Temperature in Celsius.
float dhtTemperatureF = 0;                                                                          // Temperature in Fahrenheit.
float dhtHumidity = 0;                                                                              // Humidity.
float dhtHeatIndexC = 0;                                                                            // Heat index in Celsius.
float dhtHeatIndexF = 0;                                                                            // Heat index in Fahrenheit.

/**
 * Collect DHT data.
 */
void dhtReadData() {
    // Read DHT
    dhtTemperatureC = dht.readTemperature();
    dhtTemperatureF = dht.readTemperature(true);
    dhtHumidity = dht.readHumidity();

    // Check if it was read.
    if (isnan(dhtTemperatureC) || isnan(dhtTemperatureF) || isnan(dhtHumidity)) {
        Logger::warning("Failed to read from DHT sensor!");
        dhtTemperatureC = 0.0;
        dhtTemperatureF = 0.0;
        dhtHumidity = 0.0;
        dhtHeatIndexC = 0.0;
        dhtHeatIndexF = 0.0;
        return;
    }
    
    dhtTemperatureC = roundf(dhtTemperatureC * 10) / 10;
    dhtTemperatureF = roundf(dhtTemperatureF * 10) / 10;
    dhtHumidity = roundf(dhtHumidity * 10) / 10;
    dhtHeatIndexC = roundf(dht.computeHeatIndex(dhtTemperatureC, dhtHumidity, false) * 10) / 10;
    dhtHeatIndexF = roundf(dht.computeHeatIndex(dhtTemperatureF, dhtHumidity) * 10) / 10;
}

/**
 * Start DHT.
 */
void dhtBegin() {
    dht.begin();
}

/**
 * DHT Loop.
 */
void dhtLoop() {
    dhtReadData();
}

/**
 * Get DHT Temperature in C.
 */
float getDHTTemperatureC() {
    return dhtTemperatureC;
}

/**
 * Get DHT Temperature in F.
 */
float getDHTTemperatureF() {
    return dhtTemperatureF;
}

/**
 * Get DHT Heat Index in C.
 */
float getDHTHeatIndexC() {
    return dhtHeatIndexC;
}

/**
 * Get DHT Heat Index in F.
 */
float getDHTHeatIndexF() {
    return dhtHeatIndexF;
}

/**
 * Get DHT Humidity.
 */
float getDHTHumidity() {
    return dhtHumidity;
}
