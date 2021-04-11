//
// Created by breno on 4/7/21.
//

#include "Cpu.h"
#include "Instruction.h"
#include "../utils/utils.h"

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
//    Instruction instruction = {.word = this->load32(this->pc)};

// Usa a instrução previamente carregada
    Instruction instruction = this->nextInstruction;

//    Busca a proxima instrucao no PC
    this->nextInstruction = Instruction(this->load32(this->pc));

//    Incrementa PC
    this->pc += 4;

    this->decodeAndExecute(instruction);
}

void Cpu::reset() {
    this->pc = Cpu::PC_RESET_ADDR;
    this->nextInstruction = Instruction(0x0);
    this->sr = 0;

//    Lixo de memoria que pode ajudar a debugar
    std::fill(registers.begin(), registers.end(),0xdeadbeef);
    registers[0] = 0;
}

uint32_t Cpu::load32(uint32_t addr) {
    return this->interconnect->load32(addr);
}

//bool Cpu::checkAddOverflow(int32_t a, int32_t b, int32_t *result) {
//    if (a > 0 && b > INT32_MAX - a)
//        return true;
//
//    *result = a + b;
//    return false;
//}

// TODO: talvez fazer um sistema de log, buscar alguma lib
void Cpu::decodeAndExecute(Instruction& instruction) {
//    auto op = instruction.op();

    std::cout << "DEBUG WORD " << std::hex << instruction.word << std::endl;
    std::cout << "OP: " << std::hex << instruction.op() << std::endl;

    switch (instruction.op()) {
        case 0b001111:
            LUI(instruction);
            break;

        case 0b001101:
            ORI(instruction);
            break;

        case 0b101011:
            SW(instruction);
            break;

        case 0b001001:
            ADDIU(instruction);
            break;

        case 0b000000:
            switch (instruction.funct()) {
                case 0b000000:
                    SLL(instruction);
                    break;

                case 0b100101:
                    OR(instruction);
                    break;

                default:
                    std::cout << "unhandled instruction at function " << std::hex << instruction.word << std::endl;
                    std::exit(1);
            }
            break;

        case 0b000010:
            J(instruction);
            break;

        case 0b010000:
            COP0(instruction);
            break;

        case 0b000101:
            BNE(instruction);
            break;

        case 0b001000:
            ADDI(instruction);
            break;

        case 0b100011:
            LW(instruction);
            break;

        default:
            std::cout << "unhandled instruction " << std::hex << instruction.word << std::endl;
            std::exit(1);
    }

}

void Cpu::COP0(Instruction &instruction) {
    std::cout << "parsing COP0 instruction " << std::hex << instruction.word << std::endl;

    switch (instruction.rs()) {
        case 0b00100:
            MTC0(instruction);
            break;

        default:
            std::cout << "unhandled cop0 instruction " << std::hex << instruction.word << std::endl;
            std::exit(1);
    }
}

void Cpu::MTC0(Instruction &instruction) {
    std::cout << "INSTRUCTION MTC0" << std::endl;

    auto cpuRt = instruction.rt();
    auto copRd = instruction.rd();

    auto value = this->reg(cpuRt);

    switch (copRd) {
        case 12:
            this->sr = value;
            break;

        default:
            std::cout << "unhandled cop0 register: " << copRd << std::endl;
            std::exit(1);
    }
}

void Cpu::branch(uint32_t offset) {
//    Offsets de branch sempre sao multiplicados por 4 devido ao alinhamento da memoria
    offset = offset << 2;

    uint32_t pc = this->pc;

    pc += offset;

//    Precisamos compensar o add hardcoded em runNextInstruction
    pc -= 4;

    this->pc = pc;
}

void Cpu::LUI(Instruction& instruction) {
    auto immediate = instruction.imm();
    auto rt = instruction.rt();

//    Os 16 bits baixo sao setados pra 0
    auto value = immediate << 16;

    this->setReg(rt, value);
}


void Cpu::ORI(Instruction& instruction) {
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
//    Cache isolado, ignorar write
    if ((this->sr & 0x10000) != 0) {
        std::cout << "ignoring SW while cache is isolated" << std::endl;
        return;
    }

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

void Cpu::ADDIU(Instruction &instruction) {
    auto imm = instruction.imm();
    auto rt = instruction.rt();
    auto rs = instruction.rs();
    auto value = this->reg(rs) + imm;

    this->setReg(rt, value);
}

void Cpu::J(Instruction &instruction) {
    auto imm = instruction.addr();

    this->pc = (this->pc & 0xf0000000) | (imm << 2);
}

void Cpu::OR(Instruction &instruction) {
    auto rd = instruction.rd();
    auto rs = instruction.rs();
    auto rt = instruction.rt();

    auto value = this->reg(rs) | this->reg(rt);

    this->setReg(rd, value);
}

void Cpu::BNE(Instruction &instruction) {
//    auto imm = instruction.signedImm();
    auto rs = instruction.rs();
    auto rt = instruction.rt();

    if (this->reg(rs) != this->reg(rt)) {
        this->branch(instruction.imm());
    }
}

void Cpu::ADDI(Instruction &instruction) {
    auto imm = (int32_t) instruction.signedImm();
    auto rt = instruction.rt();
    auto rs = instruction.rs();

    auto signedRsValue = (int32_t) this->reg(rs);
    int32_t result = 0xdeadbeff;

//    auto didOverflow = utils::checkedAddOverflow(signedRsValue, imm, &result);
    auto didOverflow = utils::checkedAddOverflow(&result, signedRsValue, imm);
    if (didOverflow) {
        std::cout << "ADDI overflow" << std::endl;
        std::exit(1);
    }

    auto value = (uint32_t) result;

    std::cout << "DEBUG ADDDI IMM = " << std::dec << imm << std::endl;
    std::cout << "REG " << std::dec << rt << std::endl;

    this->setReg(rt, value);
}

void Cpu::LW(Instruction &instruction) {
    if (this->sr & 0x10000 != 0) {
//        Cache isolado, ignorando LW
        std::cout << "ignorando LW enquanto o cache estiver isolado" << std::endl;
        return;
    }

    auto imm = instruction.signedImm();
    auto rt = instruction.rt();
    auto rs = instruction.rs();

    auto addr = this->reg(rs) + imm;
    auto value = this->load32(addr);

    this->setReg(rt, value);
}
