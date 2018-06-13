#include "Window.hpp"

using namespace Displays;

namespace UI {
    Window::Window(IPanel *panel, int width, int height){
        _frame = new Frame(0, 0, width, height);
        _panel = panel;
    }

    Window::Window(IPanel *panel, IDisplay *display){
        _frame = new Frame(0, 0, display->GetWidth(), display->GetHeight());
        _panel = panel;
    }

    Frame* Window::Render(void){
        return _panel->Render(_frame);
    }
    
}