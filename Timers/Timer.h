

#ifndef TIMER_H_
#define TIMER_H_




typedef enum{
  TIMERBLOCK0=0,
  TIMERBLOCK1,
  TIMERBLOCK2,
  TIMERBLOCK3,
  TIMERBLOCK4,
  TIMERBLOCK5,
  TIMERBLOCK0_W,
  TIMERBLOCK1_W,
  TIMERBLOCK2_W,
  TIMERBLOCK3_W,
  TIMERBLOCK4_W,
  TIMERBLOCK5_W,
}TIMER_BLOCK_t;

typedef enum{
  TIMERA=0,
  TIMERB,
}SUBTIMER_t;


typedef enum{
    TIMER_CFG_32BITMODE = 0,
    TIMER_CFG_RTC_MODE ,
    TIMER_CFG_16BITMODE = 4
}TIMER_CONFIG_t;

typedef enum {
    TIMER_MODE_ONE_SHOT = 0x00000001,
    TIMER_MODE_ONE_SHOT_UP = 0x00000031,
    TIMER_MODE_PERIODIC = 0x00000002,
    TIMER_MODE_PERIODIC_UP = 0x00000032,
    TIMER_MODE_PWM = 0x0000000A,
    TIMER_MODE_EDGE_TIME = 0x00000017,
    TIMER_MODE_EDGE_TIME_F = 0x00000018,
    TIMER_MODE_EDGE_TIME_R = 0x00000019,
    TIMER_MODE_EDGE_TIME_B = 0x00000020,

}TIMER_MODES_t;

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_CTL register.
//
//*****************************************************************************
#define TIMER_CTL_TBPWML        0x00004000  // GPTM Timer B PWM Output Level
#define TIMER_CTL_TBOTE         0x00002000  // GPTM Timer B Output Trigger
                                            // Enable
#define TIMER_CTL_TBEVENT_M     0x00000C00  // GPTM Timer B Event Mode
#define TIMER_CTL_TBEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TBEVENT_NEG   0x00000400  // Negative edge
#define TIMER_CTL_TBEVENT_BOTH  0x00000C00  // Both edges
#define TIMER_CTL_TBSTALL       0x00000200  // GPTM Timer B Stall Enable
#define TIMER_CTL_TBEN          0x00000100  // GPTM Timer B Enable
#define TIMER_CTL_TAPWML        0x00000040  // GPTM Timer A PWM Output Level
#define TIMER_CTL_TAOTE         0x00000020  // GPTM Timer A Output Trigger
                                            // Enable
#define TIMER_CTL_RTCEN         0x00000010  // GPTM RTC Stall Enable
#define TIMER_CTL_TAEVENT_M     0x0000000C  // GPTM Timer A Event Mode
#define TIMER_CTL_TAEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TAEVENT_NEG   0x00000004  // Negative edge
#define TIMER_CTL_TAEVENT_BOTH  0x0000000C  // Both edges
#define TIMER_CTL_TASTALL       0x00000002  // GPTM Timer A Stall Enable
#define TIMER_CTL_TAEN          0x00000001  // GPTM Timer A Enable


//*****************************************************************************
//
// Values that can be passed to TimerIntEnable, TimerIntDisable, and
// TimerIntClear as the ui32IntFlags parameter, and returned from
// TimerIntStatus.
//
//*****************************************************************************
#define TIMER_TIMB_DMA          0x00002000 // TimerB DMA Complete Interrupt.
#define TIMER_TIMB_MATCH        0x00000800  // TimerB match interrupt
#define TIMER_CAPB_EVENT        0x00000400  // CaptureB event interrupt
#define TIMER_CAPB_MATCH        0x00000200  // CaptureB match interrupt
#define TIMER_TIMB_TIMEOUT      0x00000100  // TimerB time out interrupt
#define TIMER_TIMA_DMA          0x00000020 // TimerA DMA Complete Interrupt.
#define TIMER_TIMA_MATCH        0x00000010  // TimerA match interrupt
#define TIMER_RTC_MATCH         0x00000008  // RTC interrupt mask
#define TIMER_CAPA_EVENT        0x00000004  // CaptureA event interrupt
#define TIMER_CAPA_MATCH        0x00000002  // CaptureA match interrupt
#define TIMER_TIMA_TIMEOUT      0x00000001  // TimerA time out interrupt

//*****************************************************************************
//
// The following are functions prototypes for timer driver.
//
//*****************************************************************************



void TimerInit (TIMER_BLOCK_t timerBlock, SUBTIMER_t subTimer, TIMER_CONFIG_t config, TIMER_MODES_t mode);

void TimerLoadSet(TIMER_BLOCK_t timerBlock, SUBTIMER_t subTimer, u32 value);

void TimerMatchSet(TIMER_BLOCK_t timerBlock, SUBTIMER_t subTimer, u32 value);

void TimerIntClear(TIMER_BLOCK_t timerBlock, u32 IntFlags);

void TimerEnable(TIMER_BLOCK_t timerBlock, SUBTIMER_t subTimer );

void TimerDisable(TIMER_BLOCK_t timerBlock, SUBTIMER_t subTimer );

void TimerIntDisable (TIMER_BLOCK_t timerBlock, u32 IntFlags);

void TimerIntEnable (TIMER_BLOCK_t timerBlock, u32 IntFlags);

void TimerSetCallBack (TIMER_BLOCK_t timerBlock, SUBTIMER_t subTimer, void (*pfnHandler)(void));





#endif /* TIMER_H_ */
