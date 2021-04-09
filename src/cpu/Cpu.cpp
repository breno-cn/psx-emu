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
//    Instruction instruction(this->load32(this->pc));
    Instruction instruction = {.word = this->load32(this->pc)};

//    Incrementa PC
    this->pc += 4;

    this->decodeAndExecute(instruction);
}

void Cpu::reset() {
    this->pc = Cpu::PC_RESET_ADDR;

//    Lixo de memoria que pode ajudar a debugar
    std::fill(registers.begin(), registers.end(),0xdeadbeef);
    registers[0] = 0;
}

uint32_t Cpu::load32(uint32_t addr) {
    return this->interconnect->load32(addr);
}

// TODO: talvez fazer um sistema de log, buscar alguma lib
void Cpu::decodeAndExecute(Instruction& instruction) {
//    uint32_t function = instruction.function();
    uint32_t function = instruction.word >> 26;

    switch (function) {
        case 0b001111:
            LUI(instruction);
            break;

        case 0b001101:
            ORI(instruction);
            break;

        case 0b101011:
            SW(instruction);
            break;

        default:
            std::cout << "unhandled instruction " << std::hex << instruction.word << std::endl;
            std::exit(1);
    }

}

void Cpu::LUI(Instruction instruction) {
//    auto immediate = instruction.immediate();
//    auto regIndex = instruction.regIndex();
    auto immediate = instruction.iType.imm;
    auto regIndex = instruction.iType.rt;

//    Os 16 bits baixo sao setados pra 0
    auto value = immediate << 16;

    this->setReg(regIndex, value);
}


void Cpu::ORI(Instruction instruction) {
//    auto immediate = instruction.immediate();
//    auto regIndex = instruction.regIndex();
//    auto s = instruction.regSrc();
    auto immediate = instruction.iType.imm;
    auto regIndex = instruction.iType.rt;
    auto s = instruction.iType.rs;

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

void Cpu::store32(uint32_t addr, uint32_t value) {
    this->interconnect->store32(addr, value);
}

void Cpu::SW(Instruction instruction) {
//    i
//    t
//    s

//    auto immediate = instruction.immediate();
//    auto to = instruction.regIndex();
//    auto src = instruction.regSrc();
    auto immediate = instruction.iType.imm;
    auto rt = instruction.iType.rt;
    auto rs = instruction.iType.rs;

    auto addr = this->reg(rs) + immediate;
    auto value = this->reg(rt);

    this->store32(addr, value);
}
