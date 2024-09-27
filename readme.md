# MCU Part of TDT4295 Project

## Build

To build this project, you need to have the following downloaded and placed in the root directory:

- Gecko SDK
- GNU Arm toolchain

Build by running from the root directory:

```
make -f flying_soft.Makefile -j12
```

## Flash:

To flash the file onto the MCU, we use Segger's J-Link Software by running each of these commands in terminal:

```
JLinkExe -device EFM32GG990F1024 -if SWD -speed 4000 -autoconnect 1
```

```
LoadFile /path/to/flying_soft.hex
```

```
g
```

# Sleeptimer Bare Metal

This example application demonstrates use of timers in a bare metal environment. The application uses low frequency RTC (Real Time Clock) peripheral to create periodic and one-shot timers. The on-board button used to control the timers stop and start operation. The status will be shown on the virtual COM serial port console.

This application has three timers:

- Periodic timer - Toggles LED0 when timeout
- One-shot timer - Toggles LED1 when timeout
- Periodic timer - Prints remaining time of periodic & one-shot timers

Once you flash the application both timers will be started. Button0 is used to start/stop the periodic timer and button1 is used to start/stop the one-shot timer. The status timer will never be stopped and prints status of other two timers periodically when timeout occurs.

## Requirements

Silicon Labs board with 2 buttons and 2 LEDs.

## Resources

- [AN0005: Real Time Counters](https://www.silabs.com/documents/public/application-notes/AN0005-EFM32-RTC.pdf)
- [AN0014: EFM32 Timers](https://www.silabs.com/documents/public/application-notes/AN0014.pdf)
