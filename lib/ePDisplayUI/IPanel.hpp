#ifndef IPANEL_H
#define IPANEL_H

#include "IUIElement.hpp"
#include <Vector.h>

#pragma once

namespace UI{

    class IPanel : public IUIElement {
        private:
            Vector<IUIElement> children;
        public:
            Vector<IUIElement> GetChildren(void){
                return children;
            }
            bool HasChildren(void){
                return children.Size() != 0;
            }
    };

}

#endif