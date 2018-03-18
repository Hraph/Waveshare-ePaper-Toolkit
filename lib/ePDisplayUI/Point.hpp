#ifndef POINT_H
#define POINT_H

#include "IUIElement.hpp"
#include "Frame.hpp"
#include <DisplayColor.hpp>

#pragma once

using namespace Displays;

namespace UI {

    class Point : public IUIElement {
        public:
            Point();
            Point(int x, int y);
            Point(int x, int y, DisplayColor color);
            int GetX(void);
            int GetY(void);
            DisplayColor GetColor(void);
            void SetX(int x);
            void SetY(int y);
            void SetColor(DisplayColor color);
            Frame* Render(Frame *frame);
        private:
            int x = 0;
            int y = 0;
            DisplayColor color = DisplayColor::Uncolored;
            
    };
}

#endif /* POINT_H */