#include "ncrgb.h"

namespace NCore {
///
/// \class NCRgb
/// \brief Convenience class representing a RGB 24 bits color
///

///
/// \brief NCRgb::NCRgb
/// \param r Red component
/// \param g Green component
/// \param b Blue component
///
NCRgb::NCRgb(uint8_t r, uint8_t g, uint8_t b)
{
    setRgb(r, g, b);
}

///
/// \brief Sets RGB values
/// \param r Red component
/// \param g Green component
/// \param b Blue component
///
void NCRgb::setRgb(const uint8_t &r, const uint8_t &g, const uint8_t &b)
{
    this->setR(r);
    this->setG(g);
    this->setB(b);
}

///
/// \brief Returns red component
/// \return Red component
///
uint8_t NCRgb::r() const
{
    return m_r;
}

///
/// \brief Sets red component
/// \param value New red component
///
void NCRgb::setR(const uint8_t &value)
{
    m_r = value;
}

///
/// \brief Returns green component
/// \return Green component
///
uint8_t NCRgb::g() const
{
    return m_g;
}

///
/// \brief Sets green component
/// \param value New green component
///
void NCRgb::setG(const uint8_t &value)
{
    m_g = value;
}

///
/// \brief Returns blue component
/// \return Blue component
///
uint8_t NCRgb::b() const
{
    return m_b;
}

///
/// \brief Sets blue component
/// \param value New blue component
///
void NCRgb::setB(const uint8_t &value)
{
    m_b = value;
}
}
