#include "gtest/gtest.h"

#include "Workspace.h"

namespace leddotmatrix {

TEST(WorkspaceTestSuite, constructor_widthLessThanOne_widthEqualsToOne) {
    const auto workspace = Workspace::makeRectangle(0, 1);
    ASSERT_EQ(1, workspace.getWidth());
}

}
