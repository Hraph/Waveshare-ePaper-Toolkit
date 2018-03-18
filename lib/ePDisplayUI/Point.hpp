#ifndef POINT_H
#define POINT_H

#include "IUIElement.hpp"
#include "Frame.hpp"
#include <IDisplay.hpp>

#pragma once

using namespace Displays;

namespace UI {

    class Point : public IUIElement {
        public:
            Point();
            Point(int x, int y, DisplayColor color);
            int GetX(void);
            int GetY(void);
            DisplayColor GetColor(void);
            void SetX(int x);
            void SetY(int y);
            void SetColor(DisplayColor color);
        private:
            int x;
            int y;
            DisplayColor color;
        protected:
            Frame* Render(Frame *frame) = 0;
    };
}

#endif /* POINT_H */