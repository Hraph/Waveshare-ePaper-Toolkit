#include "DisplayConnector.hpp"
#include <spi.h>
#include <Arduino.h>

DisplayConnector::DisplayConnector(){};
DisplayConnector::DisplayConnector(int RST_Pin, int DC_Pin, int CS_Pin, int BUSY_Pin){
    SetPins(RST_Pin, DC_Pin, CS_Pin, BUSY_Pin);
};

DisplayConnector::~DisplayConnector(){};


void DisplayConnector::DigitalWrite(int pin, int value) {
    digitalWrite(pin, value);
}

int DisplayConnector::DigitalRead(int pin) {
    return digitalRead(pin);
}

void DisplayConnector::DelayMs(unsigned int delaytime) {
    delay(delaytime);
}

void DisplayConnector::SpiTransfer(unsigned char data) {
    digitalWrite(_cs_pin, LOW);
    SPI.transfer(data);
    digitalWrite(_cs_pin, HIGH);
}

int DisplayConnector::IfInit(void) {
    pinMode(_cs_pin, OUTPUT);
    pinMode(_reset_pin, OUTPUT);
    pinMode(_cs_pin, OUTPUT);
    pinMode(_busy_pin, INPUT); 
    SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
    SPI.begin();
    return 0;
}

void DisplayConnector::SetPins(int RST_Pin, int DC_Pin, int CS_Pin, int BUSY_Pin){
    _reset_pin = RST_Pin;
    _dc_pin = DC_Pin;
    _cs_pin = CS_Pin;
    _busy_pin = BUSY_Pin;
}
