#ifndef IUIELEMENT_H
#define IUIELEMENT_H

#pragma once

namespace UI {

    class IUIElement {
        protected:
            virtual void Render(void) = 0;
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