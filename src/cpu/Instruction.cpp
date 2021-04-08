//
// Created by breno on 4/7/21.
//

#include "Instruction.h"

Instruction::Instruction(uint32_t word) {
    this->word = word;
}

uint32_t Instruction::function() {
    return this->word >> 26;
}

uint32_t Instruction::regIndex() {
    return (this->word >> 16) & 0x1f;
}

uint32_t Instruction::immediate() {
    return this->word & 0xffff;
}

uint32_t Instruction::regSrc() {
    return (this->word >> 16) & 0x1f;
}
