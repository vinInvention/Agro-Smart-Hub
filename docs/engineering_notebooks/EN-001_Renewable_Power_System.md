# Engineering Notebook 001

# Renewable Power System Design

Project: Agro-Smart Hub

Notebook ID: EN-001

---

# Engineering Problem

The Agro-Smart Hub required a reliable electrical power source capable of supplying energy to multiple mechanical and electronic subsystems without depending on mains electricity.

The system also needed to demonstrate sustainable engineering practices in line with modern industrial automation.

---

# Design Requirements

The power system had to:

- Operate without mains electricity.
- Be rechargeable.
- Supply stable power to multiple loads.
- Support Arduino controllers.
- Support DC gear motors.
- Support relay modules.
- Support Bluetooth communication.
- Be portable.
- Be safe for students to use.

---

# Initial Ideas

Several possible power sources were considered.

### Option 1

Disposable batteries

Advantages

- Simple

Disadvantages

- Expensive over time
- Environmentally unfriendly
- Low capacity

---

### Option 2

AC mains supply

Advantages

- Stable power

Disadvantages

- Requires wall outlet
- Not portable
- Unsuitable for outdoor demonstrations

---

### Option 3

Rechargeable battery with solar charging

Advantages

- Portable
- Renewable
- Rechargeable
- Demonstrates sustainability

Disadvantages

- More complex
- Higher initial cost

---

# Final Decision

A rechargeable lithium-ion battery pack charged using a solar panel was selected.

---

# Why This Decision Was Made

The project theme focused on industrialization.

Modern industrial systems increasingly incorporate renewable energy technologies.

A solar-powered battery system aligned with this objective while also allowing demonstrations in locations without reliable mains electricity.

---

# Engineering Calculations

The first step was to determine the electrical demand of the system.

The current requirements of each subsystem were estimated.

Examples included:

- Truck motors
- Conveyor motors
- Siever motor
- Arduino boards
- Bluetooth modules
- Relay modules

The combined demand was then used to estimate the required battery capacity.

> **Note:** Detailed power calculations are documented separately in `calculations/Power_Budget.md`.

See vdeo here --> ![Load Sizing](../../assets/engineering_notebooks/1. Load Sizing.png)

# Voltage Regulation

Different components required different operating voltages.

Buck converters were introduced to regulate the battery voltage before supplying individual subsystems.

This improved electrical safety and reduced the risk of over-voltage damage.
See vdeo here --> ![1. Solar power station diagram](../../assets/Power station/1. Solar power station diagram.png)

---

# Construction

The renewable power station consisted of:

- Solar panel
- Battery pack
- Battery Management System (BMS)
- Buck converters
- Distribution towers
- Output connectors

The distribution towers simplified wiring and made maintenance easier.

---

# Testing

The following tests were completed:

- Battery charging
- Battery discharge
- Buck converter adjustment
- Voltage measurement
- Power distribution
- System integration

All tests were completed successfully before system integration.

---

# Competition Performance

The renewable power system powered the Agro-Smart Hub throughout development and testing.

During the competition, however, the primary battery pack unexpectedly failed near the end of the demonstration.

Although this prevented completion of the presentation, the experience emphasized the importance of battery reliability and redundancy in engineering systems.

---

# Lessons Learned

This subsystem demonstrated that designing the power system should receive the same level of engineering attention as designing the mechanical and software systems.

Future improvements could include:

- Battery monitoring
- State-of-charge indication
- Redundant battery packs
- Modular battery replacement
- Fuse protection
- Current monitoring
