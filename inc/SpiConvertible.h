#ifndef LEDDOTMATRIX_SPICONVERTIBLE_H
#define LEDDOTMATRIX_SPICONVERTIBLE_H

#include <cstdint>
#include <vector>

namespace leddotmatrix {

class SpiConvertible {
public:
    using SpiByte = std::uint8_t;
    using SpiData = std::vector<SpiByte>;

    [[nodiscard]] virtual SpiData convertToSpiData() const = 0;
    virtual ~SpiConvertible() noexcept = default;
};

}

#endif //LEDDOTMATRIX_SPICONVERTIBLE_H
