#ifndef LEDDOTMATRIX_SPITRANSMITTERMOCK_H
#define LEDDOTMATRIX_SPITRANSMITTERMOCK_H

#include <memory>

#include "gmock/gmock.h"
#include "interfaces/SpiTransmitter.h"

namespace leddotmatrix {

using testing::NiceMock;
using testing::Return;

class SpiTransmitterMock : public SpiTransmitter {
public:
    using SpiTransmitterPtr = std::unique_ptr<SpiTransmitter>;

    MOCK_METHOD(bool, transmit, (const SpiData &data), (const, override));

    static SpiTransmitterPtr create(const SpiData &expected) {
        auto mock = std::make_unique<SpiTransmitterMock>();
        EXPECT_CALL(*mock, transmit(expected)).WillRepeatedly(Return(true));
        return mock;
    }
};

}

#endif //LEDDOTMATRIX_SPITRANSMITTERMOCK_H
