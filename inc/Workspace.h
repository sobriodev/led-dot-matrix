#ifndef LEDDOTMATRIX_WORKSPACE_H
#define LEDDOTMATRIX_WORKSPACE_H

namespace leddotmatrix {

class Workspace {
public:
    static constexpr int MIN_SIZE = 1;
    static constexpr int MAX_SIZE = 128;

    static Workspace makeRectangle(int width, int height);
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
private:
    static int getBoundedSize(int size);
    Workspace(int width, int height) noexcept;

    int width;
    int height;
};

}

#endif //LEDDOTMATRIX_WORKSPACE_H
