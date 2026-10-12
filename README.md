# Custom AXI4-Lite IP Using Vitis HLS

<p align="center">
  <img src="https://img.shields.io/badge/FPGA-Zynq--7000-blue?style=for-the-badge" alt="Zynq-7000">
  <img src="https://img.shields.io/badge/AMD-Vitis%20HLS-orange?style=for-the-badge" alt="Vitis HLS">
  <img src="https://img.shields.io/badge/Vivado-2026.1-red?style=for-the-badge" alt="Vivado">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge" alt="C++">
</p>

## Overview

This project demonstrates the design, synthesis, packaging, and integration of a custom AXI4-Lite hardware IP using **Vitis High-Level Synthesis (HLS)** and **AMD Vivado Design Suite 2026.1**.

The accelerator computes the mathematical function:

\[
Y=A^2+B^2
\]

The algorithm is implemented in C++, synthesized into hardware using Vitis HLS, packaged as reusable IP, and integrated with the Zynq Processing System through an AXI4-Lite interface in Vivado.

The project demonstrates the FPGA hardware-acceleration workflow, from high-level C++ code to RTL generation, IP integration, timing analysis, and FPGA bitstream generation.

> **Hardware status:** Synthesis, IP packaging, Vivado integration, implementation, and bitstream generation were completed. Physical execution on the PYNQ-Z2 board was not performed because the board was unavailable.

## Objectives

- Implement a mathematical computation in synthesizable C++.
- Verify functionality through C simulation and a testbench.
- Convert the algorithm into RTL using Vitis HLS.
- Analyze hardware interfaces and synthesis reports.
- Package the generated design as reusable custom IP.
- Integrate the IP with the Zynq Processing System through AXI4-Lite.
- Complete Vivado design validation, implementation, and bitstream generation.
- Study FPGA resource utilization and estimated timing performance.

## Problem Statement

Design a custom hardware accelerator that accepts two input values, \(A\) and \(B\), and computes the sum of their squares.

\[
Y=A^2+B^2
\]

The accelerator must be synthesized using Vitis HLS, packaged as a custom AXI4-Lite IP core, and integrated into a Zynq-based FPGA system using Vivado.

## System Architecture

```text
       C++ Algorithm
              |
              v
       Vitis HLS Design
              |
              v
       C Simulation
              |
              v
         C Synthesis
              |
              v
       RTL / IP Generation
              |
              v
       Custom AXI4-Lite IP
              |
              v
       Vivado IP Integrator
              |
              v
     Zynq Processing System
              |
              v
       Design Implementation
              |
              v
        Bitstream Generation
              |
              v
       FPGA Hardware Deployment
```

The final hardware deployment stage was not performed on the physical PYNQ-Z2 board.

## Hardware and Software Requirements

### Hardware

- PYNQ-Z2 FPGA development board (target platform; unavailable during this experiment)
- USB programming cable
- PC or laptop

### Software

- AMD Vitis Unified IDE 2026.1
- AMD Vivado Design Suite 2026.1
- C/C++ testbench and simulation environment

## Target FPGA

| Parameter | Specification |
|---|---|
| Development board | PYNQ-Z2 |
| FPGA family | Zynq-7000 |
| Target device | `xc7z020clg400-1` |
| Hardware interface | AXI4-Lite |
| HLS input language | C++ |
| Hardware output | RTL and packaged IP |

## Implementation Workflow

### 1. HLS Design Entry

The computation was implemented in C++ using Vitis HLS. The design accepts two inputs and returns the sum of their squares.

### 2. C Simulation

A C++ testbench was used to validate the functional behavior of the algorithm before hardware synthesis.

| Input A | Input B | Expected Output |
|---:|---:|---:|
| 3 | 4 | 25 |
| 5 | 12 | 169 |
| 10 | 20 | 500 |

### 3. C Synthesis

Vitis HLS converted the C++ algorithm into synthesizable hardware and generated reports describing the estimated timing, hardware interfaces, and FPGA resource utilization.

### 4. IP Packaging

The synthesized design was packaged as a reusable IP core with an AXI4-Lite control interface.

### 5. Vivado Integration

The custom IP was imported into Vivado and integrated with the Zynq Processing System using the IP Integrator block design.

Design validation completed successfully without errors or critical warnings.

