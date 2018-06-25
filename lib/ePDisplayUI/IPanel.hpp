#ifndef IPANEL_H
#define IPANEL_H

#include "IUIElement.hpp"
#include "IControl.hpp"
#include <vector>
#include <algorithm>

#pragma once

namespace UI{

    class IPanel : public IUIElement {
        public:
            void SetNumberOfElements(int number);
            IPanel* AddElement(IControl *element);
            void RemoveElement(int index);
            void RemoveElement(IControl* element);
            void ClearElements(void);
            bool HasElements(void);
            int CountElements(void);

            Frame* RenderBlack(Frame *frame);
            Frame* RenderColored(Frame *frame);
        protected:
            IPanel();
        private:
            std::vector<IControl*> _elements;
    };

}

#endif /* IPANEL_H */