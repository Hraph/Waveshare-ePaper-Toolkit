#include "Rectangle.hpp"
#include "RenderingTools.hpp"
#include <Arduino.h>

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
        this->SetColor(color);
    };
    Rectangle::Rectangle(int fromX, int fromY, int toX, int toY,bool filled, DisplayColor color){
        this->fromX = fromX;
        this->fromY = fromY;
        this->toX = toX;
        this->toY = toY;
        this->filled = filled;
        this->SetColor(color);
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
    
    Frame* Rectangle::Render(Frame *frame){
        if (!this->filled)
            RenderingTools::DrawRectangle(frame, this->fromX, this->fromY, this->toX, this->toY, this->GetColor());
        else
            RenderingTools::DrawFilledRectangle(frame, this->fromX, this->fromY, this->toX, this->toY, this->GetColor());
        return frame;
    };
}