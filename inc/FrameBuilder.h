#ifndef LEDDOTMATRIX_FRAMEBUILDER_H
#define LEDDOTMATRIX_FRAMEBUILDER_H

#include <utility>
#include <cstdint>
#include <vector>
#include <memory>

#include "Registers.h"
#include "WorkspaceInterface.h"

namespace leddotmatrix {

class FrameBuilder {
    using WorkspaceInterfacePtr = std::unique_ptr<WorkspaceInterface>;
    using Frame = std::pair<Register, uint8_t>;
    using Frames = std::vector<Frame>;
    using SerialData = std::vector<uint8_t>;
public:
    explicit FrameBuilder(WorkspaceInterfacePtr workspaceInterfacePtr) noexcept;
    [[nodiscard]] SerialData getSerialData() const;
private:

    WorkspaceInterfacePtr workspace;
    Frames serialFrames;
};

}

#endif //LEDDOTMATRIX_FRAMEBUILDER_H
