# Software Architecture

Project: Agro-Smart Hub

---

# Overview

The Agro-Smart Hub software consists of three major software components that work together to control the entire system.

1. Android Controller
2. Truck Controller Firmware
3. Hub Controller Firmware

The Android application acts as the Human-Machine Interface (HMI), while two Arduino Uno microcontrollers execute the control logic for the mobile truck and the stationary processing hub.

---

# Software Components

## Android Controller

Responsibilities

- Connect to the truck via Bluetooth.
- Display user controls.
- Generate control commands.
- Send encoded messages.
- Provide manual control of the complete system.

Development Platform

- MIT App Inventor

---

## Truck Controller Firmware

Platform

- Arduino Uno

Responsibilities

- Receive Bluetooth commands.
- Parse incoming messages.
- Control truck movement.
- Control the lifting mechanism.
- Control the discharge mechanism.
- Forward hub commands to the Hub Controller.

---

## Hub Controller Firmware

Platform

- Arduino Uno

Responsibilities

- Receive forwarded commands.
- Control the siever.
- Control the flat conveyor.
- Control the slant conveyor.
- Operate relay outputs.

---

# Communication Flow

The communication process is illustrated below.

Android Application

↓

Truck Bluetooth Module

↓

Truck Arduino

↓

If command is for Truck

↓

Execute locally

OR

If command is for Hub

↓

Forward through Master Bluetooth

↓

Slave Bluetooth

↓

Hub Arduino

↓

Execute command

---

# Command Protocol

Commands are transmitted as text strings.

Examples

T:START

T:FWD

T:BWD

T:LEFT

T:RIGHT

T:LIFT

T:LOWER

T:DIS

H:SIEVER_ON

H:SIEVER_OFF

H:FLAT_ON

H:SLANT_ON

Each message consists of a prefix identifying the destination subsystem followed by the command.

---

# Message Parsing

Each received message is divided into two sections using the colon (:) delimiter.

Example

T:FWD

becomes

Destination = T

Command = FWD

The firmware then determines whether the command should be executed locally or forwarded to the Hub Controller.

---

# Truck Firmware Workflow

1. Wait for Bluetooth message.
2. Read complete command.
3. Parse command.
4. Verify system state.
5. Execute truck command or forward hub command.
6. Wait for next command.

---

# Hub Firmware Workflow

1. Wait for forwarded command.
2. Read command.
3. Match command.
4. Activate or deactivate relay.
5. Return to waiting state.

---

# Error Handling

The firmware includes several simple error handling strategies.

- Ignore unknown commands.
- Trim whitespace from received messages.
- Use newline characters to separate consecutive commands.
- Execute commands only after the system has been started.

---

# Design Decisions

Several software design decisions improved system reliability.

- Separate firmware for truck and hub.
- Text-based command protocol.
- Modular command routing.
- SoftwareSerial communication between controllers.
- Distributed control architecture.

---

# Future Improvements

Future software enhancements may include:

- Command acknowledgements.
- Error reporting.
- Automatic reconnection.
- Battery status reporting.
- Sensor feedback.
- Autonomous navigation.
- Computer vision integration.

---

# Media to Add Later

- Android App screenshots.
- App Inventor block diagrams.
- Firmware flowcharts.
- Communication sequence diagram.
