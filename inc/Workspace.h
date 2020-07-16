#ifndef LEDDOTMATRIX_WORKSPACE_H
#define LEDDOTMATRIX_WORKSPACE_H

namespace leddotmatrix {

class Workspace {
public:
    static constexpr int MIN_SIZE = 1;
    static constexpr int MAX_SIZE = 128;

    static Workspace makeRectangle(int width, int height);
    [[nodiscard]] virtual bool isSizeValid(int size) const;
    [[nodiscard]] virtual bool isDeviceHandleValid(int deviceHandle) const;
    [[nodiscard]] virtual int getWidth() const;
    [[nodiscard]] virtual int getHeight() const;
    [[nodiscard]] virtual int devicesUsed() const;
    virtual ~Workspace() = default;
protected:
    Workspace() noexcept = default;
private:
    static int getBoundedSize(int size);
    Workspace(int width, int height) noexcept;

    int width = MIN_SIZE;
    int height = MAX_SIZE;
};

}

#endif //LEDDOTMATRIX_WORKSPACE_H
