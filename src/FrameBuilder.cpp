#include "FrameBuilder.h"
#include "NullPointerException.h"

namespace leddotmatrix {

FrameBuilder::FrameBuilder(WorkspacePtr workspacePtr):
        workspace(std::move(workspacePtr)) {
    if (!workspace) {
        throw NullPointerException();
    }
    serialFrames = Frames(workspace->devicesUsed());
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
    if (!workspace->isDeviceHandleValid(deviceHandle)) {
        return false;
    }
    serialFrames.at(deviceHandle) = frame;
    return true;
}

const FrameBuilder::Frames &FrameBuilder::getFrames() const {
    return serialFrames;
}

}