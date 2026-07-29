# EN-002 – Battery Pack Engineering Notebook

**Project:** Agro-Smart Hub
**Subsystem:** Renewable Power Station
**Engineering Area:** Electrical / Power Electronics
**Status:** Completed Prototype

---

# 1. Introduction

The battery pack was one of the foundational subsystems of the Agro-Smart Hub.

The objective was to create a rechargeable energy-storage system capable of storing solar-generated electricity and supplying the electrical energy required by the mechanical and embedded systems of the project.

Because the Agro-Smart Hub was intended to demonstrate renewable-energy-powered industrial automation, the battery pack was designed as part of a larger renewable power station consisting of:

- Solar panel
- Battery pack
- Battery Management System
- Charge-control stage
- Power distribution system
- Buck converters

The battery pack was also one of the first subsystems developed. After constructing the power system, it was used to provide power while the remaining mechanical and electrical units were being developed and tested.

---

# 2. Battery Pack Objectives

The battery pack was designed to:

1. Store energy generated from the solar panel.
2. Supply electrical power to the project during operation.
3. Provide sufficient energy for approximately one hour of demonstration operation.
4. Supply a voltage suitable for the project's DC power architecture.
5. Support multiple lower-voltage loads through buck converters.
6. Provide protection through a Battery Management System.
7. Integrate with the renewable power station.
8. Provide a practical and affordable solution that could be constructed within the project's budget.

---

# 3. Design Process

The battery pack was not selected arbitrarily.

The design process followed the approximate sequence:

```text
Identify Electrical Loads
        ↓
Estimate Power Consumption
        ↓
Calculate Energy Requirement
        ↓
Account for Losses and Design Margin
        ↓
Determine Battery Energy Requirement
        ↓
Select Battery Voltage
        ↓
Determine Series Configuration
        ↓
Determine Parallel Configuration
        ↓
Select BMS
        ↓
Construct Battery Pack
        ↓
Test Battery Pack
        ↓
Integrate with Power Station
```

The detailed calculations are documented in:

`docs/Power_System_Design.md`

---

# 4. Initial Design Considerations

The project contained loads operating at different voltages.

The major loads included:

- 5 V electronics
- 6 V motors
- Other electrical components requiring regulated DC power

Rather than creating separate battery packs for each voltage level, a higher-voltage battery pack was selected and voltage regulation was introduced between the battery and the individual loads.

This led to the decision to use a lithium-ion battery configuration with buck converters.

---

# 5. Electrical Design

The estimated base electrical load was approximately:

**53 W**

For one hour:

**53 Wh**

Additional allowances were then incorporated into the battery sizing process.

The resulting calculated battery energy requirement was approximately:

**107.13 Wh**

A 4S5P lithium-ion configuration was subsequently selected.

The resulting nominal battery characteristics were approximately:

| Parameter                               |        Value |
| --------------------------------------- | -----------: |
| Configuration                           |         4S5P |
| Cells                                   | 18650 Li-ion |
| Nominal cell voltage                    |        3.7 V |
| Cell capacity                           |       1.5 Ah |
| Total cells in calculated configuration |           20 |
| Nominal pack voltage                    |       14.8 V |
| Maximum charge voltage                  |       16.8 V |
| Pack capacity                           |       7.5 Ah |
| Nominal energy                          |       111 Wh |

The detailed calculations and assumptions are documented in:

`docs/Power_System_Design.md`

---

# 6. Battery Construction

After determining the required configuration, the cells were arranged into series and parallel groups.

The intended arrangement was:

```text
5 Cells Parallel
       │
       ▼
  3.7 V / 7.5 Ah
       │
       ▼
5 Cells Parallel
       │
       ▼
  3.7 V / 7.5 Ah
       │
       ▼
5 Cells Parallel
       │
       ▼
  3.7 V / 7.5 Ah
       │
       ▼
5 Cells Parallel
       │
       ▼
  3.7 V / 7.5 Ah

Four parallel groups connected in series
= 4S5P
```

Nickel strip was used for the battery interconnections, and a Battery Management System was integrated into the battery system.

The BMS provided battery protection and management functions appropriate to the 4S lithium-ion configuration.

The completed battery pack was then fitted with appropriate output connections so that electrical energy could be distributed to the project.

---

# 7. Integration with the Renewable Power Station

The battery pack did not operate as an isolated component.

It formed part of the renewable power station together with:

- Solar panel
- Charge-control circuit
- Protection components
- Distribution towers
- Buck converters

The general energy flow was:

```text
Solar Panel
     ↓
Charging / Protection Circuit
     ↓
Battery Pack
     ↓
Distribution System
     ↓
Buck Converters
     ↓
Project Loads
```

Distribution towers were subsequently constructed to carry electrical energy from the battery/power station to the locations where electrical power was required.

---

# 8. Testing

The battery pack was used extensively during the construction and testing of the Agro-Smart Hub.

Because it was one of the first units completed, it became an important development tool for testing other subsystems.

It was used to supply power during:

- Motor testing
- Conveyor testing
- Siever testing
- Embedded-controller testing
- System integration
- Full-system demonstrations

The power system performed reliably throughout the majority of the development process.

---

# 9. Problems Encountered

The most significant battery-related problem occurred close to the competition.

During the period after the first demonstration, the battery used on the truck became unavailable, and the charger being used also failed. Another charger had been lost together with the engineering tools that were accidentally left in a tricycle.

This created a practical problem because the team needed functioning batteries for continued testing and debugging.

To keep the project moving, available batteries from previous projects were recovered and charged using a capacity tester that was available at home.

This allowed preparation for the competition to continue.

However, on the main competition day, the main battery pack powering the renewable power station unexpectedly failed during the second judging stage.

This was particularly significant because the battery had performed successfully throughout the development period and had been used to test the other subsystems.

The failure prevented the complete system from continuing the demonstration as planned.

---

# 10. Lessons Learned

The battery development process demonstrated that electrical design requires more than achieving the required voltage and capacity on paper.

The project taught several important lessons:

### 10.1 Design calculations are necessary but not sufficient

The battery was sized through calculations, but actual reliability also depends on:

- Cell condition
- Cell matching
- Connections
- Charging history
- Temperature
- Current demand
- Protection circuitry
- Mechanical construction

### 10.2 Capacity testing is important

Future battery packs should be tested under controlled loads to determine their actual usable capacity rather than relying entirely on nominal cell ratings.

### 10.3 Endurance testing should be performed

The battery should be subjected to repeated full-system operating cycles before competition.

### 10.4 Critical systems require redundancy

Because the battery was the central power source for the project, a backup battery or alternative power source would have significantly reduced the risk associated with a single battery failure.

### 10.5 Battery reliability should be treated as a system-level requirement

A battery can successfully power individual components during testing while still failing to provide reliable operation during a long, integrated demonstration.

---

# 11. Engineering Record

The battery pack represents an important stage in the development of the Agro-Smart Hub because it was one of the first complete subsystems constructed and subsequently became the energy foundation for the rest of the project.

The experience reinforced an important engineering principle:

> A system is only as reliable as its critical subsystems.

The competition failure therefore became an important engineering lesson rather than simply a competition result.

Detailed electrical sizing calculations are maintained separately in:

`docs/Power_System_Design.md`
