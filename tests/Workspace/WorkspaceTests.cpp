#include "gtest/gtest.h"

#include "Workspace.h"

namespace leddotmatrix {

TEST(WorkspaceTestSuite, constructor_widthLessThanOne_widthEqualsToOne) {
    const auto workspace = Workspace::makeRectangle(0, 1);
    ASSERT_EQ(1, workspace.getWidth());
}

TEST(WorkspaceTestSuite, constructor_heightLessThanOne_heightEqualsToOne) {
    const auto workspace = Workspace::makeRectangle(1, 0);
    ASSERT_EQ(1, workspace.getHeight());
}

}
