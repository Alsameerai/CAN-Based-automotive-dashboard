/*NAME :   ALSAMEERA I
DATE 27/09//2025
PROJECT TITLE: CAN BASED AUTOMOTIVE DASHBOARD
ECU1*/
#include "adc.h"
#include "can.h"
#include "ecu1_sensor.h"
#include "msg_id.h"
#include "uart.h"
#include "clcd.h"
#include "matrix_keypad.h"
#define _XTAL_FREQ 20000000
void init_config(void)
{
    init_adc();   
    init_can();
    init_uart();
    init_clcd();
    // init_digital_keypad();
    init_matrix_keypad();
}

unsigned int idx=0;
uint16_t speed_msg_id,gear_msg_id;
uint16_t len_gear,len_speed;
char speed_received[3],gear_received[3];
extern unsigned char event[9][3]; 
int main()
{
    //Call the functions
   
    init_config();
    
    while(1)
    {

        /*char *speed =*/ get_speed(); //collecting the speed in pointer
    //     for(unsigned int i=100;i--;);
    //     can_receive(&speed_msg_id,speed_received,&len_speed);
    //     speed_received[len_speed]='\0';
    //      //__delay_ms(20);
    //     // clcd_print("Hi",LINE1(5));
    //     // puts("Receiving\n\r");
    //     // puts(speed_received);
    //     // puts("Received\n\r");

    //     if(SPEED_MSG_ID == speed_msg_id)
    //     {
    //         clcd_print("SPEED:",LINE1(0));
    //         /*In clcd we can print only strings*/
    //         // clcd_putch(speed_received[0],LINE2(0));
    //         // clcd_putch(speed_received[1],LINE2(1));
    //         clcd_print(speed_received,LINE2(0));

    //     }    
    //     /* Here we can  check whether it is receioving correct or not*/
    //     /*Use pass by referecne so that whatever changes will reflect into the main*/
    //     /*collect data in ptr becuase rpm isof 4 char speed isof 2 char so that receive iin data[5]
    //     can_receive(&msg_id,data,&len)*/
        
    //     /*Gear*/
       get_gear_pos();
        
    //     /*can receive and check using if both msg id are same*/
        
    //     can_receive(&gear_msg_id,gear_received,&len_gear);
    //     // gear_received[len_gear]='\0';
    //     // clcd_print("GEAR:", LINE1(9));unsigned char event[9][3]={"ON","GN","G1","G2","G3","G4","G5","GR","C_"};
    //     if(GEAR_MSG_ID == gear_msg_id)
    //     {
    //         clcd_print("GEAR:", LINE1(9));
    //         clcd_putch(gear_received[0],LINE2(11));   
    //         clcd_putch(gear_received[1],LINE2(12));
    //     }
        
    }    

   

}