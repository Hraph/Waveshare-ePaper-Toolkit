#include "Circle.hpp"
#include "RenderingTools.hpp"

using namespace Displays;

namespace UI {
    Circle::Circle(int x, int y, int radius){
        this->x = x;
        this->y = y;
        this->radius = radius;
    };
    Circle::Circle(int x, int y, int radius, bool filled){
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->filled = filled;
    };
    Circle::Circle(int x, int y, int radius, DisplayColor color){
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->SetColor(color);
    };
    Circle::Circle(int x, int y, int radius, bool filled, DisplayColor color){
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->filled = filled;
        this->SetColor(color);
    };

    //Getters - Setters
    int Circle::GetX(void){
        return this->x;
    };
    int Circle::GetY(void){
        return this->y;
    };
    int Circle::GetRadius(void){
        return this->radius;
    };
    bool Circle::GetFilled(void){
        return this->filled;
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
    void Circle::SetFilled(bool filled){
        this->filled = filled;
    };

    Frame* Circle::Render(Frame *frame){
        if (!this->filled)
            RenderingTools::DrawCircle(frame, this->x, this->y, this->radius, this->GetColor());
        else   
            RenderingTools::DrawFilledCircle(frame, this->x, this->y, this->radius, this->GetColor());
        return frame;
    };
}