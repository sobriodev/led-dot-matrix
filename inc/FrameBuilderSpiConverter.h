#ifndef LEDDOTMATRIX_FRAMEBUILDERSPICONVERTER_H
#define LEDDOTMATRIX_FRAMEBUILDERSPICONVERTER_H

#include <memory>

#include "interfaces/SpiConvertible.h"
#include <interfaces/FrameBuilderInterface.h>

namespace leddotmatrix {

class FrameBuilderSpiConverter : public SpiConvertible {
public:
    using FrameBuilderInterfacePtr = std::shared_ptr<FrameBuilderInterface>;

    explicit FrameBuilderSpiConverter(FrameBuilderInterfacePtr frameBuilderInterfacePtr) noexcept;
    [[nodiscard]] SpiData convertToSpiData() const override;
private:
    FrameBuilderInterfacePtr frameBuilder;
};

}

#endif //LEDDOTMATRIX_FRAMEBUILDERSPICONVERTER_H
