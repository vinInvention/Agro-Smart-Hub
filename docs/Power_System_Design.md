# Power System Design

**Project:** Agro-Smart Hub
**System:** Renewable Solar Power Station
**Application:** Cassava Processing Automation
**Project Type:** Student-Built Mechatronic Prototype

---

# 1. Introduction

The Agro-Smart Hub required an independent electrical power system capable of supplying energy to its mechanical, embedded, communication, and mobile subsystems.

Because the project was designed around the theme **"Robotics for Industrialization"**, the power system was designed around renewable energy rather than relying solely on mains electricity. Solar energy was selected as the primary energy source, while a rechargeable lithium-ion battery pack was used to store electrical energy for operation when solar power was insufficient or unavailable.

The power system therefore served as both the energy source and the electrical backbone of the Agro-Smart Hub.

The system supplied power to:

- Conveyor motors
- Sieving mechanism
- Mobile truck
- Truck lifting mechanism
- Arduino controllers
- Sensors and communication electronics
- Other electrical actuators used throughout the system

The design process involved estimating the electrical load, determining the required battery capacity, selecting a suitable battery configuration, sizing the solar panel, selecting a Battery Management System (BMS), selecting a charge-control method, and distributing regulated power to the different subsystems.

---

# 2. Power System Requirements

The power system was designed around the following requirements.

## 2.1 Runtime Requirement

The target was to provide sufficient stored electrical energy to support approximately **one hour of demonstration operation**.

The system therefore required sufficient battery capacity to accommodate:

- Mechanical loads
- Embedded electronics
- Power conversion losses
- Design margins
- Battery operating limitations

## 2.2 Renewable Energy Requirement

The system was required to use renewable energy as its primary energy source.

Solar energy was selected because:

- Solar power is readily available in the project's operating environment.
- It eliminates dependence on mains electricity during operation.
- It provides an opportunity to demonstrate sustainable industrial automation.
- It allows the battery to be recharged between demonstrations.

## 2.3 Load Requirements

The major electrical loads consisted of:

- Three TT gear motors
- Two DC motors
- Two servo motors
- Arduino and sensor electronics
- Communication and control electronics

The motors represented the majority of the electrical demand, while the Arduino and sensor system represented a comparatively smaller continuous electronic load.

---

# 3. Electrical Load Analysis

Electrical load estimation was performed before finalizing the battery configuration.

The basic power relationship used was:

[
P = V \times I
]

where:

- (P) = electrical power in watts (W)
- (V) = voltage in volts (V)
- (I) = current in amperes (A)

For a one-hour operating period:

[
E = P \times t
]

where:

- (E) = energy in watt-hours (Wh)
- (P) = power in watts (W)
- (t) = operating time in hours

## 3.1 Estimated Electrical Loads

| System Component    | Quantity | Voltage | Current per Unit | Total Power | Energy for 1 Hour |
| ------------------- | -------: | ------: | ---------------: | ----------: | ----------------: |
| TT Gear Motor       |        3 |     6 V |            1.5 A |      27.0 W |           27.0 Wh |
| Servo Motor 1       |        1 |     5 V |            0.5 A |       2.5 W |            2.5 Wh |
| Servo Motor 2       |        1 |     6 V |            0.5 A |       3.0 W |            3.0 Wh |
| DC Motor            |        2 |     6 V |            1.5 A |      18.0 W |           18.0 Wh |
| Arduino + 3 Sensors |        1 |     5 V |           ~0.5 A |       2.5 W |            2.5 Wh |
| **Base Load Total** |          |         |                  |  **53.0 W** |       **53.0 Wh** |

The calculated base electrical load was therefore approximately:

[
P_{base}=53W
]

For one hour of continuous operation:

[
E_{base}=53Wh
]

This 53 Wh value represents the estimated energy delivered to the loads before accounting for conversion losses, design margin, and battery operating limitations.

### Design Note

The values above represent estimated or rated loads. Actual motor consumption varies with mechanical loading, acceleration, friction, duty cycle, and operating conditions. Consequently, the calculated 53 W should be regarded as a design estimate rather than a direct measurement of average system consumption.

---

# 4. Battery Energy Requirement

The battery was sized from the estimated system energy requirement.

The base load requirement was:

[
53Wh
]

However, the battery does not deliver energy to the loads through a perfectly lossless electrical path. The system contains voltage-conversion stages and other electrical losses.

The original design therefore incorporated additional allowances for:

1. Power-management losses
2. Converter losses
3. Engineering design margin
4. Battery depth-of-discharge limitation

