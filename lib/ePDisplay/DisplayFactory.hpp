#ifndef DISPLAYFACTORY_H
#define DISPLAYFACTORY_H

#include "IDisplay.hpp"
#include <Arduino.h>

#pragma once

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
        static DisplayFactory *_instance;
};

#endif /* DISPLAYFACTORY_H */ 