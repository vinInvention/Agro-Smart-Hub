# Truck Subsystem

## Overview

The Truck Subsystem is a mobile robotic platform responsible for transporting sieved cassava from the Agro-Smart Hub to the frying area. In addition to material transportation, the truck serves as the communication gateway between the Android controller and the stationary hub.

Unlike a conventional transport robot, the truck performs both mechanical and communication functions, making it a central component of the Agro-Smart Hub architecture.

---

# Objectives

The Truck Subsystem was designed to:

- Receive commands from the Android application.
- Turn right, turn left, move forward, backward, left, and right.
- Receive sieved cassava from the flat conveyor.
- Transport cassava to the frying area.
- Lift and discharge the cassava carrier.
- Forward hub commands to the stationary controller.

---

# Functional Requirements

| ID    | Requirement                                             |
| ----- | ------------------------------------------------------- |
| TR-01 | Receive wireless commands from the Android application. |
| TR-02 | Control four DC gear motors.                            |
| TR-03 | Support forward and reverse movement.                   |
| TR-04 | Support left and right turning.                         |
| TR-05 | Carry cassava during transportation.                    |
| TR-06 | Lift and discharge the cassava carrier.                 |
| TR-07 | Forward commands intended for the hub.                  |
| TR-08 | Indicate system status using an LED.                    |

---

# Major Components

| Component                 | Function                       |
| ------------------------- | ------------------------------ |
| Arduino Uno               | Main controller                |
| L293D Motor Driver Shield | Controls four DC gear motors   |
| HC-05 Bluetooth Module    | Receives commands from Android |
| HC-05 Bluetooth Module    | Forwards commands to the hub   |
| Four DC Gear Motors       | Drive the truck                |
| Four Relay Module         | Controls lifting mechanism     |
| Linkage Mechanism         | Raises and lowers the carrier  |
| Rack and Pinion Mechanism | Closes and opens the linkage   |
| Indicator LED             | Shows system status            |

---

# Communication Flow

```
Android App
      │
      ▼
HC-05 (Truck Receiver)
      │
      ▼
Arduino Uno
      │
 ┌────┴────┐
 │         │
 ▼         ▼
Truck   HC-05 (Master)
Control      │
             ▼
        Hub HC-05 (Slave)
             │
             ▼
        Hub Arduino
```

> **Truck System Wiring** > ![Truck Controller System Wirirng](../../assets/truck/1.%20Truck%20system%20wiring.png)

---

> **Truck Controller Pinouts**

> ![Truck Controller System Wirirng](../../assets/truck/3.%20Truck%20controller%20pinouts.PNG)

---

> **Truck Power Distribution Wiring** > ![Truck Power Distribution Wirirng](../../assets/truck/2.%20Truck%20Power%20distribution%20wiring.png)

---

The Arduino examines each incoming command. If the command is intended for the truck, it executes it locally. If it is intended for the hub, it forwards the command through the second Bluetooth module.

---

# Mechanical Design

The truck consists of:

- Wooden chassis
- Four-wheel drive
- Cassava carrier
- Linkage lifting mechanism
- Rack and pinion mechanism

The carrier receives sieved cassava directly from the flat conveyor before transporting it to the frying area.

---

# Electrical Design

The truck electronics include:

- Arduino Uno
- L293D Motor Driver Shield
- Two HC-05 Bluetooth modules
- Relay-controlled actuators
- DC gear motors
- Renewable battery supply

Power is supplied from the central renewable power system.

---

# Software Design

The Arduino software performs the following tasks:

1. Receive Bluetooth commands.
2. Decode incoming messages.
3. Determine whether the command is for the truck or hub.
4. Execute truck commands.
5. Forward hub commands.
6. Control truck movement.
7. Control the lifting mechanism.
8. Control the discharge mechanism.

---

# Engineering Challenges

## Pin Availability

The L293D Motor Driver Shield occupied a large number of Arduino Uno pins.

This prevented the use of the originally planned nRF24L01 wireless module.

The communication architecture was redesigned to use Bluetooth modules instead.

---

## Continuous Movement

Initially, the truck continued moving after receiving a movement command.

The Android application was modified so that movement commands were transmitted continuously only while a button remained pressed.

---

## Bluetooth Message Synchronization

Multiple commands occasionally merged into a single message.

Appending a newline character (`\n`) to every transmitted command and processing messages using `readStringUntil('\n')` resolved this issue.

---

## Turning Performance

After installing the lifting mechanism, the additional weight reduced the truck's turning ability.

Increasing the turning speed restored reliable steering performance without mechanical redesign.

---

## Lifting Mechanism

The first linkage design failed when carrying cassava.

The linkage geometry was redesigned, and an additional rack-and-pinion stage was introduced.

The improved mechanism successfully lifted loaded cassava.

---

# Testing

The following tests were completed:

- Bluetooth communication
- Motor direction
- Turning performance
- Carrier lifting
- Carrier discharge
- Command forwarding
- Integrated operation with the hub

The truck successfully completed all functional tests before the competition.

---

# Lessons Learned

Developing the Truck Subsystem demonstrated the importance of considering mechanical, electrical, and software constraints together.

Several successful solutions—including the communication redesign, software improvements, and linkage modifications—were achieved through iterative testing rather than replacing hardware.

The truck became both the transportation platform and the communication gateway, making it one of the most technically significant subsystems within the Agro-Smart Hub.
