#include <memory>

#include "FrameBuilderSpiConverter.h"
#include "NullPointerException.h"

namespace leddotmatrix {

FrameBuilderSpiConverter::FrameBuilderSpiConverter(
        FrameBuilderPtr frameBuilderPtr):
        frameBuilder(std::move(frameBuilderPtr)) {
    if (!frameBuilder) {
        throw NullPointerException();
    }
}

SpiConvertible::SpiData FrameBuilderSpiConverter::convertToSpiData() const {
    SpiData spiData;
    for (auto iter = frameBuilder->getFrames().crbegin(); iter != frameBuilder->getFrames().crend(); iter++) {
        spiData.push_back(static_cast<SpiByte>(iter->first));
        spiData.push_back(iter->second);
    }
    return spiData;
}

}