
#ifndef MCAL_EXT_INT_EXT_INT_INTERFACE_H_
#define MCAL_EXT_INT_EXT_INT_INTERFACE_H_

#include "Std_Types.h"

#define EXT_INT0 	0
#define EXT_INT1 	1
#define EXT_INT2	2

void Ext_Int_Init(uint8 interruptChannel);
void Ext_Int_Enable(uint8 interruptChannel);
void Ext_Int_Disable(uint8 interruptChannel);
void Ext_Int_SetCallBack(uint8 interruptChannel, void (*interruptAction)(void));


#endif /* MCAL_EXT_INT_EXT_INT_INTERFACE_H_ */
