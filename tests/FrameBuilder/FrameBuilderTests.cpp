#include <memory>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "WorkspaceStub.h"
#include "FrameBuilder.h"

namespace leddotmatrix {

using ::testing::NiceMock;
using ::testing::SizeIs;
using ::testing::Return;

using WorkspaceStubPtr = std::unique_ptr<WorkspaceInterface>;

WorkspaceStubPtr makeWorkspaceStub() {
    auto stub = std::make_unique<NiceMock<WorkspaceStub>>();
    ON_CALL(*stub, isSizeValid).WillByDefault(Return(true));
    ON_CALL(*stub, getWidth).WillByDefault(Return(4));
    ON_CALL(*stub, getHeight).WillByDefault(Return(2));
    ON_CALL(*stub, devicesUsed).WillByDefault(Return(8));

    return std::move(stub);
}

TEST(FrameBuilderTestSuite, getSerialData_Workspace4x2Passed_DataVectorHas16Elements) {
    const FrameBuilder sut(makeWorkspaceStub());

    ASSERT_THAT(sut.getSerialData(), SizeIs(16));
}

}