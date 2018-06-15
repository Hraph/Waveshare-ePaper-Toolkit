#ifndef TEXT_H
#define TEXT_H

#include "IControl.hpp"
#include "Frame.hpp"
#include <DisplayParameters.hpp>
#include <Fonts.hpp>
#include <WString.h>

#pragma once

using namespace Displays;

namespace UI {

    class Text : public IControl {
        public:
            Text();
            Text(int x, int y, String *content, sFONT *font);
            Text(int x, int y, String *content, sFONT *font, DisplayColor color);
            int GetX(void);
            int GetY(void);
            void SetX(int x);
            void SetY(int y);
            Frame* Render(Frame *frame);
        private:
            int _x;
            int _y;
            String* _content;
            sFONT* _font;
    };
}

#endif /* TEXT_H */