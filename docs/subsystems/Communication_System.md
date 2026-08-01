# Communication System

## 1. Overview

The Agro-Smart Hub uses a wireless communication system to allow a single operator to control both the mobile transport truck and the stationary cassava-processing hub.

The system uses **three HC-05 Bluetooth modules** distributed across the Android controller, Truck Controller, and Hub Controller.

The Truck Controller serves as the communication gateway between the Android application and the stationary Hub Controller.

The communication architecture consists of two wireless communication links:

1. **Android Controller → Truck Controller**
2. **Truck Controller → Hub Controller**

The three Bluetooth modules work together to establish these communication paths.

---

# 2. Communication Objectives

The communication system was designed to:

- Provide wireless control of the Agro-Smart Hub.
- Allow one operator to control the complete system.
- Allow the Android application to control both the truck and stationary hub.
- Eliminate long communication cables between controllers.
- Separate truck commands from hub commands.
- Allow the Truck Controller to forward commands to the Hub Controller.
- Provide reliable communication during system demonstrations.
- Keep the communication architecture compatible with the Arduino Uno hardware used in the project.

---

# 3. Communication Hardware

The communication system consists of the following major components:

| Component                      | Quantity | Function                                                 |
| ------------------------------ | -------: | -------------------------------------------------------- |
| Android Phone                  |        1 | User interface and command generation                    |
| HC-05 — Truck Slave            |        1 | Receives commands from Android Controller                |
| Arduino Uno — Truck Controller |        1 | Processes truck commands and routes hub commands         |
| HC-05 — Truck Master           |        1 | Transmits hub commands from truck to hub                 |
| HC-05 — Hub Slave              |        1 | Receives forwarded commands from truck                   |
| Arduino Uno — Hub Controller   |        1 | Processes hub commands and controls stationary equipment |

---

# 4. Bluetooth Module Roles

Three HC-05 modules are used in the complete system.

| Module          | Location | Bluetooth Role | Communication   |
| --------------- | -------- | -------------- | --------------- |
| HC-05 — Slave 1 | Truck    | Slave          | Android → Truck |
| HC-05 — Master  | Truck    | Master         | Truck → Hub     |
| HC-05 — Slave 2 | Hub      | Slave          | Truck → Hub     |

The two HC-05 modules located on the truck perform different communication functions.

### Slave 1

The first HC-05 receives commands from the Android application.

```text
Android Controller
        │
    Bluetooth
        │
        ▼
HC-05 Slave 1
        │
        ▼
Truck Arduino
```

### Master

The second HC-05 is configured as a master and communicates with the HC-05 Slave 2 located on the stationary hub.

```text
Truck Arduino
      │
SoftwareSerial
      │
      ▼
HC-05 Master
      │
  Bluetooth
      │
      ▼
HC-05 Slave 2
      │
      ▼
Hub Arduino
```

---

# 5. Communication Architecture

The complete communication architecture is:

```text
                    ANDROID CONTROLLER
                           │
                       Bluetooth
                           │
                           ▼
                  ┌─────────────────┐
                  │ HC-05 — Slave 1 │
                  │     Truck       │
                  └────────┬────────┘
                           │
                           │ Serial
                           ▼
                  ┌─────────────────┐
                  │ Truck Arduino   │
                  │   Controller    │
                  └────────┬────────┘
                           │
                     SoftwareSerial
                           │
                           ▼
                  ┌─────────────────┐
                  │ HC-05 — Master  │
                  │     Truck       │
                  └────────┬────────┘
                           │
                       Bluetooth
                           │
                           ▼
                  ┌─────────────────┐
                  │ HC-05 — Slave 2 │
                  │      Hub        │
                  └────────┬────────┘
                           │
                     SoftwareSerial
                           │
                           ▼
                  ┌─────────────────┐
                  │ Hub Arduino     │
                  │   Controller    │
                  └───────┬─────────┘
                          │
             ┌────────────┼────────────┐
             ▼            ▼            ▼
        Slant Conveyor  Flat Conveyor  Siever
```

The Truck Controller therefore functions as a **wireless communication gateway** between the Android application and the stationary Hub Controller.

---

# 6. Communication Links

## 6.1 Link 1 — Android to Truck

The first communication link connects the Android application to the Truck Controller.

```text
Android Application
        │
    Bluetooth
        │
        ▼
HC-05 Slave 1
        │
        ▼
Truck Arduino
```

The Android application sends commands containing instructions for either:

- the truck, or
- the stationary hub.

The Truck Arduino receives these commands and determines their destination.

---

## 6.2 Link 2 — Truck to Hub

