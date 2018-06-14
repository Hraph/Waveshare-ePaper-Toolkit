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
            void SetX(int x);
            void SetY(int y);
            Frame* Render(Frame *frame);
        private:
            int x;
            int y;
    };
}

#endif /* POINT_H */