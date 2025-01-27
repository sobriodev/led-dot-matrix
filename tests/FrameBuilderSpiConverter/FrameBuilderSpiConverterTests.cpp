#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Registers.h"
#include "FrameBuilder.h"
#include "FrameBuilderSpiConverter.h"
#include "FrameBuilderStub.h"
#include "NullPointerException.h"

using testing::SizeIs;
using testing::Each;
using testing::ElementsAre;

namespace leddotmatrix {

TEST(FrameBuilderSpiConverterTestSuite, FrameBuilderSpiConverter_NullFrameBuilder_ExceptionIsThrown) {
    ASSERT_THROW(FrameBuilderSpiConverter(nullptr), NullPointerException);
}

TEST(FrameBuilderSpiConverterTestSuite,
     convertToSpiData_ByDefault_SpiDataVectorHasTwiceAsManyElementsAsFrameBuilderFramesVector) {
    const FrameBuilderSpiConverter::FrameBuilderPtr fakeFrameBuilder = FrameBuilderStub::createFixedSize(10);
    const FrameBuilderSpiConverter sut(fakeFrameBuilder);

    ASSERT_THAT(sut.convertToSpiData(), SizeIs(20));
}

TEST(FrameBuilderSpiConverterTestSuite, convertToSpiData_ByDefault_OnlyNoOpFramesArePresent) {
    const FrameBuilderSpiConverter::FrameBuilderPtr fakeFrameBuilder = FrameBuilderStub::createFixedSize(120);
    const FrameBuilderSpiConverter sut(fakeFrameBuilder);

    ASSERT_THAT(sut.convertToSpiData(), Each(0x00));
}

TEST(FrameBuilderSpiConverterTestSuite, convertToSpiData_FramesAreConvertedToSpiData) {
    const FrameBuilder::Frames frames{
            {Register::NO_OP,        0x00},
            {Register::DISPLAY_TEST, 0xFF},
            {Register::SHUTDOWN,     0x01},
            {Register::NO_OP,        0x00},
            {Register::DISPLAY_TEST, 0x00}
    };
    const FrameBuilderSpiConverter::FrameBuilderPtr fakeFrameBuilder = FrameBuilderStub::createFixedFrames(frames);
    const FrameBuilderSpiConverter sut(fakeFrameBuilder);

    ASSERT_THAT(sut.convertToSpiData(),
                ElementsAre(0x0F, 0x00, 0x00, 0x00, 0x0C, 0x01, 0x0F, 0xFF, 0x00, 0x00));
}

}