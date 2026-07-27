# 📈 SmartSensorFilter

> *"Turning chaotic sensor noise into silky-smooth data streams"*

[![Arduino Compile Check](https://img.shields.io/badge/Arduino-Compatible-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)
[![Version](https://img.shields.io/badge/Version-v1.0.0-blue.svg?style=for-the-badge)](https://github.com/tawfique02/SmartSensorFilter/releases)
[![Platform](https://img.shields.io/badge/Platform-Embedded-orange?style=for-the-badge)](https://www.arduino.cc/)

---

## 🎯 **What is SmartSensorFilter?**

**SmartSensorFilter** is a lightweight, memory-efficient C++ library crafted specifically for Arduino and embedded systems. It tames the wild fluctuations of analog sensor readings using a **Moving Average Algorithm** – transforming erratic, noisy data into clean, reliable, and actionable insights.

Whether you're building a weather station, a robotic arm, or a home automation system, this library ensures your sensors speak the truth, not the noise.

---

## ✨ **Why Choose SmartSensorFilter?**

Real-world sensors are messy. Electrical interference, voltage drops, and environmental factors create data chaos. SmartSensorFilter silences this noise with elegance:

| Feature | Benefit |
|---------|---------|
| 🚀 **Ultra-Lightweight** | Uses less than 11% of Arduino Uno's dynamic memory |
| ⚡ **Blazing Fast** | Real-time filtering with zero perceptible lag |
| 🎛️ **Fully Configurable** | Adjust sample window size from 2 to 100+ samples |
| 🔌 **Plug & Play** | Add to any sketch with just **2 lines of code** |
| 🌍 **Hardware Agnostic** | Works on Uno, Nano, Mega, ESP8266, ESP32, STM32, and more |
| 🧠 **Intelligent Buffer** | Circular buffer design for optimal memory usage |

---

## 🔬 **The Science Behind the Magic**

SmartSensorFilter employs a **rolling window average** – each new reading replaces the oldest sample in the buffer, and the average is recalculated instantly. This creates a smooth, responsive data stream that adapts to changes while canceling out random spikes.

### 📊 **Visual Comparison**

```text
Raw Signal (Jumpy):    [57] ---> [69] ---> [73] ---> [58] ---> [74]
Filtered (Smoothed):   [05] ---> [12] ---> [19] ---> [25] ---> [57]
```

## 📁 Repository Architecture
```
SmartSensorFilter/
├── examples/
│   └── BasicSmoothing/
│       └── BasicSmoothing.ino   # Complete ready-to-run demo sketch
├── src/
│   ├── SmartSensorFilter.cpp    # High-performance C++ implementation
│   └── SmartSensorFilter.h      # Clean & documented header definition
├── keywords.txt                 # Syntax highlighting configuration for Arduino IDE
├── library.properties           # Metadata for official Arduino Library Manager
└── README.md                    # Project documentation
```
## 📦 Installation
### Method 1: Manual ZIP Installation (Recommended)
```
Click the green Code button at the top of this repository and select Download ZIP.

Open your Arduino IDE.

Navigate to Sketch ➔ Include Library ➔ Add .ZIP Library...

Select the downloaded .zip file.
```
### Method 2: Arduino Library Manager
```
(Upcoming) Search for SmartSensorFilter directly in the Arduino Library Manager and click Install.
```
## 🚀 Quick Start Example
```
#include <SmartSensorFilter.h>

// Initialize filter with a moving average sample window of 10
SmartSensorFilter filter(10);

void setup() {
  Serial.begin(9600);
  filter.begin(); // Initialize internal buffer
}

void loop() {
  // Simulate noisy sensor data (e.g., values jumping between 50 and 80)
  int rawValue = random(50, 80);

  // Process the raw input and retrieve smoothed output
  int filteredValue = filter.update(rawValue);

  // Send readings to Serial Plotter for real-time visualization
  Serial.print("Raw:");
  Serial.print(rawValue);
  Serial.print(",");
  Serial.print("Filtered:");
  Serial.println(filteredValue);

  delay(100);
}
```
### 💡 Pro Tip: Go to Tools ➔ Serial Plotter in the Arduino IDE to view a live graph comparing raw noise vs. filtered signals!
---
### 🛠️ API Reference
SmartSensorFilter(int windowSize)

---
```
Description: Constructor. Prepares the filter with a designated sample window length.

Parameter: windowSize (int) — Number of historic readings to average (e.g., 5 for fast response, 20 for maximum smoothing).

void begin()
Description: Allocates buffer space and clears historic data. Call inside setup().

int update(int rawInput)
Description: Pushes a new raw reading into the buffer, recalculates the moving average, and returns the smoothed value.

Parameter: rawInput (int) — Current raw sensor value from analogRead().

Returns: (int) — Clean, filtered sensor reading.
```
## **📜 License**
*Distributed under the [MIT License](https://opensource.org/licenses/MIT). See [LICENSE](https://github.com/tawfique02/SmartSensorFilter/blob/main/LICENSE) for more information.*
## 🤝 Author & Support

Crafted with ❤️ by tawfique02
> *If this library saved you time or improved your hardware project, please consider giving it a ⭐️ Star! Issues and Pull Requests are always welcome.*
