#include "Window.hpp"
#include "DisplayParameters.hpp"

using namespace Displays;

namespace UI {
    Window::Window(IPanel *panel, int width, int height){
        _blackFrame = new Frame(0, 0, width, height);
        _blackFrame->Clear(Displays::DisplayColor::White);
        _coloredFrame = new Frame(0, 0, width, height);
        _coloredFrame->Clear(Displays::DisplayColor::White);
        _panel = panel;
    }

    Frame* Window::GetBlackFrame(void){
        return _blackFrame;
    }
    Frame* Window::RenderBlack(void){
        return _panel->RenderBlack(_blackFrame);
    }
    Frame* Window::GetColoredFrame(void){
        return _coloredFrame;
    }
    Frame* Window::RenderColored(void){
        return _panel->RenderColored(_coloredFrame);
    }
    
}