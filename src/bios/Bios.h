//
// Created by breno on 4/7/21.
//

#ifndef PSX_BIOS_H
#define PSX_BIOS_H

#include <cstdint>
#include <array>

class Bios {

public:
//    512Kb de memória para a BIOS
    static constexpr uint32_t SIZE = 512 * 1024;
    Bios();
    ~Bios();

    uint32_t load32(uint32_t offset);

private:
    std::array<uint8_t, Bios::SIZE> biosData;

};


#endif //PSX_BIOS_H
