#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "SpiController.h"
#include "SpiTransmitterMock.h"
#include "SpiConvertibleStub.h"

namespace leddotmatrix {

TEST(SpiControllerTestSuite, transmit_SpiDataPassed_DataSentCorrectly) {
    const auto spiConvertibleStub = SpiConvertibleStub::create();
    const std::shared_ptr<SpiTransmitter> spiTransmitterMock =
            SpiTransmitterMock::create(spiConvertibleStub->convertToSpiData());
    const SpiController sut(spiTransmitterMock);

    const auto result = sut.update(*spiConvertibleStub);

    ASSERT_TRUE(result);
}

}
