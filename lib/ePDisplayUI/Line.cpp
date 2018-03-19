#include "Line.hpp"
#include "RenderingTools.hpp"

using namespace Displays;

namespace UI {
    Line::Line(int fromX, int fromY, int toX, int toY){
        this->fromX = fromX;
        this->fromY = fromY;
        this->toX = toX;
        this->toY = toY;
    };
    Line::Line(int fromX, int fromY, int toX, int toY, DisplayColor color){
        this->fromX = fromX;
        this->fromY = fromY;
        this->toX = toX;
        this->toY = toY;
        this->color = color;
    };

    //Getters - Setters
    int Line::GetFromX(void){
        return this->fromX;
    };
    int Line::GetFromY(void){
        return this->fromY;
    };
    int Line::GetToX(void){
        return this->toX;
    };
    int Line::GetToY(void){
        return this->toY;
    };
    DisplayColor Line::GetColor(void){
        return this->color;
    };
    void Line::SetFromX(int x){
        this->fromX = x;
    };
    void Line::SetFromY(int y){
        this->fromY= y;
    };
    void Line::SetToX(int x){
        this->toX = x;
    };
    void Line::SetToY(int y){
        this->toY= y;
    };
    void Line::SetColor(DisplayColor color){
        this->color = color;
    };

    Frame* Line::Render(Frame *frame){
        RenderingTools::DrawLine(frame, this->fromX, this->fromY, this->toX, this->toY, this->color);
        return frame;
    };
}