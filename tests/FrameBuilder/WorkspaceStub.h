#ifndef LEDDOTMATRIX_WORKSPACESTUB_H
#define LEDDOTMATRIX_WORKSPACESTUB_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "WorkspaceInterface.h"

namespace leddotmatrix {

class WorkspaceStub : public WorkspaceInterface {
public:
    MOCK_METHOD(bool, isSizeValid, (int size), (const, override));
    MOCK_METHOD(bool, isDeviceHandleValid, (int deviceHandle), (const, override));
    MOCK_METHOD(int, getWidth, (), (const, override));
    MOCK_METHOD(int, getHeight, (), (const, override));
    MOCK_METHOD(int, devicesUsed, (), (const, override));
};

}

#endif //LEDDOTMATRIX_WORKSPACESTUB_H
