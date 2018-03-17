#include "DisplayConnector.hpp"
#include <SPI.h>
#include <Arduino.h>

namespace Displays {
    DisplayConnector::DisplayConnector(){};
    DisplayConnector::DisplayConnector(int RST_Pin, int DC_Pin, int CS_Pin, int BUSY_Pin){
        SetPins(RST_Pin, DC_Pin, CS_Pin, BUSY_Pin);
    };

    DisplayConnector::~DisplayConnector(){};

    void DisplayConnector::SpiTransfer(unsigned char data) {
        digitalWrite(cs_pin, LOW);
        SPI.transfer(data);
        digitalWrite(cs_pin, HIGH);
    }

    /**
     *  @brief: basic function for sending commands
     */
    void DisplayConnector::SendCommand(unsigned char command) {
        digitalWrite(dc_pin, LOW);
        SpiTransfer(command);
    }

    /**
     *  @brief: basic function for sending data
     */
    void DisplayConnector::SendData(unsigned char data) {
        digitalWrite(dc_pin, HIGH);
        SpiTransfer(data);
    }

    /**
     *  @brief: Wait until the busy_pin goes HIGH
     */
    void DisplayConnector::WaitUntilIdle(void) {
        while(digitalRead(busy_pin) == 0) {      //0: busy, 1: idle
            delay(100);
        }      
    }

    /**
     *  @brief: module reset. 
     *          often used to awaken the module in deep sleep, 
     *          see Epd::Sleep();
     */
    void DisplayConnector::Reset(void) {
        digitalWrite(reset_pin, LOW);
        delay(200);
        digitalWrite(reset_pin, HIGH);
        delay(200);   
    }

    int DisplayConnector::IfInit(void) {
        pinMode(cs_pin, OUTPUT);
        pinMode(reset_pin, OUTPUT);
        pinMode(cs_pin, OUTPUT);
        pinMode(busy_pin, INPUT); 
        SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
        SPI.begin();
        return 0;
    }

    void DisplayConnector::DelayMs(unsigned int delaytime) {
        delay(delaytime);
    }

    void DisplayConnector::SetPins(int RST_Pin, int DC_Pin, int CS_Pin, int BUSY_Pin){
        reset_pin = RST_Pin;
        dc_pin = DC_Pin;
        cs_pin = CS_Pin;
        busy_pin = BUSY_Pin;
    }
}