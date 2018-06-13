#include "IPanel.hpp"

using namespace Displays;

namespace UI {
    Frame* IPanel::Render(Frame *frame){
        for(int i = 0; i < _elements.Size(); i++)
        {
            _elements[i]->Render(frame);
        }   
    }

    IPanel* IPanel::SetNumberOfElements(int number){
        _elements.Reserve(number);
    }

    IPanel* IPanel::AddElement(IUIElement *element){
        _elements.PushBack(element);
        return this;
    }
    
    bool IPanel::HasElement(void){
        return _elements.Size() != 0;
    }
    
}