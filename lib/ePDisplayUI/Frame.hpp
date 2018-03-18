#ifndef FRAME_H
#define FRAME_H

#include <Fonts.h>

#pragma once

namespace UI {

    class Frame {
        public:
            Frame(int width, int height);
            Frame(unsigned char* image, int width, int height);
            unsigned char* GetImage(void);
            int GetWidth(void);
            int GetHeight(void);
            int GetRotate(void);
            void SetRotate(int rotate);
            Frame Clear(int colored);

        private:
            unsigned char* image;
            int width;
            int height;
            int rotate;
    };
}

#endif /* FRAME_H */