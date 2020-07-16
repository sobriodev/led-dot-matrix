#ifndef LEDDOTMATRIX_SPICONTROLLER_H
#define LEDDOTMATRIX_SPICONTROLLER_H

#include <memory>

#include "interfaces/SpiConvertible.h"
#include "interfaces/SpiTransmitter.h"

namespace leddotmatrix {

class SpiController {
public:
    using SpiTransmitterPtr = std::shared_ptr<SpiTransmitter>;

    explicit SpiController(SpiTransmitterPtr transmitter);
    [[nodiscard]] bool update(const SpiConvertible &convertible) const;
private:
    SpiTransmitterPtr spiTransmitter;
};

}

#endif //LEDDOTMATRIX_SPICONTROLLER_H
