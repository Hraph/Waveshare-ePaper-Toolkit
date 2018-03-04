#include "DisplayFactory.hpp"
#include "IDisplay.hpp"

/**
 * Displays includes
 */
#include "displays/Display2in9B.hpp"


DisplayFactory::DisplayFactory(){};

DisplayFactory *DisplayFactory::Get(){
    if (nullptr == _instance)
        _instance = new DisplayFactory();

    return _instance;
};

IDisplay *DisplayFactory::Create(const String displayName){
    if (displayName == "2in9B")
        return new Display2in9B;

    return nullptr;
};