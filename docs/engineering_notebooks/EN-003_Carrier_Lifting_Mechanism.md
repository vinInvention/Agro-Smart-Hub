# Engineering Notebook 003

# Carrier Lifting Mechanism Development

Project: Agro-Smart Hub

Notebook ID: EN-003

---

# Engineering Problem

The truck required a mechanism capable of lifting one side of the cassava carrier so that the processed cassava could be discharged into the frying area.

The lifting mechanism needed to operate electrically, support the weight of the carrier and its load, and return to its original position after unloading.

---

# Design Requirements

The mechanism had to:

- Lift a loaded carrier.
- Lower the carrier smoothly.
- Be electrically actuated.
- Fit within the truck chassis.
- Be repeatable and reliable.

---

# Initial Design

The original lifting system consisted of:

- DC gear motor
- Spur gear
- Pinion
- Rack
- Rack holder
- Linkage mechanism
- Cassava carrier

The gear motor rotated the pinion.

The pinion drove the rack in a straight line.

The rack pushed the linkage, causing the carrier to rise.

---

# Initial Testing

The mechanism operated correctly when the carrier was empty.

The linkage raised and lowered the carrier smoothly.

This confirmed that the mechanism functioned under no-load conditions.

---

# Engineering Challenge

When load was placed inside the carrier, the mechanism could no longer lift it.

The gear motor failed to generate enough torque to close the linkage mechanism, hence, the linkage did't rise.

The system stalled under load.

---

# Investigation

Several possibilities were considered:

- Insufficient motor torque.
- Weak linkage.
- Excessive friction.
- Poor force transmission.

After several unsuccessful attempts to improve the mechanism, attention shifted to the geometry of the linkage itself.

---

# Root Cause

Careful observation revealed that the joint connecting the rack to the linkage was positioned above the point where the driving force was being applied.

As a result, much of the motor's effort was being wasted instead of producing useful lifting motion.

The issue was not primarily the motor's power but the mechanical advantage created by the linkage geometry.

---

# Engineering Solution

The mechanism was redesigned by:

- Lowering the linkage joint.
- Raising the rack drive assembly.
- Improving the direction of force transmission.
- Adding a second gear, pinion, and rack assembly to increase the effective driving force.

These changes improved the mechanical advantage of the lifting system.

---

# Final Testing

The redesigned mechanism successfully:

- Lifted the empty carrier.
- Lifted the loaded carrier.
- Lowered the carrier smoothly.
- Repeated the operation consistently during testing.

The redesign met all functional requirements.

---

# Engineering Reflection

This was the most significant mechanical design challenge encountered during the project.

Unlike many software or electronics problems, no existing tutorial or reference directly addressed the issue.

The solution emerged through observation, experimentation, and reasoning about force transmission and linkage geometry.

Successfully solving this problem increased my confidence in applying mechanical engineering principles to create original design solutions.

---

# Lessons Learned

This experience reinforced several engineering principles:

- Mechanical geometry can be as important as actuator power.
- Testing under real operating loads is essential.
- Prototype failures provide valuable design information.
- Engineering solutions often require redesign rather than simply increasing motor size.
- Systematic analysis can reveal solutions that are not immediately obvious.

---

# Future Improvements

Possible future improvements include:

- CAD-based linkage optimization.
- Finite Element Analysis (FEA) of the linkage components.
- Adjustable linkage joints for tuning.
- Position feedback using limit switches or sensors.
- Automated lift position control.

---

# Media to Add Later

- [ ] Initial linkage design
- [ ] Rack-and-pinion assembly
- [ ] Linkage before redesign
- [ ] Modified linkage geometry
- [ ] Second rack-and-pinion assembly
- [ ] Photos of lifting tests
- [ ] Video of successful unloading
- [ ] Sketches explaining force transmission
