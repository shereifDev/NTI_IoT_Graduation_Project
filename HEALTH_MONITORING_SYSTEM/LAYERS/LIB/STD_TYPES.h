/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version   0x01                     ****************** */
/************************ @file      STD_TYPES.h              ****************** */



#ifndef         _STD_TYPES_H
#define         _STD_TYPES_H


typedef         unsigned char               uint_8       ;
typedef         unsigned short int          uint_16      ;
typedef         unsigned long int           uint_32      ;
typedef         unsigned long long int      uint_64      ;


typedef         signed char                 int_8        ;  
typedef         signed short int            int_16       ;
typedef         signed long int             int_32       ;
typedef         signed long long int        int_64       ;


typedef         float                       float_32     ;
typedef         double                      float_64     ;
typedef         long double                 float_128    ;


typedef         unsigned char                boolean     ;
#define          TRUE                       (boolean)1
#define          FALSE                      (boolean)0



typedef         uint_8                     ErrorState    ;      
#define          NOK                              0 
#define          OK                               1
   

#define          NULL                      ((void*)0)


#define          ZERO                           0

#define          LOW                            0 
#define          HIGH                           1
   

#endif /* _STD_TYPES_H */