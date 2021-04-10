//
// Created by breno on 4/7/21.
//

#ifndef PSX_RANGE_H
#define PSX_RANGE_H

#include <cstdint>
#include "../cpu/Cpu.h"
#include "../bios/Bios.h"

namespace range {
    class Range {

    private:
        uint32_t begin;
        uint32_t length;

    public:
        Range(uint32_t begin, uint32_t length);

        uint32_t contains(uint32_t addr);

//    static constexpr Range BIOS = Range(Cpu::PC_RESET_ADDR, Bios::SIZE);

    };

    static Range BIOS = Range(Cpu::PC_RESET_ADDR, Bios::SIZE);

//    TODO: constantes apropriadas pra MEM_CONTROL
    static Range MEM_CONTROL = Range(0x1f801000, 36);

//    TODO: constantes para RAM_SIZE
//    TODO: etudar esse registrador, parece nao ser necessario emular ele para o ps1, apenas
//          se fosse emular um processador MIPS completo
    static Range RAM_SIZE = Range(0x1f801060, 4);
}


#endif //PSX_RANGE_H
