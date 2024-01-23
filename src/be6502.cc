#include "mos6502.h"
#include "mos65c22.h"
#include <fstream>

using namespace std;

uint8_t rom[0x8000];
uint8_t ram[0x8000];
mos65c22 interface;

uint8_t MemoryRead(uint16_t address);
void MemoryWrite(uint16_t address, uint8_t value);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: be6502 <rom>" << endl;
        return 1;
    }

    // load the rom
    ifstream romFile;
    romFile.open(argv[1], ios::binary);
    if (!romFile.is_open())
    {
        cout << "Unable to open rom file: " << argv[1] << endl;
        return 1;
    }
    romFile.read((char *)rom, 0x8000);
    romFile.close();

    mos6502 cpu(MemoryRead, MemoryWrite);
    cpu.Reset();
    cpu.RunEternally(10);

    return 0;
}

uint8_t MemoryRead(uint16_t address)
{
    if (address >= 0x6000 && address <= 0x600F)
    {
        // address the 65c22
        uint8_t registerSelect = address & 0x0F;
        return interface.readCall(registerSelect);
    }
    else if (address >= 0x8000)
    {
        return rom[address - 0x8000];
    }
    else
    {
        return ram[address];
    }
}

void MemoryWrite(uint16_t address, uint8_t value)
{
    if (address >= 0x6000 && address <= 0x600F)
    {
        // address the 65c22
        uint8_t registerSelect = address & 0x0F;
        interface.writeCall(registerSelect, value);
    }
    else if (address >= 0x8000)
    {
        rom[address - 0x8000] = value;
    }
    else
    {
        ram[address] = value;
    }
}