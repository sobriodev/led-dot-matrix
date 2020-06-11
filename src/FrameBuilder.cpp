#include "FrameBuilder.h"

namespace leddotmatrix {

FrameBuilder::FrameBuilder(WorkspaceInterfacePtr workspaceInterfacePtr) noexcept:
        workspace(std::move(workspaceInterfacePtr)), serialFrames(workspace->devicesUsed()) {}

FrameBuilder::SerialData FrameBuilder::getSerialData() const {
    SerialData response;
    for (auto iter = serialFrames.crbegin(); iter != serialFrames.crend(); ++iter) {
       response.push_back(static_cast<uint8_t>(iter->first));
       response.push_back(iter->second);
    }
    return response;
}

}