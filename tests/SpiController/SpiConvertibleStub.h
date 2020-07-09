#ifndef LEDDOTMATRIX_SPICONVERTIBLESTUB_H
#define LEDDOTMATRIX_SPICONVERTIBLESTUB_H

#include <memory>

#include "gmock/gmock.h"
#include "interfaces/SpiConvertible.h"

namespace leddotmatrix {

class SpiConvertibleStub : public SpiConvertible {
public:
    using SpiConvertiblePtr = std::unique_ptr<SpiConvertible>;

    MOCK_METHOD(SpiData, convertToSpiData, (), (const, override));

    static SpiConvertiblePtr create();
};

}

#endif //LEDDOTMATRIX_SPICONVERTIBLESTUB_H
