#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "IControl.hpp"
#include "Frame.hpp"
#include <DisplayParameters.hpp>

#pragma once

using namespace Displays;

namespace UI {

    class Rectangle : public IControl {
        public:
            Rectangle();
            Rectangle(int fromX, int fromY, int toX, int toY);
            Rectangle(int fromX, int fromY, int toX, int toY, bool filled);
            Rectangle(int fromX, int fromY, int toX, int toY, DisplayColor color);
            Rectangle(int fromX, int fromY, int toX, int toY, bool filled, DisplayColor color);
            int GetFromX(void);
            int GetFromY(void);
            int GetToX(void);
            int GetToY(void);
            bool GetFilled(void);
            DisplayColor GetColor(void);
            void SetFromX(int x);
            void SetFromY(int y);
            void SetToX(int x);
            void SetToY(int y);
            void SetFilled(bool filled);
            void SetColor(DisplayColor color);
        private:
            int fromX;
            int fromY;
            int toX;
            int toY;
            bool filled = false;
            DisplayColor color = DisplayColor::Uncolored;
        protected:
            Frame* Render(Frame *frame);
    };
}

#endif /* RECTANGLE_H */