#include "mos65c22.h"

mos65c22::mos65c22()
{
    ddra = 0;
    ddrb = 0;
    ira = 0;
    irb = 0;
    ora = 0;
    orb = 0;
}

uint8_t mos65c22::readCall(uint8_t registerSelect)
{
    switch (registerSelect)
    {
    case 0x00:
        return readIrb();
        break;
    case 0x01:
        return readIra();
        break;
    default:
        return 0;
        break;
    }
}

void mos65c22::writeCall(uint8_t registerSelect, uint8_t value)
{
    switch (registerSelect)
    {
    case 0x00:
        writeOrb(value);
        break;
    case 0x01:
        writeOra(value);
        break;
    case 0x02:
        writeDdrb(value);
        break;
    case 0x03:
        writeDdra(value);
        break;
    default:
        break;
    }
}

uint8_t mos65c22::readIrb()
{
    return irb & !ddrb;
}

void mos65c22::writeOrb(uint8_t data)
{
    orb = data;
    uint8_t orbBuffer = orb & ddrb;
    std::cout << "\r"
              << "orb: " << std::bitset<8>(orb);
}

uint8_t mos65c22::readIra()
{
    return ira & !ddra;
}

void mos65c22::writeOra(uint8_t data)
{
    ora = data;
    uint8_t oraBuffer = ora & ddra;
}

void mos65c22::writeDdrb(uint8_t data)
{
    ddrb = data;
}

void mos65c22::writeDdra(uint8_t data)
{
    ddra = data;
}