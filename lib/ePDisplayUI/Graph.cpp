#include "Graph.hpp"
#include "RenderingTools.hpp"
#include <Arduino.h>
#include <algorithm>

using namespace Displays;

namespace UI {
    Graph::Graph(int _fromX, int _fromY, int _toX, int _toY){
        this->_fromX = _fromX;
        this->_fromY = _fromY;
        this->_toX = _toX;
        this->_toY = _toY;
    };
    Graph::Graph(int _fromX, int _fromY, int _toX, int _toY, bool _filled){
        this->_fromX = _fromX;
        this->_fromY = _fromY;
        this->_toX = _toX;
        this->_toY = _toY;
        this->_filled = _filled;
    };
    Graph::Graph(int _fromX, int _fromY, int _toX, int _toY, DisplayColor color){
        this->_fromX = _fromX;
        this->_fromY = _fromY;
        this->_toX = _toX;
        this->_toY = _toY;
        this->SetColor(color);
    };
    Graph::Graph(int _fromX, int _fromY, int _toX, int _toY,bool _filled, DisplayColor color){
        this->_fromX = _fromX;
        this->_fromY = _fromY;
        this->_toX = _toX;
        this->_toY = _toY;
        this->_filled = _filled;
        this->SetColor(color);
    };

    //Getters - Setters
    int Graph::GetFromX(void){
        return this->_fromX;
    };
    int Graph::GetFromY(void){
        return this->_fromY;
    };
    int Graph::GetToX(void){
        return this->_toX;
    };
    int Graph::GetToY(void){
        return this->_toY;
    };
    bool Graph::GetFilled(void){
        return this->_filled;
    }
    void Graph::SetFromX(int x){
        this->_fromX = x;
    };
    void Graph::SetFromY(int y){
        this->_fromY= y;
    };
    void Graph::SetToX(int x){
        this->_toX = x;
    };
    void Graph::SetToY(int y){
        this->_toY= y;
    };
    void Graph::SetFilled(bool _filled){
        this->_filled= _filled;
    };
    
    Frame* Graph::Render(Frame *frame){
        if (_dots.size() < 2) return frame; //2 values are required

        int lengthX = _toX - _fromX;
        int lengthY = _toY - _fromY;
        
        int sizeBetween = lengthX / (_dots.size() - 1); //Last point is on toX so we dont count it
        float maxY = *std::max_element(_dots.begin(), _dots.end());
        float minY = *std::min_element(_dots.begin(), _dots.end());
        
        int nextX = 0;
        int nextY = map(_dots[0], minY, maxY, _toY, _fromY);

        for(int i = 0; i < _dots.size() - 1; ++i){
            int x = nextX;
            int y = nextY;
            nextX += sizeBetween;
            nextY = map(_dots[i+1], minY, maxY, _toY, _fromY);
            RenderingTools::DrawLine(frame, x, y, nextX, nextY, GetColor());

            /*Serial.print("From ");
            Serial.print(x);
            Serial.print(",");
            Serial.print(y);
            Serial.print(" to ");
            Serial.print(nextX);
            Serial.print(",");
            Serial.println(nextY);*/
        }
        return frame;
    };
}