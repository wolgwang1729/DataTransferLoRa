# DataTransferLoRa

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

## Overview
DataTransferLoRa continuously transmits vehicle sensor data (humidity, temperature, distance, RPM and GPS) over long distances using SX1278 LoRa transceivers and Arduino Uno.

## Hardware Requirements
- 2× SX1278 LoRa modules  
- 2× Arduino Uno  
- DHT11 temperature & humidity sensor  
- HC‑SR04 ultrasonic distance sensor  
- IR sensor (for RPM)  
- NEO‑6M GPS module  

## Wiring Diagram
- LoRa  
  - NSS → D10, SCK → D13, MISO → D12, MOSI → D11, RESET → D9, DIO0 → D2  
- DHT11: data pin → D7  
- HC‑SR04: trig → D9, echo → D10  
- IR sensor → D5  
- GPS RX/TX → D4/D3  

<!-- add visual references -->
![LoRa wiring][1]  
![DHT11 wiring][2]  
![IR wiring][3]  
![GPS wiring][4]  

[1]: https://i.sstatic.net/0cVwpICY.png  
[2]: https://i.sstatic.net/jtN45WAF.png  
[3]: https://i.sstatic.net/oJqCoJUA.png  
[4]: https://i.sstatic.net/CbLImHur.png

## Installation
1. Clone the repo:  
   `git clone https://github.com/youruser/DataTransferLoRa.git`  
2. Open **Transmitter.ino** and **Receiver.ino** in the Arduino IDE.  
3. Install libraries: `LoRa`, `DHT sensor library`, `SoftwareSerial`.  
4. Upload firmware to respective Arduinos.

## Usage
1. Power both units.  
2. Receiver’s Serial Monitor (9600 baud) will display incoming packets.  
3. Transmitter sends sensor readings every second.

## Project Structure
- **Transmitter.ino** – reads sensors and sends LoRa packets  
- **Receiver.ino** – listens for LoRa packets and prints them  

## License
This project is released under the MIT License. See [LICENSE](LICENSE) for details.
