![CF Logo](https://cftechsol.com/wp-content/uploads/2017/12/caiofrota-logo-300x171.png)

# CF Arduino Thermostat

# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [2.0.2] - 2021-03-08
### Fixed

- Bug fix: Telemetry problem with string greater than 64 bytes.

## [2.0.1] - 2021-03-07
### Added

- Add a flag to know when DHT couldn't be read.
- Cleaning code using CFIconSet API.
- Default Wi-Fi password.
- Option to start config portal.
- Option to reset config.

### Changed

- Display OFF default.

## [2.0.0] - 2021-03-07
### Added

- Git ignore file.
- Option to use Display (for NodeMCU Only).
- Temperature index in Celsius and Fahrenheit monitoring via ThingsBoard Dashboard.

### Changed

- Rearrange variables into files and create accessors methods.
- Time to send data to ThingsBoard was increased.
- Wi-Fi manager portal layout.

## [1.0.0] - 2021-02-19
### Added

- Wi-Fi setup via Local IP.
- ThingsBoard setup via Local IP.
- Temperature in Celsius and Fahrenheit monitoring via ThingsBoard Dashboard.
- Humidity monitoring via ThingsBoard Dashboard.

[2.0.2]: https://github.com/caiofrota/cf-arduino-thermostat/compare/v2.0.1...v2.0.2
[2.0.1]: https://github.com/caiofrota/cf-arduino-thermostat/compare/v2.0.0...v2.0.1
[2.0.0]: https://github.com/caiofrota/cf-arduino-thermostat/compare/v1.0.0...v2.0.0
[1.0.0]: https://github.com/caiofrota/cf-arduino-thermostat/releases/tag/v1.0.0