#ifndef IPANEL_H
#define IPANEL_H

#include "IUIElement.hpp"
#include "vector"

#pragma once

namespace UI{

    class IPanel : public IUIElement {
        public:
            void SetNumberOfElements(int number);
            IPanel* AddElement(IUIElement *element);
            bool HasElement(void);
            Frame* Render(Frame *frame);
        protected:
            IPanel();
        private:
            std::vector<IUIElement*> _elements;
    };

}

#endif /* IPANEL_H */