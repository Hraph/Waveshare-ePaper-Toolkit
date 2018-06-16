#ifndef WINDOW_H
#define WINDOW_H

#pragma once

#include <IPanel.hpp>

using namespace Displays;

namespace UI {

    class Window {
        public:
            Window(IPanel *panel, int width, int height);
            void SetPanel(IPanel *panel);
            Frame* GetBlackFrame(void);
            Frame* RenderBlack(void);
            Frame* GetColoredFrame(void);
            Frame* RenderColored(void);
            void SetRotate(DisplayOrientation orientation);
        private:
            Frame* _blackFrame;
            Frame* _coloredFrame;
            IPanel* _panel;
    };
}

#endif /* WINDOW_H */