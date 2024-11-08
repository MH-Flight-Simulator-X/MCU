#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// $[ACMP0]
// [ACMP0]$

// $[ACMP1]
// [ACMP1]$

// $[ADC0]
// ADC0 CH0 on PD0
#ifndef ADC0_CH0_PORT                           
#define ADC0_CH0_PORT                            gpioPortD
#endif
#ifndef ADC0_CH0_PIN                            
#define ADC0_CH0_PIN                             0
#endif

// ADC0 CH1 on PD1
#ifndef ADC0_CH1_PORT                           
#define ADC0_CH1_PORT                            gpioPortD
#endif
#ifndef ADC0_CH1_PIN                            
#define ADC0_CH1_PIN                             1
#endif

// [ADC0]$

// $[BU]
// [BU]$

// $[CMU]
// [CMU]$

// $[DAC0]
// [DAC0]$

// $[DBG]
// [DBG]$

// $[ETM]
// [ETM]$

// $[GPIO]
// [GPIO]$

// $[HFXO]
// [HFXO]$

// $[I2C0]
// I2C0 SCL on PA1
#ifndef I2C0_SCL_PORT                           
#define I2C0_SCL_PORT                            gpioPortA
#endif
#ifndef I2C0_SCL_PIN                            
#define I2C0_SCL_PIN                             1
#endif
#ifndef I2C0_ROUTE_LOC                          
#define I2C0_ROUTE_LOC                           0
#endif

// I2C0 SDA on PA0
#ifndef I2C0_SDA_PORT                           
#define I2C0_SDA_PORT                            gpioPortA
#endif
#ifndef I2C0_SDA_PIN                            
#define I2C0_SDA_PIN                             0
#endif

// [I2C0]$

// $[I2C1]
// [I2C1]$

// $[LCD]
// [LCD]$

// $[LESENSE]
// [LESENSE]$

// $[LETIMER0]
// [LETIMER0]$

// $[LEUART0]
// [LEUART0]$

// $[LEUART1]
// [LEUART1]$

// $[LFXO]
// [LFXO]$

// $[PCNT0]
// [PCNT0]$

// $[PCNT1]
// [PCNT1]$

// $[PCNT2]
// [PCNT2]$

// $[PRS.CH0]
// [PRS.CH0]$

// $[PRS.CH1]
// [PRS.CH1]$

// $[PRS.CH2]
// [PRS.CH2]$

// $[PRS.CH3]
// [PRS.CH3]$

// $[TIMER0]
// [TIMER0]$

// $[TIMER1]
// [TIMER1]$

// $[TIMER2]
// [TIMER2]$

// $[TIMER3]
// [TIMER3]$

// $[USART0]
// [USART0]$

// $[USART1]
// [USART1]$

// $[USART2]
// [USART2]$

// $[CUSTOM_PIN_NAME]
#ifndef _PORT                                   
#define _PORT                                    gpioPortA
#endif
#ifndef _PIN                                    
#define _PIN                                     0
#endif

#ifndef LED0_PORT                               
#define LED0_PORT                                gpioPortA
#endif
#ifndef LED0_PIN                                
#define LED0_PIN                                 2
#endif

#ifndef LED1_PORT                               
#define LED1_PORT                                gpioPortA
#endif
#ifndef LED1_PIN                                
#define LED1_PIN                                 3
#endif

#ifndef THUMB_X_PORT                            
#define THUMB_X_PORT                             gpioPortD
#endif
#ifndef THUMB_X_PIN                             
#define THUMB_X_PIN                              0
#endif

#ifndef THUMB_Y_PORT                            
#define THUMB_Y_PORT                             gpioPortD
#endif
#ifndef THUMB_Y_PIN                             
#define THUMB_Y_PIN                              1
#endif

// [CUSTOM_PIN_NAME]$

#endif // PIN_CONFIG_H

