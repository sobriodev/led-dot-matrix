#ifndef LEDDOTMATRIX_SPICONVERTIBLE_H
#define LEDDOTMATRIX_SPICONVERTIBLE_H

#include <cstdint>
#include <vector>

namespace leddotmatrix {

class SpiConvertible {
    using SpiByte = std::uint8_t;
    using SpiData = std::vector<SpiByte>;
public:
    [[nodiscard]] virtual SpiData convertToSpiData() const = 0;
    virtual ~SpiConvertible() noexcept = default;
};

}

#endif //LEDDOTMATRIX_SPICONVERTIBLE_H
