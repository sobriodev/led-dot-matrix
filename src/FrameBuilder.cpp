#include "FrameBuilder.h"

namespace leddotmatrix {

FrameBuilder::FrameBuilder(WorkspaceInterfacePtr workspaceInterfacePtr) noexcept:
        workspace(std::move(workspaceInterfacePtr)), serialFrames(workspace->devicesUsed()) {
    initFramesVector();
}

FrameBuilder::SerialData FrameBuilder::getSerialData() const {
    SerialData response;
    for (auto iter = serialFrames.crbegin(); iter != serialFrames.crend(); ++iter) {
       response.push_back(static_cast<uint8_t>(iter->first));
       response.push_back(iter->second);
    }
    return response;
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