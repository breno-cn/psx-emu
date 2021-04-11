//
// Created by breno on 4/10/21.
//

#include <cstdint>
#include "utils.h"

bool utils::checkedAddOverflow(int32_t a, int32_t b, int32_t *result) {
    if (a > 0 && b > INT32_MAX - a)
        return true;

    *result = a + b;
    return false;
}
