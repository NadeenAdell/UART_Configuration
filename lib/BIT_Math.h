
#ifndef SERVIES_BIT_MATH_H_
#define SERVIES_BIT_MATH_H_


#define SET_BIT(REG,BIT_NUMBER) 	(REG |= (1<<BIT_NUMBER))
#define GET_BIT(REG,BIT_NUMBER)		((REG>>BIT_NUMBER)&1)
#define CLEAR_BIT(REG,BIT_NUMBER) 	(REG &= (~(1<<BIT_NUMBER)))
#define TOGGLE_BIT(REG,BIT_NUMBER) 	(REG ^=(1<<BIT_NUMBER))
#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0
#define NULL 0

#endif /* SERVIES_BIT_MATH_H_ */
