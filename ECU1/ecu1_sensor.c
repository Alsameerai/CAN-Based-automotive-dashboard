#include "ecu1_sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "uart.h"
#include "clcd.h"
#include "matrix_keypad.h"
#define _XTAL_FREQ 20000000

unsigned char event[9][3]={"ON","GN","G1","G2","G3","G4","G5","GR","C_"};
uint16_t get_speed(void)
{
    // Implement the speed function
    unsigned int spd=(unsigned int)(read_adc(CHANNEL4)/10.33);//reading from the pot channel
    // return speed;//returning those speed
    /**/
    static char speed[3];
    speed[0]=((spd / 10)+ '0');
    speed[1]=((spd % 10)+ '0'); 
    speed[2]='\0';   

    can_transmit(SPEED_MSG_ID,speed,5);//only 2 valid char we are sending 
    __delay_ms(80);
    /*can tansmit (speeed_msd_id,speed,2)*/
    // puts("Tx:\n\r");
    // puts(speed);
}

uint16_t get_gear_pos()
{
    // Implement the gear function
    extern unsigned int idx;
    static char gear_buff[3];
    unsigned char gear;//which is a key
    static unsigned char acc_flag=0;//to retain the value btwn the fn calls
    gear=read_switches(STATE_CHANGE);
    if(gear== MK_SW1 && acc_flag==0)
    {
        if(idx < MAX_GEAR) //Until GR
        {
            idx++;
          
        }   
    }
    else if(gear == MK_SW2 && acc_flag==0)//Until GN
    {
        if(idx > 1)
        {
            idx--;
            // *event--;
        }
    }
    else if(gear == MK_SW3  && acc_flag==0)//collison happens
    {
        
        idx=8;
        acc_flag=1;
        
    }
    if(acc_flag==1 && (gear==MK_SW1 || gear==MK_SW2))//met with collision and if any switch press hapens means
    {
        acc_flag=0;
        idx=1;
    } 
    /*pass event[idx] in data*/
   /*can_transmit*/
    // gear_buff[0]= idx + '0';
    // gear_buff[1]='\0';
    /*event[idx]-->is the base addres for the 2d array*/
    puts("Gear\n\r");
    putch(idx + '0');
    can_transmit(GEAR_MSG_ID, event[idx],5);
    __delay_ms(80);
    
    return idx;


}