#ifndef LINE_H
#define LINE_H

#include "IControl.hpp"
#include "Frame.hpp"
#include <DisplayParameters.hpp>

#pragma once

using namespace Displays;

namespace UI {

    class Line : public IControl {
        public:
            Line();
            Line(int fromX, int fromY, int toX, int toY);
            Line(int fromX, int fromY, int toX, int toY, DisplayColor color);
            int GetFromX(void);
            int GetFromY(void);
            int GetToX(void);
            int GetToY(void);
            void SetFromX(int x);
            void SetFromY(int y);
            void SetToX(int x);
            void SetToY(int y);
            Frame* Render(Frame *frame);
        private:
            int fromX;
            int fromY;
            int toX;
            int toY;            
    };
}

#endif /* LINE_H */