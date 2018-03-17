#ifndef DISPLAYCONNECTOR_H
#define DISPLAYCONNECTOR_H

#pragma once

namespace Displays {
    /**
     * @brief This class is a wrapper to the Arduino library and SPI functions
     */
    class DisplayConnector {
        public:
            unsigned int width;
            unsigned int height;

            DisplayConnector();
            DisplayConnector(int RST_Pin, int DC_Pin, int CS_Pin, int BUSY_Pin);
            ~DisplayConnector();
            

            int  IfInit(void);
            void DigitalWrite(int pin, int value); 
            int  DigitalRead(int pin);
            void DelayMs(unsigned int delaytime);
            void SpiTransfer(unsigned char data);

            void SetPins(int RSTPin, int DCPin, int CSPin, int BUSYPin);

        private:
            unsigned int _reset_pin = 16;
            unsigned int _dc_pin = 17;
            unsigned int _cs_pin = 5;
            unsigned int _busy_pin = 4;
    };
}
#endif /* DISPLAYCONNECTOR_H */ 