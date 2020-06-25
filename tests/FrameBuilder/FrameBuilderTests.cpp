#include <memory>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "WorkspaceStub.h"
#include "FrameBuilder.h"

namespace leddotmatrix {

using ::testing::SizeIs;
using ::testing::Each;
using ::testing::AllOf;

using FakeWorkspacePtr = std::shared_ptr<WorkspaceInterface>;

static auto createSampleSpiFrame() {
    static FrameBuilder::Frame sampleFrame(Register::DISPLAY_TEST, 0xFF);
    return sampleFrame;
}

class GetFramesTestFixture : public ::testing::TestWithParam<int> {};
INSTANTIATE_TEST_SUITE_P(VariousNumberOfDevicesUsed, GetFramesTestFixture, ::testing::Values(1, 8, 16129));

TEST_P(GetFramesTestFixture, getFrames_WorkspacePassed_SerialDataVectorHasTheSameNumberOfElementsAsDevicesUsed) {
    const int devicesUsed = GetParam();
    const FakeWorkspacePtr fakeWorkspace = WorkspaceStub::createFakeWorkspace(devicesUsed);
    const FrameBuilder sut(fakeWorkspace);

    ASSERT_THAT(sut.getFrames(), SizeIs(devicesUsed));
}

TEST(FrameBuilderTestSuite, getFrames_ByDefault_SerialDataVectorIsFilledWithZeros) {
    const FakeWorkspacePtr fakeWorkspace = WorkspaceStub::createFakeWorkspace();
    const FrameBuilder sut(fakeWorkspace);

    const std::pair<Register, uint8_t> expectedFrame(Register::NO_OP, 0x00);
    ASSERT_THAT(sut.getFrames(), Each(expectedFrame));
}

TEST(FrameBuilderTestSuite, fillAll_FramePassed_AllElementsInSerialDataEqualPassedFrame) {
    const FakeWorkspacePtr fakeWorkspace = WorkspaceStub::createFakeWorkspace();
    FrameBuilder sut(fakeWorkspace);

    const auto framePassed = createSampleSpiFrame();
    sut.fillAll(framePassed);

    const auto &actual = sut.getFrames();
    ASSERT_THAT(actual, AllOf(SizeIs(fakeWorkspace->devicesUsed()), Each(framePassed)));
}

TEST(FrameBuilderTestSuite, fillOne_WrongDeviceHandle_NothingIsDoneAndFalseIsReturned) {
    const FakeWorkspacePtr fakeWorkspace = WorkspaceStub::createInvalidFakeWorkspace();
    FrameBuilder sut(fakeWorkspace);

    const auto frame = createSampleSpiFrame();
    const int dummyDeviceHandle = 1;
    const auto &framesBefore = sut.getFrames();

    ASSERT_FALSE(sut.fillOne(dummyDeviceHandle, frame));
    ASSERT_EQ(sut.getFrames(), framesBefore);
}

TEST(FrameBuilderTestSuite, fillOne_CorrectDeviceHandle_FrameIsSetAndTrueIsReturned) {
    const FakeWorkspacePtr fakeWorkspace = WorkspaceStub::createFakeWorkspace(5);
    FrameBuilder sut(fakeWorkspace);

    const auto framePassed = createSampleSpiFrame();
    const int deviceHandle = 0;

    ASSERT_TRUE(sut.fillOne(deviceHandle, framePassed));
    ASSERT_EQ(sut.getFrames().at(deviceHandle), framePassed);
}

}