#ifndef NCVECTOR3D_H
#define NCVECTOR3D_H

#include "ncore_global.h"

// TODO: SOME CALCULATION ERRORS STILL EXISTS
namespace NCore {
class NCORE_EXPORT NCVector3D
{
public:
    NCVector3D(double x = 0.0, double y = 0.0, double z = 0.0);

    double x() const;
    void setX(double x);

    double y() const;
    void setY(double y);

    double z() const;
    void setZ(double z);

    void normalize();
    NCVector3D normalized() const;
    double distanceToPoint(const NCVector3D &point) const;
    double length() const;
    double lengthSquared() const;
    double dotProduct(const NCVector3D &other) const;
    static double dotProduct(const NCVector3D &v1, const NCVector3D &v2);
    static NCVector3D crossProduct(const NCVector3D &v1, const NCVector3D &v2);

    NCVector3D operator-();

    NCVector3D operator+=(const NCVector3D &other);
    NCVector3D operator-=(const NCVector3D &other);
    NCVector3D operator*=(const NCVector3D &other);
    NCVector3D operator/=(const NCVector3D &other);

    NCVector3D operator+=(const double &val);
    NCVector3D operator-=(const double &val);
    NCVector3D operator*=(const double &val);
    NCVector3D operator/=(const double &val);

    NCORE_EXPORT friend NCVector3D operator+(const NCVector3D &l, const NCVector3D &r);
    NCORE_EXPORT friend NCVector3D operator-(const NCVector3D &l, const NCVector3D &r);
    NCORE_EXPORT friend NCVector3D operator*(const NCVector3D &l, const NCVector3D &r);
    NCORE_EXPORT friend NCVector3D operator/(const NCVector3D &l, const NCVector3D &r);

    NCORE_EXPORT friend NCVector3D operator+(const NCVector3D &l, const double &val);
    NCORE_EXPORT friend NCVector3D operator-(const NCVector3D &l, const double &val);
    NCORE_EXPORT friend NCVector3D operator*(const NCVector3D &l, const double &val);
    NCORE_EXPORT friend NCVector3D operator/(const NCVector3D &l, const double &val);

private:
    double m_x;
    double m_y;
    double m_z;
};
}

#endif // NCVECTOR3D_H
