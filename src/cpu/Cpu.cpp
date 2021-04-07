//
// Created by breno on 4/7/21.
//

#include "Cpu.h"

#include <iostream>
#include <cstdint>

Cpu::Cpu() {
    std::cout << "Criando CPU" << std::endl;
    this->reset();
}

Cpu::~Cpu() {
    std::cout << "Destroindo CPU" << std::endl;
}

void Cpu::runNextInstruction() {
//  Busca a instrução do PC
    uint32_t instruction = this->pc;

//    Incrementa PC
    this->pc += 4;

//    this->decodeAndExecute(instruction);
}

void Cpu::reset() {
    this->pc = Cpu::PC_RESET_ADDR;
}
