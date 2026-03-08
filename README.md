# 🌫️ IoT Air Quality Monitoring using ESP32 and ThingSpeak

This project implements a **real-time air quality monitoring system** using an **ESP32 microcontroller** and a **gas sensor**. The system reads gas concentration values from the sensor, classifies the air quality level, and uploads the data to **ThingSpeak cloud** for remote monitoring and analysis.

---

# 📌 Project Overview

Air pollution is a major environmental concern. This project provides a simple **IoT-based solution** to monitor air quality in real time.

The ESP32 reads analog values from a **gas sensor (MQ series)** connected to GPIO34. The sensor data is processed, categorized into air quality levels, and transmitted to **ThingSpeak** over WiFi.

Users can monitor the air quality remotely using the **ThingSpeak dashboard and graphs**.

---

# ⚙️ Hardware Requirements

* ESP32 Development Board
* MQ Gas Sensor (MQ2 / MQ135 or similar)
* Breadboard
* Jumper Wires
* WiFi connection

---

# 💻 Software Requirements

* Arduino IDE
* ESP32 Board Package
* ThingSpeak Library

Install the required library in Arduino IDE:

```
ThingSpeak by MathWorks
```

---

# 🔌 System Architecture

Gas Sensor → ESP32 ADC → Data Processing → WiFi → ThingSpeak Cloud → Dashboard Visualization

---

# 📡 Pin Configuration

| Component                | ESP32 Pin |
| ------------------------ | --------- |
| Gas Sensor Analog Output | GPIO34    |

---

# 🧠 Working Principle

1. ESP32 connects to a WiFi network.
2. The gas sensor provides an **analog voltage proportional to gas concentration**.
3. ESP32 reads the sensor value using **ADC (Analog-to-Digital Converter)**.
4. Multiple readings are averaged to reduce noise.
5. Air quality is classified into three levels:

| Gas Value   | Air Quality |
| ----------- | ----------- |
| 0 – 1200    | Low         |
| 1201 – 2500 | Medium      |
| > 2500      | High        |

6. Data is uploaded to **ThingSpeak**:

   * Field 1 → Gas Sensor Value
   * Field 2 → Air Quality Level

7. The cloud dashboard visualizes the readings using graphs.

---

# 📊 ThingSpeak Channel Fields

| Field   | Description       |
| ------- | ----------------- |
| Field 1 | Gas Sensor Value  |
| Field 2 | Air Quality Level |

---

# 🚀 How to Run the Project

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/yourusername/air-quality-monitor-esp32.git
```

---

### 2️⃣ Configure WiFi Credentials

Edit the following in the code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

---

### 3️⃣ Configure ThingSpeak

Update your channel details:

```cpp
unsigned long channelID = YOUR_CHANNEL_ID;
const char* writeAPIKey = "YOUR_WRITE_API_KEY";
```

---

### 4️⃣ Upload Code

1. Connect ESP32 to your computer.
2. Select the correct **COM port**.
3. Upload the code using **Arduino IDE**.

---

### 5️⃣ Monitor Output

Open **Serial Monitor (115200 baud)** to view sensor readings and connection status.

---

# 📈 Example Serial Output

```
Gas Value: 1350
Air Quality Level: 2
Data Sent Successfully
```



---

If you want, I can also give you a **🔥 more professional GitHub README (with badges, architecture diagram, and screenshots)** that looks **much better for internships and resumes.**
