#ifndef LEDDOTMATRIX_FRAMEBUILDERINTERFACE_H
#define LEDDOTMATRIX_FRAMEBUILDERINTERFACE_H

#include <utility>
#include <cstdint>
#include <vector>
#include "Registers.h"

namespace leddotmatrix {

class FrameBuilderInterface {
public:
    using Frame = std::pair<Register, uint8_t>;
    using Frames = std::vector<Frame>;

    [[nodiscard]] virtual const Frames &getFrames() const = 0;
    virtual ~FrameBuilderInterface() noexcept = default;
};

}

#endif //LEDDOTMATRIX_FRAMEBUILDERINTERFACE_H
