#ifndef IMAGE_H
#define IMAGE_H

#include "IControl.hpp"
#include "Frame.hpp"
#include <DisplayParameters.hpp>

#pragma once

using namespace Displays;

namespace UI {

    class Image : public IControl {
        public:
            Image();
            Image(int x, int y, int width, int height, const unsigned char* buffer);
            Image(int x, int y, int width, int height, const unsigned char* buffer, DisplayColor color);
            int GetX(void);
            int GetY(void);
            void SetX(int x);
            void SetY(int y);
            int GetWidth(void);
            int GetHeight(void);
            Frame* Render(Frame *frame);
        private:
            int _x;
            int _y;
            int _width;
            int _height;
            const unsigned char* _buffer;
    };
}

#endif /* IMAGE_H */