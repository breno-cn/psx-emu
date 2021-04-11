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
    Instruction nextInstruction;

    std::array<uint32_t, 32> registers;

//    registrador 12 de Cop0: Status Register
    uint32_t sr;

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

//    check overflow

//  Retorna true caso haja overflow
//    static bool checkAddOverflow(int32_t a, int32_t b, int32_t *result);

//    Coprocessador 0
    void COP0(Instruction& instruction);
    void MTC0(Instruction& instruction);

    void branch(uint32_t offset);

//    Opcodes
    void LUI(Instruction& instruction);
    void ORI(Instruction& instruction);
    void SW(Instruction& instruction);
    void SLL(Instruction& instruction);
    void ADDIU(Instruction& instruction);
    void J(Instruction& instruction);
    void OR(Instruction& instruction);
    void BNE(Instruction& instruction);
    void ADDI(Instruction& instruction);
};


#endif //PSX_CPU_H
