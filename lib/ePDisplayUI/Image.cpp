#include "Image.hpp"
#include "RenderingTools.hpp"

using namespace Displays;

namespace UI {
    Image::Image(int x, int y, int width, int height, const unsigned char* buffer){
        this->_x = x;
        this->_y = y;
        this->_width = width;
        this->_height = height;
        this->_buffer = buffer;
    };
    Image::Image(int x, int y,int width, int height, const unsigned char* buffer, DisplayColor color){
        Image(x, y, width, height, buffer);
        this->SetColor(color);
    };

    //Getters - Setters
    int Image::GetX(void){
        return this->_x; 
    };
    int Image::GetY(void){
        return this->_y;
    };
    void Image::SetX(int x){
        this->_x = x;
    };
    void Image::SetY(int y){
        this->_y= y;
    };
    int Image::GetWidth(void){
        return this->_width;
    };
    int Image::GetHeight(void){
        return this->_height;
    };

    Frame* Image::Render(Frame *frame){
        RenderingTools::DrawImage(frame, this->_x, this->_y, this->_width, this->_height, this->_buffer, this->GetColor());        
        return frame;
    };
}