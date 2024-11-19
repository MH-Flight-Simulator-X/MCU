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

// ADC0 CH2 on PD2
#ifndef ADC0_CH2_PORT                           
#define ADC0_CH2_PORT                            gpioPortD
#endif
#ifndef ADC0_CH2_PIN                            
#define ADC0_CH2_PIN                             2
#endif

// [ADC0]$

// $[BU]
// [BU]$

// $[CMU]
// [CMU]$

// $[DAC0]
// [DAC0]$

// $[DBG]
// DBG SWO on PF2
#ifndef DBG_SWO_PORT                            
#define DBG_SWO_PORT                             gpioPortF
#endif
#ifndef DBG_SWO_PIN                             
#define DBG_SWO_PIN                              2
#endif
#ifndef DBG_ROUTE_LOC                           
#define DBG_ROUTE_LOC                            0
#endif

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
// USART0 CLK on PE12
#ifndef USART0_CLK_PORT                         
#define USART0_CLK_PORT                          gpioPortE
#endif
#ifndef USART0_CLK_PIN                          
#define USART0_CLK_PIN                           12
#endif
#ifndef USART0_ROUTE_LOC                        
#define USART0_ROUTE_LOC                         0
#endif

// USART0 CS on PE13
#ifndef USART0_CS_PORT                          
#define USART0_CS_PORT                           gpioPortE
#endif
#ifndef USART0_CS_PIN                           
#define USART0_CS_PIN                            13
#endif

// USART0 RX on PE11
#ifndef USART0_RX_PORT                          
#define USART0_RX_PORT                           gpioPortE
#endif
#ifndef USART0_RX_PIN                           
#define USART0_RX_PIN                            11
#endif

// USART0 TX on PE10
#ifndef USART0_TX_PORT                          
#define USART0_TX_PORT                           gpioPortE
#endif
#ifndef USART0_TX_PIN                           
#define USART0_TX_PIN                            10
#endif

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

#ifndef led0_PORT                               
#define led0_PORT                                gpioPortA
#endif
#ifndef led0_PIN                                
#define led0_PIN                                 2
#endif

#ifndef led1_PORT                               
#define led1_PORT                                gpioPortA
#endif
#ifndef led1_PIN                                
#define led1_PIN                                 3
#endif

#ifndef btn0_PORT                               
#define btn0_PORT                                gpioPortA
#endif
#ifndef btn0_PIN                                
#define btn0_PIN                                 4
#endif

#ifndef btn1_PORT                               
#define btn1_PORT                                gpioPortA
#endif
#ifndef btn1_PIN                                
#define btn1_PIN                                 5
#endif

#ifndef button_fire_PORT                        
#define button_fire_PORT                         gpioPortD
#endif
#ifndef button_fire_PIN                         
#define button_fire_PIN                          3
#endif

#ifndef button_led_PORT                         
#define button_led_PORT                          gpioPortD
#endif
#ifndef button_led_PIN                          
#define button_led_PIN                           4
#endif

// [CUSTOM_PIN_NAME]$

#endif // PIN_CONFIG_H

