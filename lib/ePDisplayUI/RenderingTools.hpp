#ifndef RENDERINGTOOLS_H
#define RENDERINGTOOLS_H

#include <Fonts.hpp>
#include <Frame.hpp>

#pragma once

// Display orientation
#define ROTATE_0            0
#define ROTATE_90           1
#define ROTATE_180          2
#define ROTATE_270          3

// Color inverse. 1 or 0 = set or reset a bit if set a colored pixel
#define IF_INVERT_COLOR     1

namespace UI {

    class RenderingTools {
        public:
            static Frame* DrawAbsolutePixel(Frame *frame, int x, int y, int colored);
            static Frame* DrawPixel(Frame *frame, int x, int y, int colored);
            static Frame* DrawCharAt(Frame *frame, int x, int y, char ascii_char, sFONT* font, int colored);
            static Frame* DrawStringAt(Frame *frame, int x, int y, const char* text, sFONT* font, int colored);
            static Frame* DrawLine(Frame *frame, int x0, int y0, int x1, int y1, int colored);
            static Frame* DrawHorizontalLine(Frame *frame, int x, int y, int width, int colored);
            static Frame* DrawVerticalLine(Frame *frame, int x, int y, int height, int colored);
            static Frame* DrawRectangle(Frame *frame, int x0, int y0, int x1, int y1, int colored);
            static Frame* DrawFilledRectangle(Frame *frame, int x0, int y0, int x1, int y1, int colored);
            static Frame* DrawCircle(Frame *frame, int x, int y, int radius, int colored);
            static Frame* DrawFilledCircle(Frame *frame, int x, int y, int radius, int colored);
    };
}

#endif /* RENDERINGTOOLS_H */