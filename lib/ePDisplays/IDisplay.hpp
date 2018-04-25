#ifndef IDISPLAY_H
#define IDISPLAY_H
#include "DisplayConnector.hpp"
#include "DisplayParameters.hpp"
#include <Frame.hpp>

#pragma once

using namespace UI;

namespace Displays {
    class IDisplay : public DisplayConnector {
    public:
        virtual int  Init(void) = 0;
        virtual void SetFrame(Frame *frame, DisplayColor color) = 0;
        virtual void SetDualFrames(Frame *uncoloredFrame, Frame *coloredFrame) = 0;
        virtual void DisplayFrame(void) = 0;
        virtual void ClearFrame(void) = 0;
        virtual void Sleep(void) = 0;

        virtual void DebugFrame(UI::Frame *frame) = 0;
    };
}

#endif