//
// Created by breno on 4/7/21.
//

#include "Instruction.h"
#include <cstdint>

Instruction::Instruction(uint32_t word) {
    this->word = word;
}

uint32_t Instruction::op() {
    return this->word >> 26;
}

uint32_t Instruction::rs() {
    return (this->word >> 21) & 0x1f;
}

// correto
uint32_t Instruction::rt() {
    return (this->word >> 16) & 0x1f;
}

uint32_t Instruction::rd() {
    return (this->word >> 11) & 0x1f;
}

uint32_t Instruction::shamt() {
    return (this->word >> 6) & 0x1f;
}

uint32_t Instruction::funct() {
    return this->word & 0x1f;
}

uint32_t Instruction::imm() {
    return this->word & 0xffff;
//    auto value = (uint16_t) (this->word & 0xffff);
//
//    return (uint32_t) value;
}

uint32_t Instruction::signedImm() {
    auto value = (int16_t) (this->word & 0xffff);

    return (uint32_t) value;
}

uint32_t Instruction::addr() {
    return this->word & 0x3ffffff;
}

//
//uint32_t Instruction::function() {
//    return this->word >> 26;
//}
//
//uint32_t Instruction::regIndex() {
//    return (this->word >> 16) & 0x1f;
//}
//
//uint32_t Instruction::immediate() {
//    return this->word & 0xffff;
//}
//
//uint32_t Instruction::regSrc() {
//    return (this->word >> 16) & 0x1f;
//}
