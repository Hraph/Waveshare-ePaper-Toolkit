#ifndef FRAME_H
#define FRAME_H

#pragma once

namespace UI {

    class Frame {
        public:
            Frame(int x, int y, int width, int height);
            Frame(unsigned char* image, int x, int y, int width, int height);
            unsigned char* GetImage(void);
            int GetX(void);
            int GetY(void);
            int GetWidth(void);
            int GetHeight(void);
            int GetRotate(void);
            void SetRotate(int rotate);
            void Clear(int colored);

        private:
            unsigned char* image;
            int x;
            int y;
            int width;
            int height;
            int rotate;
    };
}

#endif /* FRAME_H */