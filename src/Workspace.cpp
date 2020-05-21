#include "Workspace.h"

namespace leddotmatrix {

Workspace Workspace::makeRectangle(int width, int height) {
    return Workspace(0, 0);
}

int Workspace::getWidth() const {
    return width;
}

int Workspace::getHeight() const {
    return height;
}

int Workspace::isSizeBounded(int size) {
    return size > 0;
}

Workspace::Workspace(int width, int height) noexcept : width(isSizeBounded(width) ? width : MIN_SIZE), height(isSizeBounded(height) ? height : MIN_SIZE) {}

}