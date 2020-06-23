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

using FakeWorkspacePtr = std::shared_ptr<WorkspaceInterface>;

std::unique_ptr<WorkspaceStub> createFakeWorkspace(int devicesUsed = 10) {
    auto stub = std::make_unique<NiceMock<WorkspaceStub>>();
    ON_CALL(*stub, devicesUsed).WillByDefault(Return(devicesUsed));
    return stub;
}

class GetFramesTestFixture : public ::testing::TestWithParam<int> {};
INSTANTIATE_TEST_SUITE_P(VariousNumberOfDevicesUsed, GetFramesTestFixture, ::testing::Values(1, 8, 16129));

TEST_P(GetFramesTestFixture, getFrames_WorkspacePassed_SerialDataVectorHasTheSameNumberOfElementsAsDevicesUsed) {
    const int devicesUsed = GetParam();
    const FakeWorkspacePtr fakeWorkspace = createFakeWorkspace(devicesUsed);
    const FrameBuilder sut(fakeWorkspace);

    ASSERT_THAT(sut.getFrames(), SizeIs(devicesUsed));
}

TEST(FrameBuilderTestSuite, getFrames_ByDefault_SerialDataVectorIsFilledWithZeros) {
    const FakeWorkspacePtr fakeWorkspace = createFakeWorkspace();
    const FrameBuilder sut(fakeWorkspace);

    const std::pair<Register, uint8_t> expectedFrame(Register::NO_OP, 0x00);
    ASSERT_THAT(sut.getFrames(), Each(expectedFrame));
}

TEST(FrameBuilderTestSuite, fillAll_FramePassed_AllElementsInSerialDataEqualPassedFrame) {
    const FakeWorkspacePtr fakeWorkspace = createFakeWorkspace();
    FrameBuilder sut(fakeWorkspace);

    const std::pair<Register, uint8_t> framePassed(Register::DISPLAY_TEST, 0xFF);
    sut.fillAll(framePassed);

    const auto &actual = sut.getFrames();
    ASSERT_THAT(actual, AllOf(SizeIs(fakeWorkspace->devicesUsed()), Each(framePassed)));
}

}