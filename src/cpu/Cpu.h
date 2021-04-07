//
// Created by breno on 4/7/21.
//

#ifndef PSX_CPU_H
#define PSX_CPU_H

#include "../interconnect/Interconnect.h"

#include <cstdint>

class Cpu {
private:
    uint32_t pc;
    Interconnect *interconnect;

public:
    static constexpr uint32_t PC_RESET_ADDR = 0xbfc00000;

    Cpu(Interconnect *interconnect);
    ~Cpu();

    void runNextInstruction();
    void reset();
    uint32_t load32(uint32_t addr);

    void decodeAndExecute(uint32_t instruction);
};


#endif //PSX_CPU_H
