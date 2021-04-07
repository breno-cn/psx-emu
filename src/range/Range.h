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
}


#endif //PSX_RANGE_H
