![alt text](https://cftechsol.com/wp-content/uploads/2017/12/caiofrota-logo-300x171.png)

[![GitHub issues](https://img.shields.io/github/issues/caiofrota/cf-arduino-thermostat.svg)](https://github.com/caiofrota/cf-rest/issues)
[![Fork](https://img.shields.io/github/forks/caiofrota/cf-arduino-thermostat.svg)](#)
[![Stars](https://img.shields.io/github/stars/caiofrota/cf-arduino-thermostat.svg)](#)
[![License](https://img.shields.io/github/license/caiofrota/cf-arduino-thermostat.svg)](#)
[![Total Downloads](https://img.shields.io/github/downloads/caiofrota/cf-arduino-thermostat/total.svg)](https://github.com/caiofrota/cf-arduino-thermostat/releases)
[![Slack Chat](https://img.shields.io/badge/chat-slack-green.svg)](https://cftechsol.slack.com)
[![Website](https://img.shields.io/badge/website-cftechsol.com-green.svg)](https://cftechsol.com)

# CF Arduino Thermostat

IoT - Configurable thermostat using ESP8266 (ESP01 or NodeMCU 1.0 ESP-12E), DHT (11 or 22) and ThingsBoard as server.

Version 2.0.2

## Quick Start

### Prerequisites

What things you need to install the software and how to install them

- [Arduino IDE](https://www.arduino.cc/) - Development IDE Version 1.8.13
- [ESP8266](https://arduino.esp8266.com/Arduino/versions/2.0.0/doc/installing.html) - ESP8266 Boards Version 2.7.4

### Dependencies

- [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library/releases/tag/1.10.6) - Adafruit GFX Library Version 1.10.6
- [Adafruit SSD1306.h](https://github.com/adafruit/Adafruit_SSD1306/releases/tag/2.4.3) - Adafruit SSD1306 Library Version 2.4.3
- [ArduinoJson](https://github.com/bblanchon/ArduinoJson/releases/tag/v6.17.3) - Arduino JSON Library Version 6.17.3
- [DHT](https://github.com/adafruit/DHT-sensor-library/releases/tag/1.4.1) - DHT Sensor Library Version 1.4.1
- [Logger](https://github.com/caiofrota/Logger/releases/tag/v1.0.3_caiofrota) - Logger Library Version 1.0.3 (modified)
- [ThingsBoard](https://github.com/caiofrota/ThingsBoard-Arduino-MQTT-SDK/releases/tag/v0.5.0) - Things Board Version 0.5.0 (modified)
- [WiFiManager](https://github.com/tzapu/WiFiManager) - Wi-Fi Manager Version 2.0.4_beta

#### Arduino Libraries

- SPI - Serial Peripheral Interface Library.
- Wire - I2C Communication Library.

### Installing

- Checkout the latest changes or a release from GitHub.
- Open the file "src/cf-arduino-thermostat/cf-arduino-thermostat.ino" on Arduino IDE.
- Select your board (Tools > Board > ESP8266 Boards).
- Upload (Sketch > Upload).

### For more info about usage

- Please read our [Wiki](https://github.com/caiofrota/cf-arduino-thermostat/wiki).

## Support or Contact

Contact us at contact@cftechsol.com for questions and we'll help you sort it out.

## Issues

Find a bug or want to request a new feature? Please let us know by [submitting an issue](https://github.com/caiofrota/cf-arduino-thermostat/issues).

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/caiofrota/6e65a17fd3bf100d058cb48dcc780b21) for details on our code of conduct, and the process for submitting pull requests to us.

## Authors

* **Caio Frota** - *Initial work* - [caiofrota](https://github.com/caiofrota) | [CF Technology Solutions](https://cftechsol.com)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details