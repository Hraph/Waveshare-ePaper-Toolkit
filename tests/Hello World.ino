#include <Arduino.h>

#include <SPI.h>
//#include <epd2in9b.h>
#include <DisplayFactory.hpp>
#include <IDisplay.hpp>
#include <epdpaint.h>
#include <CourierNew12pt.c>
#include <CourierNew16pt.c>

#define COLORED     0
#define UNCOLORED   1


using namespace Displays;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IDisplay *display = DisplayFactory::Get()->Create("2in9B");

  if (display->Init() != 0) {
    Serial.print("e-Paper init failed");
    return;
  }

  /* This clears the SRAM of the e-paper display */
  Serial.println("Clear");
  display->ClearFrame();

  /**
    * Due to RAM not enough in Arduino UNO, a frame buffer is not allowed.
    * In this case, a smaller image buffer is allocated and you have to 
    * update a partial display several times.
    * 1 byte = 8 pixels, therefore you have to set 8*N pixels at a time.
    */
  unsigned char image[1024];
  Paint paint(image, 128, 18);    //width should be the multiple of 8 

  paint.Clear(UNCOLORED);
  paint.DrawStringAt(0, 0, "e-Paper Demo", &Font12, COLORED);
  display->SetPartialWindowBlack(paint.GetImage(), 24, 32, paint.GetWidth(), paint.GetHeight());

  paint.Clear(COLORED);
  paint.DrawStringAt(2, 2, "Hello world", &Font16, UNCOLORED);
  display->SetPartialWindowRed(paint.GetImage(), 0, 64, paint.GetWidth(), paint.GetHeight());
  
  paint.SetWidth(64);
  paint.SetHeight(64);

  paint.Clear(UNCOLORED);
  paint.DrawRectangle(0, 0, 40, 50, COLORED);
  paint.DrawLine(0, 0, 40, 50, COLORED);
  paint.DrawLine(40, 0, 0, 50, COLORED);
  display->SetPartialWindowBlack(paint.GetImage(), 8, 120, paint.GetWidth(), paint.GetHeight());
  
  paint.Clear(UNCOLORED);
  paint.DrawCircle(32, 32, 30, COLORED);
  display->SetPartialWindowBlack(paint.GetImage(), 64, 120, paint.GetWidth(), paint.GetHeight());

  paint.Clear(UNCOLORED);
  paint.DrawFilledRectangle(0, 0, 40, 50, COLORED);
  display->SetPartialWindowRed(paint.GetImage(), 8, 200, paint.GetWidth(), paint.GetHeight());

  paint.Clear(UNCOLORED);
  paint.DrawFilledCircle(32, 32, 30, COLORED);
  display->SetPartialWindowRed(paint.GetImage(), 64, 200, paint.GetWidth(), paint.GetHeight());

  /* This displays the data from the SRAM in e-Paper module */
  display->DisplayFrame();

  /* Deep sleep */
  display->Sleep();
}

void loop() {
  // put your main code here, to run repeatedly:

}
