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

    if (addr % 4 != 0) {
        std::cout << "unaligned store32 at " << std::hex << addr << std::endl;
        std::exit(1);
    }

    std::cout << "unhandled store32 at addr " << std::hex << addr << " with value " << std::hex << value  << std::endl;
    std::exit(1);
}
