#include <xc.h>
#include "isr.h"

// extern unsigned int key_detected;

void __interrupt() isr(void)
{
	extern unsigned int flag;
	if (INT0F == 1)
	{
		// key_detected = 1;

		INT0F = 0;
	}
}
