# ⚡ PowerSentry – Smart Charging Socket

**“Automatically cuts power when charging is complete – Save energy. Protect your battery.”**

**PowerSentry** is a smart IoT-based socket that prevents overcharging by cutting off the power supply once a device reaches full charge. Built using **NodeMCU ESP8266**, **Arduino Uno**, and a **relay module**, it ensures safe, efficient, and energy-conscious charging. It can simulate charging behavior or integrate actual current sensors for real-time monitoring, all controllable via the **Blynk** app.

---

## 🔧 Core Features

- Manual ON/OFF control via Blynk  
- Simulated charging progress with percentage tracking  
- Automatic relay cutoff at 100% charge  
- Green and Red status indicators  
- Real-time label updates  
- Optional current sensor integration (ACS712 / INA219)  

---

## 🌍 Impact

- Reduces phantom power usage  
- Prevents battery overcharging and degradation  
- Encourages sustainable and safe charging habits  
- Ideal for homes, hostels, and elderly-friendly automation  

---

## 🛠 Tech Stack

- **Microcontrollers**: NodeMCU ESP8266, Arduino Uno  
- **Relay Control**: 5V Relay Module  
- **Communication**: UART Serial  
- **Interface**: Blynk IoT Dashboard  
- **Optional Sensors**: ACS712 or INA219 (for real-time current detection)  
- **Development Platform**: Arduino IDE, Fritzing (for circuit design)  

---

## 🚀 How to Run

1. Upload the provided code to your NodeMCU using Arduino IDE.  
2. Connect the NodeMCU to a relay module following the circuit diagram.  
3. Use serial communication via Arduino Uno for relay control.  
4. Open the Blynk app and use the following link to access the live dashboard:  
   🔗 https://blynk.cloud/dashboard/514505/global/devices/1/organization/514505/devices/1661831/dashboard
5. Use virtual pins V0 to V4 for control and feedback.
