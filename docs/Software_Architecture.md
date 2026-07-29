# System Architecture

**Project:** Agro-Smart Hub

---

# 1. Overview

The Agro-Smart Hub is a modular mechatronic system designed to automate the sieving stage of cassava processing and transport the processed cassava toward the frying stage of Gari production.

The system integrates:

- Mechanical engineering
- Electrical engineering
- Power electronics
- Renewable energy
- Embedded systems
- Wireless communication
- Mobile application development
- Mobile robotics

The complete prototype consists of several independently developed subsystems that were eventually integrated into a single operating system.

---

# 2. System Architecture

At a high level, the Agro-Smart Hub consists of two major groups:

1. **Stationary processing hub**
2. **Mobile transport truck**

The stationary hub performs the material-processing operation while the truck receives, transports, and discharges the processed material.

---

# 3. High-Level Control Architecture

```text
                    ANDROID CONTROLLER
                           │
                           │ Bluetooth
                           ▼
                  ┌──────────────────┐
                  │  TRUCK CONTROLLER │
                  │    Arduino Uno    │
                  └────────┬─────────┘
                           │
                  ┌────────┴─────────┐
                  │                  │
            Truck Command       Hub Command
                  │                  │
                  ▼                  │
          Truck Motors              │
          Lift Mechanism             │
                                     │
                         Bluetooth Master
                                     │
                                     ▼
                         Bluetooth Slave
                                     │
                                     ▼
                           ┌────────────────┐
                           │ HUB CONTROLLER │
                           │   Arduino Uno  │
                           └───────┬────────┘
                                   │
                    ┌──────────────┼──────────────┐
                    │              │              │
                    ▼              ▼              ▼
              Slant Conveyor     Siever      Flat Conveyor
```

The truck therefore served as the communication gateway between the Android controller and the stationary hub.

---

# 4. Renewable Power Architecture

The renewable power station supplied electrical energy to the project.

```text
                     SOLAR PANEL
                          │
                          ▼
                        FUSE
                          │
                          ▼
                  SCHOTTKY DIODE
                          │
                          ▼
                    XL4016 CC/CV
                          │
                          ▼
                       4S BMS
                          │
                          ▼
                  LI-ION BATTERY
                     4S5P
                          │
                          ▼
                POWER DISTRIBUTION
                          │
              ┌───────────┼───────────┐
              │           │           │
              ▼           ▼           ▼
          BUCK 5 V    BUCK 6 V    OTHER DC
              │           │        LOADS
              └───────────┴───────────┘
```

The power station consisted of:

- Solar panel
- Rechargeable battery pack
- Battery management system
- Charge-control stage
- Protection components
- Distribution towers
- Buck converters

Detailed power-system calculations are documented in:

`Power_System_Design.md`

---

# 5. Renewable Power Station

The renewable power station served as the electrical backbone of the Agro-Smart Hub.

Its primary functions were:

- Generate electrical energy from sunlight.
- Store electrical energy in the battery pack.
- Regulate electrical voltage.
- Distribute power to the different subsystems.

The system was designed to demonstrate how renewable energy could support localized automated agro-processing.

---

# 6. Embedded Control System

Two Arduino Uno boards were used as the primary embedded controllers.

## 6.1 Truck Controller

The Arduino on the truck performed several functions:

- Receive commands from the Android application.
- Interpret incoming commands.
- Control truck movement.
- Control the truck lifting mechanism.
- Determine whether commands were intended for the truck or the stationary hub.
- Forward hub commands to the stationary hub.

The truck controller therefore performed both **local control** and **communication gateway** functions.

---

## 6.2 Hub Controller

The Arduino on the stationary hub controlled the processing mechanisms.

Its responsibilities included:

- Receive commands forwarded by the truck.
- Control the slanting conveyor.
- Control the sieving mechanism.
- Control the flat conveyor.
- Activate the required switching devices.

---

# 7. Wireless Communication Architecture

The communication system operated through multiple Bluetooth modules.

The communication sequence was:

```text
Android Application
        │
        │ Bluetooth
        ▼
Truck Bluetooth Module
        │
        ▼
Truck Arduino
        │
        │ Software Serial
        ▼
Truck Bluetooth Master
        │
        │ Bluetooth
        ▼
Hub Bluetooth Slave
        │
        ▼
Hub Arduino
```

The truck Arduino acted as the gateway.

When a command was received, the truck controller determined whether the command was:

- intended for the truck, or
- intended for the stationary hub.

Truck commands were executed locally.

Hub commands were forwarded to the stationary hub.

---

# 8. Mechanical System

The mechanical system consisted of the following major units:

- Slanting conveyor
- Sieving mechanism
- Flat conveyor
- Mobile truck
- Truck carrier
- Truck lifting mechanism

Each unit performed a dedicated mechanical function.

---

# 9. Slanting Conveyor

The slanting conveyor transported cassava from a lower loading area upward toward the sieving unit.

Its primary function was to:

1. Receive cassava.
2. Move cassava upward.
3. Discharge cassava into the siever.

This reduced the need for manual transfer of cassava into the sieving stage.

