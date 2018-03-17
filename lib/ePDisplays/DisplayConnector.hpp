#ifndef DISPLAYCONNECTOR_H
#define DISPLAYCONNECTOR_H

#pragma once

namespace Displays {
    /**
     * @brief This class is a wrapper to the Arduino library and SPI functions
     */
    class DisplayConnector {
        protected:
            DisplayConnector();
            DisplayConnector(int RST_Pin, int DC_Pin, int CS_Pin, int BUSY_Pin);
            ~DisplayConnector();
        
            int  IfInit(void);
            void SpiTransfer(unsigned char data);
            void SendCommand(unsigned char command);
            void SendData(unsigned char data);
            void WaitUntilIdle(void);
            void Reset(void);
            void DelayMs(unsigned int delaytime);

            unsigned int width;
            unsigned int height;

        public:
            void SetPins(int RSTPin, int DCPin, int CSPin, int BUSYPin);

        private:
            //Default pins for ESP32
            unsigned int reset_pin = 16;
            unsigned int dc_pin = 17;
            unsigned int cs_pin = 5;
            unsigned int busy_pin = 4;
 
    };
}
#endif /* DISPLAYCONNECTOR_H */ 