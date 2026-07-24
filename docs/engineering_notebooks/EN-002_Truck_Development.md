# Engineering Notebook 002

# Truck Development

Project: Agro-Smart Hub

Notebook ID: EN-002

---

# Engineering Problem

The Agro-Smart Hub required a mobile platform capable of receiving cassava from the processing hub, transporting it to the frying area, and discharging it automatically. The truck also needed to serve as the communication gateway between the Android application and the hub.

---

# Design Requirements

The truck had to:

- Turn right, Turn left, Move forward, backward.
- Receive commands wirelessly from an Android application.
- Forward hub commands wirelessly.
- Carry cassava.
- Lift the carrier.
- Discharge cassava.
- Operate using rechargeable battery power.
- Be stable while carrying loads.

---

# Initial Design

The truck consisted of:

- Wooden chassis
- Four geared DC motors
- Four wheels
- Motor driver shield
- Arduino Uno
- Bluetooth modules
- Four Relay-controlled lifting mechanism
- Rack and Pinion discharge mechanism
- Linkage mechanism
- Cassava carrier

---

# Communication Architecture

The truck was designed to act as the communication gateway for the entire Agro-Smart Hub.

The communication flow was:

Android App

↓

Truck Bluetooth

↓

Arduino Uno (Truck)

↓

Decision Logic

↓

Execute Truck Command

or

Forward Command to Hub

This architecture reduced the complexity of the Android application because it only needed to communicate with a single device.

---

# Engineering Challenge 1

## Radio Communication Selection

### Original Plan

The initial design used nRF24L01 radio modules because they were less expensive and offered longer communication range than Bluetooth.

Three nRF24L01 modules were purchased for the project.

### Problem

After integrating the L293D motor driver shield with the Arduino Uno, the available input/output pins became very limited.

The nRF24L01 required SPI pins that conflicted with the motor shield connections.

### Engineering Decision

Bluetooth communication was selected instead because it could operate on the remaining available Arduino pins using SoftwareSerial.

### Result

The communication system became compatible with the existing hardware without redesigning the truck electronics.

---

# Engineering Challenge 2

## Motors Did Not Move

### Observation

The truck successfully received Bluetooth commands.

The indicator LED responded correctly.

However, none of the drive motors rotated.

### Investigation

Serial Monitor confirmed that all commands were arriving correctly.

This suggested that the software was functioning properly.

Attention shifted toward the motor driver hardware.

### Solution

The integrated circuit chips on the motor shield were removed, their pins cleaned, and reinserted.

### Result

The motors immediately began responding correctly.

---

# Engineering Challenge 3

## Continuous Forward Motion

### Observation

After receiving a single forward command, the truck continued moving without stopping.

### Investigation

The Android application transmitted the command only once when the button was pressed.

The Arduino therefore continued executing the previous command.

### Solution

The Android application was modified so that movement commands were transmitted continuously while the button remained pressed.

### Result

Truck movement became responsive and intuitive.

---

# Engineering Challenge 4

## Direction Buttons Did Not Work

### Observation

Forward movement operated correctly.

Left, right, and backward controls produced no response.

### Investigation

Serial Monitor showed that no commands were being received for those buttons.

The Arduino code itself was correct.

Research revealed that using images as control buttons in MIT App Inventor prevented those events from firing correctly.

### Solution

Image controls were replaced with standard Button components.

The images were then assigned as the button backgrounds.

### Result

All movement commands were transmitted successfully.

---

# Engineering Challenge 5

## Delayed Command Execution

### Observation

The truck sometimes responded several seconds after commands were sent.

### Investigation

Serial Monitor revealed that multiple Bluetooth messages were being combined into one long string.

### Solution

Each Android command was modified to include a newline character (`\n`).

The Arduino program used `readStringUntil('\n')` to process one command at a time.

### Result

Communication became significantly faster and more reliable.

---

# Engineering Challenge 6

## Reduced Turning Performance

### Observation

After installing the lifting mechanism, the truck struggled to turn.

### Investigation

The added mechanical load increased resistance during turning.

### Solution

Turning speed was increased from 200 to 250 while keeping forward and reverse speeds unchanged.

### Result

The truck regained reliable turning performance without mechanical redesign.

---

# Final Outcome

The completed truck successfully:

- Received Bluetooth commands.
- Executed movement commands.
- Controlled the lifting mechanism.
- Controlled the discharge mechanism.
- Routed commands to the hub.
- Operated as the communication gateway for the Agro-Smart Hub.

---

# Lessons Learned

The truck became the most complex subsystem in the project because it integrated mechanical, electrical, embedded, and wireless communication systems.

Many of the challenges were solved through systematic debugging using the Serial Monitor and by isolating hardware and software faults.

The development process reinforced the importance of subsystem integration, iterative testing, and engineering trade-off analysis.

---

# Media to Add Later

- [ ] Truck chassis
- [ ] Arduino Uno with motor shield
- [ ] Bluetooth modules
- [ ] Wiring layout
- [ ] Android controlling truck
- [ ] Truck carrying cassava
- [ ] Truck lifting mechanism
- [ ] Truck discharge mechanism
- [ ] Serial Monitor debugging screenshots
- [ ] Videos of truck movement tests
