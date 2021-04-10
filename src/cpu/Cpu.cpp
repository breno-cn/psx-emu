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
//    Instruction instruction = {.word = this->load32(this->pc)};

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
    auto op = instruction.op();

    std::cout << "DEBUG WORD " << std::hex << instruction.word << std::endl;

    switch (op) {
        case 0b001111:
            LUI(instruction);
            break;

        case 0b001101:
            ORI(instruction);
            break;

        case 0b101011:
            SW(instruction);
            break;

        case 0b000000:
            switch (instruction.funct()) {
                case 0b000000:
                    SLL(instruction);
                    break;

                default:
                    std::cout << "unhandled instruction at function " << std::hex << instruction.word << std::endl;
                    std::exit(1);
            }
            break;

        default:
            std::cout << "unhandled instruction " << std::hex << instruction.word << std::endl;
            std::exit(1);
    }

}

void Cpu::LUI(Instruction& instruction) {
//    auto immediate = instruction.iType.imm;
//    auto regIndex = instruction.iType.rt;

    auto immediate = instruction.imm();
    auto rt = instruction.rt();

//    Os 16 bits baixo sao setados pra 0
    auto value = immediate << 16;

    this->setReg(rt, value);
}


void Cpu::ORI(Instruction& instruction) {
//    auto immediate = instruction.iType.imm;
//    auto regIndex = instruction.iType.rt;
//    auto s = instruction.iType.rs;

    auto immediate = instruction.imm();
    auto rt = instruction.rt();
    auto rs = instruction.rs();

    auto value = this->reg(rs) | immediate;

    this->setReg(rt, value);
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

void Cpu::SW(Instruction& instruction) {
    auto immediate = instruction.signedImm();
    auto rt = instruction.rt();
    auto rs = instruction.rs();

    auto addr = this->reg(rs) + immediate;
    auto value = this->reg(rt);

    this->store32(addr, value);
}

void Cpu::SLL(Instruction& instruction) {
    auto shamt = instruction.shamt();
    auto rt = instruction.rt();
    auto rd = instruction.rd();

    std::cout << "TESTING " << shamt << " " << rt << " " << rd << std::endl;

    auto value = this->reg(rt) << shamt;
    this->setReg(rd, value);
}