The second communication link connects the Truck Controller to the stationary Hub Controller.

```text
Truck Arduino
     │
     ▼
HC-05 Master
     │
 Bluetooth
     │
     ▼
HC-05 Slave 2
     │
     ▼
Hub Arduino
```

Commands intended for the stationary processing equipment are forwarded through this link.

---

# 7. Command Routing

The Truck Controller is responsible for determining the destination of every command received from the Android application.

The processing sequence is:

```text
Receive command
      │
      ▼
Identify command prefix
      │
      ▼
Determine destination
      │
      ├───────────────┐
      │               │
      ▼               ▼
Truck command     Hub command
      │               │
      ▼               ▼
Execute locally   Forward through
                  HC-05 Master
                      │
                      ▼
                  Hub Controller
```

Truck commands are processed directly by the Truck Arduino.

Hub commands are transmitted through the Truck Master Bluetooth module to the Hub Slave Bluetooth module.

---

# 8. Message Structure

Commands are transmitted as encoded text strings.

A command contains a prefix that identifies its destination and an instruction that identifies the required operation.

---

## 8.1 Truck Commands

| Command   | Function              |
| --------- | --------------------- |
| `T:START` | Turn truck system ON  |
| `T:STOP`  | Turn truck system OFF |
| `T:FWD`   | Move forward          |
| `T:BWD`   | Move backward         |
| `T:LEFT`  | Turn left             |
| `T:RIGHT` | Turn right            |
| `T:LIFT`  | Raise carrier         |
| `T:LOWER` | Lower carrier         |
| `T:DIS`   | Discharge cassava     |

The `T:` prefix identifies the command as a Truck Controller command.

---

## 8.2 Hub Commands

| Command      | Function             |
| ------------ | -------------------- |
| `H:CLSTART`  | Start slant conveyor |
| `H:CLSTOP`   | Stop slant conveyor  |
| `H:CUSSTART` | Start flat conveyor  |
| `H:CUSSTOP`  | Stop flat conveyor   |
| `H:SSTART`   | Start siever         |
| `H:SSTOP`    | Stop siever          |

The `H:` prefix identifies the command as a Hub Controller command.

---

# 9. Message Delimiting

A newline character (`\n`) is appended to transmitted commands.

For example:

```text
T:FWD\n
```

The receiving Arduino reads commands until the newline delimiter is encountered.

The implementation uses:

```cpp
readStringUntil('\n');
```

This provides a clear boundary between individual commands and prevents multiple rapidly transmitted commands from being interpreted as one continuous message.

---

# 10. Truck Controller Communication Processing

The Truck Arduino performs two communication functions simultaneously:

1. Communication with the Android application.
2. Communication with the stationary Hub Controller.

The Android-facing Bluetooth module uses the Truck Arduino's hardware serial interface, while the second HC-05 is connected through SoftwareSerial.

The Truck Controller therefore acts as the central communication processor.

Conceptually:

```text
                  Truck Arduino
                  ┌───────────────┐
                  │               │
Android ─────────►│ Receive       │
                  │               │
                  │ Command       │
                  │ Routing        │
                  │               │
                  └───────┬───────┘
                          │
                   Hub command?
                          │
                          ▼
                    HC-05 Master
                          │
                       Bluetooth
                          │
                          ▼
                     Hub Slave
```

---

# 11. Hub Controller Communication

The Hub Controller receives commands from the Truck Controller through the Hub's HC-05 Slave module.

The Hub Arduino interprets the received command and activates the appropriate subsystem.

For example:

```text
H:CLSTART
      │
      ▼
Hub HC-05 Slave
      │
      ▼
Hub Arduino
      │
      ▼
Slant Conveyor Relay
      │
      ▼
Slant Conveyor Motor
```

Similarly:

```text
H:SSTART
      │
      ▼
Hub Arduino
      │
      ▼
Siever Relay
      │
      ▼
Siever Motor
```

---

# 12. Communication and Hardware Integration

The communication architecture was designed around the hardware limitations of the Arduino Uno and the L293D motor driver shield used on the truck.

The original communication concept proposed using **nRF24L01 radio modules**.

During development, the available Arduino pins became a significant constraint because several pins were already occupied by the motor driver and other truck-control functions.

Bluetooth was therefore selected as an alternative communication technology because the HC-05 modules could be integrated into the existing controller architecture without requiring a major redesign of the motor-control system.

This was an example of adapting the system architecture to practical hardware constraints.

---

# 13. Bluetooth Configuration

The HC-05 modules were configured according to their respective communication roles.

### Truck Slave 1

Configured to communicate with the Android controller.

### Truck Master

