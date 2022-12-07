/*  Date    : 27/8/2022
    Name    : Rafik Sameh Yanni
	Version : 1.0
	SWC     : bit math
	*/

#ifndef BITMATH_H_
#define BITMATH_H_


#define GET_BIT(REG,BIT_NUM) ((REG>>BIT_NUM)&1)
#define TOG_BIT(REG,BIT_NUM) (REG^=(1<<BIT_NUM))
#define CLR_BIT(REG,BIT_NUM) REG&=(~(1<<BIT_NUM))
#define SET_BIT(REG,BIT_NUM) REG|=(1<<BIT_NUM)

#endif