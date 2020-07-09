#ifndef LEDDOTMATRIX_SPITRANSMITTERMOCK_H
#define LEDDOTMATRIX_SPITRANSMITTERMOCK_H

#include <memory>

#include "gmock/gmock.h"
#include "interfaces/SpiTransmitter.h"

namespace leddotmatrix {

class SpiTransmitterMock : public SpiTransmitter {
public:
    using SpiTransmitterPtr = std::unique_ptr<SpiTransmitter>;

    MOCK_METHOD(bool, transmit, (const SpiData &data), (const, override));

    static SpiTransmitterPtr create(const SpiData &expected);
};

}

#endif //LEDDOTMATRIX_SPITRANSMITTERMOCK_H
