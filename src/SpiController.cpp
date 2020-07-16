#include <memory>

#include "SpiController.h"
#include "NullPointerException.h"

namespace leddotmatrix {

SpiController::SpiController(SpiTransmitterPtr transmitter):
        spiTransmitter(std::move(transmitter)) {
    if (!spiTransmitter) {
        throw NullPointerException();
    }
}

bool SpiController::update(const SpiConvertible &convertible) const {
    return spiTransmitter->transmit(convertible.convertToSpiData());
}

}