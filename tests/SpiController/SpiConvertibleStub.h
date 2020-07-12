#ifndef LEDDOTMATRIX_SPICONVERTIBLESTUB_H
#define LEDDOTMATRIX_SPICONVERTIBLESTUB_H

#include <memory>

#include "gmock/gmock.h"
#include "interfaces/SpiConvertible.h"

namespace leddotmatrix {

using testing::NiceMock;
using testing::Return;

class SpiConvertibleStub : public SpiConvertible {
public:
    using SpiConvertiblePtr = std::unique_ptr<SpiConvertible>;

    MOCK_METHOD(SpiData, convertToSpiData, (), (const, override));

    static SpiConvertiblePtr create() {
        const SpiData spiData = {0x0F, 0x00, 0x00, 0x00, 0x0C, 0x01, 0x0F, 0xFF, 0x00, 0x00};

        auto stub = std::make_unique<NiceMock<SpiConvertibleStub>>();
        ON_CALL(*stub, convertToSpiData).WillByDefault(Return(spiData));
        return stub;
    }
};

}

#endif //LEDDOTMATRIX_SPICONVERTIBLESTUB_H
