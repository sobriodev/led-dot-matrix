#ifndef LEDDOTMATRIX_FRAMEBUILDERSPICONVERTER_H
#define LEDDOTMATRIX_FRAMEBUILDERSPICONVERTER_H

#include "SpiConvertible.h"

namespace leddotmatrix {

class FrameBuilderSpiConverter : public SpiConvertible {
public:
    [[nodiscard]] SpiData convertToSpiData() const override;
};

}

#endif //LEDDOTMATRIX_FRAMEBUILDERSPICONVERTER_H
