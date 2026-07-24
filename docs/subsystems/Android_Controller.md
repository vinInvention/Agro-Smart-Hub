# Android Controller

## Overview

The Android Controller serves as the Human-Machine Interface (HMI) for the Agro-Smart Hub. Developed using MIT App Inventor, it provides a simple graphical interface that allows an operator to wirelessly control both the mobile truck and the stationary processing hub.

Rather than requiring separate applications for different subsystems, the Android Controller communicates with the truck, which acts as the communication gateway to the hub.

---

# Objectives

The Android Controller was designed to:

- Provide a simple user interface for operating the system.
- Control the movement of the truck.
- Control the lifting and discharge mechanisms.
- Control the siever and conveyor systems.
- Minimize operator training.
- Provide reliable wireless command transmission.

---

# Development Platform

| Item              | Description              |
| ----------------- | ------------------------ |
| Platform          | MIT App Inventor         |
| Device            | Android Smartphone       |
| Communication     | Bluetooth Classic        |
| Programming Style | Event-Driven Programming |

---

# User Interface

The application contains controls for the following operations:

## Truck Controls

- Truck ON
- Truck OFF
- System ON
- System OFF
- Forward
- Backward
- Left
- Right
- Lift Carrier
- Lower Carrier
- Discharge Cassava

---

## Hub Controls

- Start Slant Conveyor
- Stop Slant Conveyor
- Start Siever
- Stop Siever
- Start Flat Conveyor
- Stop Flat Conveyor

---

# Communication Protocol

The application sends simple text-based commands.

### Truck Commands

| Command | Description       |
| ------- | ----------------- |
| T:START | Turn truck ON     |
| T:STOP  | Turn truck OFF    |
| T:FWD   | Move forward      |
| T:BWD   | Move backward     |
| T:LEFT  | Turn left         |
| T:RIGHT | Turn right        |
| T:LIFT  | Lift carrier      |
| T:LOWER | Lower carrier     |
| T:DIS   | Discharge cassava |

---

### Hub Commands

| Command    | Description            |
| ---------- | ---------------------- |
| H:CLSTART  | Start lifting conveyor |
| H:CLSTOP   | Stop lifting conveyor  |
| H:CUSSTART | Start flat conveyor    |
| H:CUSSTOP  | Stop flat conveyor     |
| H:SSTART   | Start siever           |
| H:SSTOP    | Stop siever            |

---

# Software Design

The application follows an event-driven programming model.

When a user presses a button:

1. The application generates the corresponding command.
2. A newline character (`\n`) is appended.
3. The command is transmitted over Bluetooth.
4. The Truck Arduino receives and processes the message.

---

# Engineering Challenges

## Continuous Truck Movement

### Problem

Initially, pressing a movement button caused the truck to continue moving even after the operator released the button.

### Investigation

The application transmitted only a single movement command, leaving the truck with no instruction to stop.

### Solution

The application was modified to repeatedly transmit movement commands while the control button remained pressed.

When the button was released, command transmission stopped.

### Outcome

The truck responded naturally to user input and movement became significantly easier to control.

---

## Direction Buttons Not Responding

### Problem

The directional controls appeared correctly on the screen but produced no movement.

### Investigation

Serial debugging confirmed that the Arduino was not receiving commands from these buttons.

The issue was traced to the way image-based controls had been implemented in MIT App Inventor.

### Solution

The image controls were replaced with standard Button components while retaining the desired appearance.

### Outcome

The directional commands were transmitted correctly and truck movement was restored.

---

## Bluetooth Message Synchronization

### Problem

Multiple commands occasionally merged into a single Bluetooth message.

### Solution

Each transmitted command was terminated with a newline character (`\n`).

The Arduino processed incoming messages using `readStringUntil('\n')`.

### Outcome

Command processing became reliable even during rapid user interaction.

---

# Testing

The Android application was tested for:

- Bluetooth connection.
- Command transmission.
- Truck movement.
- Conveyor control.
- Siever control.
- Lift mechanism.
- Command routing.
- User interaction.

All major functions operated successfully after iterative debugging and refinement.

---

# Lessons Learned

Developing the Android Controller demonstrated that designing an effective Human-Machine Interface involves more than creating a graphical layout. Reliable communication, intuitive controls, and responsive behavior required repeated testing and refinement.

The debugging process also reinforced the importance of validating both the software interface and the underlying communication protocol when developing embedded control systems.
