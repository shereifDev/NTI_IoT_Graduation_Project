/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     BIT_MATH.h                ****************** */



#ifndef         _BIT_MATH_H
#define         _BIT_MATH_H





#define          SET_BIT(REG,POS)              (REG|=(1<<POS))
#define          CLR_BIT(REG,POS)              (REG&=(~(1<<POS)))
#define          TOGGLE_BIT(REG,POS)           (REG^=(1<<4)) 
#define          READ_BIT(REG,POS)             ((REG&(1<<POS))>>POS)  




#endif /*<_BIT_MATH_H*/