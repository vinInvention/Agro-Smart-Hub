# Bill of Materials (BOM)

**Project:** Agro-Smart Hub
**Project Type:** Student-Built Mechatronic Prototype

---

# 1. Overview

This document lists the major materials, electrical components, mechanical components, tools, and software used during the development of the Agro-Smart Hub prototype.

The Bill of Materials serves as a reference for:

- Procurement
- Construction
- Assembly
- Maintenance
- Future redesign
- Cost estimation
- Component replacement

The project was developed using locally available materials wherever practical, with emphasis on affordability and accessibility.

---

# 2. Mechanical Components

| Item  | Description                       |     Qty | Application / Notes              |
| ----- | --------------------------------- | ------: | -------------------------------- |
| M-001 | Plywood sheets                    |       1 | Structural frames and supports   |
| M-002 | Ceiling board                     |       1 | Conveyor and siever construction |
| M-003 | PVC pipe                          |       1 | Conveyor rollers                 |
| M-004 | Wooden shafts / ceiling batten    |       4 | Conveyor roller shafts           |
| M-005 | Bearings                          |       6 | Conveyor shaft rotation          |
| M-006 | Conveyor belt material            |       — | Flat and slanting conveyors      |
| M-007 | Spur gears                        |       2 | Truck carrier lift mechanism     |
| M-008 | Pinion gears                      |       2 | Truck carrier lift mechanism     |
| M-009 | Rack gears                        |       2 | Truck carrier lift mechanism     |
| M-010 | Linkage components                |       2 | Carrier lifting mechanism        |
| M-011 | Wheels                            |       4 | Truck mobility                   |
| M-012 | Fasteners: nuts, bolts and screws |       — | Mechanical assembly              |
| M-013 | L-shaped brackets                 |      40 | Mechanical assembly and support  |
| M-014 | Nails, various sizes              | ~0.5 lb | Mechanical construction          |

---

# 3. Electrical and Electronic Components

| Item  | Description                     |     Qty | Application / Notes                |
| ----- | ------------------------------- | ------: | ---------------------------------- |
| E-001 | Arduino Uno                     |       1 | Truck controller                   |
| E-002 | Arduino Uno                     |       1 | Hub controller                     |
| E-003 | HC-05 Bluetooth module          |       1 | Android-to-truck communication     |
| E-004 | HC-05 Bluetooth module          |       1 | Truck-to-hub communication, Master |
| E-005 | HC-05 Bluetooth module          |       1 | Hub communication, Slave           |
| E-006 | DC gear motors                  |       9 | Conveyors, siever, and truck drive |
| E-007 | L293D motor driver / shield     |       1 | Truck motor control                |
| E-008 | Relay modules                   |       7 | Switching conveyors and actuators  |
| E-009 | Buck converters, 2 A            |       3 | Voltage regulation                 |
| E-010 | Solar panel                     |       1 | Renewable energy generation        |
| E-011 | 18650 Li-ion cells              |      26 | Battery development / battery pack |
| E-012 | Battery Management System (BMS) |       1 | Battery protection and management  |
| E-013 | Power switches                  |       2 | System control                     |
| E-014 | Indicator LEDs                  |       3 | Status indication                  |
| E-015 | Male-to-male jumper wires       |   1 set | Electrical connections             |
| E-016 | Female-to-female jumper wires   |   1 set | Electrical connections             |
| E-017 | Male-to-female jumper wires     |  2 sets | Electrical connections             |
| E-018 | Twisted-pair CAT wire           |    2 yd | Electrical connections             |
| E-019 | Flexible electrical wire        |   16 yd | Power and signal connections       |
| E-020 | Terminal blocks                 |       3 | Power distribution                 |
| E-021 | Electrical connectors           | 6 pairs | Power distribution                 |
| E-022 | USB socket                      |       1 | Power distribution                 |
| E-023 | Nickel strip                    |    1 yd | Battery construction               |
| E-024 | Buck converters, 5 A            |       1 | Voltage regulation                 |
| E-025 | Buck converters, 10 A           |       2 | Voltage regulation                 |

### Battery Configuration Note

The electrical design calculation documented a target **4S5P configuration**, consisting of 20 cells of approximately 3.7 V, 1.5 Ah each.

The BOM records **26 18650 cells acquired/used during development**. The additional cells may have served as spare or development cells.

The final as-built battery configuration should be confirmed from the physical battery pack and photographs.

---

# 4. Software and Development Tools

| Software / Platform | Purpose                                              |
| ------------------- | ---------------------------------------------------- |
| Arduino IDE         | Embedded firmware development                        |
| MIT App Inventor    | Android controller development                       |
| Git                 | Version control                                      |
| GitHub              | Source-code and engineering documentation repository |

---

# 5. Hand Tools

The following tools were used during fabrication, electrical assembly, debugging, and testing:

- Screwdrivers
- Soldering iron
- Spot-welding machine
- Solder wire
- Wire stripper
- Long-nose pliers
- Pliers
- Side cutter
- Multimeter
- Hot glue gun
- Drill
- Dremel drill
- Measuring tape
- Steel ruler
- Hammer
- Saw

---

# 6. Consumables

- Electrical tape
- Heat-shrink tubing
- Cable ties
- Wood glue
- Hot glue sticks
- Sandpaper
- Solder wire
- Nickel strip

---

# 7. Procurement Notes

Materials and components were sourced primarily through local electronics and hardware markets.

Before purchasing components, prices from multiple vendors were compared to reduce project expenditure while maintaining acceptable component quality.

This market-survey approach was particularly important because the project was developed within a limited student-project budget.

Mechanical construction materials such as plywood, ceiling board, PVC pipe, wooden shafts, brackets, and fasteners were selected based on local availability, cost, ease of fabrication, and suitability for rapid prototyping.

---

# 8. Component Selection Notes

Major component selections were based on the functional requirements of the project.

Examples include:

- Lithium-ion cells for rechargeable energy storage.
- Solar panel for renewable energy generation.
- Buck converters for voltage regulation.
- Arduino Uno boards for embedded control.
- HC-05 Bluetooth modules for wireless communication.
- DC gear motors for mechanical actuation.
- Relay modules for switching higher-current loads.
- L293D motor driver for truck motor control.

Detailed electrical design calculations are documented in:

`Power_System_Design.md`

---

# 9. Future BOM Improvements

Future revisions of this BOM should include:

- Manufacturer
- Part number
- Supplier
- Unit cost
- Total cost
- Purchase date
- Replacement part
- Component specification
- Actual quantity installed
- Spare quantity
- Final as-built configuration
