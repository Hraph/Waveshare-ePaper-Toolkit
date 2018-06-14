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
            Frame* GetUncoloredFrame(void);
            Frame* RenderUncolored(void);
            Frame* GetColoredFrame(void);
            Frame* RenderColored(void);
        private:
            Frame* _uncoloredFrame;
            Frame* _coloredFrame;
            IPanel* _panel;
    };
}

#endif /* WINDOW_H */