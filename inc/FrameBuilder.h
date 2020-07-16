#ifndef LEDDOTMATRIX_FRAMEBUILDER_H
#define LEDDOTMATRIX_FRAMEBUILDER_H

#include <memory>

#include "interfaces/FrameBuilderInterface.h"
#include "Workspace.h"

namespace leddotmatrix {

class FrameBuilder : public FrameBuilderInterface {
public:
    using WorkspacePtr = std::shared_ptr<Workspace>;

    explicit FrameBuilder(WorkspacePtr workspaceInterfacePtr);
    [[nodiscard]] const Frames &getFrames() const override;
    void fillAll(const Frame &frame);
    bool fillOne(int deviceHandle, const Frame &frame);
private:
    void initSerialFrames();

    WorkspacePtr workspace;
    Frames serialFrames;
};

}

#endif //LEDDOTMATRIX_FRAMEBUILDER_H