---

## 4.1 BMS Design Allowance

An assumed BMS efficiency of approximately 97% was initially included in the sizing calculation.

Using:

[
\eta=\frac{E_{out}}{E_{in}}
]

and:

[
0.97=\frac{53}{E_{in}}
]

gives:

[
E_{in}=\frac{53}{0.97}
]

[
E_{in}\approx54.64Wh
]

This produced an additional design allowance of approximately:

[
54.64-53=1.64Wh
]

### Engineering Note

The BMS itself is primarily a protection and battery-management device rather than a conventional power-conversion stage. Therefore, the 97% figure should be regarded as an **overall design allowance associated with the battery-management path**, rather than a measured BMS efficiency.

---

## 4.2 Buck Converter Loss

The project used buck converters to reduce the battery voltage to the voltage required by individual loads.

An assumed converter efficiency of 85% was used during the original sizing process.

[
0.85=\frac{54.64}{E_{in}}
]

Therefore:

[
E_{in}=\frac{54.64}{0.85}
]

[
E_{in}\approx64.28Wh
]

The estimated energy allowance associated with this stage was:

[
64.28-54.64=9.64Wh
]

---

## 4.3 Engineering Design Margin

An additional 20% engineering allowance was applied to account for practical system losses and uncertainties not completely captured by the simple component calculations.

This produced an assumed overall efficiency of 80% for this design stage:

[
0.80=\frac{64.28}{E_{in}}
]

Therefore:

[
E_{in}=\frac{64.28}{0.80}
]

[
E_{in}\approx80.35Wh
]

The resulting design energy requirement before applying the battery depth-of-discharge allowance was approximately:

[
80.35Wh
]

### Engineering Note

This 20% allowance was a design margin rather than a measured loss. It was intentionally conservative because the system contained motors, wiring, switching devices, converters, mechanical loads, and other real-world factors that could cause the actual energy demand to differ from the theoretical calculation.

---

## 4.4 Battery Depth of Discharge

The design targeted approximately 75% usable battery capacity.

In other words, approximately 25% of the nominal battery capacity was reserved rather than intentionally consumed during normal demonstration operation.

The required nominal battery energy was therefore estimated as:

[
E_{battery}=\frac{80.35}{0.75}
]

[
E_{battery}\approx107.13Wh
]

Therefore, the calculated battery energy requirement was approximately:

[
\boxed{107.13Wh}
]

---

# 5. Battery Configuration

## 5.1 Selection of Series Configuration

The system contained loads requiring approximately 5 V and 6 V, as well as a higher-voltage section associated with the system architecture.

A battery configuration with sufficient voltage overhead was therefore required.

A lithium-ion 18650 cell has a nominal voltage of approximately:

[
3.7V
]

Four cells connected in series provide:

[
3.7V\times4=14.8V
]

A fully charged 4S lithium-ion pack reaches approximately:

[
4.2V\times4=16.8V
]

Therefore, a **4S configuration** was selected.

The higher battery voltage could then be reduced to the required load voltages using buck converters.

---

## 5.2 Selection of Parallel Configuration

The calculated battery energy requirement was approximately:

[
107.13Wh
]

Using a 14.8 V nominal battery voltage:

[
Capacity=\frac{107.13}{14.8}
]

[
Capacity\approx7.24Ah
]

A parallel capacity of approximately 7 Ah or greater was therefore required.

Each available 18650 cell was rated approximately:

[
3.7V,\ 1.5Ah
]

Five cells in parallel provide:

[
1.5Ah\times5=7.5Ah
]

Therefore, a **5P configuration** was selected.

---

## 5.3 Final Battery Configuration

The resulting configuration was:

**4S5P**

This means:

- 4 cells connected in series
- 5 cells connected in parallel within each series group
- 20 cells in the nominal 4S5P configuration

The resulting battery characteristics were:

| Parameter                |        Value |
| ------------------------ | -----------: |
| Cell type                | 18650 Li-ion |
| Cell nominal voltage     |        3.7 V |
| Cell capacity            |       1.5 Ah |
| Series configuration     |           4S |
| Parallel configuration   |           5P |
| Total cells              |           20 |
| Nominal battery voltage  |       14.8 V |
| Maximum charging voltage |       16.8 V |
| Pack capacity            |       7.5 Ah |
| Nominal energy           |       111 Wh |

The nominal pack energy was:

[
14.8V\times7.5Ah=111Wh
]

Therefore:

[
\boxed{E_{pack}\approx111Wh}
]

This exceeded the calculated requirement of 107.13 Wh and therefore provided a small additional capacity margin.

