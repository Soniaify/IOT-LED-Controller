# IoT LED Controller (Arduino + Wi-Fi)

This project allows you to control an LED remotely over Wi-Fi using an Arduino board with ESP8266/ESP32 capabilities. The system listens for HTTP requests and switches the LED **ON** or **OFF** accordingly. It’s a simple starting point for building home automation systems.

---

Features
- Remote LED control via HTTP requests
- Works on a local network or over the internet
- Simple and lightweight code
- Easy to expand for multiple devices

---

Components Required
- Arduino board with Wi-Fi capability (ESP8266 NodeMCU / ESP32)
- LED
- 220Ω resistor
- Breadboard and jumper wires
- USB cable for programming

---

Circuit Diagram
1. **LED Anode (+)** → **GPIO Pin** (as defined in the code)
2. **LED Cathode (-)** → **GND** (through 220Ω resistor)


---

Setup Instructions

1. **Install Arduino IDE**  
   Download from [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software).

2. **Add ESP8266/ESP32 Board Support**  
   - Go to **File → Preferences**  
   - Add this URL in **Additional Board Manager URLs**:  
     ```
     http://arduino.esp8266.com/stable/package_esp8266_index.json
     ```
     *(Or for ESP32, use its respective URL.)*

3. **Install Required Libraries**  
   - `ESP8266WiFi` (comes with board package)
   - `ESP8266WebServer` (comes with board package)

4. **Edit the Code**  
   - Open `LED_IOT.ino`
   - Set your **Wi-Fi SSID** and **password** in the variables:
     ```cpp
     const char* ssid = "YOUR_WIFI_NAME";
     const char* password = "YOUR_WIFI_PASSWORD";
     ```

5. **Upload the Code**  
   - Select the correct board and COM port
   - Upload the sketch

---

Usage
- Once uploaded, open **Serial Monitor** (baud 115200) to see the device’s IP address.
- In your browser, type:
  - `http://<DEVICE_IP>/led/on` → Turn LED ON
  - `http://<DEVICE_IP>/led/off` → Turn LED OFF

Example for GPIO 2 (D4 on NodeMCU):
