/*  12_Channel_Keypad_OLED.ino
/*
 *  
 * Copyright (c) 2019 Seeed Technology Co., Ltd.
 * Website    : www.seeed.cc
 * Create Time: February 2019
 * Change Log :
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <SoftwareSerial.h>
#include <Wire.h>
#include <SeeedGrayOLED.h>
#include <avr/pgmspace.h>

#if defined(ARDUINO_ARCH_AVR)
#define SERIAL Serial
SoftwareSerial mySerial(2,3);
#define TRANS_SERIAL  mySerial
#elif defined(ARDUINO_ARCH_SAMD)
#define SERIAL SerialUSB
#define TRANS_SERIAL  Serial
#else

#endif

//RX=2,TX=3(D2) Software Serial Port

void setup() {
    Wire.begin();
    SeeedGrayOled.init(SH1107G);             //initialize SEEED OLED display
    SeeedGrayOled.clearDisplay();     //Clear Display.
    SeeedGrayOled.setNormalDisplay(); //Set Normal Display Mode
    SeeedGrayOled.setVerticalMode();  // Set to vertical mode for displaying text
    mySerial.begin(9600); 
    SERIAL.begin(9600);  // start serial for output
    SERIAL.println("Version:v1.0");
}

void loop() {
    printData();
}

/*
* data mapping:E1---1；E2---2；E3---3；E4---4；E5---5；E6---6；
*              E7---7；E8---8；E9---9；EA---*；EB---0；EC---#；
*/
void printData() {
    while(mySerial.available()) {
        uint8_t data = mySerial.read();
        switch(data) {
                case 0xE1 :
                    SERIAL.println("1");
                    SeeedGrayOled.clearDisplay();
                    SeeedGrayOled.setTextXY(0,0);
                    SeeedGrayOled.putString("1");
                    break;
                case 0xE2 :
                    SERIAL.println("2");
                    SeeedGrayOled.clearDisplay();
                    SeeedGrayOled.setTextXY(0,0);
                    SeeedGrayOled.putString("2");
                    break;
                case 0xE3 :
                    SERIAL.println("3");
                    SeeedGrayOled.clearDisplay();
                    SeeedGrayOled.setTextXY(0,0);
                    SeeedGrayOled.putString("3");
                    break;
                case 0xE4 :
                    SERIAL.println("4");
                    SeeedGrayOled.clearDisplay();
                    SeeedGrayOled.setTextXY(0,0);
                    SeeedGrayOled.putString("4");
                    break;
                case 0xE5 :
                    SERIAL.println("5");
                    SeeedGrayOled.clearDisplay();
                    SeeedGrayOled.setTextXY(0,0);
                    SeeedGrayOled.putString("5");
                    break;
                case 0xE6 :
                    SERIAL.println("6");
                    SeeedGrayOled.clearDisplay();
                    SeeedGrayOled.setTextXY(0,0);
                    SeeedGrayOled.putString("6");
                    break;
                case 0xE7 :
                    SERIAL.println("7");
                    SeeedGrayOled.clearDisplay();
                    SeeedGrayOled.setTextXY(0,0);
                    SeeedGrayOled.putString("7");
                    break;
                case 0xE8 :
                    SERIAL.println("8");
                    SeeedGrayOled.clearDisplay();
                    SeeedGrayOled.setTextXY(0,0);
                    SeeedGrayOled.putString("8");
                    break;
                case 0xE9 :
                    SERIAL.println("9");
                    SeeedGrayOled.clearDisplay();
                    SeeedGrayOled.setTextXY(0,0);
                    SeeedGrayOled.putString("9");
                    break;
                case 0xEA :
                    SERIAL.println("*");
                    SeeedGrayOled.clearDisplay();
                    SeeedGrayOled.setTextXY(0,0);
                    SeeedGrayOled.putString("*");
                    break;
                case 0xEB :
                    SERIAL.println("0");
                    SeeedGrayOled.clearDisplay();
                    SeeedGrayOled.setTextXY(0,0);
                    SeeedGrayOled.putString("0");
                    break;
                case 0xEC :
                    SERIAL.println("#");
                    SeeedGrayOled.clearDisplay();
                    SeeedGrayOled.setTextXY(0,0);
                    SeeedGrayOled.putString("#");
                    break;
                default:
                    break;
            }
    }

}