---

# 6. Solar Panel Sizing

The solar panel had two roles:

1. Provide renewable energy to the system.
2. Recharge the battery.

The initial design calculation considered the energy required to operate the load and replenish the battery within an assumed four-hour peak-sunlight period.

## 6.1 Required Energy

The design used:

- Load energy allowance: 80.35 Wh
- Battery nominal energy: 111 Wh

Therefore:

[
E_{solar}=80.35+111
]

[
E_{solar}=191.35Wh
]

---

## 6.2 Solar Panel Power

An assumed effective panel/system efficiency of 80% was used.

With four hours of effective sunlight:

[
P_{panel}=
\frac{191.35}{4\times0.80}
]

[
P_{panel}\approx59.8W
]

Therefore, the minimum calculated panel size was approximately:

[
\boxed{60W}
]

---

## 6.3 Selected Solar Panel

An **80 W monocrystalline solar panel** was ultimately purchased.

The selected panel therefore provided additional capacity above the calculated 60 W minimum.

The panel specification used during the project was approximately:

- Rated power: 80 W
- Nominal operating voltage: approximately 19 V

The higher panel capacity provided additional margin for real-world solar variation and allowed the system to support charging while the project was operating in appropriate conditions.

---

# 7. Battery Management System (BMS) Selection

The BMS was selected based on the estimated battery-side current requirement.

## 7.1 Estimated Current

Using:

[
I=\frac{P}{V}
]

and the design power allowance:

[
P=80.35W
]

with a nominal battery voltage of:

[
V=14.8V
]

gives:

[
I=\frac{80.35}{14.8}
]

[
I\approx5.43A
]

The estimated continuous battery-side current was therefore approximately 5.43 A.

---

## 7.2 Safety Margin

A safety margin was applied to avoid selecting a BMS operating too close to its nominal current limit.

At 30% margin:

[
5.43\times1.30=7.06A
]

At 50% margin:

[
5.43\times1.50=8.15A
]

A BMS rated above these calculated values was therefore desirable.

---

## 7.3 Selected BMS

A **4S 20 A BMS** was selected for the project.

The 20 A rating provided substantial current headroom above the calculated approximately 5.43 A continuous design current and helped accommodate temporary current increases associated with motor operation.

---

# 8. Charge Controller Selection

## 8.1 Battery Capacity and Charging Current

The final battery pack capacity was approximately:

[
7.5Ah
]

Typical lithium-ion charging rates can be expressed using the C-rate.

For example:

### 0.2C

[
7.5\times0.2=1.5A
]

### 0.3C

[
7.5\times0.3=2.25A
]

### 0.5C

[
7.5\times0.5=3.75A
]

The project therefore considered a charging current in the approximate range of 2.25–3.75 A depending on the desired charging rate and cell specifications.

---

## 8.2 Solar Panel Current

For an 80 W panel operating at approximately 19 V:

[
I=\frac{80}{19}
]

[
I\approx4.21A
]

The theoretical maximum panel current was therefore approximately 4.21 A under the assumed operating point.

Because this could exceed the desired battery charging rate, current regulation was considered necessary.

---

## 8.3 XL4016 CC/CV Module

An **XL4016 adjustable buck converter** was used as the charge-control stage.

The module was configured to provide:

- Constant-voltage control
- Constant-current limiting

The intended battery charging voltage for the 4S lithium-ion pack was:

[
4\times4.2V=16.8V
]

The target output voltage was therefore approximately:

[
\boxed{16.8V}
]

The current limit could be adjusted to an appropriate charging current based on the selected charging strategy.

---

## 8.4 XL4016 Calibration

The voltage and current controls of the XL4016 were adjusted before connecting the battery.

### Voltage Calibration

A suitable DC input source was connected to the XL4016.

The output voltage was measured with a multimeter and adjusted toward the required charging voltage.

The target was:

[
16.8V
]

The charging path was then checked to account for voltage drop across protection components.

### Current Calibration

The current limit was adjusted using an appropriate test load and current measurement.

The target charging current was selected based on the battery capacity and desired charging rate.

### Safety Note

The XL4016 current-control calibration should be performed using an appropriate test load or manufacturer-recommended procedure. Direct short-circuit testing through a multimeter can damage the meter, its internal fuse, wiring, or the power supply and therefore should not be treated as the preferred general procedure.

---

# 8.5 Blocking Diode

A blocking Schottky diode was included to reduce the possibility of reverse current from the battery toward the charging circuit when solar generation was unavailable.

