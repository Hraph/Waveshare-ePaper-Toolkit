#ifndef FRAME_H
#define FRAME_H

#pragma once

#include <DisplayParameters.hpp>

using namespace Displays;

namespace UI {

    class Frame {
        public:
            Frame(int x, int y, int width, int height);
            Frame(unsigned char* image, int x, int y, int width, int height);
            unsigned char* GetImage(void);
            int GetX(void);
            int GetY(void);
            int GetWidth(void);
            int GetHeight(void);
            int GetRotate(void);
            void SetRotate(DisplayOrientation rotate);
            void Clear(DisplayColor color);

        private:
            unsigned char* image;
            int x;
            int y;
            int width;
            int height;
            DisplayOrientation rotate = DisplayOrientation::Rotate_0;
    };
}

#endif /* FRAME_H */