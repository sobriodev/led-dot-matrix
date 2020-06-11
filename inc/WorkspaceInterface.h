#ifndef LEDDOTMATRIX_WORKSPACEINTERFACE_H
#define LEDDOTMATRIX_WORKSPACEINTERFACE_H

namespace leddotmatrix {

class WorkspaceInterface {
public:
    [[nodiscard]] virtual bool isSizeValid(int size) const = 0;
    [[nodiscard]] virtual int getWidth() const = 0;
    [[nodiscard]] virtual int getHeight() const = 0;
    [[nodiscard]] virtual int devicesUsed() const = 0;
    virtual ~WorkspaceInterface() noexcept = default;
};

}

#endif //LEDDOTMATRIX_WORKSPACEINTERFACE_H
