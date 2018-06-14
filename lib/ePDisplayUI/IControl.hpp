#ifndef ICONTROL_H
#define ICONTROL_H

#pragma once

#include "IUIElement.hpp"

namespace UI {
    class IControl : public IUIElement {
        public:
            virtual Frame* Render(Frame *frame) = 0;
            void SetColor(DisplayColor color);
            DisplayColor GetColor(void);
        private:
            DisplayColor _color = DisplayColor::Black;
    };
}

#endif /* ICONTROL_H */