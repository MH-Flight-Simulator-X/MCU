![MH Flight Simulator X](/docs/images/MHFS_Color.png)

# Flight Simulator on Custom Hardware (TDT4295)

This project is part of the TDT4295 course at NTNU and focuses on building a flight simulator on custom hardware. This repository contains the source code for the MCU part of the project, utilizing the Silicon Labs EFM32GG chipset.

## Overview

The flight simulator uses the **EFM32GG842F1024** MCU to handle user inputs, updates to the segment displays, and communication with custom hardware components like SPI communication to an FPGA and various control interfaces. The goal is to create a basic flight simulation program using optimized low-level programming.

## Project Features

- **Real-time flight simulation** with a simple physics simulation.
- **Path-following opponents** that act as targets for the shooting functionality.
- **User inputs** using physical components like joystick and buttons to control in-flight functions such as throttle, roll, and pitch.
- **Data communication** between the MCU and FPGA using a predefined SPI protocol.

## Development Environment

### Dependencies

- **Simplicity Studio** by Silicon Labs for development, building, and debugging.
- **Silicon Labs Gecko SDK** integrated within Simplicity Studio.

## Building the Project

The project is built using Silicon Labs **Simplicity Studio**:

1. **Clone the repository** to your local machine:

   ```bash
   git clone https://github.com/yourusername/flight-sim-hardware.git
   cd flight-sim-hardware
   ```

2. **Open Simplicity Studio** and import the project:

   - Go to `File` > `Import` > `Simplicity Studio Project`.
   - Select the cloned repository and open the project.

3. **Build the project**:
   - Select the desired build configuration (e.g., `Debug`).
   - Click the **hammer** icon to compile the project.
   - The resulting binary will be generated in the output folder as a `.hex` file.

## Flashing the Firmware to the Custom PCB

### Requirements

- **Giant Gecko Development Board** to act as a debugger.
- **SWO debug header** connection to the custom PCB.

### Flashing Instructions

1. **Connect the Giant Gecko Board** to your PC via USB.
2. **Connect the custom PCB** to the Giant Gecko Board:

   - Use the **20-pin connector** to link the Giant Gecko to the custom PCB.
   - Ensure that the custom PCB is powered on.

3. **Configure the Giant Gecko Board in Simplicity Studio**:

   - In Simplicity Studio, go to the `Debug Adapters` section.
   - Select the connected Giant Gecko board.
   - Set the `Debug Mode` to **OUT**.

4. **Set the target device**:

   - In Simplicity Studio, ensure that the target part is set to **EFM32GG842F1024**.

5. **Flash the hex file**:

   - Open the **Simplicity Commander** tool within Simplicity Studio.
   - Select the Giant Gecko board and navigate to the **Flash Utility**.
   - Load the compiled `.hex` file and press **Flash**.

6. **Debugging**:
   - Open the **SWO Terminal** in Simplicity Studio.
   - Press **Start** to see debug output from the MCU.
