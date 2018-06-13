#include "IPanel.hpp"

using namespace Displays;

namespace UI {
    Frame* IPanel::Render(Frame *frame){
        for(int i = 0; i < _elements.size(); i++) {
            //_elements[i]->Render(frame);
        }   
    }

    void IPanel::SetNumberOfElements(int number){
        _elements.reserve(number);
        
    }

    IPanel::IPanel(){
        
    }

    IPanel* IPanel::AddElement(IUIElement *element){
        _elements.push_back(element);
        return this;
    }
    
    bool IPanel::HasElement(void){
        return _elements.size() != 0;
    }
    
}