#include "gtest/gtest.h"

#include "Workspace.h"

namespace leddotmatrix {

class WorkspaceTestFixture : public ::testing::TestWithParam<int> {};
INSTANTIATE_TEST_SUITE_P(InvalidSizes, WorkspaceTestFixture, ::testing::Values(-100, -57, -1, 0, 129, 130, 150, 211));

TEST_P(WorkspaceTestFixture, isSizeValid_InvalidSize_FalseReturned) {
    const int invalidSize = GetParam();
    const auto actual = Workspace::isSizeValid(invalidSize);
    ASSERT_FALSE(actual);
}

TEST(WorkspaceTestSuite, makeRectangle_SizesEqualToZero_Rectangle1x1Received) {
    const auto workspace = Workspace::makeRectangle(0, 0);
    ASSERT_EQ(1, workspace.getWidth());
    ASSERT_EQ(1, workspace.getHeight());
}

TEST(WorkspaceTestSuite, makeRectangle_SizesTooBig_Rectangle128x128Received) {
    const auto workspace = Workspace::makeRectangle(129, 129);
    ASSERT_EQ(128, workspace.getWidth());
    ASSERT_EQ(128, workspace.getHeight());
}

TEST(WorkspaceTestSuite, makeRectangle_ValidRectangle_TheSameRectangleReceived) {
    const auto workspace = Workspace::makeRectangle(1, 127);
    ASSERT_EQ(1, workspace.getWidth());
    ASSERT_EQ(127, workspace.getHeight());
}

TEST(WorkspaceTestSuite, isSizeValid_ValidSize_TrueReturned) {
    const auto result = Workspace::isSizeValid(125);
    ASSERT_TRUE(result);
}

}
