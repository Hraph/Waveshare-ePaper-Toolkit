#ifndef IDISPLAY_H
#define IDISPLAY_H
#include "DisplayConnector.hpp"

#pragma once
namespace Displays {
    class IDisplay : public DisplayConnector {
    public:
        virtual int  Init(void) = 0;
        virtual void SetPartialWindow(const unsigned char* buffer_black, const unsigned char* buffer_red, int x, int y, int w, int l) = 0;
        virtual void SetPartialWindowBlack(const unsigned char* buffer_black, int x, int y, int w, int l) = 0;
        virtual void SetPartialWindowRed(const unsigned char* buffer_red, int x, int y, int w, int l) = 0;
        virtual void DisplayFrame(const unsigned char* frame_buffer_black, const unsigned char* frame_buffer_red) = 0;
        virtual void DisplayFrame(void) = 0;
        virtual void ClearFrame(void) = 0;
        virtual void Sleep(void) = 0;
    };
}

#endif