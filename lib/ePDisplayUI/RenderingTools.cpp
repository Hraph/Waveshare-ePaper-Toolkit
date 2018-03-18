#include "RenderingTools.hpp"

using namespace Displays;

namespace UI {

    /**
    *  @brief: this draws a pixel by absolute coordinates.
    *          this function won't be affected by the rotate parameter.
    */
    Frame* RenderingTools::DrawAbsolutePixel(Frame *frame, int x, int y, DisplayColor color) {
        unsigned char* image = frame->GetImage();
        if (x < 0 || x >= frame->GetWidth() || y < 0 || y >= frame->GetHeight()) {
            return frame;
        }
        if (IF_INVERT_COLOR) {
            if (color == DisplayColor::Uncolored) {
                image[(x + y * frame->GetWidth()) / 8] |= 0x80 >> (x % 8);
            } else {
                image[(x + y * frame->GetWidth()) / 8] &= ~(0x80 >> (x % 8));
            }
        } else {
            if (color == DisplayColor::Uncolored) {
                image[(x + y * frame->GetWidth()) / 8] &= ~(0x80 >> (x % 8));
            } else {
                image[(x + y * frame->GetWidth()) / 8] |= 0x80 >> (x % 8);
            }
        }
        return frame;
    } 

    /**
    *  @brief: this draws a pixel by the coordinates
    */
    Frame* RenderingTools::DrawPixel(Frame *frame, int x, int y, DisplayColor color) {
        int point_temp;
        if (frame->GetRotate() == ROTATE_0) {
            if(x < 0 || x >= frame->GetWidth() || y < 0 || y >= frame->GetHeight()) {
                return frame;
            }
            DrawAbsolutePixel(frame, x, y, color);
        } else if (frame->GetRotate() == ROTATE_90) {
            if(x < 0 || x >= frame->GetHeight() || y < 0 || y >= frame->GetWidth()) {
            return frame;
            }
            point_temp = x;
            x = frame->GetWidth() - y;
            y = point_temp;
            DrawAbsolutePixel(frame, x, y, color);
        } else if (frame->GetRotate() == ROTATE_180) {
            if(x < 0 || x >= frame->GetWidth() || y < 0 || y >= frame->GetHeight()) {
            return frame;
            }
            x = frame->GetWidth() - x;
            y = frame->GetHeight() - y;
            DrawAbsolutePixel(frame, x, y, color);
        } else if (frame->GetRotate() == ROTATE_270) {
            if(x < 0 || x >= frame->GetHeight() || y < 0 || y >= frame->GetWidth()) {
            return frame;
            }
            point_temp = x;
            x = y;
            y = frame->GetHeight() - point_temp;
            DrawAbsolutePixel(frame, x, y, color);
        }
        return frame;
    }

    /**
     *  @brief: this draws a charactor on the frame buffer but not refresh
     */
    Frame* RenderingTools::DrawCharAt(Frame *frame, int x, int y, char ascii_char, sFONT* font, DisplayColor color) {
        int i, j;
        unsigned int char_offset = (ascii_char - ' ') * font->Height * (font->Width / 8 + (font->Width % 8 ? 1 : 0));
        const unsigned char* ptr = &font->table[char_offset];

        for (j = 0; j < font->Height; j++) {
            for (i = 0; i < font->Width; i++) {
                if ((*ptr) & (0x80 >> (i % 8))) {
                    DrawPixel(frame, x + i, y + j, color);
                }
                if (i % 8 == 7) {
                    ptr++;
                }
            }
            if (font->Width % 8 != 0) {
                ptr++;
            }
        }
        return frame;
    }

    /**
    *  @brief: this displays a string on the frame buffer but not refresh
    */
    Frame* RenderingTools::DrawStringAt(Frame *frame, int x, int y, const char* text, sFONT* font, DisplayColor color) {
        const char* p_text = text;
        unsigned int counter = 0;
        int refcolumn = x;
        
        /* Send the string character by character on EPD */
        while (*p_text != 0) {
            /* Display one character on EPD */
            DrawCharAt(frame, refcolumn, y, *p_text, font, color);
            /* Decrement the column position by 16 */
            refcolumn += font->Width;
            /* Point on the next character */
            p_text++;
            counter++;
        }
        return frame;
    }

    /**
    *  @brief: this draws a line on the frame buffer
    */
    Frame* RenderingTools::DrawLine(Frame *frame, int x0, int y0, int x1, int y1, DisplayColor color) {
        /* Bresenham algorithm */
        int dx = x1 - x0 >= 0 ? x1 - x0 : x0 - x1;
        int sx = x0 < x1 ? 1 : -1;
        int dy = y1 - y0 <= 0 ? y1 - y0 : y0 - y1;
        int sy = y0 < y1 ? 1 : -1;
        int err = dx + dy;

        while((x0 != x1) && (y0 != y1)) {
            DrawPixel(frame, x0, y0 , color);
            if (2 * err >= dy) {     
                err += dy;
                x0 += sx;
            }
            if (2 * err <= dx) {
                err += dx; 
                y0 += sy;
            }
        }
        return frame;
    }

