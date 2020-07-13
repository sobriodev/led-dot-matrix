#include "NullPointerException.h"

namespace leddotmatrix {

NullPointerException::NullPointerException() : std::runtime_error(MESSAGE) {}

}