# Communication System

## Overview

The Communication System enables wireless control of the Agro-Smart Hub using an Android application. It allows a single operator to control both the mobile truck and the stationary processing hub without physical wiring between the two controllers.

The truck functions as the communication gateway, receiving commands from the Android application and forwarding hub-specific commands to the stationary hub.

---

# Objectives

The Communication System was designed to:

- Provide wireless control of the complete system.
- Allow one Android application to control both the truck and the hub.
- Eliminate long communication cables.
- Separate truck commands from hub commands.
- Provide reliable communication during demonstrations.

---

# Hardware Components

| Component                        | Quantity | Function                       |
| -------------------------------- | -------- | ------------------------------ |
| Android Phone                    | 1        | User interface                 |
| HC-05 Bluetooth (Truck Receiver) | 1        | Receives commands from Android |
| Arduino Uno (Truck)              | 1        | Processes and routes commands  |
| HC-05 Bluetooth (Truck Master)   | 1        | Sends hub commands             |
| HC-05 Bluetooth (Hub Slave)      | 1        | Receives forwarded commands    |
| Arduino Uno (Hub)                | 1        | Controls stationary equipment  |

---

# Communication Architecture

```


                ANDROID CONTROLLER
                         │
                    Bluetooth
                         │
                         ▼
                ┌─────────────────┐
                │ HC-05 — Slave 1 │
                │  Truck Controller│
                └────────┬────────┘
                         │
                  Arduino UNO
                  TRUCK CONTROLLER
                         │
                    SoftwareSerial
                         │
                         ▼
                ┌─────────────────┐
                │ HC-05 — Master  │
                │  Truck Controller│
                └────────┬────────┘
                         │
                    Bluetooth
                         │
                         ▼
                ┌─────────────────┐
                │ HC-05 — Slave 2 │
                │  Hub Controller │
                └────────┬────────┘
                         │
                    SoftwareSerial
                         │
                         ▼
                  Arduino UNO
                  HUB CONTROLLER
                         │
          ┌──────────────┼──────────────┐
          ▼              ▼              ▼
     Slant Conveyor   Flat Conveyor    Siever
```

---

# Message Structure

Commands are transmitted as encoded text strings.

### Truck Commands

| Command | Function              |
| ------- | --------------------- |
| T:START | Turn truck system ON  |
| T:STOP  | Turn truck system OFF |
| T:FWD   | Move forward          |
| T:BWD   | Move backward         |
| T:LEFT  | Turn left             |
| T:RIGHT | Turn right            |
| T:LIFT  | Raise carrier         |
| T:LOWER | Lower carrier         |
| T:DIS   | Discharge cassava     |

---

### Hub Commands

| Command    | Function               |
| ---------- | ---------------------- |
| H:CLSTART  | Start lifting conveyor |
| H:CLSTOP   | Stop lifting conveyor  |
| H:CUSSTART | Start flat conveyor    |
| H:CUSSTOP  | Stop flat conveyor     |
| H:SSTART   | Start siever           |
| H:SSTOP    | Stop siever            |

---

# Command Processing

The Truck Arduino performs the following sequence:

1. Receive Bluetooth message.
2. Split the command into prefix and instruction.
3. Determine the destination.
4. Execute truck commands locally.
5. Forward hub commands through the second Bluetooth module.

This routing strategy allows a single Bluetooth connection between the Android application and the Agro-Smart Hub.

---

# Engineering Decisions

## Gateway Architecture

Instead of connecting the Android application independently to two controllers, the truck was selected as the communication gateway.

Advantages:

- One user connection.
- Simpler Android application.
- Reduced operator workload.
- Centralized command routing.

---

## Bluetooth Selection

The original design proposed the use of nRF24L01 radio modules.

During development, pin availability on the Arduino Uno became a limiting factor because the L293D Motor Driver Shield occupied several digital pins.

Bluetooth modules were selected because they could be integrated without conflicting with the motor driver shield.

---

## Message Delimiting

A newline character (`\n`) was appended to every transmitted command.

The Arduino software reads commands using:

```cpp
readStringUntil('\n');
```

This prevents multiple commands from merging into a single message during rapid transmission.

---

# Testing

The Communication System was tested for:

- Android to truck communication.
- Truck movement commands.
- Hub command forwarding.
- Bluetooth pairing.
- Simultaneous subsystem control.
- Command reliability.

The communication architecture successfully enabled wireless control of both mobile and stationary subsystems during development and competition demonstrations.

---

# Lessons Learned

The Communication System highlighted the importance of designing around hardware constraints.

Although Bluetooth was not the original communication technology, adapting the design in response to Arduino pin limitations resulted in a reliable and effective communication architecture.

The gateway approach simplified system operation and demonstrated how embedded controllers can coordinate distributed mechatronic subsystems.
