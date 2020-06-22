#include <memory>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "WorkspaceStub.h"
#include "FrameBuilder.h"

namespace leddotmatrix {

using ::testing::NiceMock;
using ::testing::SizeIs;
using ::testing::Return;
using ::testing::Each;
using ::testing::AllOf;

class GetFramesTestFixture : public ::testing::TestWithParam<int> {};
INSTANTIATE_TEST_SUITE_P(VariousNumberOfDevicesUsed, GetFramesTestFixture, ::testing::Values(1, 8, 16129));

TEST_P(GetFramesTestFixture, getFrames_WorkspacePassed_SerialDataVectorHasTheSameNumberOfElementsAsDevicesUsed) {
    const int devicesUsed = GetParam();
    auto stub = std::make_unique<NiceMock<WorkspaceStub>>();
    ON_CALL(*stub, devicesUsed).WillByDefault(Return(devicesUsed));

    const FrameBuilder sut(std::move(stub));

    ASSERT_THAT(sut.getFrames(), SizeIs(devicesUsed));
}

TEST(FrameBuilderTestSuite, getFrames_ByDefault_SerialDataVectorIsFilledWithZeros) {
    auto stub = std::make_unique<NiceMock<WorkspaceStub>>();
    ON_CALL(*stub, devicesUsed).WillByDefault(Return(10));

    const FrameBuilder sut(std::move(stub));
    const std::pair<Register, uint8_t> expectedFrame(Register::NO_OP, 0x00);
    ASSERT_THAT(sut.getFrames(), Each(expectedFrame));
}

TEST(FrameBuilderTestSuite, fillAll_FramePassed_AllElementsInSerialDataEqualPassedFrame) {
    auto stub = std::make_unique<NiceMock<WorkspaceStub>>();
    ON_CALL(*stub, devicesUsed).WillByDefault(Return(10));

    FrameBuilder sut(std::move(stub));

    const std::pair<Register, uint8_t> framePassed(Register::DISPLAY_TEST, 0xFF);
    sut.fillAll(framePassed);
    const auto &actual = sut.getFrames();

    ASSERT_THAT(actual, AllOf(SizeIs(10), Each(framePassed)));
}

}