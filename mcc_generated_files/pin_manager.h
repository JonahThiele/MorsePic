/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18345
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set Latch1 aliases
#define Latch1_TRIS                 TRISCbits.TRISC0
#define Latch1_LAT                  LATCbits.LATC0
#define Latch1_PORT                 PORTCbits.RC0
#define Latch1_WPU                  WPUCbits.WPUC0
#define Latch1_OD                   ODCONCbits.ODCC0
#define Latch1_ANS                  ANSELCbits.ANSC0
#define Latch1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define Latch1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define Latch1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define Latch1_GetValue()           PORTCbits.RC0
#define Latch1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define Latch1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define Latch1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define Latch1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define Latch1_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define Latch1_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define Latch1_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define Latch1_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set Latch2 aliases
#define Latch2_TRIS                 TRISCbits.TRISC1
#define Latch2_LAT                  LATCbits.LATC1
#define Latch2_PORT                 PORTCbits.RC1
#define Latch2_WPU                  WPUCbits.WPUC1
#define Latch2_OD                   ODCONCbits.ODCC1
#define Latch2_ANS                  ANSELCbits.ANSC1
#define Latch2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define Latch2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define Latch2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define Latch2_GetValue()           PORTCbits.RC1
#define Latch2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define Latch2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define Latch2_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define Latch2_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define Latch2_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define Latch2_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define Latch2_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define Latch2_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set Button aliases
#define Button_TRIS                 TRISCbits.TRISC2
#define Button_LAT                  LATCbits.LATC2
#define Button_PORT                 PORTCbits.RC2
#define Button_WPU                  WPUCbits.WPUC2
#define Button_OD                   ODCONCbits.ODCC2
#define Button_ANS                  ANSELCbits.ANSC2
#define Button_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define Button_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define Button_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define Button_GetValue()           PORTCbits.RC2
#define Button_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define Button_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define Button_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define Button_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define Button_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define Button_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define Button_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define Button_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/