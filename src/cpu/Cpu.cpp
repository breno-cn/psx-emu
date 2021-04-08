//
// Created by breno on 4/7/21.
//

#include "Cpu.h"
#include "Instruction.h"

#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <algorithm>

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
//    uint32_t instruction = this->load32(this->pc);
    Instruction instruction(this->load32(this->pc));

//    Incrementa PC
    this->pc += 4;

    this->decodeAndExecute(instruction);
}

void Cpu::reset() {
    this->pc = Cpu::PC_RESET_ADDR;

//    Lixo de memoria que pode ajudar a debugar
    std::fill(registers.begin(), registers.end(), 0xd0d0d0d0);
    registers[0] = 0;
}

uint32_t Cpu::load32(uint32_t addr) {
    return this->interconnect->load32(addr);
}

// TODO: talvez fazer um sistema de log, buscar alguma lib
void Cpu::decodeAndExecute(Instruction& instruction) {
    uint32_t function = instruction.function();

    switch (function) {
        case 0b001111:
            LUI(instruction);
            break;

        case 0b001101:
            ORI(instruction);
            break;

        default:
            std::cout << "unhandled instruction " << std::hex << instruction.word << std::endl;
            std::exit(1);
    }

}

void Cpu::LUI(Instruction instruction) {
    auto immediate = instruction.immediate();
    auto regIndex = instruction.regIndex();

//    Os 16 bits baixo sao setados pra 0
    uint32_t value = immediate << 16;

    this->setReg(regIndex, value);
}


void Cpu::ORI(Instruction instruction) {
    auto immediate = instruction.immediate();
    auto regIndex = instruction.regIndex();
    auto s = instruction.regSrc();
    auto value = this->reg(s) | immediate;

    this->setReg(regIndex, value);
}


void Cpu::setReg(uint32_t index, uint32_t value) {
    this->registers[index] = value;

//    Caso especial, $zero é sempre zero
//    Lembrar de verificar se isso realmente é mais barato que fazer um if
    this->registers[0] = 0;
}

uint32_t Cpu::reg(uint32_t index) {
    return this->registers[index];
}
