#include "Frame.hpp"
#include "RenderingTools.hpp"

using namespace Displays;

namespace UI {

    Frame::Frame(int x, int y, int width, int height){
        this->_x = x;
        this->_y = y;
        this->_width = width % 8 ? width + 8 - (width % 8) : width;
        this->_height = height;
        this->_image = new unsigned char[(this->_width * this->_height) / 8]; //Reserve space for total image size
    };
    Frame::Frame(unsigned char* image, int x, int y, int width, int height){
        this->_x = x;
        this->_y = y;
        this->_width = width % 8 ? width + 8 - (width % 8) : width;
        this->_height = height;
        this->_image = image;
    };
    unsigned char* Frame::GetImage(void){
        return this->_image;
    };
    int Frame::GetX(void){
        return this->_x;
    };
    int Frame::GetY(void){
        return this->_y;
    };
    int Frame::GetWidth(void){
        return this->_width;
    };
    int Frame::GetHeight(void){
        return this->_height;
    };
    int Frame::GetRotate(void){
        return this->_rotate;
    };
    void Frame::SetRotate(DisplayOrientation rotate){
        this->_rotate = rotate;
    };

    /**
     *  @brief: clear the image
     */
    void Frame::Clear(DisplayColor color) {
        for (int x = 0; x < this->_width; x++) {
            for (int y = 0; y < this->_height; y++) {
                RenderingTools::DrawAbsolutePixel(this, x, y, color);
            }
        }
    }
}