#ifndef LEDDOTMATRIX_FRAMEBUILDER_H
#define LEDDOTMATRIX_FRAMEBUILDER_H

#include <memory>
#include <vector>

#include "Workspace.h"
#include "Registers.h"

namespace leddotmatrix {

class FrameBuilder {
public:
    using Frame = std::pair<Register, uint8_t>;
    using Frames = std::vector<Frame>;
    using WorkspacePtr = std::shared_ptr<Workspace>;

    explicit FrameBuilder(WorkspacePtr workspacePtr);
    [[nodiscard]] virtual const Frames &getFrames() const;
    void fillAll(const Frame &frame);
    bool fillOne(int deviceHandle, const Frame &frame);
    virtual ~FrameBuilder() = default;
protected:
    FrameBuilder() noexcept = default;
private:
    void initSerialFrames();

    WorkspacePtr workspace;
    Frames serialFrames;
};

}

#endif //LEDDOTMATRIX_FRAMEBUILDER_H
