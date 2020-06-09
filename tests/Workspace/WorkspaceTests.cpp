#include "gtest/gtest.h"
#include "Workspace.h"

namespace leddotmatrix {

Workspace createDummyWorkspace() {
    return Workspace::makeRectangle(1, 1);
}

class InvalidSizeWorkspaceTestFixture : public ::testing::TestWithParam<int> {};
INSTANTIATE_TEST_SUITE_P(InvalidSizes, InvalidSizeWorkspaceTestFixture,
                         ::testing::Values(-100, -57, -1, 0, 129, 130, 150, 211));

class ValidSizeWorkspaceTestFixture : public ::testing::TestWithParam<int> {};
INSTANTIATE_TEST_SUITE_P(ValidSizes, ValidSizeWorkspaceTestFixture,
                         ::testing::Values(1, 2, 10, 11, 100, 121, 127, 128));

TEST_P(InvalidSizeWorkspaceTestFixture, isSizeValid_InvalidSize_FalseReturned) {
    const int invalidSize = GetParam();
    const auto actual = createDummyWorkspace().isSizeValid(invalidSize);
    ASSERT_FALSE(actual);
}

TEST_P(ValidSizeWorkspaceTestFixture, isSizeValid_ValidSize_TrueReturned) {
    const int validSize = GetParam();
    const auto actual = createDummyWorkspace().isSizeValid(validSize);
    ASSERT_TRUE(actual);
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

}
