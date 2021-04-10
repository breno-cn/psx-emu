//
// Created by breno on 4/7/21.
//

#ifndef PSX_INSTRUCTION_H
#define PSX_INSTRUCTION_H

#include <cstdint>

//typedef union {
//    struct rType {
//        uint32_t funct: 6;
//        uint32_t shamt: 5;
//        uint32_t rd: 5;
//        uint32_t rt: 5;
//        uint32_t rs: 5;
//        uint32_t op: 6;
//    } rType;
//
//    struct iType {
//        uint32_t imm: 16;
//        uint32_t rt: 5;
//        uint32_t rs: 5;
//        uint32_t op: 6;
//    } iType;
//
//    struct jType {
//        uint32_t addr: 26;
//        uint32_t op: 6;
//    } jType;
//
//    uint32_t word;
//} Instruction;

class Instruction {
public:
    uint32_t word;

    Instruction(uint32_t word);

    uint32_t op();
    uint32_t rs();
    uint32_t rt();
    uint32_t rd();
    uint32_t shamt();
    uint32_t funct();
    uint32_t imm();
    uint32_t signedImm();
    uint32_t addr();

//    uint32_t function();
//    uint32_t regIndex();
//    uint32_t immediate();
//    uint32_t regSrc();
};


#endif //PSX_INSTRUCTION_H
