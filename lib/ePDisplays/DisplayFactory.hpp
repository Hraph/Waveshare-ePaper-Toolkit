#ifndef DISPLAYFACTORY_H
#define DISPLAYFACTORY_H

#include "IDisplay.hpp"
#include <Arduino.h>

#pragma once

namespace Displays {
    /**
     * @brief This class is a wrapper to the Arduino library and SPI functions
     */
    class DisplayFactory {
        public:
            static DisplayFactory *Get();
            IDisplay *Create(const String displayName);

        private:
            DisplayFactory();
            ~DisplayFactory();
            static DisplayFactory *instance;
    };
}
#endif /* DISPLAYFACTORY_H */ 