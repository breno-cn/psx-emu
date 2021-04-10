//
// Created by breno on 4/7/21.
//

#ifndef PSX_CPU_H
#define PSX_CPU_H

#include "../interconnect/Interconnect.h"
#include "Instruction.h"

#include <cstdint>
#include <array>

class Cpu {
private:
    uint32_t pc;
    std::array<uint32_t, 32> registers;

    Interconnect *interconnect;

public:
    static constexpr uint32_t PC_RESET_ADDR = 0xbfc00000;

    Cpu(Interconnect *interconnect);
    ~Cpu();

    void runNextInstruction();
    void reset();
    uint32_t load32(uint32_t addr);
    void store32(uint32_t addr, uint32_t value);

    void decodeAndExecute(Instruction& instruction);

//    Getters e setters para registradores de proposito geral
    void setReg(uint32_t index, uint32_t value);
    uint32_t reg(uint32_t index);

//    Opcodes

//  LOAD UPPER IMMEDIATE
    void LUI(Instruction& instruction);
    void ORI(Instruction& instruction);
    void SW(Instruction& instruction);
    void SLL(Instruction& instruction);
    void ADDIU(Instruction& instruction);
};


#endif //PSX_CPU_H
