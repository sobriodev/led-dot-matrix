#include "FrameBuilder.h"

namespace leddotmatrix {

FrameBuilder::FrameBuilder(WorkspaceInterfacePtr workspaceInterfacePtr) noexcept:
        workspace(std::move(workspaceInterfacePtr)), serialFrames(workspace->devicesUsed()) {
    initFramesVector();
}

void FrameBuilder::initFramesVector() {
    for (auto &frame : serialFrames) {
        frame = Frame(Register::NO_OP, 0);
    }
}

void FrameBuilder::fillAll(const FrameBuilder::Frame &frame) {
    for (auto &entry : serialFrames) {
        entry = frame;
    }
}

const FrameBuilder::Frames &FrameBuilder::getFrames() const {
    return serialFrames;
}

}