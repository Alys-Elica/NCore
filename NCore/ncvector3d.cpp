#include "ncvector3d.h"

#include <cmath>

namespace NCore {
///
/// \class NCVector3D
/// \brief Convenience class representing a 3D vector
///

///
/// \brief Default constructor
/// \param x X position
/// \param y Y position
/// \param z Z position
///
NCVector3D::NCVector3D(double x, double y, double z)
{
    setX(x);
    setY(y);
    setZ(z);
}

///
/// \brief Returns X position
/// \return X position
///
double NCVector3D::x() const
{
    return m_x;
}

///
/// \brief Sets X position
/// \param x New X position
///
void NCVector3D::setX(double x)
{
    m_x = x;
}

///
/// \brief Returns Y position
/// \return Y position
///
double NCVector3D::y() const
{
    return m_y;
}

///
/// \brief Sets Y position
/// \param y New Y position
///
void NCVector3D::setY(double y)
{
    m_y = y;
}

///
/// \brief Returns Z position
/// \return Z position
///
double NCVector3D::z() const
{
    return m_z;
}

///
/// \brief Sets Z position
/// \param z New Z position
///
void NCVector3D::setZ(double z)
{
    m_z = z;
}

///
/// \brief Normalize the vector
///
void NCVector3D::normalize()
{
    *this /= length();
}

///
/// \brief Returns a normalized copy of the vector
/// \return Normalized copy of the vector
///
NCVector3D NCVector3D::normalized() const
{
    NCVector3D tmp = *this;

    tmp.normalize();

    return tmp;
}

///
/// \brief Returns the distance between this point and the point given in parameter
/// \param point Point to get distance to
/// \return Distance between this point and the point given in parameter
///
double NCVector3D::distanceToPoint(const NCVector3D &point) const
{
    return std::pow(std::pow(point.x() - x(), 2) + std::pow(point.y() - y(), 2) + std::pow(point.z() - z(), 2), 0.5);
}

///
/// \brief Returns the vector length
/// \return The vector length
///
double NCVector3D::length() const
{
    return std::sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
}

///
/// \brief Returns the vector squared length
/// \return The vector squared length
///
double NCVector3D::lengthSquared() const
{
    return dotProduct(*this);
}

///
/// \brief Returns the dot product between this vector and the vector given in parameters
/// \param other Other vector to get dot product with
/// \return Dot product between this vector and the vector given in parameters
///
double NCVector3D::dotProduct(const NCVector3D &other) const
{
    return (x() * other.x()) + (y() * other.y()) + (z() * other.z());
}

///
/// \brief Returns the dot product between two vectors given in parameters
/// \param v1 First vector
/// \param v2 Second vector
/// \return Dot product between two vectors given in parameters
///
double NCVector3D::dotProduct(const NCVector3D &v1, const NCVector3D &v2)
{
    return v1.dotProduct(v2);
}

///
/// \brief Returns the cross product of two vectors given in parameters
/// \param v1 First vector
/// \param v2 Second vector
/// \return Cross product of two vectors given in parameters
///
NCVector3D NCVector3D::crossProduct(const NCVector3D &v1, const NCVector3D &v2)
{
    return NCVector3D(
                (v1.y() * v2.z()) - (v1.z() * v2.y()),
                (v1.z() * v2.x()) - (v1.x() * v2.z()),
                (v1.x() * v2.y()) - (v1.y() * v2.x())
                );
}

///
/// \brief NCVector3D::operator -
/// \return
///
NCVector3D NCVector3D::operator-()
{
    NCVector3D tmp = *this;

    tmp.m_x = -tmp.m_x;
    tmp.m_y = -tmp.m_y;
    tmp.m_z = -tmp.m_z;

    return tmp;
}

///
/// \brief NCVector3D::operator +=
/// \param other
/// \return
///
NCVector3D NCVector3D::operator+=(const NCVector3D &other)
{
    this->m_x += other.x();
    this->m_y += other.y();
    this->m_z += other.z();

    return *this;
}

///
/// \brief NCVector3D::operator -=
/// \param other
/// \return
///
NCVector3D NCVector3D::operator-=(const NCVector3D &other)
{
    this->m_x -= other.x();
    this->m_y -= other.y();
    this->m_z -= other.z();

    return *this;
}

///
/// \brief NCVector3D::operator *=
/// \param other
/// \return
///
NCVector3D NCVector3D::operator*=(const NCVector3D &other)
{
    this->m_x *= other.x();
    this->m_y *= other.y();
    this->m_z *= other.z();

    return *this;
}

///
/// \brief NCVector3D::operator /=
/// \param other
/// \return
///
NCVector3D NCVector3D::operator/=(const NCVector3D &other)
{
    this->m_x /= other.x();
    this->m_y /= other.y();
    this->m_z /= other.z();

    return *this;
}

///
/// \brief NCVector3D::operator +=
/// \param val
/// \return
///
NCVector3D NCVector3D::operator+=(const double &val) {
    this->m_x += val;
    this->m_y += val;
    this->m_z += val;

    return *this;
}

///
/// \brief NCVector3D::operator -=
/// \param val
/// \return
///
NCVector3D NCVector3D::operator-=(const double &val) {
    this->m_x -= val;
    this->m_y -= val;
    this->m_z -= val;

    return *this;
}

///
/// \brief NCVector3D::operator *=
/// \param val
/// \return
///
NCVector3D NCVector3D::operator*=(const double &val) {
    this->m_x *= val;
    this->m_y *= val;
    this->m_z *= val;

    return *this;
}

///
/// \brief NCVector3D::operator /=
/// \param val
/// \return
///
NCVector3D NCVector3D::operator/=(const double &val) {
    this->m_x /= val;
    this->m_y /= val;
    this->m_z /= val;

    return *this;
}

///
/// \brief operator +
/// \param l
/// \param r
/// \return
///
NCVector3D operator+(const NCVector3D &l, const NCVector3D &r)
{
    NCVector3D newVect = l;

    newVect += r;

    return newVect;
}

///
/// \brief operator -
/// \param l
/// \param r
/// \return
///
NCVector3D operator-(const NCVector3D &l, const NCVector3D &r)
{
    NCVector3D newVect = l;

    newVect -= r;

    return newVect;
}

///
/// \brief operator *
/// \param l
/// \param r
/// \return
///
NCVector3D operator*(const NCVector3D &l, const NCVector3D &r)
{
    NCVector3D newVect = l;

    newVect *= r;

    return newVect;
}

///
/// \brief operator /
/// \param l
/// \param r
/// \return
///
NCVector3D operator/(const NCVector3D &l, const NCVector3D &r)
{
    NCVector3D newVect = l;

    newVect /= r;

    return newVect;
}

///
/// \brief operator +
/// \param l
/// \param val
/// \return
///
NCVector3D operator+(const NCVector3D &l, const double &val) {
    NCVector3D newVect = l;

    newVect += val;

    return newVect;
}

///
/// \brief operator -
/// \param l
/// \param val
/// \return
///
NCVector3D operator-(const NCVector3D &l, const double &val) {
    NCVector3D newVect = l;

    newVect -= val;

    return newVect;
}

///
/// \brief operator *
/// \param l
/// \param val
/// \return
///
NCVector3D operator*(const NCVector3D &l, const double &val) {
    NCVector3D newVect = l;

    newVect *= val;

    return newVect;
}

///
/// \brief operator /
/// \param l
/// \param val
/// \return
///
NCVector3D operator/(const NCVector3D &l, const double &val) {
    NCVector3D newVect = l;

    newVect /= val;

    return newVect;
}
}