### 6. Implementation and Bitstream Generation

The integrated design proceeded through Vivado implementation and bitstream generation. The bitstream was generated successfully.

**Note:** Bitstream generation confirms that the design flow completed; it does not establish that the accelerator was executed or functionally validated on the physical board.

## Hardware Interface

The generated HLS IP exposes an AXI4-Lite control interface and registers for communicating with the computation.

| Interface element | Purpose |
|---|---|
| AXI4-Lite control interface | Memory-mapped communication with the processor |
| Input register A | Supplies the first input value |
| Input register B | Supplies the second input value |
| Output register / return value | Provides the computed result |
| Control and status registers | Control execution and report completion status |

## Synthesis Results

The following values were recorded from the Vitis HLS synthesis report.

| Parameter | Reported value |
|---|---:|
| Target clock period | 10 ns |
| Estimated clock period | 6.912 ns |
| Estimated frequency | 144.68 MHz |
| Reported latency | 30 ns |
| Initiation interval | 4 |
| LUTs | 396 |
| Flip-flops (FFs) | 606 |
| DSP slices | 6 |
| Block RAM (BRAM) | 0 |
| UltraRAM (URAM) | 0 |
| Timing status | Passed |

*These are reported synthesis estimates, not measurements from physical-board execution.*

### Resource Analysis

- **LUTs:** Implement combinational logic and supporting control circuitry.
- **Flip-flops:** Store state and intermediate information.
- **DSP slices:** Implement arithmetic operations efficiently.
- **BRAM and URAM:** Not utilized because the design does not require large data buffers or arrays.

## Verification and Results

The computation was verified using C simulation with the following test vectors:

| A | B | Calculation | Result |
|---:|---:|---|---:|
| 3 | 4 | \(3^2+4^2\) | 25 |
| 5 | 12 | \(5^2+12^2\) | 169 |
| 10 | 20 | \(10^2+20^2\) | 500 |

The results matched the expected mathematical outputs.

The custom IP was successfully synthesized, packaged, integrated with the Zynq Processing System, validated in Vivado, and used to generate an FPGA bitstream.

Physical-board execution remains unverified.

## Repository Structure

```text
custom-axi-ip-vitis-hls/
├── README.md
├── src/
│   └── compute.cpp
├── tb/
│   └── compute_tb.cpp
├── docs/
│   └── Custom-AXI-Report.pdf
├── images/
│   ├── hls-source.png
│   ├── synthesis-report.png
│   ├── axi-interface.png
│   ├── vivado-block-design.png
│   └── bitstream-generation.png
├── results/
│   └── synthesis-results.md
├── .gitignore
└── LICENSE
```

Only include source files, screenshots, and result files that are actually available in the repository.

## Applications

- FPGA-based hardware acceleration
- Custom peripheral and IP development
- Embedded processing systems
- Arithmetic accelerators
- Prototyping computational hardware
- Learning AXI4-Lite interfaces and HLS-based FPGA design

## Learning Outcomes

- Converting C++ algorithms into RTL using high-level synthesis.
- Understanding AXI4-Lite register-based communication.
- Packaging custom IP for reuse in Vivado.
- Integrating custom accelerators with a Zynq Processing System.
- Interpreting HLS timing, latency, and resource-utilization reports.
- Following the FPGA synthesis, implementation, and bitstream-generation flow.

## Future Improvements

- Execute the generated accelerator on the PYNQ-Z2 board.
- Access the IP registers from the ARM Processing System.
- Verify the hardware output against software calculations.
- Measure actual execution time and compare it with software.
- Explore pipelining, loop optimization, and resource optimization.
- Extend the accelerator to more complex mathematical functions.

## Documentation

The complete experiment report, including source-code screenshots, synthesis reports, AXI interface details, Vivado integration, timing analysis, and bitstream-generation evidence, is available in the `docs/` directory.

## Author

**Chinmay N. Yalawatti**

Electronics and Communication Engineering  
KLE Technological University, BVB Campus

### Tools and Technologies

`Vitis HLS` · `Vivado` · `C++` · `AXI4-Lite` · `RTL` · `Zynq-7000` · `FPGA Hardware Acceleration`

---

*This project is part of my ongoing exploration of FPGA design, VLSI systems, custom hardware IP, and hardware acceleration.*
