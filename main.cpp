#include <iostream>

#include "src/bios/Bios.h"
#include "src/cpu/Cpu.h"
#include "src/interconnect/Interconnect.h"

int main() {
    Bios bios;
    Interconnect interconnect(&bios);
    Cpu cpu(&interconnect);

    while (true) {
        cpu.runNextInstruction();
    }

    return 0;
}
