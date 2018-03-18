#include "Frame.hpp"
#include "RenderingTools.hpp"

using namespace Displays;

namespace UI {

    Frame::Frame(int x, int y, int width, int height){
        this->x = x;
        this->y = y;
        this->width = width % 8 ? width + 8 - (width % 8) : width;
        this->height = height;
    };
    Frame::Frame(unsigned char* image, int x, int y, int width, int height){
        this->x = x;
        this->y = y;
        this->width = width % 8 ? width + 8 - (width % 8) : width;
        this->height = height;
        this->image = image;
    };
    unsigned char* Frame::GetImage(void){
        return this->image;
    };
    int Frame::GetX(void){
        return this->x;
    };
    int Frame::GetY(void){
        return this->y;
    };
    int Frame::GetWidth(void){
        return this->width;
    };
    int Frame::GetHeight(void){
        return this->height;
    };
    int Frame::GetRotate(void){
        return this->rotate;
    };
    void Frame::SetRotate(int rotate){
        this->rotate = rotate;
    };

    /**
     *  @brief: clear the image
     */
    void Frame::Clear(DisplayColor color) {
        for (int x = 0; x < this->width; x++) {
            for (int y = 0; y < this->height; y++) {
                RenderingTools::DrawAbsolutePixel(this, x, y, color);
            }
        }
    }
}