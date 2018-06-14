#ifndef IPANEL_H
#define IPANEL_H

#include "IUIElement.hpp"
#include "IControl.hpp"
#include "vector"

#pragma once

namespace UI{

    class IPanel : public IUIElement {
        public:
            void SetNumberOfElements(int number);
            IPanel* AddElement(IControl *element);
            bool HasElements(void);

            Frame* RenderUncolored(Frame *frame);
            Frame* RenderColored(Frame *frame);
        protected:
            IPanel();
        private:
            std::vector<IControl*> _elements;
    };

}

#endif /* IPANEL_H */