/**
 * Collect DHT data.
 * 
 * @return DynamicJsonDocument JSON data.
 */
DynamicJsonDocument readDHTData(DHT dht, String prefix) {
    // Create JSON data document.
    DynamicJsonDocument data(64);
    
    // Read DHT.
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    if (isnan(temperature) || isnan(humidity)) {
        Logger::warning("Failed to read from DHT sensor!");
        temperature = 0.0;
        humidity = 0.0;
    }
    data[prefix + "_temperature"] = temperature;
    data[prefix + "_humidity"] = humidity;
    
    // Return data.
    return data;
}
