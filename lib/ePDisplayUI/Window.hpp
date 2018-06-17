#ifndef WINDOW_H
#define WINDOW_H

#pragma once

#include <IPanel.hpp>

using namespace Displays;

namespace UI {

    class Window {
        public:
            Window();
            Window(Frame* frame, bool isColoredFrame = false);
            Window(Frame* blackFrame, Frame* coloredFrame);
            Window(IPanel *panel, int width, int height);
            void SetBlackFrame(Frame* frame);
            Frame* GetBlackFrame(void);
            Frame* RenderBlack(void);
            void SetColoredFrame(Frame* frame);
            Frame* GetColoredFrame(void);
            Frame* RenderColored(void);
            void SetRotate(DisplayOrientation orientation);
            void SetPanel(IPanel* panel);
        private:
            Frame* _blackFrame = 0;
            Frame* _coloredFrame = 0;
            IPanel* _panel = 0;
    };
}

#endif /* WINDOW_H */