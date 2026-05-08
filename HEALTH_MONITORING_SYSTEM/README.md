# 🏥 IoT-Based Patient Health Monitoring System

A professional, real-time health monitoring system built using **Bare-Metal C** on the **ATmega32** microcontroller. This project monitors vital signs (Temperature & Heart Rate) and synchronizes data with the **Blynk 2.0 Cloud** via **MQTT** protocol.

---

## 🚀 Overview

This system is designed to provide continuous monitoring for patients. It processes analog and digital signals locally and bridges the gap between hardware simulation and cloud dashboards using **VSPE** and **MQTT**.

### Key Features:
- **Real-time Monitoring:** Continuous tracking of Body Temperature and BPM.
- **Layered Architecture:** Strict separation between MCAL, HAL, Service, and Application layers.
- **Cloud Integration:** Data is pushed to Blynk Cloud using MQTT over UART.
- **Smart Alarms:** Local hardware indicators (LEDs/Buzzer) for critical health thresholds.
- **Simulation-to-Cloud Bridge:** Utilizes **VSPE** and **COMPIM** to connect Proteus simulation to the live internet.

---

## 🛠️ Tech Stack

### Software:
- **Language:** Bare-metal C.
- **IDE:** Microchip Studio (Atmel Studio).
- **Protocol:** MQTT (Message Queuing Telemetry Transport).
- **Simulation:** Proteus 8.15+.
- **Bridge Tool:** VSPE (Virtual Serial Port Emulator).
- **Cloud:** Blynk 2.0.

### Hardware (Simulated):
- **MCU:** ATmega32.
- **Sensors:** LM35 (Temperature), Heartbeat Signal Simulator.
- **Outputs:** 16x2 CLCD (4-bit mode), LEDs (Normal/Critical), Active Buzzer.
- **Communication:** ESP8266 (Interfaced via COMPIM/UART).

---

## 🏗️ System Architecture

The project follows a modular **Layered Architecture** to ensure clean code and easy portability:

| Layer | Description |
| :--- | :--- |
| **APPLICATION** | Main logic, system initialization, and the super-loop. |
| **SERVICE** | Delay handlers, MQTT packet formatting, and utility functions. |
| **ECUAL/HAL** | Drivers for LCD, Sensors (LM35, Heartbeat), LEDs, and Buzzer. |
| **MCAL** | Low-level peripheral drivers: ADC, UART, Timer1, EXTI, and GPIO. |
| **LIB** | Common macros, bit-math, and standard types. |

---

## 🔌 Circuit Schematic

The system is divided into 4 main functional blocks:
1. **Sensing Unit:** Collects vital data from patient simulators.
2. **Processing Unit:** The "Brain" (ATmega32) handling calculations and logic.
3. **Local Output & Alarms:** Visual (LCD/LEDs) and Audible (Buzzer) feedback.
4. **IoT & Communication:** Bridging UART data to the Cloud via virtual COM ports.

---

## 📈 Cloud Dashboard

The system syncs with a **Blynk Dashboard** featuring:
- Real-time Gauges for Temperature and BPM.
- Historical Data Charts to track patient stability.
- Instant Mobile Notifications for emergency cases.

---

## 👥 The Team

This project was developed during the **NTI (National Telecommunication Institute)** training by:

- **Sherif Osama** - [GitHub Profile Link]
- **Team Member 1** - [GitHub Link]
- **Team Member 2** - [GitHub Link]
- **Team Member 3** - [GitHub Link]

---

## 📄 License
This project is licensed under the MIT License - see the LICENSE file for details.
