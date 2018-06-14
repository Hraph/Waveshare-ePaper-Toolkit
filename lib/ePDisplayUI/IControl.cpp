#include "IControl.hpp"
#include <Arduino.h>

using namespace Displays;

namespace UI {
    void IControl::SetColor(DisplayColor color){
        _color = color;
    }
    DisplayColor IControl::GetColor(void){
        return _color;
    }
    
}