#ifndef IUIELEMENT_H
#define IUIELEMENT_H

#pragma once

#include "Frame.hpp"

namespace UI {

    class IUIElement {
        public:
            bool IsEnabled(void){
                return _enabled;
            };
            void SetEnabled(bool state){
                _enabled = state;
            };
        private:
            bool _enabled = true;
    };
}

#endif /* IUIELEMENT_H */