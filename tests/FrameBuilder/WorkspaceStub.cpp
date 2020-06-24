#include "WorkspaceStub.h"

namespace leddotmatrix {

WorkspaceStub::WorkspaceInterfacePointer WorkspaceStub::createFakeWorkspace(int devicesUsed) {
    auto stub = std::make_unique<::testing::NiceMock<WorkspaceStub>>();
    ON_CALL(*stub, devicesUsed).WillByDefault(::testing::Return(devicesUsed));
    return stub;
}

}

