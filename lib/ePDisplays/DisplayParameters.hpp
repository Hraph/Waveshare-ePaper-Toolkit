#ifndef DISPLAYPARAMETERS_H
#define DISPLAYPARAMETERS_H

#pragma once


namespace Displays {
    enum DisplayColor {
        White = 0,
        Black,
        Colored
    };

    enum DisplayOrientation {
        Rotate_0 = 0,
        Rotate_90,
        Rotate_180,
        Rotate_270
    };
}

#endif /* DISPLAYPARAMETERS_H */