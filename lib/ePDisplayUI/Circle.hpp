#ifndef CIRCLE_H
#define CIRCLE_H

#include "IControl.hpp"
#include "Frame.hpp"
#include <DisplayParameters.hpp>

#pragma once

using namespace Displays;

namespace UI {

    class Circle : public IControl {
        public:
            Circle();
            Circle(int x, int y, int radius);
            Circle(int x, int y, int radius, DisplayColor color);
            int GetX(void);
            int GetY(void);
            int GetRadius(void);
            DisplayColor GetColor(void);
            void SetX(int x);
            void SetY(int y);
            void SetRadius(int radius);
            void SetColor(DisplayColor color);
        private:
            int x;
            int y;
            int radius;
            DisplayColor color = DisplayColor::Uncolored;
        protected:
            Frame* Render(Frame *frame);
    };
}

#endif /* CIRCLE_H */