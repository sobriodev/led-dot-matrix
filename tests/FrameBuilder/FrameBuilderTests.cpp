#include <memory>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "WorkspaceStub.h"
#include "FrameBuilder.h"

namespace leddotmatrix {

using ::testing::NiceMock;
using ::testing::SizeIs;
using ::testing::Return;

class GetSerialDataTestFixture : public ::testing::TestWithParam<int> {};
INSTANTIATE_TEST_SUITE_P(VariousNumberOfDevicesUsed, GetSerialDataTestFixture, ::testing::Values(1, 8, 16129));

TEST_P(GetSerialDataTestFixture, getSerialData_WorkspacePassed_SerialDataVectorHasTwiceAsManyElementsAsDevicesUsed) {
    const int devicesUsed = GetParam();
    auto stub = std::make_unique<NiceMock<WorkspaceStub>>();
    ON_CALL(*stub, devicesUsed).WillByDefault(Return(devicesUsed));

    const FrameBuilder sut(std::move(stub));

    const auto expected = 2 * devicesUsed;
    ASSERT_THAT(sut.getSerialData(), SizeIs(expected));
}

}