The project considered a high-current Schottky diode such as:

- 10SQ045
- 10SQ050

The selected diode needed to have sufficient reverse-voltage and current ratings for the actual charging path.

---

# 8.6 Fuse

A fuse was included as a protection device in the charging path.

The design considered a **5 A fuse**.

The purpose of the fuse was to provide protection against excessive current caused by wiring faults, short circuits, or component failure.

The final fuse rating should always be selected based on the actual conductor rating, expected operating current, and the manufacturer's recommendations for the connected components.

---

# 8.7 Night-Time Reverse Current Protection

The solar charging system required protection against undesirable current flow from the battery toward the charging circuit when solar input was unavailable.

The blocking diode provided a simple method of reducing this reverse-current path.

This was particularly important because the XL4016 is a buck converter rather than a dedicated solar MPPT charge controller.

---

# 9. Final Power Architecture

The final renewable power architecture was organized as follows:

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
              4S5P BATTERY PACK
                      │
                      ▼
             POWER DISTRIBUTION
                   TOWERS
                      │
          ┌───────────┼───────────┐
          │           │           │
          ▼           ▼           ▼
      BUCK 5V     BUCK 6V     OTHER DC
          │           │        LOADS
          │           │
          ▼           ▼
     ELECTRONICS    MOTORS
```

The battery pack stored energy generated by the solar panel.

The distribution system then routed the stored electrical energy to the appropriate subsystem.

Buck converters were used where necessary to reduce the battery voltage to the voltage required by individual loads.

---

# 10. Engineering Decisions

## 10.1 Why Lithium-Ion?

Lithium-ion 18650 cells were selected because they provided:

- High energy density
- Rechargeability
- Compact physical size
- Availability
- Relatively high energy storage compared with many alternative rechargeable cell types
- Suitability for portable robotic systems

The cells also allowed the battery to be configured in series and parallel to achieve the required voltage and capacity.

---

## 10.2 Why 4S5P?

The 4S configuration provided:

- 14.8 V nominal voltage
- 16.8 V maximum charging voltage

This voltage was suitable for the project's electrical architecture while allowing buck converters to produce the lower voltages required by the 5 V and 6 V loads.

The 5P configuration provided:

[
1.5Ah\times5=7.5Ah
]

which produced approximately:

[
14.8V\times7.5Ah=111Wh
]

of nominal stored energy.

---

## 10.3 Why Buck Converters?

The battery voltage was significantly higher than the voltage required by several loads.

Rather than connecting loads directly to the battery, buck converters were used to regulate the voltage.

This allowed:

- 5 V loads to receive approximately 5 V.
- 6 V loads to receive approximately 6 V.
- Different subsystems to operate from the same battery pack.

---

## 10.4 Why XL4016?

The XL4016 was selected because it provided an adjustable constant-current/constant-voltage function that could be configured for the 4S lithium-ion battery pack.

It was also relatively accessible and cost-effective for the prototype development environment.

However, it should be noted that an XL4016 buck converter is not equivalent to a dedicated MPPT solar charge controller. Its effectiveness depends on maintaining adequate solar-panel voltage above the battery charging voltage.

---

## 10.5 Why an 80 W Solar Panel?

The initial calculation produced a minimum estimated requirement of approximately 60 W.

An 80 W monocrystalline panel was selected instead to provide additional power margin.

The higher rating helped accommodate:

- Solar irradiance variation
- Panel losses
- Conversion losses
- Charging requirements
- Practical operating conditions

---

# 11. Lessons Learned

The renewable power subsystem demonstrated the importance of sizing an electrical system before selecting hardware.

The power calculation provided a structured basis for deciding:

- Battery configuration
- Number of cells
- BMS rating
- Solar panel capacity
- Charging current
- Voltage-conversion requirements

The project also demonstrated that theoretical calculations do not completely predict real-world system performance. Motor loads vary with mechanical resistance and operating conditions, solar output varies with environmental conditions, and electrical components introduce losses that may differ from nominal specifications.

One of the most important lessons was therefore the need to combine:

**Calculation → Component Selection → Construction → Measurement → Testing → Revision**

The final competition experience further reinforced the importance of reliability and endurance testing. Although the power system performed successfully throughout most of development and integration, the battery pack eventually failed during the competition presentation. This demonstrated that successful subsystem operation during development does not necessarily guarantee reliable operation under the stress and duration of a real demonstration.

Future versions should therefore include measured battery capacity testing, extended runtime testing, current logging, thermal monitoring, charging-cycle testing, and repeated full-system endurance tests before competition deployment.
