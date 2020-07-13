#ifndef LEDDOTMATRIX_SPICONTROLLER_H
#define LEDDOTMATRIX_SPICONTROLLER_H

#include <memory>

#include "interfaces/SpiConvertible.h"
#include "interfaces/SpiTransmitter.h"

namespace leddotmatrix {

class SpiController {
public:
    explicit SpiController(std::shared_ptr<SpiTransmitter> transmitter);
    [[nodiscard]] bool update(const SpiConvertible &convertible) const;
private:
    std::shared_ptr<SpiTransmitter> spiTransmitter;
};

}

#endif //LEDDOTMATRIX_SPICONTROLLER_H
