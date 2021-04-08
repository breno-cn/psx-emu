//
// Created by breno on 4/7/21.
//

#ifndef PSX_INSTRUCTION_H
#define PSX_INSTRUCTION_H

#include <cstdint>

class Instruction {
public:
    uint32_t word;

    Instruction(uint32_t word);

    uint32_t function();
    uint32_t regIndex();
    uint32_t immediate();
    uint32_t regSrc();
};


#endif //PSX_INSTRUCTION_H
