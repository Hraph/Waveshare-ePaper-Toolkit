#ifndef IPANEL_H
#define IPANEL_H

#include "IUIElement.hpp"
#include "../epDisplayUtils/Vector.h"

#pragma once

namespace UI{

    class IPanel : public IUIElement {
        private:
            Vector<IUIElement*> _elements;
        public:
            IPanel* SetNumberOfElements(int number);
            IPanel* AddElement(IUIElement *element);
            bool HasElement(void);
            Frame* Render(Frame *frame);
    };

}

#endif /* IPANEL_H */