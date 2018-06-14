#include "Window.hpp"
#include "DisplayParameters.hpp"

using namespace Displays;

namespace UI {
    Window::Window(IPanel *panel, int width, int height){
        _uncoloredFrame = new Frame(0, 0, width, height);
        _coloredFrame = new Frame(0, 0, width, height);
        _uncoloredFrame->Clear(Displays::DisplayColor::Uncolored);
        _coloredFrame->Clear(Displays::DisplayColor::Colored);
        _panel = panel;
    }

    Frame* Window::GetUncoloredFrame(void){
        return _uncoloredFrame;
    }
    Frame* Window::RenderUncolored(void){
        return _panel->RenderUncolored(_uncoloredFrame);
    }
    Frame* Window::GetColoredFrame(void){
        return _coloredFrame;
    }
    Frame* Window::RenderColored(void){
        return _panel->RenderColored(_coloredFrame);
    }
    
}