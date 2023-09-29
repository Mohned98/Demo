
#ifndef MCAL_TIMER1_TIMER1_PRIVATE_H_
#define MCAL_TIMER1_TIMER1_PRIVATE_H_

/* Timer Mode*/
#define   TIMER1_NORMAL_MODE        0
#define   TIMER1_CTC_MODE           1
#define   TIMER1_PHASECORRECT_MODE  2
#define   TIMER1_FASTPWM_MODE       3

/* Timer prescaler */
#define    TIMER1_PRESCALER_1                   1
#define    TIMER1_PRESCALER_8                   2
#define    TIMER1_PRESCALER_64                  3
#define    TIMER1_PRESCALER_256                 4
#define    TIMER1_PRESCALER_1024                5
#define    TIMER1_PRESCALER_EXTCLK_FALLEDGE     6
#define    TIMER1_PRESCALER_EXTCLK_RAISEDGE     7

/* Timer OC1A Mode */
#define   TIMER1_OC1A_DISCONNECTED        0
#define   TIMER1_OC1A_TOGGLE              1
#define   TIMER1_OC1A_CLEAR               2
#define   TIMER1_OC1A_SET                 3
/* Timer OC1A Mode PWM */
#define   TIMER1_OC1A_PWM_NON_INVERTING   2
#define   TIMER1_OC1A_PWM_INVERTING       3

/* Timer OC1B Mode */
#define   TIMER1_OC1B_DISCONNECTED        0
#define   TIMER1_OC1B_TOGGLE              1
#define   TIMER1_OC1B_CLEAR               2
#define   TIMER1_OC1B_SET                 3
/* Timer OC1B Mode PWM */
#define   TIMER1_OC1B_PWM_NON_INVERTING   2
#define   TIMER1_OC1B_PWM_INVERTING       3

#endif /* MCAL_TIMER1_TIMER1_PRIVATE_H_ */
