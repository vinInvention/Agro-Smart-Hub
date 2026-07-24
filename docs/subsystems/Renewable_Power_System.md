# Renewable Power System

## Overview

The Renewable Power System supplies electrical energy to the Agro-Smart Hub. It was designed to allow the prototype to operate independently of mains electricity by generating, storing, regulating, and distributing power to the various subsystems.

The system consists of a solar charging unit, a rechargeable lithium-ion battery pack, voltage regulation circuits, and a power distribution network.

---

# Objectives

The Renewable Power System was designed to:

- Generate electrical energy using solar power.
- Store energy in rechargeable batteries.
- Supply stable voltages to electronic components.
- Power the complete Agro-Smart Hub during demonstrations.
- Promote sustainable engineering practices.

---

# Major Components

| Component                       | Function                                                  |
| ------------------------------- | --------------------------------------------------------- |
| Solar Panel                     | Generates electrical energy from sunlight                 |
| Lithium-ion Battery Pack        | Stores electrical energy                                  |
| Battery Management System (BMS) | Protects the battery pack during charging and discharging |
| Buck Converters                 | Regulate voltage for individual subsystems                |
| Distribution Towers             | Distribute electrical power throughout the system         |
| Wiring and Connectors           | Deliver electrical energy to loads                        |

---

# System Architecture

```
           Solar Panel
                │
                ▼
      Battery Charging Circuit
                │
                ▼
      Lithium-ion Battery Pack
                │
                ▼
      Battery Management System
                │
                ▼
        Power Distribution
        ┌──────┬──────┬──────┐
        ▼      ▼      ▼
    Truck   Hub Arduino  Motors
```

---

# Power Distribution Strategy

Rather than connecting every subsystem directly to the battery pack, electrical energy was first routed to a central distribution system.

Buck converters were installed at the distribution points to provide the voltage required by individual loads.

This approach reduced wiring complexity and simplified future maintenance.

---

# Engineering Considerations

Several factors influenced the design of the power system.

### Renewable Energy

Solar energy was selected to reduce dependence on mains electricity and to demonstrate sustainable engineering principles.

### Modularity

The power system was designed so that individual subsystems could be disconnected or serviced without rebuilding the complete electrical network.

### Voltage Regulation

Different electrical components required different operating voltages. Voltage regulators ensured that each subsystem received an appropriate supply voltage.

### Expandability

The distribution architecture allows additional electrical loads to be incorporated into future versions of the project.

---

# Testing

The following tests were performed during development.

- Battery pack charging.
- Voltage verification.
- Power distribution verification.
- Individual subsystem power tests.
- Integrated system power tests.

The power system successfully supplied electrical energy to all project subsystems during development and testing.

---

# Challenge Encountered

During the competition, the primary battery pack unexpectedly failed during the demonstration.

Although the failure prevented completion of the final demonstration sequence, it highlighted the importance of system reliability, battery health monitoring, and contingency planning in engineering projects.

---

# Lessons Learned

The Renewable Power System demonstrated that successful mechatronic projects depend on careful electrical power planning as much as mechanical and software design.

Future versions of the project could improve reliability by incorporating:

- battery state-of-charge monitoring,
- battery health monitoring,
- redundant battery packs,
- protected charging circuitry,
- quick-swap battery modules.
