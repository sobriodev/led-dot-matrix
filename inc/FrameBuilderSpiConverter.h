#ifndef LEDDOTMATRIX_FRAMEBUILDERSPICONVERTER_H
#define LEDDOTMATRIX_FRAMEBUILDERSPICONVERTER_H

#include <memory>

#include "FrameBuilder.h"
#include "interfaces/SpiConvertible.h"

namespace leddotmatrix {

class FrameBuilderSpiConverter : public SpiConvertible {
public:
    using FrameBuilderPtr = std::shared_ptr<FrameBuilder>;

    explicit FrameBuilderSpiConverter(FrameBuilderPtr frameBuilderPtr);
    [[nodiscard]] SpiData convertToSpiData() const override;
private:
    FrameBuilderPtr frameBuilder;
};

}

#endif //LEDDOTMATRIX_FRAMEBUILDERSPICONVERTER_H
