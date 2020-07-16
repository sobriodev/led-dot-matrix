#include "FrameBuilder.h"
#include "NullPointerException.h"

namespace leddotmatrix {

FrameBuilder::FrameBuilder(WorkspacePtr workspacePtr):
        workspace(std::move(workspacePtr)) {
    if (!workspace) {
        throw NullPointerException();
    }
    initSerialFrames();
}

void FrameBuilder::initSerialFrames() {
    serialFrames = Frames(workspace->devicesUsed());

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