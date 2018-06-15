#include "Text.hpp"
#include "RenderingTools.hpp"
#include <stdlib.h>

using namespace Displays;

namespace UI {
    Text::Text(int x, int y, String *content, sFONT *font){
        this->_x = x;
        this->_y = y;
        this->_font = font;
        this->_content = content;
    };
    Text::Text(int x, int y, String *content, sFONT *font, DisplayColor color){
        Text(x, y, content, font);
        this->SetColor(color);
    };

    //Getters - Setters
    int Text::GetX(void){
        return this->_x;
    };
    int Text::GetY(void){
        return this->_y;
    };
    void Text::SetX(int x){
        this->_x = x;
    };
    void Text::SetY(int y){
        this->_y= y;
    };

    Frame* Text::Render(Frame *frame){
        RenderingTools::DrawStringAt(frame, this->_x, this->_y, _content, _font, this->GetColor());
        return frame;
    };
}