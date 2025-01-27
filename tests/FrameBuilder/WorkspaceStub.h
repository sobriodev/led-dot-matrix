#ifndef LEDDOTMATRIX_WORKSPACESTUB_H
#define LEDDOTMATRIX_WORKSPACESTUB_H

#include <memory>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Workspace.h"

namespace leddotmatrix {

using ::testing::Return;
using ::testing::NiceMock;

class WorkspaceStub : public Workspace {
public:
    using WorkspacePtr = std::unique_ptr<Workspace>;

    MOCK_METHOD(bool, isSizeValid, (int size), (const, override));
    MOCK_METHOD(bool, isDeviceHandleValid, (int deviceHandle), (const, override));
    MOCK_METHOD(int, getWidth, (), (const, override));
    MOCK_METHOD(int, getHeight, (), (const, override));
    MOCK_METHOD(int, devicesUsed, (), (const, override));

    static WorkspacePtr createFakeWorkspace(int devicesUsed = 10) {
        auto stub = std::make_unique<NiceMock<WorkspaceStub>>();
        ON_CALL(*stub, devicesUsed).WillByDefault(Return(devicesUsed));
        ON_CALL(*stub, isSizeValid).WillByDefault(Return(true));
        ON_CALL(*stub, isDeviceHandleValid).WillByDefault(Return(true));
        return stub;
    }

    static WorkspacePtr createInvalidFakeWorkspace() {
        auto stub = std::make_unique<NiceMock<WorkspaceStub>>();
        ON_CALL(*stub, isSizeValid).WillByDefault(Return(false));
        ON_CALL(*stub, isDeviceHandleValid).WillByDefault(Return(false));
        return stub;
    }
};

}

#endif //LEDDOTMATRIX_WORKSPACESTUB_H
