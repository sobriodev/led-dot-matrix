#include "SpiConvertibleStub.h"

namespace leddotmatrix {

using testing::NiceMock;
using testing::Return;

SpiConvertibleStub::SpiConvertiblePtr SpiConvertibleStub::create() {
    const SpiData spiData = {0x0F, 0x00, 0x00, 0x00, 0x0C, 0x01, 0x0F, 0xFF, 0x00, 0x00};

    auto stub = std::make_unique<NiceMock<SpiConvertibleStub>>();
    ON_CALL(*stub, convertToSpiData).WillByDefault(Return(spiData));
    return stub;
}

}
