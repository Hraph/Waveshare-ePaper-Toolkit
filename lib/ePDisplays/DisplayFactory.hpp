#ifndef DISPLAYFACTORY_H
#define DISPLAYFACTORY_H

#include "IDisplay.hpp"
#include <Arduino.h>

#pragma once

namespace Displays {
    enum ePDs {
        d2IN9B = 0
    };

    class DisplayFactory {
        public:
            static DisplayFactory *Get();
            IDisplay *Create(ePDs displayName);

        private:
            DisplayFactory();
            ~DisplayFactory();
            static DisplayFactory *instance;
    };
}
#endif /* DISPLAYFACTORY_H */ 