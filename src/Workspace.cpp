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

int Workspace::getBoundedSize(int size) {
    if (size < MIN_SIZE) {
        return MIN_SIZE;
    }
    return size;
}

Workspace::Workspace(int width, int height) noexcept : width(getBoundedSize(width)), height(getBoundedSize(height)) {}

}