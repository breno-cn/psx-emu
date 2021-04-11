//
// Created by breno on 4/7/21.
//

#ifndef PSX_INSTRUCTION_H
#define PSX_INSTRUCTION_H

#include <cstdint>

class Instruction {
public:
    uint32_t word;

    Instruction() = default;
    Instruction(uint32_t word);

    uint32_t copOpcode();

    uint32_t op();
    uint32_t rs();
    uint32_t rt();
    uint32_t rd();
    uint32_t shamt();
    uint32_t funct();
    uint32_t imm();
    uint32_t signedImm();
    uint32_t addr();
};


#endif //PSX_INSTRUCTION_H
