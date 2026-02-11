/*ECU2*/
#include "ecu2_sensor.h"
#include "adc.h"
#include "can.h"
#include "digital_keypad.h"
#include "msg_id.h"
#include "uart.h"
#include "ssd_display.h"
#define _XTAL_FREQ 20000000
#define PERIOD 100
void init_config(void)
{
    init_digital_keypad();//indicatior switch
    init_adc();//for rpm
    init_ssd_control();//for displaying the rpm
    init_led();
    // init_uart();
    init_can();

}
void init_led(void)
{
//     TRISB=TRISB & 0X3C;//making the led as output
    TRISB0=0;
    TRISB1=0;
    TRISB6=0;
    TRISB7=0;
    PORTBbits.RB0 = 0;  
    PORTBbits.RB1 = 0;
    PORTBbits.RB6 = 0;
    PORTBbits.RB7 = 0; 
    //Config the led's
    // PORTB= PORTB & 0X3C;//initial all the led's will be off
 }
static unsigned char ssd[MAX_SSD_CNT];
unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
int flag=0;
int main()
{
    //call the functions
    init_config();
    uint16_t rpm,indicator,rpm_msg_id,ind_msg_id;
    uint16_t rpm_len,ind_len;
    char rpm_buff_r[5],ind_buff[1];
    unsigned int delay=0,delay1=0;
    while(1)
    {
         get_rpm();  
        // for(unsigned int i =100;i--;);
    //     can_receive(&rpm_msg_id,rpm_buff_r,&rpm_len);
    //     // rpm_buff_r[rpm_len]='\0';    
    //     /*Displaying the rpm into the ssd*/
    //     if(rpm_msg_id == RPM_MSG_ID)
    //     { 
    //         ssd[0]=digit[rpm_buff_r[0]- 48] ;
    //         ssd[1]=digit[rpm_buff_r[1] - 48];
    //         ssd[2]=digit[rpm_buff_r[2] - 48];
    //         ssd[3]=digit[rpm_buff_r[3] - 48];
           
    //     } 
    //     for(unsigned int j= 5000;j--;);
    //        display(ssd);  
        
         /*Indicator*/
      process_indicator();//it contains whatever the switch pressed based on the return those indicator
    //     for(unsigned int i=100;i--;);
    //     can_receive(&ind_msg_id,ind_buff,&ind_len);
    //     // puts(ind_buff);
    //     if(ind_len > 0)
    //     {
    //         if(ind_buff[0] -'0' == e_ind_off)
    //         {
    //             flag=3;
    //         }
    //         else if(ind_buff[0] - '0' == e_ind_right)//converting back to numeric
    //         {
    //             flag=1;
    //         }
    //         else if(ind_buff[0] - '0' == e_ind_left)
    //         {
    //             flag =2;
    //         }
    //         else
    //         flag=0;
    //     }

    //     if(flag==1)
    //     {
        
    //         if(delay++ <= 50)//right
    //         {
    //             PORTBbits.RB0=1; //ON
    //             PORTBbits.RB1=1;
                
    //         }
    //         else if(delay < 100)
    //         {
    //             PORTBbits.RB0=0;//OFF
    //             PORTBbits.RB1=0;

    //         }
    //         else
    //         {
    //             delay=0;
    //         }
    //     }
    //     else if(flag ==2)//left
    //     {
    //         if(delay++ <= 50)
    //         {
    //             PORTBbits.RB6=1;
    //             PORTBbits.RB7=1;

    //         }
    //         else if(delay < 100)
    //         {
    //             PORTBbits.RB6=0;
    //             PORTBbits.RB7=0;
    //         }
    //         else
    //         {
    //             delay=0;
    //         }
    //     }
    //     else if(flag ==3)//off
    //     {
    //         PORTBbits.RB0=0;
    //         PORTBbits.RB1=0;
    //         PORTBbits.RB6=0;
    //         PORTBbits.RB7=0;
    //     }
    // //         ssd[1]=digit[ind_buff[0] - 48] ;
    // //         // ssd[1]=digit[rpm_buff_r[1] - 48];
    // //         // ssd[2]=digit[rpm_buff_r[2] - 48];
    // //         // ssd[3]=digit[rpm_buff_r[3] - 48];
           
         
    // // for(unsigned int j= 5000;j--;);
    // //        display(ssd);
 

    }
}
