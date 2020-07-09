#ifndef LEDDOTMATRIX_SPITRANSMITTER_H
#define LEDDOTMATRIX_SPITRANSMITTER_H

#include <vector>
#include <cstdint>

namespace leddotmatrix {

class SpiTransmitter {
public:
    using SpiData = std::vector<std::uint8_t>;

    virtual bool transmit(const SpiData &data) = 0;
    virtual ~SpiTransmitter() noexcept = default;
};

}

#endif //LEDDOTMATRIX_SPITRANSMITTER_H
