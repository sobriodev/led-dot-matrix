#ifndef LEDDOTMATRIX_WORKSPACESTUB_H
#define LEDDOTMATRIX_WORKSPACESTUB_H

#include <memory>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "WorkspaceInterface.h"

namespace leddotmatrix {

class WorkspaceStub : public WorkspaceInterface {
public:
    using WorkspaceInterfacePointer = std::unique_ptr<WorkspaceInterface>;

    MOCK_METHOD(bool, isSizeValid, (int size), (const, override));
    MOCK_METHOD(bool, isDeviceHandleValid, (int deviceHandle), (const, override));
    MOCK_METHOD(int, getWidth, (), (const, override));
    MOCK_METHOD(int, getHeight, (), (const, override));
    MOCK_METHOD(int, devicesUsed, (), (const, override));

    static WorkspaceInterfacePointer createFakeWorkspace(int devicesUsed = 10);
    static WorkspaceInterfacePointer createInvalidFakeWorkspace();
};

}

#endif //LEDDOTMATRIX_WORKSPACESTUB_H
