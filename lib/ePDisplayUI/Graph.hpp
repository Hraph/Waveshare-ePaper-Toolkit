#ifndef GRAPH_H
#define GRAPH_H

#include "IControl.hpp"
#include "Frame.hpp"
#include <DisplayParameters.hpp>
#include <vector>

#pragma once

using namespace Displays;

namespace UI {

    class Graph : public IControl {
        public:
            Graph();
            Graph(int fromX, int fromY, int toX, int toY);
            Graph(int fromX, int fromY, int toX, int toY, bool filled);
            Graph(int fromX, int fromY, int toX, int toY, DisplayColor color);
            Graph(int fromX, int fromY, int toX, int toY, bool filled, DisplayColor color);
            int GetFromX(void);
            int GetFromY(void);
            int GetToX(void);
            int GetToY(void);
            bool GetFilled(void);
            void SetFromX(int x);
            void SetFromY(int y);
            void SetToX(int x);
            void SetToY(int y);
            void SetFilled(bool filled);
            Frame* Render(Frame *frame);
        private:
            int _fromX;
            int _fromY;
            int _toX;
            int _toY;
            bool _filled = false; 
            std::vector<float> _dots {6299,6091,6081,6091,6100,6066,6219,6115,6036,6106,6199,6199,6215,6128,6179,6188,6054,6024,6100,6098,6072,6021,6016,6296,6275,6207,6134,6097,6029,6107,6004,6133,6106,6005,6069,6283,6054,6218,6264,6075,6015,6183,6120,6110,6245,6239,6250,6206,6168,6300};
    };
}

#endif /* GRAPH_H */