#ifndef LEDDOTMATRIX_SPITRANSMITTER_H
#define LEDDOTMATRIX_SPITRANSMITTER_H

#include <vector>
#include <cstdint>

namespace leddotmatrix {

class SpiTransmitter {
public:
    using SpiData = std::vector<std::uint8_t>;

    [[nodiscard]] virtual bool transmit(const SpiData &data) const = 0;
    virtual ~SpiTransmitter() noexcept = default;
};

}

#endif //LEDDOTMATRIX_SPITRANSMITTER_H
