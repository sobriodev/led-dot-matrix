#ifndef LEDDOTMATRIX_FRAMEBUILDERSTUB_H
#define LEDDOTMATRIX_FRAMEBUILDERSTUB_H

#include <memory>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "FrameBuilder.h"

namespace leddotmatrix {

using ::testing::ReturnRef;
using ::testing::NiceMock;

class FrameBuilderStub : public FrameBuilder {
public:
    using FrameBuilderPtr = std::unique_ptr<FrameBuilder>;

    MOCK_METHOD(const Frames&, getFrames, (), (const, override));

    static FrameBuilderPtr createFixedSize(int size) {
        static const Frames outputVector(size, {Register::NO_OP, 0x00});

        auto stub = std::make_unique<NiceMock<FrameBuilderStub>>();
        ON_CALL(*stub, getFrames).WillByDefault(ReturnRef(outputVector));
        return stub;
    }

    static FrameBuilderPtr createFixedFrames(const Frames &frames) {
        static const Frames spiVector = frames;

        auto stub = std::make_unique<NiceMock<FrameBuilderStub>>();
        ON_CALL(*stub, getFrames).WillByDefault(ReturnRef(spiVector));
        return stub;
    }
};

}

#endif //LEDDOTMATRIX_FRAMEBUILDERSTUB_H
