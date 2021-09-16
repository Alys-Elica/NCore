#include "ncimage.h"

#include <fstream>

#include "ncore.h"

namespace NCore {
///
/// \class NCImage
/// \brief Convenience class representing a RGB 24 bits image
///

///
/// \brief NCImage::NCImage
///
NCImage::NCImage()
{
}

///
/// \brief NCImage::NCImage
/// \param width Image width
/// \param height Image height
///
NCImage::NCImage(const size_t width, const size_t height)
{
    this->resize(width, height);
}

///
/// \brief NCImage::~NCImage
///
NCImage::~NCImage()
{
}

///
/// \brief Resize the image and fills it with default constructed NCRgb object
/// \param width New image width
/// \param height New image height
///
void NCImage::resize(const size_t width, const size_t height)
{
    m_imageMatrix.resize(height, width);
    m_imageMatrix.fill(NCRgb());
}

///
/// \brief NCImage::width
/// \return Image width
///
size_t NCImage::width() const
{
    return m_imageMatrix.cols();
}

///
/// \brief NCImage::height
/// \return Image height
///
size_t NCImage::height() const
{
    return m_imageMatrix.rows();
}

///
/// \brief NCImage::pixel
/// \param x Pixel X coordinate
/// \param y Pixel Y coordinate
/// \return Pixel at given XY coordinate, default constructed NCRgb if out of bounds
///
NCRgb NCImage::pixel(size_t x, size_t y) const
{
    if (x < m_imageMatrix.cols() && y < m_imageMatrix.rows())
        return m_imageMatrix(y, x);
    return NCRgb();
}

///
/// \brief NCImage::pixel
/// \param pt Pixel position point
/// \return Pixel at given point coordinate, default constructed NCRgb if out of bounds
///
NCRgb NCImage::pixel(const NCPoint &pt) const
{
    if (pt.x() < m_imageMatrix.cols() && pt.y() < m_imageMatrix.rows())
        return m_imageMatrix(pt.y(), pt.x());
    return NCRgb();
}

///
/// \brief Set a pixel at given position
/// \param x Pixel X coordinate
/// \param y Pixel Y coordinate
/// \param pix New pixel to set
///
void NCImage::setPixel(size_t x, size_t y, const NCRgb &pix)
{
    if (x < m_imageMatrix.cols() && y < m_imageMatrix.rows())
        m_imageMatrix(y, x) = pix;
}

///
/// \brief Set a pixel at given position
/// \param pt Pixel coordinates
/// \param pix New pixel to set
///
void NCImage::setPixel(const NCPoint &pt, const NCRgb &pix)
{
    setPixel(pt.x(), pt.y(), pix);
}

///
/// \brief Sets a grayscale intensity pixel at given coordinates
/// \param x Pixel X coordinate
/// \param y Pixel Y coordinate
/// \param value Grayscale intensity value
///
void NCImage::setGrayscalePixel(size_t x, size_t y, uint8_t value)
{
    setPixel(x, y, NCRgb(value, value, value));
}

///
/// \brief NCImage::setGrayscalePixel
/// \param pt Pixel position point
/// \param value Grayscale intensity value
///
void NCImage::setGrayscalePixel(NCPoint pt, uint8_t value)
{
    setPixel(pt, NCRgb(value, value, value));
}

///
/// \brief Fills the entire image with given color
/// \param col New color
///
void NCImage::fill(NCRgb col)
{
    m_imageMatrix.fill(col);
}

///
/// \brief Flips the entire image horizontally
///
void NCImage::flipHorizontal()
{
    NCImage tmp = *this;

    for (size_t x = 0; x < tmp.width(); ++x)
        for (size_t y = 0; y < tmp.height(); ++y)
            this->setPixel(x, y, tmp.pixel(tmp.width() - 1 - x, y));
}

///
/// \brief Flips the entire image vertically
///
void NCImage::flipVertical()
{
    NCImage tmp = *this;

    for (size_t x = 0; x < tmp.width(); ++x)
        for (size_t y = 0; y < tmp.height(); ++y)
            this->setPixel(x, y, tmp.pixel(x, tmp.height() - 1 - y));
}

///
/// \brief Saves the image as BMP with given file name
/// \param fileName Output image filename
/// \return True if successful, false otherwise
///
bool NCImage::save(std::string fileName)
{
    std::ofstream outFile(fileName, std::ios::out | std::ios::trunc | std::ios::binary);

    uint32_t filesize = 54 + (3 * m_imageMatrix.cols() * m_imageMatrix.rows());

    uint16_t width = m_imageMatrix.cols();
    uint16_t height = m_imageMatrix.rows();
    unsigned char bmpFileHeader[14] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0 };
    unsigned char bmpinfoheader[40] = { 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0 };

    bmpFileHeader[2] = (unsigned char)(filesize);
    bmpFileHeader[3] = (unsigned char)(filesize >> 8);
    bmpFileHeader[4] = (unsigned char)(filesize >> 16);
    bmpFileHeader[5] = (unsigned char)(filesize >> 24);

    bmpinfoheader[4] = (unsigned char)(width);
    bmpinfoheader[5] = (unsigned char)(width >> 8);
    bmpinfoheader[6] = (unsigned char)(width >> 16);
    bmpinfoheader[7] = (unsigned char)(width >> 24);
    bmpinfoheader[8] = (unsigned char)(height);
    bmpinfoheader[9] = (unsigned char)(height >> 8);
    bmpinfoheader[10] = (unsigned char)(height >> 16);
    bmpinfoheader[11] = (unsigned char)(height >> 24);

    outFile.write((char *)bmpFileHeader, 14);
    outFile.write((char *)bmpinfoheader, 40);

    for (int y = height - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            NCRgb pix = pixel(x, y);

            uint8_t outPix[3] = {
                pix.b(),
                pix.g(),
                pix.r(),
            };
            outFile.write((char *)outPix, 3);
        }

        // Padding
        unsigned char bmpPad[3] = { 0, 0, 0 };
        outFile.write((char *)bmpPad, (4 - (width * 3) % 4) % 4);
    }

    outFile.close();

    return true;
}
}
