//
// Created by breno on 4/7/21.
//

#include "Range.h"

range::Range::Range(uint32_t begin, uint32_t length) {
    this->begin = begin;
    this->length = length;
}

// Retorna offset a partir do comeco se addr pertence a regiao, ou -1 caso nao pertenca
uint32_t range::Range::contains(uint32_t addr) {
    if ((addr >= this->begin) && addr < (this->begin + this->length)) {
        return addr - this->begin;
    }

//    TODO: Entender melhor essa função e encontrar um retorno melhor para representar erro
    return -1;
}
