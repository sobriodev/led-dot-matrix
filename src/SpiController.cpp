#include <memory>

#include "SpiController.h"

namespace leddotmatrix {

SpiController::SpiController(std::shared_ptr<SpiTransmitter> transmitter) noexcept:
        spiTransmitter(std::move(transmitter)) {}

bool SpiController::update(const SpiConvertible &convertible) const {
    return spiTransmitter->transmit(convertible.convertToSpiData());
}

}