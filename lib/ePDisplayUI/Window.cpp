#include "Window.hpp"
#include "DisplayParameters.hpp"

using namespace Displays;

namespace UI {
    Window::Window(){
        //Initialize empty frame
        _blackFrame = new Frame(0, 0, 0, 0); 
        _coloredFrame = new Frame(0, 0, 0, 0);
    }
    Window::Window(Frame* frame, bool isColoredFrame){
        if (!isColoredFrame) {
            _blackFrame = frame;
            _coloredFrame = new Frame(0, 0, 0, 0);
        }       
        else {
            _blackFrame = new Frame(0, 0, 0, 0);
            _coloredFrame = frame;
        }
    }
    Window::Window(Frame* blackFrame, Frame* coloredFrame){
        _blackFrame = blackFrame;
        _coloredFrame = coloredFrame;
    }
    Window::Window(IPanel *panel, int width, int height){
        //Initialize and clear frames
        _blackFrame = new Frame(0, 0, width, height);
        _blackFrame->Clear(Displays::DisplayColor::White);
        _coloredFrame = new Frame(0, 0, width, height);
        _coloredFrame->Clear(Displays::DisplayColor::White);
        _panel = panel;
    }

    void Window::SetBlackFrame(Frame* frame){
        _blackFrame = frame;
    }
    void Window::SetColoredFrame(Frame* frame){
        _coloredFrame = frame;
    }
    Frame* Window::GetBlackFrame(void){
        return _blackFrame;
    }
    Frame* Window::GetColoredFrame(void){
        return _coloredFrame;
    }
    Frame* Window::RenderBlack(void){
        return (_panel != 0) ? _panel->RenderBlack(_blackFrame) : _blackFrame; //If no panel has been set return directly the frame
    }
    Frame* Window::RenderColored(void){
        return (_panel != 0) ? _panel->RenderColored(_coloredFrame) : _coloredFrame; //If no panel has been set return directly the frame
    }

    void Window::SetRotate(DisplayOrientation orientation){
        _blackFrame->SetRotate(orientation);
        _coloredFrame->SetRotate(orientation);
    }

    void Window::SetPanel(IPanel* panel){
        _panel = panel;
    }    
}