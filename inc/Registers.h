#ifndef LEDDOTMATRIX_REGISTERS_H
#define LEDDOTMATRIX_REGISTERS_H

#include <cstdint>

namespace leddotmatrix {

enum class Register : uint8_t {
    NO_OP = 0x00,
    DIGIT0,
    DIGIT1,
    DIGIT2,
    DIGIT3,
    DIGIT4,
    DIGIT5,
    DIGIT6,
    DIGIT7,
    DECODE_MODE,
    INTENSITY,
    SCAN_LIMIT,
    SHUTDOWN,
    DISPLAY_TEST = 0x0F
};

}

#endif //LEDDOTMATRIX_REGISTERS_H
