#ifndef WINDOW_H
#define WINDOW_H

#pragma once

#include <IPanel.hpp>
#include <IDisplay.hpp>

using namespace Displays;

namespace UI {

    class Window {
        public:
            Window(IPanel *panel, int width, int height);
            Window(IPanel *panel, IDisplay *display);
            void SetPanel(IPanel *panel);
            void Clear(void);
            Frame* Render(void);
        private:
            Frame* _frame;
            IPanel* _panel;
    };
}

#endif /* WINDOW_H */