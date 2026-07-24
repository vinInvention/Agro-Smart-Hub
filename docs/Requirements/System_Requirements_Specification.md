# System Requirements Specification (SRS)

## Project

Agro-Smart Hub

Version 1.0

---

# 1. Introduction

## 1.1 Purpose

This document defines the functional and non-functional requirements of the Agro-Smart Hub. These requirements guided the design, construction, testing, and validation of the system.

---

# 2. Project Goal

To design and construct a renewable energy powered mechatronic system capable of automating selected stages of cassava processing through coordinated mechanical, electrical, and embedded subsystems.

---

# 3. Functional Requirements

## Renewable Power System

| ID     | Requirement                                                 |
| ------ | ----------------------------------------------------------- |
| FR-001 | The system shall operate using rechargeable batteries.      |
| FR-002 | The battery pack shall be rechargeable using a solar panel. |
| FR-003 | The power system shall distribute power to all subsystems.  |

---

## Slant Conveyor

| ID     | Requirement                      |
| ------ | -------------------------------- |
| FR-004 | Lift cassava into the siever.    |
| FR-005 | Operate using a geared DC motor. |

---

## Siever

| ID     | Requirement                                            |
| ------ | ------------------------------------------------------ |
| FR-006 | Separate fine cassava particles from coarse particles. |
| FR-007 | Operate continuously during processing.                |

---

## Flat Conveyor

| ID     | Requirement                     |
| ------ | ------------------------------- |
| FR-008 | Receive sieved cassava.         |
| FR-009 | Deliver cassava into the truck. |

---

## Truck

| ID     | Requirement        |
| ------ | ------------------ |
| FR-010 | Move forward.      |
| FR-011 | Move backward.     |
| FR-012 | Turn left.         |
| FR-013 | Turn right.        |
| FR-014 | Receive cassava.   |
| FR-015 | Transport cassava. |
| FR-016 | Lift the carrier.  |
| FR-017 | Discharge cassava. |

---

## Communication

| ID     | Requirement                                    |
| ------ | ---------------------------------------------- |
| FR-018 | Receive commands from the Android application. |
| FR-019 | Forward hub commands wirelessly.               |
| FR-020 | Execute truck commands locally.                |

---

## Android Application

| ID     | Requirement                                  |
| ------ | -------------------------------------------- |
| FR-021 | Provide a graphical control interface.       |
| FR-022 | Allow wireless control of the entire system. |

---

# 4. Non-Functional Requirements

| ID      | Requirement                                          |
| ------- | ---------------------------------------------------- |
| NFR-001 | System shall use renewable energy.                   |
| NFR-002 | System shall be modular.                             |
| NFR-003 | Components shall be individually testable.           |
| NFR-004 | System shall be safe for demonstration.              |
| NFR-005 | Components shall be easily replaceable.              |
| NFR-006 | Materials shall be locally available where possible. |
| NFR-007 | The system shall be portable.                        |

---

# 5. Engineering Constraints

- Competition deadline.
- Budget limitations.
- Arduino Uno pin availability.
- Student skill level.
- Component availability in local markets.
- Transportation of the prototype.
- Limited workshop tools.

---

# 6. Acceptance Criteria

The project is considered successful if it can:

- Power itself from the renewable power station.
- Lift cassava using the slant conveyor.
- Sieve cassava successfully.
- Transport sieved cassava using the flat conveyor.
- Move the truck under Android control.
- Lift and discharge cassava from the truck.
- Communicate wirelessly between truck and hub.
- Operate as one integrated mechatronic system.

---

# 7. Verification Method

| Requirement Type | Verification Method             |
| ---------------- | ------------------------------- |
| Mechanical       | Functional testing              |
| Electrical       | Voltage and continuity testing  |
| Embedded         | Software validation             |
| Wireless         | Bluetooth communication testing |
| System           | Integrated demonstration        |
