//
// Created by breno on 4/7/21.
//

#include "Interconnect.h"

#include <cstdlib>
#include <iostream>

#include "../range/Range.h"

Interconnect::Interconnect(Bios *bios) {
    std::cout << "Criando Interconnect" << std::endl;

    this->bios = bios;
}

uint32_t Interconnect::load32(uint32_t addr) {

    if (addr % 4 != 0) {
        std::cout << "unaligned load32 at " << std::hex << addr << std::endl;
        std::exit(1);
    }

    uint32_t offset = range::BIOS.contains(addr);

    if (offset == -1) {
        std::cout << "unhandled fetch32 at address " << std::hex << addr << std::endl;
        std::exit(0);
    }

    std::cout << "offset = " << std::hex << offset << std::endl;
    return this->bios->load32(offset);
}

Interconnect::~Interconnect() {
    std::cout << "Destroindo Interconnect" << std::endl;
}

void Interconnect::store32(uint32_t addr, uint32_t value) {
    std::cout << "DEBUG store32 " << std::hex << addr << " " << std::hex << value << std::endl;

    if (addr % 4 != 0) {
        std::cout << "unaligned store32 at " << std::hex << addr << std::endl;
        std::exit(1);
    }

    uint32_t offset = range::MEM_CONTROL.contains(addr);
    if (offset != -1) {
        std::cout << "DEBUG store32 " << offset << " " << std::hex << addr << std::endl;
        switch (offset) {
            case 0:
                if (value != 0x1f000000) {
                    std::cout << "bad expansion base at " << std::hex << value << std::endl;
                    std::exit(1);
                }
                break;

            case 4:
                if (value != 0x1f802000) {
                    std::cout << "bad expansion base at " << std::hex << value << std::endl;
                    std::exit(1);
                }
                break;

            default:
                std::cout << "unhandled write to MEM_CONTROL " << std::hex << value << std::endl;
        }

        return;
    }

    offset = range::RAM_SIZE.contains(addr);
    if (offset != -1) {
        std::cout << "unhandled write to RAM_SIZE at addr " << std::hex << addr << " with offset " << std::hex << offset << std::endl;
        return;
    }

    std::cout << "unhandled store32 at addr " << std::hex << addr << " with value " << std::hex << value  << std::endl;
    std::exit(1);
}
