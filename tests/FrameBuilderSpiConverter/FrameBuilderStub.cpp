#include "FrameBuilderStub.h"
#include "Registers.h"

namespace leddotmatrix {

using ::testing::ReturnRef;
using ::testing::NiceMock;

FrameBuilderStub::FrameBuilderInterfacePtr FrameBuilderStub::createFixedSize(int size) {
    static const Frames outputVector(size, {Register::NO_OP, 0x00});

    auto stub = std::make_unique<NiceMock<FrameBuilderStub>>();
    ON_CALL(*stub, getFrames).WillByDefault(ReturnRef(outputVector));
    return stub;
}

}
