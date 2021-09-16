#ifndef NCIMAGE_H
#define NCIMAGE_H

#include <cstdint>
#include <string>

#include "ncore_global.h"
#include "NCore/nc2dmatrix.h"
#include "NCore/ncrgb.h"
#include "NCore/ncpoint.h"

namespace NCore {
class NCORE_EXPORT NCImage
{
public:
    NCImage();
    NCImage(const size_t width, const size_t height);
    ~NCImage();

    void resize(const size_t width, const size_t height);

    size_t width() const;
    size_t height() const;

    NCRgb pixel(size_t x, size_t y) const;
    NCRgb pixel(const NCPoint &pt) const;
    void setPixel(size_t x, size_t y, const NCRgb &pix);
    void setPixel(const NCPoint &pt, const NCRgb &pix);
    void setGrayscalePixel(size_t x, size_t y, uint8_t value);
    void setGrayscalePixel(NCPoint pt, uint8_t value);

    void fill(NCRgb col);

    void flipHorizontal();
    void flipVertical();

    bool save(std::string fileName);

    template<typename T>
    static NCImage matrixToImage(const NC2dMatrix<T> &matrix)
    {
        // Size check
        if ((matrix.rows() == 0) || (matrix.cols() == 0))
            return NCImage();

        NCImage image(matrix.cols(), matrix.rows());

        for (size_t row = 0; row < matrix.rows(); ++row) {
            for (size_t col = 0; col < matrix.cols(); ++col) {
                uint8_t pix = (uint8_t)matrix(row, col);
                image.setGrayscalePixel(col, row, pix);
            }
        }

        return image;
    };

private:
    NC2dMatrix<NCRgb> m_imageMatrix;
};
}

#endif // NCIMAGE_H
