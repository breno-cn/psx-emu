//
// Created by breno on 4/7/21.
//

#ifndef PSX_CPU_H
#define PSX_CPU_H

#include <cstdint>

class Cpu {
private:
    uint32_t pc;

public:
    static constexpr uint32_t PC_RESET_ADDR = 0xbfc00000;

    Cpu();
    ~Cpu();

    void runNextInstruction();
    void reset();
};


#endif //PSX_CPU_H
