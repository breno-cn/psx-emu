//
// Created by breno on 4/7/21.
//

#ifndef PSX_INTERCONNECT_H
#define PSX_INTERCONNECT_H

#include "../bios/Bios.h"

class Interconnect {

private:
    Bios *bios;

public:
    Interconnect(Bios *bios);
    ~Interconnect();

    uint32_t load32(uint32_t addr);
};


#endif //PSX_INTERCONNECT_H
