# Engineering Decision Log

## Purpose

This document records the major engineering decisions made during the design and development of the Agro-Smart Hub project. Each decision includes the problem, alternatives considered, final decision, justification, and outcome.

---

# EDL-001 — Adopt a Modular System Architecture

**Problem**

The project consisted of multiple mechanical, electrical, and embedded subsystems. Building everything simultaneously would make debugging difficult.

**Alternatives Considered**

- Build the entire system at once.
- Build each subsystem independently before integration.

**Decision**

Develop the project as independent subsystems before full integration.

**Justification**

This approach simplified testing, fault isolation, and student learning.

**Outcome**

Subsystems were successfully tested individually before being integrated into the complete system.

---

# EDL-002 — Use Renewable Solar Energy

**Problem**

The system required a reliable and sustainable power source.

**Alternatives Considered**

- Direct mains power.
- Disposable batteries.
- Rechargeable battery with solar charging.

**Decision**

Use a rechargeable lithium-ion battery pack charged from a solar panel.

**Justification**

The renewable power system aligned with the project's sustainability goals and enabled operation without continuous mains electricity.

**Outcome**

A renewable power station consisting of a solar panel, battery pack, and power distribution system was successfully developed.

---

# EDL-003 — Use Arduino Uno Controllers

**Problem**

The project required embedded controllers for the truck and stationary hub.

**Alternatives Considered**

- ESP32
- Raspberry Pi
- Arduino Uno

**Decision**

Use two Arduino Uno boards.

**Justification**

The Arduino Uno was affordable, widely available, familiar to the students, and sufficient for the project requirements.

**Outcome**

One Arduino controlled the truck while another controlled the stationary hub.

---

# EDL-004 — Divide Control Between Truck and Hub

**Problem**

A single controller would require long wiring runs between moving and stationary subsystems.

**Alternatives Considered**

- One Arduino controlling everything.
- Separate controllers communicating wirelessly.

**Decision**

Use independent truck and hub controllers.

**Justification**

Reduced wiring complexity and improved modularity.

**Outcome**

The truck became the communication gateway while the hub managed stationary equipment.

---

# EDL-005 — Replace nRF24L01 with Bluetooth

**Problem**

The original design planned to use nRF24L01 radio modules for wireless communication.

**Alternatives Considered**

- nRF24L01
- Bluetooth

**Decision**

Replace the nRF24L01 modules with Bluetooth modules.

**Justification**

The L293D motor driver shield occupied many Arduino Uno pins, leaving insufficient pins for the nRF24L01 interface without creating conflicts. Bluetooth modules could be integrated using the remaining available serial connections, making them the more practical solution.

**Outcome**

The Bluetooth communication architecture was successfully implemented between the Android application, truck controller, and hub controller.

---

# EDL-006 — Use the Truck as the Communication Gateway

**Problem**

The Android application needed to control both the mobile truck and the stationary hub.

**Alternatives Considered**

- Connect the phone independently to both controllers.
- Route all communication through the truck.

**Decision**

Use the truck as the communication gateway.

**Justification**

A single connection simplified operation and reduced user interaction during demonstrations.

**Outcome**

The truck successfully routed hub commands through the second Bluetooth communication link.

---

# EDL-007 — Modify Android Command Transmission

**Problem**

The truck continued moving after receiving a movement command.

**Decision**

Modify the Android application to continuously transmit movement commands only while a control button remained pressed.

**Justification**

This provided better operator control and prevented unintended continuous motion.

**Outcome**

Truck movement became predictable and responsive.

---

# EDL-008 — Delimit Commands with Newline Characters

**Problem**

Multiple Bluetooth commands occasionally merged into a single message.

**Decision**

Append a newline (`\n`) to every transmitted command and read commands using `readStringUntil('\n')`.

**Justification**

Clearly separating messages improved communication reliability.

**Outcome**

The Arduino processed each command independently without message concatenation.

---

# EDL-009 — Increase Turning Speed After Lift Installation

**Problem**

After installing the lifting mechanism, the truck struggled to turn because of the additional load.

**Alternatives Considered**

- Redesign the chassis.
- Replace the motors.
- Increase turning speed.

**Decision**

Increase the turning speed while leaving the forward speed unchanged.

**Justification**

The additional turning torque improved manoeuvrability without requiring mechanical redesign.

**Outcome**

The truck regained reliable steering performance.

---

# EDL-010 — Redesign the Linkage Mechanism

**Problem**

The lifting mechanism worked without load but failed when carrying cassava.

**Decision**

Reposition the linkage joint, raise the drive mechanism, and introduce an additional gear-and-rack stage.

**Justification**

The redesign improved the force transmission geometry and increased lifting capability.

**Outcome**

The lifting mechanism successfully raised and lowered the loaded cassava carrier.

---

# Lessons Learned

The Agro-Smart Hub project demonstrated that successful engineering requires continuous evaluation of design decisions throughout the development process. Many of the final solutions differed from the original concepts because practical testing revealed constraints that were not apparent during planning. Iterative improvement, evidence-based decision-making, and systematic debugging were essential to the successful completion of the project.
