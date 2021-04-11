//
// Created by breno on 4/7/21.
//

#include "Bios.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

Bios::Bios() {
    std::cout << "Criando BIOS" << std::endl;

    std::ifstream file("SCPH1001.BIN", std::ios::binary);

    file.seekg(0, std::ios::end);
    auto fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::cout << "filesize = " << fileSize << std::endl;

    if (fileSize > Bios::SIZE) {
        std::cout << "Tamanho da BIOS invalida" << std::endl;
        std::exit(1);
    }

//    TODO: tirar cast
    file.read((char *) this->biosData.data(), this->biosData.size());
}

Bios::~Bios() {
    std::cout << "Destroindo BIOS" << std::endl;
}

uint32_t Bios::load32(uint32_t offset) {
    uint32_t b0 = this->biosData[offset + 0];
    uint32_t b1 = this->biosData[offset + 1];
    uint32_t b2 = this->biosData[offset + 2];
    uint32_t b3 = this->biosData[offset + 3];

    return b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
}
