#include "gtest/gtest.h"

#include "Workspace.h"

namespace leddotmatrix {

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

TEST(WorkspaceTestSuite, isSizeValid_SizeEqualsToZero_FalseReturned) {
    const auto result = Workspace::isSizeValid(0);
    ASSERT_FALSE(result);
}

TEST(WorkspaceTestSuite, isSizeValid_SizeLessThanZero_FalseReturned) {
    const auto result = Workspace::isSizeValid(-100);
    ASSERT_FALSE(result);
}

TEST(WorkspaceTestSuite, isSizeValid_SizeGreaterThanMaxSize_FalseReturned) {
    const auto result = Workspace::isSizeValid(129);
    ASSERT_FALSE(result);
}

}
