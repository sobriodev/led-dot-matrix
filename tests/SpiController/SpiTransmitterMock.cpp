#include "SpiTransmitterMock.h"

namespace leddotmatrix {

using testing::NiceMock;
using testing::Return;

SpiTransmitterMock::SpiTransmitterPtr SpiTransmitterMock::create(const SpiData &expected) {
    auto mock = std::make_unique<SpiTransmitterMock>();
    EXPECT_CALL(*mock, transmit(expected)).WillRepeatedly(Return(true));
    return mock;
}

}