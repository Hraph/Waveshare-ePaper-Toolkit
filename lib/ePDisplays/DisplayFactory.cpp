#include "DisplayFactory.hpp"
#include "IDisplay.hpp"

/**
 * Displays includes
 */
#include "Display2in9B.hpp"

namespace Displays {
    DisplayFactory::DisplayFactory(){};

    DisplayFactory *DisplayFactory::Get(){
        //if (nullptr == DisplayFactory::instance)
        //  (DisplayFactory::instance = new DisplayFactory();

        return new DisplayFactory();//DisplayFactory::instance;
    };

    IDisplay *DisplayFactory::Create(ePDs displayName){
        if (displayName == ePDs::d2IN9B)
            return (new Display2in9B());

        return nullptr;
    };
}