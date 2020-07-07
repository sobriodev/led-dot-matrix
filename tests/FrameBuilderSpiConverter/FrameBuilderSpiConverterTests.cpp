#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "FrameBuilderSpiConverter.h"
#include "FrameBuilderStub.h"

using testing::SizeIs;
using testing::Each;

namespace leddotmatrix {

using FrameBuilderInterfacePtr = std::shared_ptr<FrameBuilderInterface>;

TEST(FrameBuilderSpiConverterTestSuite,
     convertToSpiData_ByDefault_SpiDataVectorHasTwiceAsManyElementsAsFrameBuilderFramesVector) {
    const FrameBuilderInterfacePtr fakeFrameBuilder = FrameBuilderStub::createFixedSize(10);
    const FrameBuilderSpiConverter sut(fakeFrameBuilder);

    ASSERT_THAT(sut.convertToSpiData(), SizeIs(20));
}

TEST(FrameBuilderSpiConverterTestSuite, convertToSpiData_ByDefault_OnlyNoOpFramesArePresent) {
    const FrameBuilderInterfacePtr fakeFrameBuilder = FrameBuilderStub::createFixedSize(120);
    const FrameBuilderSpiConverter sut(fakeFrameBuilder);

    ASSERT_THAT(sut.convertToSpiData(), Each(0));
}

}