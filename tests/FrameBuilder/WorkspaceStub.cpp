#include "WorkspaceStub.h"

namespace leddotmatrix {

using ::testing::Return;
using ::testing::NiceMock;

WorkspaceStub::WorkspaceInterfacePointer WorkspaceStub::createFakeWorkspace(int devicesUsed) {
    auto stub = std::make_unique<NiceMock<WorkspaceStub>>();
    ON_CALL(*stub, devicesUsed).WillByDefault(Return(devicesUsed));
    return stub;
}

WorkspaceStub::WorkspaceInterfacePointer WorkspaceStub::createInvalidFakeWorkspace() {
    auto stub = std::make_unique<NiceMock<WorkspaceStub>>();
    ON_CALL(*stub, isSizeValid).WillByDefault(Return(false));
    ON_CALL(*stub, isDeviceHandleValid).WillByDefault(Return(false));
    return stub;
}

}

