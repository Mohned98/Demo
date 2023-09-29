
#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_

/* Timer Mode*/
#define   TIMER0_NORMAL_MODE        0
#define   TIMER0_CTC_MODE           1
#define   TIMER0_PHASECORRECT_MODE  2
#define   TIMER0_FASTPWM_MODE       3

/* Timer prescaler */
#define    TIMER0_PRESCALER_1                   1
#define    TIMER0_PRESCALER_8                   2
#define    TIMER0_PRESCALER_64                  3
#define    TIMER0_PRESCALER_256                 4
#define    TIMER0_PRESCALER_1024                5
#define    TIMER0_PRESCALER_EXTCLK_FALLEDGE     6
#define    TIMER0_PRESCALER_EXTCLK_RAISEDGE     7

/* Timer OC0 Mode */
#define   TIMER0_OC0_DISCONNECTED        0
#define   TIMER0_OC0_TOGGLE              1
#define   TIMER0_OC0_CLEAR               2
#define   TIMER0_OC0_SET                 3
/* Timer OC0 Mode PWM */
#define   TIMER0_OC0_PWM_NON_INVERTING   2
#define   TIMER0_OC0_PWM_INVERTING       3

#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
