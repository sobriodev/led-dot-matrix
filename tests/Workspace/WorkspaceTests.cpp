#include "gtest/gtest.h"

#include "Workspace.h"

namespace leddotmatrix {

TEST(WorkspaceTestSuite, makeRectangle_WidthLessThanOne_WidthEqualsToOne) {
    const auto workspace = Workspace::makeRectangle(0, 1);
    ASSERT_EQ(1, workspace.getWidth());
}

TEST(WorkspaceTestSuite, makeRectangle_HeightLessThanOne_HeightEqualsToOne) {
    const auto workspace = Workspace::makeRectangle(1, 0);
    ASSERT_EQ(1, workspace.getHeight());
}

TEST(WorkspaceTestSuite, makeRectangle_WidthTooBigGiven_WidthLimitedToMaxWidth) {
    const auto workspace = Workspace::makeRectangle(129, 1);
    ASSERT_EQ(128, workspace.getWidth());
}

}
