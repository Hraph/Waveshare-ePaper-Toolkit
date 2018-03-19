#ifndef POINT_H
#define POINT_H

#include "IControl.hpp"
#include "Frame.hpp"
#include <DisplayParameters.hpp>

#pragma once

using namespace Displays;

namespace UI {

    class Point : public IControl {
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
        private:
            int x;
            int y;
            DisplayColor color = DisplayColor::Uncolored;
        protected:
            Frame* Render(Frame *frame) = 0;
    };
}

#endif /* POINT_H */