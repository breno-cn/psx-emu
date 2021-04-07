//
// Created by breno on 4/7/21.
//

#include "Cpu.h"

#include <iostream>
#include <cstdint>
#include <cstdlib>

Cpu::Cpu(Interconnect *interconnect) {
    std::cout << "Criando CPU" << std::endl;

    this->interconnect = interconnect;
    this->reset();
}

Cpu::~Cpu() {
    std::cout << "Destroindo CPU" << std::endl;
}

void Cpu::runNextInstruction() {
//  Busca a instrução do PC
    uint32_t instruction = this->load32(this->pc);

//    Incrementa PC
    this->pc += 4;

    this->decodeAndExecute(instruction);
}

void Cpu::reset() {
    this->pc = Cpu::PC_RESET_ADDR;
}

uint32_t Cpu::load32(uint32_t addr) {
    return this->interconnect->load32(addr);
}

void Cpu::decodeAndExecute(uint32_t instruction) {
    std::cout << "unhandled instruction " << std::hex << instruction << std::endl;
    std::exit(1);
}
