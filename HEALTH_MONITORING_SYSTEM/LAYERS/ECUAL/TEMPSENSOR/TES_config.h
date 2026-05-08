/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     TES_config.h              ****************** */




#ifndef  _TES_CONFIG_H 
#define	 _TES_CONFIG_H


/* ---------------------------------------------------------------- */
/*                  LM35 Configuration Macros                       */
/* ---------------------------------------------------------------- */

/* ADC Reference Voltage in milli-volts (e.g., 5V = 5000.0mV) */
#define LM35_VREF_MV                 5000.0f

/* Maximum number of ADC steps (10-bit resolution = 2^10 = 1024) */
#define LM35_ADC_MAX_STEPS           1024.0f

/* Sensor output in milli-volts per degree Celsius (from Datasheet) */
#define LM35_MV_PER_CELSIUS          10.0f



#endif	/* _TES_CONFIG_H */

