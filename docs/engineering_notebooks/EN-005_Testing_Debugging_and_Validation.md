# Engineering Notebook 005

# Testing, Debugging and Validation

Project: Agro-Smart Hub

Notebook ID: EN-005

---

# Purpose

Engineering prototypes rarely function perfectly on the first attempt. Throughout the development of the Agro-Smart Hub, systematic testing and debugging were carried out to identify faults, determine their causes, implement solutions, and verify the effectiveness of those solutions.

This notebook documents the testing and debugging process used during the project.

---

# Testing Strategy

Testing was performed in three stages:

1. Individual subsystem testing.
2. Integrated subsystem testing.
3. Full system validation.

Only after a subsystem passed its individual tests was it integrated into the complete system.

---

# Test 1

## Truck Bluetooth Communication

### Objective

Verify that the Android application could communicate with the truck.

### Procedure

Commands were transmitted from the Android application to the truck through the Bluetooth module.

The Serial Monitor was used to observe the received data.

### Result

The truck successfully received all transmitted commands.

**Status:** PASS

---

# Test 2

## Truck Motor Control

### Objective

Verify that Bluetooth commands produced the expected truck movement.

### Observation

Bluetooth commands were received correctly, but the truck motors did not rotate.

### Root Cause

Poor electrical contact between the motor driver integrated circuit and its socket prevented proper motor operation.

### Corrective Action

The integrated circuit was removed, its pins cleaned, and reinstalled.

### Result

The truck motors responded correctly.

**Status:** PASS

---

# Test 3

## Continuous Truck Motion

### Objective

Verify that truck movement stopped when the control button was released.

### Observation

The truck continued moving after receiving a single movement command.

### Root Cause

Movement commands were transmitted only once from the Android application.

### Corrective Action

The Android application was modified to transmit movement commands continuously while the button remained pressed.

### Result

Truck movement became responsive.

**Status:** PASS

---

# Test 4

## Android Direction Controls

### Objective

Verify all movement buttons.

### Observation

Only some movement commands reached the Arduino.

### Root Cause

Image components used as control buttons did not generate the required events.

### Corrective Action

Standard Button components were used instead.

### Result

All movement commands were transmitted correctly.

**Status:** PASS

---

# Test 5

## Bluetooth Message Integrity

### Objective

Verify reliable wireless communication.

### Observation

Multiple commands were occasionally merged into one message.

### Root Cause

The receiving Arduino could not determine where one command ended and another began.

### Corrective Action

Each transmitted command was terminated with a newline character (`\n`), and the Arduino used `readStringUntil('\n')` to process one command at a time.

### Result

Commands were processed correctly and communication became more reliable.

**Status:** PASS

---

# Test 6

## Truck Turning Performance

### Objective

Verify truck turning after installation of the lifting mechanism.

### Observation

The truck struggled to turn while carrying the additional lifting mechanism.

### Root Cause

The increased mechanical load reduced turning performance.

### Corrective Action

The turning speed was increased while keeping the forward speed unchanged.

### Result

Turning performance improved significantly.

**Status:** PASS

---

# Test 7

## Hub Relay Control

### Objective

Verify that the hub executed commands received from the truck.

### Observation

The Hub Arduino received Bluetooth commands, but the relay outputs did not operate.

### Root Cause

Faulty wiring between the Arduino outputs and the relay module.

### Corrective Action

The faulty wires were replaced.

### Result

The relays responded correctly.

**Status:** PASS

---

# Test 8

## Complete System Demonstration

### Objective

Verify coordinated operation of all project subsystems.

### Procedure

The complete Agro-Smart Hub was assembled and operated using the Android application.

### Result

The system successfully demonstrated:

- Renewable power supply.
- Cassava lifting.
- Cassava sieving.
- Material transfer.
- Truck transportation.
- Automatic unloading.

The project met its primary functional objectives.

**Status:** PASS

---

# Known Unresolved Issue

During repeated operation, the Android application occasionally became unresponsive after transmitting multiple commands.

The temporary solution was to restart the Bluetooth connection and power-cycle the system.

Due to time constraints before the competition, the root cause was not fully investigated.

This issue remains an area for future improvement.

---

# Competition Failure Analysis

During the competition, the renewable power station unexpectedly failed near the end of the demonstration.

Although the prototype had operated successfully during previous testing, the battery pack could no longer supply sufficient power for continued operation.

The exact failure mechanism could not be determined during the competition.

Future versions should include:

- Battery health monitoring.
- Voltage monitoring.
- Current monitoring.
- Redundant battery packs.
- Improved pre-competition stress testing.

---

# Engineering Lessons

The development process demonstrated that systematic testing is essential in engineering.

Many problems initially appeared to be software faults but were ultimately traced to mechanical or electrical causes.

Using structured testing, the Serial Monitor, and subsystem isolation significantly reduced troubleshooting time and improved confidence in the final prototype.

---

# Media to Add Later

- [ ] Serial Monitor screenshots
- [ ] Truck movement tests
- [ ] Hub relay testing
- [ ] Complete system testing
- [ ] Competition testing
- [ ] Videos of debugging sessions
