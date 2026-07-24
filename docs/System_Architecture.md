# System Architecture

## Overview

The Agro-Smart Hub is a modular mechatronic system designed to automate selected stages of cassava processing. The system is divided into independent subsystems that perform specific tasks while working together as a single integrated solution.

The major engineering disciplines represented in the project are:

- Mechanical Engineering
- Electrical Engineering
- Embedded Systems
- Mobile Application Development
- Wireless Communication
- Renewable Energy

---

# High-Level Architecture

```
                    Android Controller
                           │
                    Bluetooth Communication
                           │
                  ┌────────▼────────┐
                  │ Truck Controller │
                  │   (Arduino Uno)  │
                  └────────┬─────────┘
                           │
            Bluetooth (Master → Slave)
                           │
                  ┌────────▼────────┐
                  │ Hub Controller   │
                  │   (Arduino Uno)  │
                  └────────┬─────────┘
                           │
        ┌──────────┬────────────┬────────────┐
        │          │            │            │
        ▼          ▼            ▼
 Slant Conveyor  Siever   Flat Conveyor

                           │
                           ▼

                   Mobile Transport Truck

                           │

                    Frying Area
```

---

# System Components

## 1. Renewable Power Station

The renewable power station supplies electrical energy to the entire Agro-Smart Hub.

It consists of:

- Solar panel
- Rechargeable battery pack
- Buck converters
- Power distribution system

Primary function:

- Generate renewable energy.
- Store electrical energy.
- Distribute regulated power to all subsystems.

---

## 2. Embedded Control System

Two Arduino Uno boards coordinate the system.

### Truck Controller

Responsibilities:

- Receive commands from Android application.
- Control truck movement.
- Control dumping mechanism.
- Forward hub commands.

---

### Hub Controller

Responsibilities:

- Receive commands from truck.
- Control conveyors.
- Control sieving mechanism.

---

## 3. Wireless Communication

Communication occurs in two stages.

### Stage 1

Android Application

↓

Truck Bluetooth Module

↓

Truck Arduino

---

### Stage 2

Truck Arduino

↓

Truck Bluetooth (Master)

↓

Hub Bluetooth (Slave)

↓

Hub Arduino

This architecture allows the truck to function as the communication gateway for the stationary processing hub.

---

## 4. Mechanical System

The mechanical system consists of:

- Slant conveyor
- Oscillating siever
- Flat conveyor
- Transport truck
- Truck lifting mechanism

Each subsystem performs a dedicated mechanical function while contributing to the complete processing workflow.

---

## 5. Mobile Robotic Truck

The truck performs three functions:

- Receives processed cassava.
- Transports cassava.
- Discharges cassava at the frying area.

The truck also serves as the communication gateway between the Android controller and the stationary processing hub.

---

# Operational Sequence

The complete system operates as follows:

1. The operator selects a command using the Android application.

2. The command is transmitted to the truck via Bluetooth.

3. The truck Arduino determines whether the command is intended for:

   - the truck, or
   - the stationary hub.

4. Truck commands are executed locally.

5. Hub commands are forwarded wirelessly to the Hub Arduino.

6. The Hub Arduino activates the appropriate conveyor or sieving mechanism.

7. Processed cassava is discharged into the truck.

8. The truck transports the cassava to the frying area.

9. The lifting mechanism discharges the cassava.

---

# Design Philosophy

The Agro-Smart Hub follows a modular systems engineering approach.

Each subsystem was designed, constructed, tested, and validated independently before system integration.

This approach simplified debugging, reduced development risk, and allowed individual subsystems to be improved without affecting the entire system.

---

# Key Design Characteristics

- Modular construction
- Renewable energy powered
- Wireless operation
- Mobile material transport
- Embedded control
- Student-built prototype
- Agricultural automation
