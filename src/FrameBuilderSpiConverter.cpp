#include <memory>

#include "FrameBuilderSpiConverter.h"

namespace leddotmatrix {

FrameBuilderSpiConverter::FrameBuilderSpiConverter(
        FrameBuilderSpiConverter::FrameBuilderInterfacePtr frameBuilderInterfacePtr) noexcept :
        frameBuilder(std::move(frameBuilderInterfacePtr)) {}

SpiConvertible::SpiData FrameBuilderSpiConverter::convertToSpiData() const {
    SpiData output(frameBuilder->getFrames().size() * 2);
    return output;
}

}