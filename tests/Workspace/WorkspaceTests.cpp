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

}