---

# 10. Sieving Mechanism

The sieving mechanism automated the separation of cassava particles before frying.

A gear motor drove the sieving mechanism in a back-and-forth motion.

As cassava entered the siever:

- Fine particles passed through the sieving surface.
- Coarser particles were retained or separated.
- The fine material fell onto the flat conveyor beneath the siever.

The mechanical construction was primarily achieved using locally available materials including plywood and ceiling board.

---

# 11. Flat Conveyor

The flat conveyor was positioned beneath the sieving mechanism.

Its purpose was to:

1. Receive sieved cassava from the siever.
2. Transport the material horizontally.
3. Discharge the material into the mobile truck.

The conveyor was constructed using:

- Plywood supports
- Wooden shafts
- Bearings
- PVC roller surfaces
- Conveyor belt material

The shafts were supported by bearings embedded within short wooden holders.

---

# 12. Mobile Transport Truck

The truck was designed to receive processed cassava from the flat conveyor and transport it toward the frying area.

The truck consisted of:

- Structural frame
- Cassava carrier
- Wheels
- Drive motors
- Embedded controller
- Bluetooth communication module
- Motor driver
- Carrier lifting mechanism

The truck served two roles:

1. Material transportation.
2. Communication gateway for the stationary processing hub.

---

# 13. Truck Carrier Lifting Mechanism

A lifting mechanism was incorporated into the truck to discharge cassava.

The mechanism used:

- Gear mechanism
- Pinion
- Rack
- Linkage mechanism

The rack-and-pinion arrangement converted rotary motor motion into linear motion, which was then used to actuate the linkage.

The linkage raised one side of the cassava carrier, causing the material to discharge from the opposite side.

The mechanism required several design iterations before it could reliably lift a loaded carrier.

The final solution involved changing the geometry of the linkage and adding an additional gear, rack, and pinion stage to increase the available mechanical advantage.

---

# 14. Material Flow

The intended material flow through the system was:

```text
Cassava Loading Area
        │
        ▼
Slanting Conveyor
        │
        ▼
     SIEVER
        │
        ▼
  Fine Cassava
        │
        ▼
Flat Conveyor
        │
        ▼
Transport Truck
        │
        ▼
Truck Transport
        │
        ▼
Frying Area
```

This architecture automated the selected sieving and material-transfer stages of cassava processing.

---

# 15. Operational Sequence

The complete system operates through the following sequence:

1. The renewable power station is activated.
2. The Android controller establishes communication with the truck.
3. The operator sends the required command from the Android controller.
4. The truck Arduino receives and interprets the command.
5. If the command is intended for the truck, it is executed locally.
6. If the command is intended for the stationary hub, it is forwarded to the hub controller.
7. The slanting conveyor transports cassava to the siever.
8. The siever separates the cassava particles.
9. Fine cassava falls onto the flat conveyor.
10. The flat conveyor transports the sieved cassava into the truck.
11. The truck transports the cassava toward the frying area.
12. The lifting mechanism raises the truck carrier.
13. The processed cassava is discharged.

---

# 16. Modular Design Philosophy

The Agro-Smart Hub was developed using a modular engineering approach.

Rather than attempting to construct the entire system simultaneously, the project was divided into individual subsystems.

These included:

- Renewable power station
- Battery pack
- Slanting conveyor
- Siever
- Flat conveyor
- Truck
- Truck lifting mechanism
- Embedded control
- Wireless communication
- Android controller

Each unit could be developed and tested independently before integration.

This approach provided several advantages:

- Simplified debugging
- Reduced system complexity
- Allowed students to focus on individual engineering problems
- Enabled independent subsystem testing
- Made troubleshooting easier
- Reduced the risk of changing the entire system when one subsystem failed

---

# 17. Engineering Disciplines Integrated

The final prototype demonstrated the integration of several engineering disciplines.

| Discipline             | Application                                             |
| ---------------------- | ------------------------------------------------------- |
| Mechanical Engineering | Conveyors, siever, truck, linkage and lifting mechanism |
| Electrical Engineering | Power distribution and electrical loads                 |
| Power Electronics      | Buck conversion and battery charging                    |
| Embedded Systems       | Arduino-based control                                   |
| Wireless Communication | Bluetooth command transmission                          |
| Mobile Development     | Android controller                                      |
| Renewable Energy       | Solar-powered electrical system                         |
| Systems Engineering    | Subsystem integration and testing                       |

---

# 18. Key Design Characteristics

The Agro-Smart Hub was characterized by:

- Modular construction
- Renewable-energy power
- Wireless control
- Embedded control
- Mobile material transportation
- Automated cassava sieving
- Localized fabrication
- Low-cost construction
- Student participation
- Multi-disciplinary engineering integration

---

# 19. Related Documentation

Detailed engineering information is documented in the following project documents:

- `Power_System_Design.md`
- `System_Requirements_Specification.md`
- `Engineering_Design_History.md`
- `Software_Architecture.md`
- `Test_Report.md`
- `Bill_of_Materials.md`
- `Engineering_Reflection.md`
- `Competition_Journey.md`