    /**
    *  @brief: this draws a horizontal line on the frame buffer
    */
    Frame* RenderingTools::DrawHorizontalLine(Frame *frame, int x, int y, int line_width, DisplayColor color) {
        int i;
        for (i = x; i < x + line_width; i++) {
            DrawPixel(frame, i, y, color);
        }
        return frame;
    }

    /**
    *  @brief: this draws a vertical line on the frame buffer
    */
    Frame* RenderingTools::DrawVerticalLine(Frame *frame, int x, int y, int line_height, DisplayColor color) {
        int i;
        for (i = y; i < y + line_height; i++) {
            DrawPixel(frame, x, i, color);
        }
        return frame;
    }

    /**
    *  @brief: this draws a rectangle
    */
    Frame* RenderingTools::DrawRectangle(Frame *frame, int x0, int y0, int x1, int y1, DisplayColor color) {
        int min_x, min_y, max_x, max_y;
        min_x = x1 > x0 ? x0 : x1;
        max_x = x1 > x0 ? x1 : x0;
        min_y = y1 > y0 ? y0 : y1;
        max_y = y1 > y0 ? y1 : y0;
        
        DrawHorizontalLine(frame, min_x, min_y, max_x - min_x + 1, color);
        DrawHorizontalLine(frame, min_x, max_y, max_x - min_x + 1, color);
        DrawVerticalLine(frame, min_x, min_y, max_y - min_y + 1, color);
        DrawVerticalLine(frame, max_x, min_y, max_y - min_y + 1, color);
        return frame;
    }

    /**
    *  @brief: this draws a filled rectangle
    */
    Frame* RenderingTools::DrawFilledRectangle(Frame *frame, int x0, int y0, int x1, int y1, DisplayColor color) {
        int min_x, min_y, max_x, max_y;
        int i;
        min_x = x1 > x0 ? x0 : x1;
        max_x = x1 > x0 ? x1 : x0;
        min_y = y1 > y0 ? y0 : y1;
        max_y = y1 > y0 ? y1 : y0;
        
        for (i = min_x; i <= max_x; i++) {
            DrawVerticalLine(frame, i, min_y, max_y - min_y + 1, color);
        }
        return frame;
    }

    /**
    *  @brief: this draws a circle
    */
    Frame* RenderingTools::DrawCircle(Frame *frame, int x, int y, int radius, DisplayColor color) {
        /* Bresenham algorithm */
        int x_pos = -radius;
        int y_pos = 0;
        int err = 2 - 2 * radius;
        int e2;

        do {
            DrawPixel(frame, x - x_pos, y + y_pos, color);
            DrawPixel(frame, x + x_pos, y + y_pos, color);
            DrawPixel(frame, x + x_pos, y - y_pos, color);
            DrawPixel(frame, x - x_pos, y - y_pos, color);
            e2 = err;
            if (e2 <= y_pos) {
                err += ++y_pos * 2 + 1;
                if(-x_pos == y_pos && e2 <= x_pos) {
                e2 = 0;
                }
            }
            if (e2 > x_pos) {
                err += ++x_pos * 2 + 1;
            }
        } while (x_pos <= 0);
        return frame;
    }

    /**
    *  @brief: this draws a filled circle
    */
    Frame* RenderingTools::DrawFilledCircle(Frame *frame, int x, int y, int radius, DisplayColor color) {
        /* Bresenham algorithm */
        int x_pos = -radius;
        int y_pos = 0;
        int err = 2 - 2 * radius;
        int e2;

        do {
            DrawPixel(frame, x - x_pos, y + y_pos, color);
            DrawPixel(frame, x + x_pos, y + y_pos, color);
            DrawPixel(frame, x + x_pos, y - y_pos, color);
            DrawPixel(frame, x - x_pos, y - y_pos, color);
            DrawHorizontalLine(frame, x + x_pos, y + y_pos, 2 * (-x_pos) + 1, color);
            DrawHorizontalLine(frame, x + x_pos, y - y_pos, 2 * (-x_pos) + 1, color);
            e2 = err;
            if (e2 <= y_pos) {
                err += ++y_pos * 2 + 1;
                if(-x_pos == y_pos && e2 <= x_pos) {
                    e2 = 0;
                }
            }
            if(e2 > x_pos) {
                err += ++x_pos * 2 + 1;
            }
        } while(x_pos <= 0);
        return frame;
    }

}
