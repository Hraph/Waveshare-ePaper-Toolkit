#include "IPanel.hpp"
#include <Arduino.h>

using namespace Displays;

namespace UI {
    Frame* IPanel::RenderBlack(Frame *frame){
        for(int i = 0; i < _elements.size(); i++) {
            if (_elements[i]->IsEnabled() && _elements[i]->GetColor() == Displays::DisplayColor::Black){
                _elements[i]->Render(frame);
            }
        }
        return frame;   
    }

    Frame* IPanel::RenderColored(Frame *frame){
        for(int i = 0; i < _elements.size(); i++) {
            if (_elements[i]->IsEnabled() && _elements[i]->GetColor() == Displays::DisplayColor::Colored){
                _elements[i]->Render(frame);   
            }
        }
        return frame;   
    }

    void IPanel::SetNumberOfElements(int number){
        _elements.reserve(number); 
    }

    IPanel::IPanel(){
        
    }

    IPanel* IPanel::AddElement(IControl *element){
        _elements.push_back(element);
        return this;
    }

    void IPanel::RemoveElement(int index){
        _elements.erase(_elements.begin() + index);
    }

    void IPanel::RemoveElement(IControl* element){
        _elements.erase(std::remove(_elements.begin(), _elements.end(), element), _elements.end());
    }

    void IPanel::ClearElements(void){
        _elements.clear();
    }
    
    bool IPanel::HasElements(void){
        return _elements.size() != 0;
    }

    int IPanel::CountElements(void){
        return _elements.size();
    }
    
}