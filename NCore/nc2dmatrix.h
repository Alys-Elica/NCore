#ifndef NC2DMATRIX_H
#define NC2DMATRIX_H

#include <algorithm>
#include <fstream>

#include "ncore_global.h"

namespace NCore {
template<typename T>
class NC2dMatrix
{
public:
    NC2dMatrix(const size_t rows = 0, const size_t cols = 0);
    NC2dMatrix(const NC2dMatrix &other);
    ~NC2dMatrix();

    bool isValid();
    void clear();
    void resize(const size_t rows, const size_t cols);
    size_t rows() const;
    size_t cols() const;
    void fill(const T val);

    void flipHorizontal();
    void flipVertical();

    NC2dMatrix operator=(const NC2dMatrix &other);
    NC2dMatrix operator+=(const NC2dMatrix &other);
    NC2dMatrix operator-=(const NC2dMatrix &other);
    NC2dMatrix operator*=(const NC2dMatrix &other);
    NC2dMatrix operator/=(const NC2dMatrix &other);
    NC2dMatrix operator*=(const double &val);

    T& operator()(size_t row, size_t col);
    T operator()(size_t row, size_t col) const;

private:
    void destroy();
    T *m_array;
    size_t m_cols;
    size_t m_rows;
};

template<typename T>
NC2dMatrix<T>::NC2dMatrix(const size_t rows, const size_t cols)
{
    m_array = nullptr;
    m_cols = 0;
    m_rows = 0;
    this->resize(rows, cols);
}

template <typename T>
NC2dMatrix<T>::NC2dMatrix(const NC2dMatrix &other)
{
    m_array = nullptr;
    m_cols = 0;
    m_rows = 0;
    this->resize(other.m_rows, other.m_cols);

    std::copy(other.m_array, other.m_array + (m_rows * m_cols), m_array);
}

template<typename T>
NC2dMatrix<T>::~NC2dMatrix()
{
    this->destroy();
}

template<typename T>
bool NC2dMatrix<T>::isValid()
{
    return m_rows > 0 && m_cols > 0;
}

template<typename T>
void NC2dMatrix<T>::resize(const size_t rows, const size_t cols)
{
    if (rows == 0 || cols == 0)
        return;

    this->clear();
    m_array = new T[rows * cols];

    m_rows = rows;
    m_cols = cols;
}

template<typename T>
size_t NC2dMatrix<T>::rows() const
{
    return m_rows;
}

template<typename T>
size_t NC2dMatrix<T>::cols() const
{
    return m_cols;
}

template<typename T>
void NC2dMatrix<T>::fill(const T val)
{
    if (!this->isValid())
        return;

    std::fill(m_array, m_array + (m_rows * m_cols), val);
}

template<typename T>
void NC2dMatrix<T>::flipHorizontal()
{
    NC2dMatrix<T> tmp = *this;

    for (size_t row = 0; row < tmp.rows(); ++row)
        for (size_t col = 0; col < tmp.cols(); ++col)
            (*this)(row, col) = tmp(row, tmp.cols() - 1 - col);
}

template<typename T>
void NC2dMatrix<T>::flipVertical()
{
    NC2dMatrix<T> tmp = *this;

    for (size_t row = 0; row < tmp.rows(); ++row)
        for (size_t col = 0; col < tmp.cols(); ++col)
            (*this)(row, col) = tmp(tmp.rows() - 1 - row, col);
}

template<typename T>
NC2dMatrix<T> NC2dMatrix<T>::operator=(const NC2dMatrix<T> &other)
{
    m_array = nullptr;
    m_cols = 0;
    m_rows = 0;
    this->resize(other.m_rows, other.m_cols);

    std::copy(other.m_array, other.m_array + (m_rows * m_cols), m_array);

    return *this;
}

template<typename T>
NC2dMatrix<T> NC2dMatrix<T>::operator+=(const NC2dMatrix<T> &other)
{
    // TODO: more effective algorithm
    if (m_rows != other.m_rows || m_cols != other.m_cols)
        return *this;

    for (int i = 0; i < (m_rows * m_cols); ++i)
        m_array[i] += other.m_array[i];

    return *this;
}

template<typename T>
NC2dMatrix<T> NC2dMatrix<T>::operator-=(const NC2dMatrix<T> &other)
{
    // TODO: more effective algorithm
    if (m_rows != other.m_rows || m_cols != other.m_cols)
        return *this;

    for (int i = 0; i < (m_rows * m_cols); ++i)
        m_array[i] -= other.m_array[i];

    return *this;
}

template<typename T>
NC2dMatrix<T> NC2dMatrix<T>::operator*=(const NC2dMatrix<T> &other)
{
    // TODO: more effective algorithm
    if (m_rows != other.m_rows || m_cols != other.m_cols)
        return *this;

    for (int i = 0; i < (m_rows * m_cols); ++i)
        m_array[i] -= other.m_array[i];

    return *this;
}

template<typename T>
NC2dMatrix<T> NC2dMatrix<T>::operator/=(const NC2dMatrix<T> &other)
{
    // TODO: more effective algorithm
    if (m_rows != other.m_rows || m_cols != other.m_cols)
        return *this;

    for (int i = 0; i < (m_rows * m_cols); ++i)
        m_array[i] /= other.m_array[i];

    return *this;
}

template<typename T>
NC2dMatrix<T> NC2dMatrix<T>::operator*=(const double &val)
{
    for (int i = 0; i < (m_rows * m_cols); ++i)
        m_array[i] *= val;

    return *this;
}

template<typename T>
T &NC2dMatrix<T>::operator()(size_t row, size_t col)
{
    return m_array[m_cols * row + col];
}

template<typename T>
T NC2dMatrix<T>::operator()(size_t row, size_t col) const
{
    return m_array[m_cols * row + col];
}

template<typename T>
void NC2dMatrix<T>::clear()
{
    if (!this->isValid())
        return;

    this->destroy();

    m_array = nullptr;
    m_rows = 0;
    m_cols = 0;
}

template<typename T>
void NC2dMatrix<T>::destroy()
{
    if (this->isValid())
        delete[] m_array;
}

template<typename T>
std::ofstream &operator<<(std::ofstream &out, NC2dMatrix<T> const &matrix)
{
    size_t rows = matrix.rows();
    size_t cols = matrix.cols();

    for (size_t i = sizeof(size_t); i > 0; --i)
        out.put(rows >> ((i - 1) * 8));
    for (size_t i = sizeof(size_t); i > 0; --i)
        out.put(cols >> ((i - 1) * 8));

    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            T val = matrix(row, col);

            char *ptr = reinterpret_cast<char *>(&val);
            for (size_t i = sizeof(T); i > 0; --i)
                out.put(ptr[i - 1]);
        }
    }

    return out;
}

template<typename T>
std::ifstream &operator>>(std::ifstream &in, NC2dMatrix<T> &matrix)
{
    size_t rows = 0;
    size_t cols = 0;

    for (size_t i = sizeof(size_t); i > 0; --i)
        rows |= in.get() << ((i - 1) * 8);
    for (size_t i = sizeof(size_t); i > 0; --i)
        cols |= in.get() << ((i - 1) * 8);

    matrix.resize(rows, cols);

    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            T val;

            char *ptr = reinterpret_cast<char *>(&val);
            for (size_t i = sizeof(T); i > 0; --i)
                ptr[i - 1] = in.get();

            matrix(row, col) = val;
        }
    }

    return in;
}
}

#endif // NC2DMATRIX_H
