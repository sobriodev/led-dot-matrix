#include "FrameBuilder.h"

namespace leddotmatrix {

FrameBuilder::FrameBuilder(WorkspaceInterfacePtr workspaceInterfacePtr) noexcept:
        workspace(std::move(workspaceInterfacePtr)), serialFrames(workspace->devicesUsed()) {
    initSerialFrames();
}

void FrameBuilder::initSerialFrames() {
    const Frame noOperationFrame(Register::NO_OP, 0);
    fillAll(noOperationFrame);
}

void FrameBuilder::fillAll(const FrameBuilder::Frame &frame) {
    for (auto &entry : serialFrames) {
        entry = frame;
    }
}

bool FrameBuilder::fillOne(int deviceHandle, const FrameBuilder::Frame &frame) {
    return workspace->isDeviceHandleValid(deviceHandle);
}

const FrameBuilder::Frames &FrameBuilder::getFrames() const {
    return serialFrames;
}

}