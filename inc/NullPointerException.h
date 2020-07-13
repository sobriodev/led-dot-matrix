#ifndef LEDDOTMATRIX_NULLPOINTEREXCEPTION_H
#define LEDDOTMATRIX_NULLPOINTEREXCEPTION_H

#include <stdexcept>

namespace leddotmatrix {

class NullPointerException : public std::runtime_error {
public:
    static constexpr const char *MESSAGE = "Null pointer is not allowed here";
    NullPointerException();
};

}

#endif //LEDDOTMATRIX_NULLPOINTEREXCEPTION_H
