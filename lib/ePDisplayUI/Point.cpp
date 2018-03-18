#include "Point.hpp"
#include "RenderingTools.hpp"

using namespace Displays;

namespace UI {
    Point::Point(int x, int y){
        this->x = x;
        this->y = y;
    };
    Point::Point(int x, int y, DisplayColor color){
        Point(x, y);
        this->color = color;
    };

    //Getters - Setters
    int Point::GetX(void){
        return this->x;
    };
    int Point::GetY(void){
        return this->y;
    };
    DisplayColor Point::GetColor(void){
        return this->color;
    };
    void Point::SetX(int x){
        this->x = x;
    };
    void Point::SetY(int y){
        this->y= y;
    };
    void Point::SetColor(DisplayColor color){
        this->color = color;
    };

    Frame* Point::Render(Frame *frame){
        RenderingTools::DrawPixel(frame, this->x, this->y, this->color);
        return frame;
    };
}