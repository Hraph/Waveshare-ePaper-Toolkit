#include "Frame.hpp"

namespace UI {

    Frame::Frame(int width, int height){
        this->width = width % 8 ? width + 8 - (width % 8) : width;
        this->height = height;
    };
    Frame::Frame(unsigned char* image, int width, int height){
        this->width = width % 8 ? width + 8 - (width % 8) : width;
        this->height = height;
        this->image = image;
    };
    unsigned char* Frame::GetImage(void){
        return this->image;
    };
    int Frame::GetWidth(void){
        return this->width;
    };
    int Frame::GetHeight(void){
        return this->height;
    };

}