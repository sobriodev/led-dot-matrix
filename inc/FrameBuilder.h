#ifndef LEDDOTMATRIX_FRAMEBUILDER_H
#define LEDDOTMATRIX_FRAMEBUILDER_H

#include <memory>

#include "interfaces/WorkspaceInterface.h"
#include "interfaces/FrameBuilderInterface.h"

namespace leddotmatrix {

class FrameBuilder : public FrameBuilderInterface {
public:
    using WorkspaceInterfacePtr = std::shared_ptr<WorkspaceInterface>;

    explicit FrameBuilder(WorkspaceInterfacePtr workspaceInterfacePtr);
    [[nodiscard]] const Frames &getFrames() const override;
    void fillAll(const Frame &frame);
    bool fillOne(int deviceHandle, const Frame &frame);
private:
    void initSerialFrames();

    WorkspaceInterfacePtr workspace;
    Frames serialFrames;
};

}

#endif //LEDDOTMATRIX_FRAMEBUILDER_H
