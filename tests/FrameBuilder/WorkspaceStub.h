#ifndef LEDDOTMATRIX_WORKSPACESTUB_H
#define LEDDOTMATRIX_WORKSPACESTUB_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Workspace.h"

namespace leddotmatrix {

class WorkspaceStub : public Workspace {
public:
    MOCK_METHOD(bool, isSizeValid, (int size), (const, override));
    MOCK_METHOD(int, getWidth, (), (const, override));
    MOCK_METHOD(int, getHeight, (), (const, override));
};

}

#endif //LEDDOTMATRIX_WORKSPACESTUB_H
