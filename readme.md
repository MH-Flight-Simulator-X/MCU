# MCU Part of TDT4295 Project

This is one of three components developed for TDT4295: Computer Design Project at NTNU, alongside an FPGA implementation and a PCB.

## Build

To build this project, you need to have the following downloaded and placed in the root directory:

- Gecko SDK
- GNU Arm toolchain

Build by running from the root directory:

```
make -f flying_soft.Makefile -j12
```

## Flash

To flash the file onto the MCU, we first connect to the MCU using Segger's J-Link Software in terminal:

```
JLinkExe -device EFM32GG990F1024 -if SWD -speed 4000 -autoconnect 1
```

Remove the existing software:

```
erase
```

Load the file we just built:

```
loadfile {path to project}/build/debug/flying_soft.hex
```

Start the CPU:

```
g
```
