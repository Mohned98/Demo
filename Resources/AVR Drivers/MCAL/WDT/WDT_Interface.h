#ifndef MCAL_WDT_WDT_INTERFACE_H_
#define MCAL_WDT_WDT_INTERFACE_H_

#include "Std_Types.h"

#define WDT_SLEEP_TIME_16_3_MS   0
#define WDT_SLEEP_TIME_32_5_MS   1
#define WDT_SLEEP_TIME_65_MS     2
#define WDT_SLEEP_TIME_0_13_S    3
#define WDT_SLEEP_TIME_0_26_S    4
#define WDT_SLEEP_TIME_0_52_S    5
#define WDT_SLEEP_TIME_1_S       6
#define WDT_SLEEP_TIME_2_1_S     7

void WDT_Enable(void);
void WDT_Disable(void);
void WDT_Sleep(uint8 timeOut);
void WDT_Refresh(void);

#endif /* MCAL_WDT_WDT_INTERFACE_H_ */

