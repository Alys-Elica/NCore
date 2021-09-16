#ifndef NCRECT_H
#define NCRECT_H

#include "ncore_global.h"

namespace NCore {
class NCORE_EXPORT NCRect
{
public:
    NCRect(int x = 0, int y = 0, int width = 0, int height = 0);

    int x() const;
    void setX(int x);

    int y() const;
    void setY(int y);

    int width() const;
    void setWidth(int width);

    int height() const;
    void setHeight(int height);

    int top() const;
    void setTop(int top);
    int bottom() const;
    void setBottom(int bottom);
    int left() const;
    void setLeft(int left);
    int right() const;
    void setRight(int right);

private:
    int m_x;
    int m_y;

    int m_width;
    int m_height;
};
}

#endif // NCRECT_H
