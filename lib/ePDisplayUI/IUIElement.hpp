#ifndef IUIELEMENT_H
#define IUIELEMENT_H

#pragma once

#include "Frame.hpp"

namespace UI {

    class IUIElement {
        protected:
            virtual Frame* Render(Frame *frame) = 0;
            bool IsEnabled(void){
                return enabled;
            };
            void SetEnabled(bool state){
                enabled = state;
            };
        private:
            bool enabled = true;
    };
}

#endif /* IUIELEMENT_H */