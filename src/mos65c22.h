#ifndef MOS65C22_H
#define MOS65C22_H

#include <stdint.h>
#include <iostream>
#include <bitset>

class mos65c22
{
private:
    uint8_t ddra;
    uint8_t ddrb;
    uint8_t ira;
    uint8_t irb;
    uint8_t ora;
    uint8_t orb;

    uint8_t readIrb();
    void writeOrb(uint8_t data);
    uint8_t readIra();
    void writeOra(uint8_t data);
    void writeDdrb(uint8_t data);
    void writeDdra(uint8_t data);

public:
    mos65c22();
    uint8_t readCall(uint8_t registerSelect);
    void writeCall(uint8_t registerSelect, uint8_t value);
};

#endif