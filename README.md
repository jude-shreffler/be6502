# be6502
A software implementation of [Ben Eater's](eater.net/6502) 6502 breadboard computer

# Usage
`be6502 <rom>` will run a specified rom image on the VM

# Details
Uses the mos6502 library to run the cpu itself which has been slightly modified to run the VM at 1MHz. Currently, ROM, RAM, and the 65c22 Versatile Interface Adapter (VIA) are implemented, with the following memory map:

```
0x0000 - 0x5FFF: RAM
0x6000 - 0x600F: VIA
0x6010 - 0x7FFF: RAM
0x8000 - 0xFFFF: ROM
```

ROM images must be 0x8000 bytes, with a reset vector at 0x7FFC (0xFFFC to the 6502)

# Planned
- LCD Display
- UART
- VGA interface
- Improved command line options to toggle which peripherals to use