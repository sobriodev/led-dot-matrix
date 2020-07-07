#include <memory>

#include "FrameBuilderSpiConverter.h"

namespace leddotmatrix {

FrameBuilderSpiConverter::FrameBuilderSpiConverter(
        FrameBuilderSpiConverter::FrameBuilderInterfacePtr frameBuilderInterfacePtr) noexcept :
        frameBuilder(std::move(frameBuilderInterfacePtr)) {}

SpiConvertible::SpiData FrameBuilderSpiConverter::convertToSpiData() const {
    SpiData spiData;
    for (auto iter = frameBuilder->getFrames().crbegin(); iter != frameBuilder->getFrames().crend(); iter++) {
        spiData.push_back(static_cast<SpiByte>(iter->first));
        spiData.push_back(iter->second);
    }
    return spiData;
}

}