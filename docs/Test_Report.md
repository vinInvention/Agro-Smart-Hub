# Test Report

Project: Agro-Smart Hub

---

# Purpose

This document records the testing activities carried out during the development of the Agro-Smart Hub. Testing was performed at both the subsystem level and the integrated system level to verify that the prototype operated as intended.

---

# Testing Strategy

Testing was conducted in three phases:

1. Unit Testing
2. Integration Testing
3. System Demonstration Testing

Each subsystem was first tested independently before being connected to the complete system.

---

# Unit Testing

## Test 1 – Renewable Power Station

### Objective

Verify that the power station supplied stable electrical power to the system.

### Procedure

- Charge the battery pack.
- Connect the distribution tower.
- Measure output voltages from the buck converters.
- Power the Arduino controllers and motors.

### Expected Result

- Stable output voltage.
- Arduino boards power successfully.
- Motors receive adequate power.

### Result

**Pass**

### Remarks

The renewable power station successfully powered all project subsystems during development.

---

## Test 2 – Slant Conveyor

### Objective

Verify that the slant conveyor transported cassava to the siever.

### Procedure

- Power the conveyor.
- Load cassava.
- Observe material movement.

### Expected Result

Cassava should move smoothly toward the siever.

### Result

**Pass**

---

## Test 3 – Siever

### Objective

Verify that the siever separated fine cassava particles from coarse particles.

### Procedure

- Operate the siever with cassava.
- Observe the sieving action.

### Expected Result

Fine particles should fall onto the flat conveyor while coarse particles remain separated.

### Result

**Pass**

---

## Test 4 – Flat Conveyor

### Objective

Verify that the flat conveyor transported sieved cassava into the truck.

### Procedure

- Run the conveyor.
- Observe material movement.

### Expected Result

Cassava should be discharged into the truck without excessive spillage.

### Result

**Pass**

---

## Test 5 – Truck

### Objective

Verify truck mobility and lifting operations.

### Procedure

Test:

- Forward
- Reverse
- Left turn
- Right turn
- Lift mechanism
- Discharge mechanism

### Expected Result

Each command should execute correctly.

### Result

**Pass**

### Remarks

Several software and mechanical issues were identified during development and resolved before the final demonstration.

---

## Test 6 – Android Controller

### Objective

Verify wireless control of the Agro-Smart Hub.

### Procedure

Send operational commands from the Android application.

### Expected Result

Commands should be transmitted and executed correctly.

### Result

**Pass**

### Remarks

Early versions experienced communication issues that were resolved through software debugging and improvements to the communication protocol.

---

# Integration Testing

## Objective

Verify that all subsystems functioned correctly when connected together.

### Procedure

1. Start the renewable power station.
2. Connect the Android application.
3. Operate the conveyors.
4. Operate the truck.
5. Test command forwarding.
6. Test material movement through the complete system.

### Expected Result

All subsystems should operate together as a single integrated system.

### Result

**Pass**

---

# Demonstration Testing

## Internal Demonstration

The prototype successfully completed internal testing before presentation to the competition review team.

Result:

**Pass**

---

## Pre-Competition Demonstration

The complete system was demonstrated before the competition and was approved for participation after resolving last-minute relay wiring issues.

Result:

**Pass**

---

## Competition Demonstration

During the competition:

- The integrated system operated successfully during the initial stages.
- The project completed the first judging session.
- During later stages, the renewable power station experienced an unexpected battery pack failure.

Result:

**Partially Successful**

### Observations

The battery failure prevented completion of the remaining demonstration sequence despite successful operation of the mechanical, embedded, and communication subsystems.

---

# Summary of Issues Encountered

| Issue                            | Resolution                                                        |
| -------------------------------- | ----------------------------------------------------------------- |
| Motor driver malfunction         | Cleaned and reseated motor driver ICs                             |
| Continuous truck movement        | Modified Android application logic                                |
| Direction buttons not responding | Replaced image controls with button components                    |
| Bluetooth command concatenation  | Introduced newline-delimited commands                             |
| Truck turning difficulty         | Increased turning motor speed                                     |
| Linkage unable to lift load      | Redesigned linkage geometry                                       |
| Relay wiring fault               | Replaced faulty wiring                                            |
| Bluetooth application freezing   | Temporary restart procedure during demonstrations                 |
| Battery pack failure             | Identified as a major reliability improvement for future versions |

---

# Lessons Learned

Testing throughout development proved essential to identifying both software and mechanical faults before full system integration. The project also demonstrated the importance of endurance testing and validating the renewable power system under conditions that closely match real-world operation.

---

# Future Testing

Future versions of the Agro-Smart Hub should include:

- Extended endurance testing.
- Battery capacity validation.
- Communication stress testing.
- Mechanical load testing.
- Solar charging performance evaluation.
- Reliability testing under continuous operation.
