# Agro-Smart Hub

> **A renewable energy-powered mechatronic prototype developed to automate the cassava sieving stage of gari production through the integration of mechanical systems, embedded electronics, wireless communication, and Android-based control.**

> Developed for **Battle of the Bots Robotics Competition 2.0** under the theme **"Robotics for Industrialization."**

---

## 📸 Project Showcase

> ![Agro-Smart Hub Prototype Diagram](assets/1.%20Complete%20system%20diagram.jpg)

---

> ![Agro-Smart Hub Complete Sytem](assets/3.%20Entire%20setupb.png)

---

# Project Overview

Agro-Smart Hub is an educational mechatronics engineering project designed to automate one of the most labor-intensive stages of gari production—the sieving of cassava mash before frying.

The project combines mechanical engineering, electrical engineering, embedded systems, renewable energy, and software engineering into a single integrated prototype. It was developed together with secondary school students as part of the Battle of the Bots Robotics Competition 2.0.

Rather than building isolated subsystems, the project demonstrates how multiple engineering disciplines can work together to solve a real agricultural problem.

---

# The Problem

Traditional cassava processing involves several manual operations before gari is produced.

One of these operations is sieving the cassava mash to separate fine particles from coarse particles before frying. Manual sieving:

- Requires continuous human effort.
- Can be time-consuming.
- May introduce contamination through excessive handling.
- Limits processing efficiency.

The project focuses on automating this stage while demonstrating how renewable energy and embedded systems can support localized agricultural processing.

---

# The Solution

Agro-Smart Hub automates the cassava sieving process using a collection of interconnected subsystems.

The complete system includes:

- Renewable Solar Power Station
- Rechargeable Battery Pack
- Slant Conveyor
- Motorized Siever
- Flat Conveyor
- Mobile Transport Truck
- Android Control Application
- Distributed Arduino Control System
- Bluetooth Communication Network

Together, these subsystems receive cassava, sieve it, transport the processed material, and allow wireless operation from an Android device.

---

# Key Features

- Renewable solar-powered operation
- Battery-powered mobile system
- Automated cassava sieving
- Wireless Android control
- Distributed embedded control architecture
- Modular subsystem design
- Mechanical material handling
- Custom communication protocol
- Educational engineering platform
- Designed and constructed with secondary school students

---

# System Architecture

> ![System Architecture diagram](assets/System%20Architectural%20diagram.png)

---

# Major Subsystems

## Renewable Power Station

Provides electrical power to the entire Agro-Smart Hub using a rechargeable battery system supplied by solar energy.

> ![Agro-Smart Hub Renewable Power Station](assets/Power%20station/6.%20Power%20station%20working.PNG)

---

## Battery Pack

Stores electrical energy for the project and distributes regulated power to the different subsystems through buck converters.

> ![Agro-Smart Hub Battery Pack](assets/Battery%20pack/Battery%20Pack.PNG)

---

## Slant Conveyor

Transfers cassava upward into the sieving system.

> ![Agro-Smart Hub Slant conveyor](assets/Slanting%20Conveyor/2a.%20Sieving%20hub.PNG)

---

## Motorized Siever

Separates fine cassava particles from coarse particles using a reciprocating mechanical motion.

> ![Agro-Smart Hub Siever](assets/Sieving%20hub/Siever.PNG)

---

## Flat Conveyor

Receives sieved cassava and transports it into the collection truck.

> ![Agro-Smart Hub Flat Conveyor](assets/Flat%20conveyor%20with%20Siever%20construction/Flat%20conveyor.jpeg)

---

## Transport Truck

Receives processed cassava, transports it to the discharge area, and empties its carrier using a custom lifting mechanism.

> ![Agro-Smart Hub Truck under construction](assets/truck/10.%20Mechanism%20and%20wiring.PNG)

---

> ![Agro-Smart Hub Prototype](assets/truck/11.%20Final%20outcome.jpeg)

---

## Android Controller

Provides a wireless Human-Machine Interface (HMI) for controlling the complete system.

> ![Agro-Smart Hub Prototype](assets/Android%20app%20interface/1.%20Android%20app%20interface.jpeg)

---

# Software Architecture

The software consists of three primary components:

- Android Controller (MIT App Inventor)
- Truck Controller Firmware (Arduino Uno)
- Hub Controller Firmware (Arduino Uno)

The Android application communicates with the truck controller through Bluetooth. The truck controller executes local commands and forwards hub commands to the stationary processing hub using a second Bluetooth communication link.

---

# Communication Architecture

The system uses a distributed wireless communication model.

