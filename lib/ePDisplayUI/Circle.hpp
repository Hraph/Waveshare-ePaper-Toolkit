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
            Circle(int x, int y, int radius, bool filled);
            Circle(int x, int y, int radius, DisplayColor color);
            Circle(int x, int y, int radius, bool filled, DisplayColor color);
            int GetX(void);
            int GetY(void);
            int GetRadius(void);
            bool GetFilled(void);
            DisplayColor GetColor(void);
            void SetX(int x);
            void SetY(int y);
            void SetRadius(int radius);
            void SetFilled(bool filled);
            void SetColor(DisplayColor color);
        private:
            int x;
            int y;
            int radius;
            int filled = false;
            DisplayColor color = DisplayColor::Uncolored;
        protected:
            Frame* Render(Frame *frame);
    };
}

#endif /* CIRCLE_H */