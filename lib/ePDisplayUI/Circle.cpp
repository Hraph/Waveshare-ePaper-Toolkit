#include "Circle.hpp"
#include "RenderingTools.hpp"

using namespace Displays;

namespace UI {
    Circle::Circle(int x, int y, int radius){
        this->x = x;
        this->y = y;
        this->radius = radius;
    };
    Circle::Circle(int x, int y, int radius, DisplayColor color){
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->color = color;
    };

    //Getters - Setters
    int Circle::GetX(void){
        return this->x;
    };
    int Circle::GetY(void){
        return this->y;
    };
    DisplayColor Circle::GetColor(void){
        return this->color;
    };
    void Circle::SetX(int x){
        this->x = x;
    };
    void Circle::SetY(int y){
        this->y= y;
    };
    void Circle::SetRadius(int radius){
        this->radius= radius;
    };
    void Circle::SetColor(DisplayColor color){
        this->color = color;
    };

    Frame* Circle::Render(Frame *frame){
        RenderingTools::DrawCircle(frame, this->x, this->y, this->radius, this->color);
        return frame;
    };
}