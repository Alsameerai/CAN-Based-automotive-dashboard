#include "ecu2_sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "adc.h"
#include "uart.h"
#include "digital_keypad.h"
#define _XTAL_FREQ 20000000
#define PERIOD 100
uint16_t get_rpm(void)
{
    //Implement the rpm function
    /*Reading from pot*/
    uint16_t rpm= (uint16_t)(read_adc(CHANNEL4) /10.23) *60;
    unsigned char rpm_buff[5];
    rpm_buff[0]=((rpm / 1000 ) + '0');
    rpm_buff[1]=((rpm / 100) %10 + '0');
    rpm_buff[2]=((rpm / 10) % 10 + '0');
    rpm_buff[3]=((rpm % 10) + '0');
    rpm_buff[4]='\0';
    can_transmit(RPM_MSG_ID,rpm_buff,5);
    __delay_ms(80);
    
    // puts("RPM");
    // puts("Tx--->\n\r");
    // puts(rpm_buff);
    // puts("\n\r");
    // return rpm; 
}

// uint16_t get_engine_temp()
// {
//     //Implement the engine temperature function
// }

void process_indicator(void)
{
    //Implement the indicator function
    unsigned int key,delay=0,cur_status;
    key= read_digital_keypad(STATE_CHANGE);
    if(key == SWITCH1)
    {
        // return e_ind_left;//1
        cur_status=1;   
    }
    else if(key == SWITCH3)
    {
        // return e_ind_right;//2
        cur_status=2;
    }
    else if(key == SWITCH2)
    {
        // return e_ind_off;//0
        cur_status=0;
    }
    else 
    {
        cur_status=5;
    }    
    char indicator_buff[2];
    indicator_buff[0] = cur_status + '0';
    indicator_buff[1] = '\0';
     can_transmit(INDICATOR_MSG_ID,indicator_buff,5);
     __delay_ms(80);
//     //  if(cur_ind_status == 1)
//     //  return 
//     //  for(int )   
}