#ifndef NCPOINT_H
#define NCPOINT_H

#include "ncore_global.h"

namespace NCore {
class NCORE_EXPORT NCPoint
{
public:
    NCPoint(int x = 0, int y = 0);

    int x() const;
    void setX(int value);

    int y() const;
    void setY(int value);

private:
    int m_x;
    int m_y;
};
}

#endif // NCPOINT_H