Configured as a Bluetooth master and bound to the Hub Slave.

### Hub Slave 2

Configured as a Bluetooth slave and paired with the Truck Master.

The detailed HC-05 wiring, AT-mode configuration, address binding, baud-rate configuration, and setup procedure are documented separately in the **Bluetooth Setup Guide**.

---

# 14. Communication Reliability

The communication system was tested during development to verify:

- Android-to-truck communication.
- Truck movement commands.
- Truck-to-hub command forwarding.
- Bluetooth pairing.
- Master/slave communication.
- Command delimiting.
- Rapid command transmission.
- Simultaneous operation of different subsystems.

During development, several communication-related issues were identified and resolved.

These included:

- Bluetooth command concatenation.
- Application communication freezing.
- Direction-control communication issues.
- Communication reliability during rapid command transmission.

The use of newline-delimited commands and improved application logic increased communication reliability.

---

# 15. Communication Testing

The following communication tests were performed:

| Test                     | Description                                       | Result |
| ------------------------ | ------------------------------------------------- | ------ |
| Android → Truck          | Send truck movement commands                      | Pass   |
| Android → Truck          | Send lift/lower commands                          | Pass   |
| Truck → Hub              | Forward conveyor commands                         | Pass   |
| Truck → Hub              | Forward siever commands                           | Pass   |
| Bluetooth pairing        | Establish master/slave connection                 | Pass   |
| Command delimiting       | Separate consecutive commands                     | Pass   |
| Integrated communication | Control truck and hub through Android application | Pass   |

The communication system successfully enabled wireless control of the mobile and stationary subsystems during development and competition demonstrations.

---

# 16. Engineering Decisions

## 16.1 Gateway Architecture

The Truck Controller was selected as the communication gateway rather than connecting the Android application independently to both controllers.

This provided several advantages:

- One Android control interface.
- One operator connection.
- Simpler command management.
- Reduced operator workload.
- Centralized command routing.
- No direct communication cable between the truck and Android device beyond Bluetooth.

---

## 16.2 Bluetooth Selection

Bluetooth was selected because it provided a practical wireless communication solution that could be integrated with the available Arduino Uno hardware.

The HC-05 modules were also relatively inexpensive and readily available, making them suitable for the prototype.

---

## 16.3 Text-Based Commands

Text-based commands were selected because they were:

- Simple to implement.
- Easy to debug.
- Easy to display during testing.
- Human-readable.
- Suitable for the relatively small number of commands required by the prototype.

The use of prefixes such as `T:` and `H:` also made command routing straightforward.

---

# 17. Lessons Learned

The communication system demonstrated the importance of considering hardware constraints when designing a mechatronic system.

The original communication approach was modified when the available Arduino pins became constrained by the motor-control hardware.

The use of three HC-05 modules provided a practical solution while maintaining the desired operator experience.

The gateway architecture also demonstrated how one embedded controller can coordinate communication between a user interface and another distributed embedded controller.

An important lesson from development was that communication protocols must account for message boundaries. The introduction of newline-delimited commands helped prevent multiple commands from merging during rapid transmission.

The project also demonstrated that communication reliability should be tested under conditions that resemble actual operation rather than only under isolated laboratory conditions.

---

# 18. Final Communication Architecture

The final communication system consists of three Bluetooth modules:

```text
                       ANDROID
                     CONTROLLER
                         │
                         │
                     Bluetooth
                         │
                         ▼
                ┌─────────────────┐
                │ HC-05 Slave 1   │
                │ Truck Receiver  │
                └────────┬────────┘
                         │
                         │ Serial
                         ▼
                ┌─────────────────┐
                │ TRUCK ARDUINO   │
                │   CONTROLLER    │
                └────────┬────────┘
                         │
                    SoftwareSerial
                         │
                         ▼
                ┌─────────────────┐
                │ HC-05 Master    │
                │ Truck Transmit  │
                └────────┬────────┘
                         │
                     Bluetooth
                         │
                         ▼
                ┌─────────────────┐
                │ HC-05 Slave 2   │
                │  Hub Receiver   │
                └────────┬────────┘
                         │
                    SoftwareSerial
                         │
                         ▼
                ┌─────────────────┐
                │  HUB ARDUINO    │
                │   CONTROLLER    │
                └────────┬────────┘
                         │
              ┌──────────┼──────────┐
              ▼          ▼          ▼
           SLANT       FLAT       SIEVER
         CONVEYOR    CONVEYOR
```

The final architecture allows a single operator to control the complete Agro-Smart Hub from the Android application while maintaining separate wireless communication links between the Android controller, mobile truck, and stationary processing hub.
