#include "Workspace.h"

namespace leddotmatrix {

Workspace Workspace::makeRectangle(int width, int height) {
    return Workspace(width, height);
}

bool Workspace::isSizeValid(int size) const {
    return getBoundedSize(size) == size;
}

bool Workspace::isDeviceHandleValid(int deviceHandle) const {
    return deviceHandle >= 0 && deviceHandle <= devicesUsed() - 1;
}

int Workspace::getWidth() const {
    return width;
}

int Workspace::getHeight() const {
    return height;
}

int Workspace::devicesUsed() const {
    return width * height;
}

int Workspace::getBoundedSize(int size) {
    if (size < MIN_SIZE) {
        return MIN_SIZE;
    } else if (size > MAX_SIZE) {
        return MAX_SIZE;
    } else {
        return size;
    }
}

Workspace::Workspace(int width, int height) noexcept : width(getBoundedSize(width)), height(getBoundedSize(height)) {}

}