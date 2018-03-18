#ifndef IDISPLAY_H
#define IDISPLAY_H
#include "DisplayConnector.hpp"
#include <Frame.hpp>

#pragma once

namespace Displays {
    enum DisplayColor {
        Uncolored = 0,
        Colored
    };

    class IDisplay : public DisplayConnector {
    public:
        virtual int  Init(void) = 0;
        virtual void SetFrame(UI::Frame *frame, DisplayColor color) = 0;
        virtual void SetDualFrames(UI::Frame *uncoloredFrame, UI::Frame *coloredFrame) = 0;
        virtual void DisplayFrame(void) = 0;
        virtual void ClearFrame(void) = 0;
        virtual void Sleep(void) = 0;
    };
}

#endif