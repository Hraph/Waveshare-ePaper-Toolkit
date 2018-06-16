#ifndef RENDERINGTOOLS_H
#define RENDERINGTOOLS_H

#include <Fonts.hpp>
#include <Frame.hpp>
#include <DisplayParameters.hpp>
#include <Arduino.h>

#pragma once

using namespace Displays;

// Color inverse. 1 or 0 = set or reset a bit if set a colored pixel
#define IF_INVERT_COLOR     1

namespace UI {

    class RenderingTools {
        public:
            static Frame* DrawAbsolutePixel(Frame *frame, int x, int y, DisplayColor color);
            static Frame* DrawPixel(Frame *frame, int x, int y, DisplayColor color);
            static Frame* DrawCharAt(Frame *frame, int x, int y, char ascii_char, sFONT* font, DisplayColor color);
            static Frame* DrawStringAt(Frame *frame, int x, int y, const char* text, sFONT* font, DisplayColor color);
            static Frame* DrawStringAt(Frame *frame, int x, int y, String* text, sFONT* font, DisplayColor color);
            static Frame* DrawImage(Frame *frame, int x, int y, int width, int height, const unsigned char* buffer, DisplayColor color);
            static Frame* DrawLine(Frame *frame, int x0, int y0, int x1, int y1, DisplayColor color);
            static Frame* DrawHorizontalLine(Frame *frame, int x, int y, int width, DisplayColor color);
            static Frame* DrawVerticalLine(Frame *frame, int x, int y, int height, DisplayColor color);
            static Frame* DrawRectangle(Frame *frame, int x0, int y0, int x1, int y1, DisplayColor color);
            static Frame* DrawFilledRectangle(Frame *frame, int x0, int y0, int x1, int y1, DisplayColor color);
            static Frame* DrawCircle(Frame *frame, int x, int y, int radius, DisplayColor color);
            static Frame* DrawFilledCircle(Frame *frame, int x, int y, int radius, DisplayColor color);
    };
}

#endif /* RENDERINGTOOLS_H */