```
Android Application
        │
        ▼
Truck Bluetooth Module
        │
        ▼
Truck Arduino
     │         │
     │         ▼
     │   Execute Truck Command
     │
     ▼
Master Bluetooth
        │
Slave Bluetooth
        │
        ▼
Hub Arduino
        │
        ▼
Execute Hub Commands
```

> ![Agro-Smart Hub Communication Architecture](assets/Communication/Complete%20controller%20communication%20architechtural%20diagram.png)

---

# Technologies Used

## Hardware

- Arduino Uno
- HC-05 Bluetooth Modules
- DC Gear Motors
- L293D Motor Driver
- Relay Modules
- 18650 Lithium-Ion Batteries
- Solar Panel
- Buck Converters
- Bearings
- PVC Pipes
- Steel Shafts

---

## Software

- Arduino IDE
- MIT App Inventor
- Draw.io
- Git
- GitHub

---

# Engineering Documentation

The complete engineering documentation for this project is available in the **docs** directory.

| Document                            | Link                                                                                            |
| ----------------------------------- | ----------------------------------------------------------------------------------------------- |
| Engineering Design History          | ![Engineering design history](docs/02_Engineering_Design_History/Engineering_Design_History.md) |
| System Requirements Specification   | ![System Requirements](docs/Requirements/System_Requirements_Specification.md)                  |
| System Architecture                 | ![System Architecture](docs/Software_Architecture.md)                                           |
| Engineering Design Decisions        | ![Engineering Decisions](docs/02_Engineering_Design_History/Engineering_Design_History.md)      |
| Engineering Notebook Series         | ![Engineering Design History](docs/engineering_notebooks/)                                      |
| Bill of Materials                   | ![Bill of Materials](docs/Bill_of_Materials.md)                                                 |
| Test Report                         | ![Test Report](docs/Test_Report.md)                                                             |
| Manufacturing Drawings & Dimensions | ![Manufacturing Drawings](docs/Manufacturing_Drawings_and_Dimensions.md)                        |
| Engineering Reflection              | ![Engineering Reflection](docs/Engineering_Reflection.md)                                       |
| Competition Journey                 | ![Competition Journey](docs/Competition_Journey.md)                                             |

---

# Repository Structure

```text
Agro-Smart-Hub/
│
├── assets/
│   ├── android_app_interface/
│   ├── battery_pack/
│   ├── flat_conveyor_and_siever/
│   ├── power_station/
│   ├── simulations/
│   └── truck/
│
├── docs/
│
├── software/
│
└── README.md
```

---

# Demonstration

### Prototype Demonstration

> **Testing the Flat Conveyor Unit**

---

> ![Flat Conveyor Unit](http://tiny.cc/wur7101)

---

> **Insert YouTube or Google Drive video link**

### Android Controller Demonstration

> **Insert Video Link**

### Competition Demonstration

> **Insert Video Link**

---

# Competition

Agro-Smart Hub was developed for the **Battle of the Bots Robotics Competition 2.0** under the theme **"Robotics for Industrialization."**

The project successfully progressed through proposal review, subsystem development, integration, and technical evaluation before participating in the competition.

During the competition, an unexpected failure of the renewable power station battery pack interrupted the final demonstration sequence. Despite this setback, the team completed its presentation and finished **12th out of 38 competing secondary school teams**.

The experience provided valuable lessons in systems integration, engineering design, testing, project management, and resilience.

---

# Future Improvements

Future versions of Agro-Smart Hub may include:

- Battery Management System (BMS) monitoring
- Closed-loop motor control
- Automatic battery status reporting
- ESP32-based controller architecture
- Computer vision for cassava monitoring
- Autonomous truck navigation
- Sensor-based process automation
- Improved mechanical robustness

---

# Acknowledgements

This project would not have been possible without the enthusiasm and commitment of the students who participated throughout the design, construction, testing, and presentation of the Agro-Smart Hub, the school (Royal Dutch School - Ago Lagos state) which provided us the space and sponsored the project finacially.

Their curiosity, teamwork, and willingness to learn transformed this project into both an engineering achievement and an educational experience.

---

# Author

**Chinonyerem Vincent**

Computer Science Graduate • Robotics Educator • Aspiring Mechatronics Engineer

Agro-Smart Hub represents my journey of applying engineering principles to solve real-world agricultural problems

The Agro-Smart Hub project was the most ambitious engineering project I had undertaken at the time of its development. It required me to combine concepts from mechanical engineering, electrical engineering, embedded systems, renewable energy, software development, and project management into a single working prototype.
while mentoring young learners in robotics and embedded systems.

Beyond building a functional system, the project challenged me to think like an engineer: identifying problems, evaluating alternatives, testing solutions, and continuously improving the design.

---

## License

This project is licensed under the MIT License.

See the **LICENSE** file for details.
