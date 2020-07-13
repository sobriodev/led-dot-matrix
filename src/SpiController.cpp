#include <memory>

#include "SpiController.h"
#include "NullPointerException.h"

namespace leddotmatrix {

SpiController::SpiController(std::shared_ptr<SpiTransmitter> transmitter):
        spiTransmitter(std::move(transmitter)) {
    if (!spiTransmitter) {
        throw NullPointerException();
    }
}

bool SpiController::update(const SpiConvertible &convertible) const {
    return spiTransmitter->transmit(convertible.convertToSpiData());
}

}