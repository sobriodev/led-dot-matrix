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
public:
    using WorkspaceInterfacePtr = std::shared_ptr<WorkspaceInterface>;
    using Frame = std::pair<Register, uint8_t>;
    using Frames = std::vector<Frame>;
    using SerialData = std::vector<uint8_t>;

    explicit FrameBuilder(WorkspaceInterfacePtr workspaceInterfacePtr) noexcept;
    [[nodiscard]] const Frames &getFrames() const;
    void fillAll(const Frame &frame);
    bool fillOne(int deviceHandle, const Frame &frame);
private:
    void initSerialFrames();

    WorkspaceInterfacePtr workspace;
    Frames serialFrames;
};

}

#endif //LEDDOTMATRIX_FRAMEBUILDER_H
