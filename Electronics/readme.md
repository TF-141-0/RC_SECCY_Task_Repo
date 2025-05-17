# PCB Design Task – Arduino Nano + MPU9250 + Power Regulation + LEDs

## Objective
Design a PCB circuit that includes the following components:

- Arduino Nano
- MPU9250 IMU Sensor Module
- Voltage Regulator to provide a stable 5V output from a 3S Li-ion battery pack  
  (11.1V nominal, made of 18650 cells)
- Two LEDs

---

## Deliverables

The schematic and PCB layout must ensure proper, logical, and real-world-ready electrical connections between all components. This includes best practices like:
- Pull-up resistors (e.g., for I²C)
- Decoupling capacitors
- Stable power routing
- Grounding discipline

---

### 1. Schematic Diagram (30 Points)
- Clean and well-organized schematic
- Proper component names and designators (e.g., R1, C2, U1)
- Labels for all net connections (e.g., VCC, GND, SDA, SCL)
- Fully logical and complete circuit for functional behavior

---

### 2. PCB Layout and Gerber Files (70 Points)
- Compact, clean layout on a single or double-layer PCB
- Good routing practices:
  - Short trace lengths
  - Proper signal/power separation
  - Solid grounding
- Perform and pass DRC (Design Rule Check)
- Export manufacturer-ready Gerber files

---

## Final Submission Should Include:
- Schematic.pdf
- Project.kicad_pcb
- Gerber/ directory with all layer files
- Optional: 3D renders or BOM (.csv) if available

---

Note: Use KiCad or a compatible open-source EDA tool.
