#include "NullPointerException.h"

namespace leddotmatrix {

NullPointerException::NullPointerException() noexcept: std::runtime_error(MESSAGE) {}

}