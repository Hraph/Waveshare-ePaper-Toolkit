#include "Rectangle.hpp"
#include "RenderingTools.hpp"

using namespace Displays;

namespace UI {
    Rectangle::Rectangle(int fromX, int fromY, int toX, int toY){
        this->fromX = fromX;
        this->fromY = fromY;
        this->toX = toX;
        this->toY = toY;
    };
    Rectangle::Rectangle(int fromX, int fromY, int toX, int toY, bool filled){
        this->fromX = fromX;
        this->fromY = fromY;
        this->toX = toX;
        this->toY = toY;
        this->filled = filled;
    };
    Rectangle::Rectangle(int fromX, int fromY, int toX, int toY, DisplayColor color){
        this->fromX = fromX;
        this->fromY = fromY;
        this->toX = toX;
        this->toY = toY;
        this->color = color;
    };
    Rectangle::Rectangle(int fromX, int fromY, int toX, int toY,bool filled, DisplayColor color){
        this->fromX = fromX;
        this->fromY = fromY;
        this->toX = toX;
        this->toY = toY;
        this->filled = filled;
        this->color = color;
    };

    //Getters - Setters
    int Rectangle::GetFromX(void){
        return this->fromX;
    };
    int Rectangle::GetFromY(void){
        return this->fromY;
    };
    int Rectangle::GetToX(void){
        return this->toX;
    };
    int Rectangle::GetToY(void){
        return this->toY;
    };
    bool Rectangle::GetFilled(void){
        return this->filled;
    }
    DisplayColor Rectangle::GetColor(void){
        return this->color;
    };
    void Rectangle::SetFromX(int x){
        this->fromX = x;
    };
    void Rectangle::SetFromY(int y){
        this->fromY= y;
    };
    void Rectangle::SetToX(int x){
        this->toX = x;
    };
    void Rectangle::SetToY(int y){
        this->toY= y;
    };
    void Rectangle::SetFilled(bool filled){
        this->filled= filled;
    };
    void Rectangle::SetColor(DisplayColor color){
        this->color = color;
    };

    Frame* Rectangle::Render(Frame *frame){
        if (!this->filled)
            RenderingTools::DrawRectangle(frame, this->fromX, this->fromY, this->toX, this->toY, this->color);
        else
            RenderingTools::DrawFilledRectangle(frame, this->fromX, this->fromY, this->toX, this->toY, this->color);
        return frame;
    };
}