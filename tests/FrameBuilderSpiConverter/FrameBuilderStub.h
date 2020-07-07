#ifndef LEDDOTMATRIX_FRAMEBUILDERSTUB_H
#define LEDDOTMATRIX_FRAMEBUILDERSTUB_H

#include <memory>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "FrameBuilderInterface.h"

namespace leddotmatrix {

class FrameBuilderStub : public FrameBuilderInterface {
public:
    using FrameBuilderInterfacePtr = std::unique_ptr<FrameBuilderInterface>;

    MOCK_METHOD(const Frames&, getFrames, (), (const, override));

    static FrameBuilderInterfacePtr createFixedSize(int size);
    static FrameBuilderInterfacePtr createFixedFrames(const Frames &frames);
};

}

#endif //LEDDOTMATRIX_FRAMEBUILDERSTUB_H
