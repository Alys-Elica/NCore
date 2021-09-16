#include "ncrect.h"

namespace NCore {
///
/// \class NCRect
/// \brief Convenience class representing a rectangle
///

///
/// \brief Default constructor
/// \param x Rectangle X position
/// \param y Rectangle Y position
/// \param width Rectangle width
/// \param height Rectangle height
///
NCRect::NCRect(int x, int y, int width, int height)
{
    setX(x);
    setY(y);
    setWidth(width);
    setHeight(height);
}

///
/// \brief Returns rectangle X position
/// \return Rectangle X position
///
int NCRect::x() const
{
    return m_x;
}

///
/// \brief Sets rectangle X position
/// \param x New X position
///
void NCRect::setX(int x)
{
    m_x = x;
}

///
/// \brief Sets rectangle Y position
/// \return Rectangle Y position
///
int NCRect::y() const
{
    return m_y;
}

///
/// \brief Ses rectangle Y position
/// \param y New Y position
///
void NCRect::setY(int y)
{
    m_y = y;
}

///
/// \brief Returns rectangle width
/// \return Rectangle width
///
int NCRect::width() const
{
    return m_width;
}

///
/// \brief Sets rectangle width
/// \param width New rectangle width
///
void NCRect::setWidth(int width)
{
    m_width = width;
}

///
/// \brief Returns rectangle height
/// \return rectangle height
///
int NCRect::height() const
{
    return m_height;
}

///
/// \brief Sets rectangle height
/// \param height New rectangle height
///
void NCRect::setHeight(int height)
{
    m_height = height;
}

///
/// \brief Returns rectangle top position
/// \return Rectangle top position
///
int NCRect::top() const
{
    return y();
}

///
/// \brief Sets rectangle top position
/// \param top New top position
///
void NCRect::setTop(int top)
{
    setY(top);
}

///
/// \brief Returns rectangle bottom position
/// \return Rectangle bottom position
///
int NCRect::bottom() const
{
    return top() + height();
}

///
/// \brief Sets rectangle bottom position
/// \param bottom New bottom position
///
void NCRect::setBottom(int bottom)
{
    setHeight(bottom - top());
}

///
/// \brief Returns rectangle left position
/// \return rectangle left position
///
int NCRect::left() const
{
    return x();
}

///
/// \brief Sets rectangle left position
/// \param left New left position
///
void NCRect::setLeft(int left)
{
    setX(left);
}

///
/// \brief Returns rectangle right position
/// \return Rectangle right position
///
int NCRect::right() const
{
    return left() + width();
}

///
/// \brief Sets rectangle right position
/// \param right new right position
///
void NCRect::setRight(int right)
{
    setWidth(right - left());
}
}
