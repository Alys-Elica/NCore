#ifndef NCRGB_H
#define NCRGB_H

#include "ncore_global.h"

#include <cinttypes>

namespace NCore {
class NCORE_EXPORT NCRgb
{
public:
    NCRgb(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0);

    void setRgb(const uint8_t &r, const uint8_t &g, const uint8_t &b);

    uint8_t r() const;
    void setR(const uint8_t &value);

    uint8_t g() const;
    void setG(const uint8_t &value);

    uint8_t b() const;
    void setB(const uint8_t &value);

private:
    uint8_t m_r;
    uint8_t m_g;
    uint8_t m_b;
};
}

#endif // NCRGB_H
