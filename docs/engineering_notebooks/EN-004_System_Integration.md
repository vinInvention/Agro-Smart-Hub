# Engineering Notebook 004

# System Integration

Project: Agro-Smart Hub

Notebook ID: EN-004

---

# Engineering Problem

The Agro-Smart Hub was developed as several independent subsystems. Although each subsystem functioned correctly during individual testing, the final challenge was integrating them into a single coordinated mechatronic system.

Successful integration required mechanical alignment, electrical power distribution, wireless communication, and synchronized software control.

---

# Integrated Subsystems

The completed Agro-Smart Hub consisted of the following subsystems:

- Renewable Power Station
- Slant Conveyor
- Siever
- Flat Conveyor
- Truck
- Android Controller
- Hub Controller
- Wireless Communication System

Each subsystem was first tested independently before system integration.

---

# Integration Strategy

To reduce debugging complexity, the project was integrated one subsystem at a time.

The integration sequence was:

1. Renewable power station
2. Flat conveyor
3. Siever
4. Slant conveyor
5. Truck
6. Wireless communication
7. Android controller
8. Complete system testing

Testing each subsystem individually before combining it with the others helped isolate faults quickly.

---

# Mechanical Integration

Mechanical integration involved:

- Aligning the slant conveyor with the siever.
- Positioning the flat conveyor directly beneath the siever.
- Positioning the truck to receive cassava from the flat conveyor.
- Ensuring sufficient clearance for truck movement and carrier lifting.

Several small adjustments were made during assembly to improve alignment and smooth material flow.

---

# Electrical Integration

The renewable power station supplied electrical energy to:

- Arduino controllers
- DC gear motors
- Relay modules
- Bluetooth modules

Buck converters regulated the required voltages for different components.

Power distribution was organized to simplify maintenance and troubleshooting.

---

# Embedded System Integration

The project used two Arduino Uno boards.

Truck Arduino responsibilities:

- Receive commands from the Android application.
- Execute truck-related commands.
- Forward hub commands wirelessly.

Hub Arduino responsibilities:

- Receive forwarded commands.
- Control the siever.
- Control the flat conveyor.
- Control the slant conveyor.

This distributed architecture reduced software complexity and separated responsibilities between controllers.

---

# Wireless Communication Integration

Communication followed the sequence:

Android Application

↓

Truck Bluetooth Module

↓

Truck Arduino

↓

Truck Bluetooth Module (Master)

↓

Hub Bluetooth Module (Slave)

↓

Hub Arduino

This architecture allowed the Android application to communicate with the entire system through a single access point.

---

# Integration Challenge

During the first complete integration test, the hub failed to respond to commands.

Serial Monitor confirmed that the Hub Arduino was receiving Bluetooth messages correctly.

This indicated that wireless communication was functioning as expected.

Further investigation revealed that several wires connecting the Arduino outputs to the relay module had poor electrical connections.

The faulty wires were replaced.

After replacement, all hub functions operated correctly.

---

# System Validation

The fully integrated system successfully demonstrated:

- Renewable power distribution.
- Cassava lifting.
- Cassava sieving.
- Material transfer to the truck.
- Wireless truck control.
- Wireless hub control.
- Automatic cassava discharge.

The successful integration confirmed that all subsystems operated together as one coordinated mechatronic system.

---

# Engineering Lessons

System integration is often more challenging than subsystem development.

Successful subsystem testing does not guarantee successful system operation.

Structured integration, systematic debugging, and step-by-step verification significantly reduced troubleshooting time.

---

# Future Improvements

Future versions could include:

- Automatic fault detection.
- Power monitoring.
- Modular electrical connectors.
- Status indicators for each subsystem.
- Central diagnostic interface.

---

# Media to Add Later

- [ ] Complete Agro-Smart Hub
- [ ] System integration process
- [ ] Electrical wiring
- [ ] Truck communicating with hub
- [ ] Complete operating system
- [ ] Demonstration photographs
- [ ] System architecture diagram
