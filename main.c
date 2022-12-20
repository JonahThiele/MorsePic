/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:    `
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18345
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

//define time in ms between dashes and dots
#define DASH 50
#define DOT 4
#define SPACE 60000

/*
                         Main application
 */

//global variables

bool leds_on = true;
unsigned char LEDS [] =
    {
        0x00,
        0x00,
        0x00,
        0x0,
        0x0,
        0x0,
        0x0,
        0
    };
void PutColumnVCC(unsigned char col)
{
  SPI1_Open(0);
  //CLR(PORTE, pe_vccs_latch);// Clear PWM pin 2 (PE4)
  Latch1_LAT = 0;
  
  SPI1_WriteByte(col);

  //SET(PORTE, pe_vccs_latch);// Set PWM pin 2 (PE4)
  Latch1_LAT = 1;
  SPI1_Close();
}
void PutRowGND(unsigned char row)
{
  SPI1_Open(0);
    
  //CLR(PORTE, pe_gnds_latch);// Clear PWM pin 3 (PE5)
  Latch2_LAT = 0;

  SPI1_WriteByte(row);
  Latch2_LAT = 1;
  //SET(PORTE, pe_gnds_latch);// Set PWM pin 3 (PE5)
  SPI1_Close();
}

// Rendering methods
void Render()
{
  if (!leds_on)
    return;

  PutRowGND(0xFE);
  unsigned char rowBytes[8] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF,0x7F};
  for(int row = 0; row < 8; row++)
  {
    PutRowGND(rowBytes[row]);
    for (int col = 0; col < 8; col ++)
    {
        int reg = 1 << col;
        PutColumnVCC((unsigned char)(LEDS[row] & reg));
    }
    PutColumnVCC(0); 
  }
}

//we only need the char not string because only one char will
// display at a time
void SetChar(char c)
{
  // The scaning process starts from row 0 to row 7. Since the leds are aranged from bottom to top, we need to setup them from top to bottom.
    switch(c)
    {
        case '0':
           LEDS [7] = 0B00000000;
           LEDS [6] = 0B00111100;
           LEDS [5] = 0B01000110;
           LEDS [4] = 0B01001010;
           LEDS [3] = 0B01010010;
           LEDS [2] = 0B01100010;
           LEDS [1] = 0B00111100;
           LEDS [0] = 0B00000000;
           break;
        case '1':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B00001110;
          LEDS [5] = 0B00010110;
          LEDS [4] = 0B00100110;
          LEDS [3] = 0B01000110;
          LEDS [2] = 0B00000110;
          LEDS [1] = 0B00000110;
          LEDS [0] = 0B00000000;
          break;
        case '2':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B00000010;
          LEDS [4] = 0B01111110;
          LEDS [3] = 0B01111110;
          LEDS [2] = 0B01000000;
          LEDS [1] = 0B01111110;
          LEDS [0] = 0B00000000;
          break;
        case '3':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B00000010;
          LEDS [4] = 0B01111110;
          LEDS [3] = 0B01111110;
          LEDS [2] = 0B00000010;
          LEDS [1] = 0B01111110;
          LEDS [0] = 0B00000000;
          break;
        case '4':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01000010;
          LEDS [5] = 0B01000010;
          LEDS [4] = 0B01111110;
          LEDS [3] = 0B01111110;
          LEDS [2] = 0B00000010;
          LEDS [1] = 0B00000010;
          LEDS [0] = 0B00000000;
          break;
        case '5':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B01000000;
          LEDS [4] = 0B01111110;
          LEDS [3] = 0B01111110;
          LEDS [2] = 0B00000010;
          LEDS [1] = 0B01111110;
          LEDS [0] = 0B00000000; 
          break;
        case '6':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B01000000;
          LEDS [4] = 0B01111110;
          LEDS [3] = 0B01111110;
          LEDS [2] = 0B01000010;
          LEDS [1] = 0B01111110;
          LEDS [0] = 0B00000000;
          break;
        case '7':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B00000110;
          LEDS [4] = 0B00001100;
          LEDS [3] = 0B00011000;
          LEDS [2] = 0B00110000;
          LEDS [1] = 0B01100000;
          LEDS [0] = 0B00000000;     
          break;
        case '8':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B00111100;
          LEDS [5] = 0B01000010;
          LEDS [4] = 0B00111100;
          LEDS [3] = 0B00111100;
          LEDS [2] = 0B01000010;
          LEDS [1] = 0B00111100;
          LEDS [0] = 0B00000000;
          break;
        case '9':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B01000010;
          LEDS [4] = 0B01111110;
          LEDS [3] = 0B01111110;
          LEDS [2] = 0B00000010;
          LEDS [1] = 0B01111110;
          LEDS [0] = 0B00000000;
          break;
        case 'a':
        case 'A':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B01000010;
          LEDS [4] = 0B01111110;
          LEDS [3] = 0B01000010;
          LEDS [2] = 0B01000010;
          LEDS [1] = 0B01000010;
          LEDS [0] = 0B00000000;
          break;
        case 'b':
        case 'B':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111100;
          LEDS [5] = 0B01000010;
          LEDS [4] = 0B01111100;
          LEDS [3] = 0B01000010;
          LEDS [2] = 0B01000010;
          LEDS [1] = 0B01111100;
          LEDS [0] = 0B00000000;
          break;
        case 'c':
        case 'C':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B01000000;
          LEDS [4] = 0B01000000;
          LEDS [3] = 0B01000000;
          LEDS [2] = 0B01000000;
          LEDS [1] = 0B01111110;
          LEDS [0] = 0B00000000;
          break;
        case 'd':
        case 'D':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111100;
          LEDS [5] = 0B01000010;
          LEDS [4] = 0B01000010;
          LEDS [3] = 0B01000010;
          LEDS [2] = 0B01000010;
          LEDS [1] = 0B01111100;
          LEDS [0] = 0B00000000;
          break;
        case 'e':
        case 'E':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B01000000;
          LEDS [4] = 0B01111110;
          LEDS [3] = 0B01111110;
          LEDS [2] = 0B01000000;
          LEDS [1] = 0B01111110;
          LEDS [0] = 0B00000000;
          break;
        case 'f':
        case 'F':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B01000000;
          LEDS [4] = 0B01111110;
          LEDS [3] = 0B01111110;
          LEDS [2] = 0B01000000;
          LEDS [1] = 0B01000000;
          LEDS [0] = 0B00000000;
          break;
        case 'g':
        case 'G':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B01000000;
          LEDS [4] = 0B01011110;
          LEDS [3] = 0B01010010;
          LEDS [2] = 0B01000010;
          LEDS [1] = 0B01111110;
          LEDS [0] = 0B00000000;
          break;
        case 'h':
        case 'H':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01000010;
          LEDS [5] = 0B01000010;
          LEDS [4] = 0B01111110;
          LEDS [3] = 0B01000010;
          LEDS [2] = 0B01000010;
          LEDS [1] = 0B01000010;
          LEDS [0] = 0B00000000;
          break;
        case 'i':
        case 'I':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B00111100;
          LEDS [5] = 0B00011000;
          LEDS [4] = 0B00011000;
          LEDS [3] = 0B00011000;
          LEDS [2] = 0B00011000;
          LEDS [1] = 0B00111100;
          LEDS [0] = 0B00000000;
          break;
        case 'j':
        case 'J':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B00011110;
          LEDS [5] = 0B00001100;
          LEDS [4] = 0B00001100;
          LEDS [3] = 0B00001100;
          LEDS [2] = 0B00101100;
          LEDS [1] = 0B00111100;
          LEDS [0] = 0B00000000;
          break;
        case 'k':
        case 'K':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01001000;
          LEDS [5] = 0B01010000;
          LEDS [4] = 0B01100000;
          LEDS [3] = 0B01100000;
          LEDS [2] = 0B01011000;
          LEDS [1] = 0B01000100;
          LEDS [0] = 0B00000000;
          break;
        case 'l':
        case 'L':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01000000;
          LEDS [5] = 0B01000000;
          LEDS [4] = 0B01000000;
          LEDS [3] = 0B01000000;
          LEDS [2] = 0B01000000;
          LEDS [1] = 0B01111110;
          LEDS [0] = 0B00000000;
          break;
        case 'm':
        case 'M':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B01011010;
          LEDS [4] = 0B01011010;
          LEDS [3] = 0B01011010;
          LEDS [2] = 0B01011010;
          LEDS [1] = 0B01011010;
          LEDS [0] = 0B00000000;
          break;
        case 'n':
        case 'N':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01000010;
          LEDS [5] = 0B01100010;
          LEDS [4] = 0B01010010;
          LEDS [3] = 0B01001010;
          LEDS [2] = 0B01000110;
          LEDS [1] = 0B01000010;
          LEDS [0] = 0B00000000;
          break;
        case 'o':
        case 'O':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B00111100;
          LEDS [5] = 0B01000010;
          LEDS [4] = 0B01000010;
          LEDS [3] = 0B01000010;
          LEDS [2] = 0B01000010;
          LEDS [1] = 0B00111100;
          LEDS [0] = 0B00000000;
          break;
        case 'p':
        case 'P':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B01000010;
          LEDS [4] = 0B01111110;
          LEDS [3] = 0B01111110;
          LEDS [2] = 0B01000000;
          LEDS [1] = 0B01000000;
          LEDS [0] = 0B00000000;
          break;
        case 'q':
        case 'Q':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B01000010;
          LEDS [4] = 0B01000010;
          LEDS [3] = 0B01001010;
          LEDS [2] = 0B01000110;
          LEDS [1] = 0B01111110;
          LEDS [0] = 0B00000001;
          break;
        case 'r':
        case 'R':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B01000010;
          LEDS [4] = 0B01111110;
          LEDS [3] = 0B01010000;
          LEDS [2] = 0B01001000;
          LEDS [1] = 0B01000100;
          LEDS [0] = 0B00000000;
          break;
        case 's':
        case 'S':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B01000000;
          LEDS [4] = 0B01111110;
          LEDS [3] = 0B00000010;
          LEDS [2] = 0B00000010;
          LEDS [1] = 0B01111110;
          LEDS [0] = 0B00000000;
          break;
        case 't':
        case 'T':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B00011000;
          LEDS [4] = 0B00011000;
          LEDS [3] = 0B00011000;
          LEDS [2] = 0B00011000;
          LEDS [1] = 0B00011000;
          LEDS [0] = 0B00000000;
          break;
        case 'u':
        case 'U':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01000010;
          LEDS [5] = 0B01000010;
          LEDS [4] = 0B01000010;
          LEDS [3] = 0B01000010;
          LEDS [2] = 0B01000010;
          LEDS [1] = 0B00111100;
          LEDS [0] = 0B00000000;
          break;
        case 'v':
        case 'V':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01000010;
          LEDS [5] = 0B01000010;
          LEDS [4] = 0B01000010;
          LEDS [3] = 0B01000010;
          LEDS [2] = 0B00100100;
          LEDS [1] = 0B00011000;
          LEDS [0] = 0B00000000;
          break;
        case 'w':
        case 'W':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01011010;
          LEDS [5] = 0B01011010;
          LEDS [4] = 0B01011010;
          LEDS [3] = 0B01011010;
          LEDS [2] = 0B01011010;
          LEDS [1] = 0B01111110;
          LEDS [0] = 0B00000000;
          break;
        case 'x':
        case 'X':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01000010;
          LEDS [5] = 0B00100100;
          LEDS [4] = 0B00011000;
          LEDS [3] = 0B00100100;
          LEDS [2] = 0B01000010;
          LEDS [1] = 0B00000000;
          LEDS [0] = 0B00000000;
          break;
        case 'y':
        case 'Y':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01000010;
          LEDS [5] = 0B00100100;
          LEDS [4] = 0B00011000;
          LEDS [3] = 0B00011000;
          LEDS [2] = 0B00011000;
          LEDS [1] = 0B00011000;
          LEDS [0] = 0B00000000;
          break;
        case 'z':
        case 'Z':
          LEDS [7] = 0B00000000;
          LEDS [6] = 0B01111110;
          LEDS [5] = 0B00000100;
          LEDS [4] = 0B00001000;
          LEDS [3] = 0B00010000;
          LEDS [2] = 0B00100000;
          LEDS [1] = 0B01111110;
          LEDS [0] = 0B00000000;
          break;
        default:
            break;
    }
  // I think this code does the scanning so I will probably remove it soon
  for (int i = 0; i < 8; i ++)
  {
    unsigned char reg = (LEDS[i] & 0x80) >> 7;
    reg |= (LEDS[i] & 0x40) >> 5;
    reg |= (LEDS[i] & 0x20) >> 3;
    reg |= (LEDS[i] & 0x10) >> 1;
    reg |= (LEDS[i] & 0x08) << 1;
    reg |= (LEDS[i] & 0x04) << 3;
    reg |= (LEDS[i] & 0x02) << 5;
    reg |= (LEDS[i] & 0x01) << 7;

    LEDS[i] = reg;
  }
}


void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    //TMR0_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    //#define CLR(x,y) (x&=(~(1<<y)))
    //#define SET(x,y) (x|=(1<<y))

    
    uint8_t MChar[5];
    uint8_t msecs = 0;
    unsigned int ssecs = 0;
    uint8_t pressed = 0;
    uint8_t i = 0;
    while (1)
    {
        // Add your application code
        //check to see if button is pressed
        
        if(Button_GetValue() == 0 && pressed == 0)
        {
           //reset the timer to check time
           TMR0IF = 0;
           pressed = 1;
           ssecs = 0;
        } else 
        {
            pressed = 0;
            i++;
        }
        
        if(TMR0_HasOverflowOccured())
        {
            if(pressed)
            {
              msecs++;
            } else
            {
              msecs = 0;
              ssecs++;
            }
            TMR0IF = 0;
        }
        
        if(msecs >= DASH && pressed == 0)
        {
            MChar[i] = 1;
        } else if(msecs >= DOT && pressed == 0){
            MChar[i] = 0;
        } else if(ssecs >= SPACE && pressed == 0)
        {
            //check MChar array for letter
            int sum = 0;
            uint8_t dashes = 0;
            uint8_t dots = 0;
            
            //number unique ids not unique enough
            if(MChar[0] == 0 && MChar[1] == 1 && MChar[2] == 1 && MChar[3] == 0)
            {
                sum = 77;
            } else {
                for(uint8_t a = 0; a <= i; a++)
                {
                    uint8_t c;
                    if(MChar[a] == 1)
                    {
                        c = 9;
                        dashes++;
                    }else 
                    {
                        c = 1;
                        dots++;
                    }
                    sum += c * a;
                }
                if(dashes == dots)
                {
                    sum *= -1;
                } else if(dashes > dots)
                {
                    sum *= 2;
                }
            }
           
            switch(sum){
                case 19:
                    SetChar('a');
                    break;
                case 82:
                    SetChar('b');
                    break;
                case -42:
                    SetChar('c');
                    break;
                case 14:
                    SetChar('d');
                    break;
                case 1:
                    SetChar('e');
                    break;
                case 34:
                    SetChar('f');
                    break;
                case 60:
                    SetChar('g');
                    break;
                case 10:
                    SetChar('h');
                    break;
                case 3:
                    SetChar('i');
                    break;
                case 164:
                    SetChar('j');
                    break;
                case 76:
                    SetChar('k');
                    break;
                case 26:
                    SetChar('l');
                    break;
                case 54:
                    SetChar('m');
                    break;
                case 11:
                    SetChar('n');
                    break;
                case 108:
                    SetChar('o');
                    break;
                case 77:
                    SetChar('p');
                    break;
                case 132:
                    SetChar('q');
                    break;
                case 22:
                    SetChar('r');
                    break;
                case 6:
                    SetChar('s');
                    break;
                case 9:
                    SetChar('t');
                    break;
                case 30:
                    SetChar('u');
                    break;
                case 42:
                    SetChar('v');
                    break;
                case 92:
                    SetChar('w');
                    break;
                case -50:
                    SetChar('x');
                    break;
                case 148:
                    SetChar('y');
                    break;
                case -34:
                    SetChar('z');
                    break;
                case 254:
                    SetChar('1');
                    break;
                case 222:
                    SetChar('2');
                    break;
                case 87:
                    SetChar('3');
                    break;
                case 55:
                    SetChar('4');
                    break;
                case 15:
                    SetChar('5');
                    break;
                case 23:
                    SetChar('6');
                    break;
                case 39:
                    SetChar('7');
                    break;
                case 126:
                    SetChar('8');
                    break;
                case 190:
                    SetChar('9');
                    break;
                case 270:
                    SetChar('0');
                    break;
                default:
                    break;
                
            }
            //reset mchar array
            //reset the ssecs as well
            i = 0;
            ssecs = 0;
            
        }
        
        Render();
    }
}
/**
 End of File
*/