#include "ncpoint.h"

namespace NCore {
///
/// \class NCPoint
/// \brief Convenience class representing a 2D point
///

///
/// \brief Default constructor
/// \param x The X position
/// \param y The Y position
///
NCPoint::NCPoint(int x, int y)
{
    this->setX(x);
    this->setY(y);
}

///
/// \brief Returns the X position
/// \return X position
///
int NCPoint::x() const
{
    return m_x;
}

///
/// \brief Sets the X position
/// \param value The new X position
///
void NCPoint::setX(int value)
{
    m_x = value;
}

///
/// \brief Returns the Y position
/// \return
///
int NCPoint::y() const
{
    return m_y;
}

///
/// \brief Sets the Y position
/// \param value The new Y position
///
void NCPoint::setY(int value)
{
    m_y = value;
}
}
