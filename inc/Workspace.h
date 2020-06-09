#ifndef LEDDOTMATRIX_WORKSPACE_H
#define LEDDOTMATRIX_WORKSPACE_H

#include "WorkspaceInterface.h"

namespace leddotmatrix {

class Workspace : public WorkspaceInterface {
public:
    static constexpr int MIN_SIZE = 1;
    static constexpr int MAX_SIZE = 128;

    static Workspace makeRectangle(int width, int height);
    bool isSizeValid(int size) const override;
    int getWidth() const override;
    int getHeight() const override;
private:
    static int getBoundedSize(int size);
    Workspace(int width, int height) noexcept;

    int width;
    int height;
};

}

#endif //LEDDOTMATRIX_WORKSPACE_H
