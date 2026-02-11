/*ECU3--RECEIVER*/
#include <xc.h>
#include <stdint.h>
#include "can.h"
#include "clcd.h"
#include "msg_id.h"
#include "isr.h"
#include "timer0.h"
#include "uart.h"
#define _XTAL_FREQ 20000000

int init_leds() {
    TRISB = 0x08; // Set RB2 as output, RB3 as input, remaining as output
    PORTB = 0x00;
}

static void init_config(void) {
    // Initialize CLCD and CANBUS
    init_clcd();
    init_can();
    // init_leds();
    init_uart();

    // Enable Interrupts
    // PEIE = 1;
    // GIE = 1;
    // init_timer0();
}

void main(void) {
    // Initialize peripherals
    init_config();
    uint16_t msg_id,flag=0;
    uint16_t len;
    unsigned char received[5];
    /* ECU1 main loop */
    while (1) 
    {
        // Read CAN Bus data and handle it
        // process_canbus_data();
        can_receive(&msg_id,received,&len);
        // received[2]='\0';
        // clcd_print("HI",LINE1(5));
        if(SPEED_MSG_ID == msg_id)
        {
            clcd_print("SPD:",LINE1(0));
            clcd_print(received,LINE1(5));
            // __delay_ms(200);

         } 
        else if(GEAR_MSG_ID == msg_id)
        {
            clcd_print("GR:", LINE1(10));
            clcd_print(received,LINE1(13));
        }   
        if(RPM_MSG_ID == msg_id)
        {
            clcd_print("RPM:",LINE2(0));
            clcd_print(received,LINE2(5));
            
        }
        else if(INDICATOR_MSG_ID == msg_id)
        {
            
            clcd_print("IC:",LINE2(10));
            if(received[0] - '0' == 0)
            {
                clcd_print("OFF",LINE2(13));
                flag = 1;//off

            }
            else if(received[0] - '0' == 1)
            {
                clcd_print("<-",LINE2(13));
            }
            else if(received[0] - '0' == 2)
            {
           /**/     clcd_print("->",LINE2(13));
            }
            __delay_ms(200);

        }

    }

    // return;
}
