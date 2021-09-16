#include "ncore.h"

namespace NCore {
/* NC2dMatrix */
///
/// \class NC2dMatrix
/// \brief Simple 2d matrix convenience class.
/// \tparam T Matrix stored type
///

///
/// \fn NC2dMatrix::NC2dMatrix(const size_t rows = 0, const size_t cols = 0);
/// \brief Initializes the matrix with given size
/// \param rows Matrix row count
/// \param cols Matrix column count
///

///
/// \fn NC2dMatrix::NC2dMatrix(const NC2dMatrix &other);
/// \brief Copy constructor
/// \param other Object to copy data from
///

///
/// \fn bool NC2dMatrix::isValid();
/// \brief Checks matrix validity
/// \return True if matrix row and column counts are more than 0
///

///
/// \fn void NC2dMatrix::clear();
/// \brief Clears matrix
///

///
/// \fn void NC2dMatrix::resize(const size_t rows, const size_t cols);
/// \brief Resizes the matrix to given size
/// \param rows Row count
/// \param cols Column count
///

///
/// \fn size_t NC2dMatrix::rows() const;
/// \brief Get matrix row count
/// \return Matrix row count
///

///
/// \fn size_t NC2dMatrix::cols() const;
/// \brief Get matrix column count
/// \return Matrix column count
///

///
/// \fn void NC2dMatrix::fill(const T val);
/// \brief Fills entire matrix with given value
/// \param val Value used to fill matrix
///

///
/// \fn void NC2dMatrix<T>::flipHorizontal();
/// \brief Flips the entire matrix horizontally
///

///
/// \fn void NC2dMatrix<T>::flipVertical();
/// \brief Flips the entire matrix vertically
///

///
/// \fn NC2dMatrix NC2dMatrix::operator=(const NC2dMatrix &other);
/// \brief Copy operator
/// \param other Matrix to copy data from
/// \return Copy of this matrix after the operation
///

///
/// \fn NC2dMatrix NC2dMatrix::operator+=(const NC2dMatrix &other);
/// \brief Adds given matrix to current matrix
/// \param other Matrix to add data from
/// \return Copy of this matrix after the operation
///

///
/// \fn NC2dMatrix NC2dMatrix::operator-=(const NC2dMatrix &other);
/// \brief Removes given matrix to current matrix
/// \param other Matrix to remove data from
/// \return Copy of this matrix after the operation
///

///
/// \fn NC2dMatrix NC2dMatrix::operator*=(const NC2dMatrix &other);
/// \brief Multiplies given matrix to current matrix
/// \param other Matrix to multiply data from
/// \return Copy of this matrix after the operation
///

///
/// \fn NC2dMatrix NC2dMatrix::operator/=(const NC2dMatrix &other);
/// \brief Divides current matrix by given matrix
/// \param other Dividor matrix
/// \return Copy of this matrix after the operation
///

///
/// \fn NC2dMatrix NC2dMatrix::operator*=(const double &val);
/// \brief Multiplies all matrix elements by given value
/// \param val Dividor double value
/// \return Copy of this matrix after the operation
///

///
/// \fn T& NC2dMatrix::operator()(size_t row, size_t col);
/// \brief Reference access to a matrix element. Note: it doesn't perform bounds-checking
/// \param row Element row position
/// \param col Element column position
/// \return Reference to element at given position
///

///
/// \fn T NC2dMatrix::operator()(size_t row, size_t col) const;
/// \brief Const access to a matrix element. Note: it doesn't perform bounds-checking
/// \param row Element row position
/// \param col Element column position
/// \return Copy element at given position
///
/* End NC2dMatrix */

///
/// \class Nephria_Core
/// \brief Main library class (used ?)
///

///
/// \brief Default constructor
///
Nephria_Core::Nephria_Core()
{
}
}
