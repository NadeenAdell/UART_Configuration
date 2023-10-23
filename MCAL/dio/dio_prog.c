/*
 * dio_program.c
 *
 * Created: 10/3/2023 10:08:37 AM
 *  Author: MarioSaad
 */ 


/*****************************************************************Includes*******************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"


#include "dio_config.h"
#include "dio_private.h"
#include "dio_interface.h"


/****************************************************************Implementations********************************************************************/
/*
 * Description : This function is responsible for configuring the direction (input or output) of a specific pin on a given port.
 * It validates the input port number, pin number, and desired pin direction and sets the direction.
 * If the input port number or pin number is invalid, the function returns an error.
 */
EN_dioError_t MDIO_setPinDirection (u8 u8_a_portNumber,u8 u8_a_pinNumber,u8 u8_a_pinDirection)
{

	EN_dioError_t en_l_errorState = DIO_OK;
	 // Check if the port number is valid 
	 if (u8_a_portNumber > NUM_OF_PORTS ) 
	 {
		 en_l_errorState = DIO_INVALID_PORT;
	 }

	 // Check if the pin number is valid 
	 else if (u8_a_pinNumber > NUM_OF_PINS) 
	 {
		 en_l_errorState = DIO_INVALID_PIN;
	 }

	 // Check if the pin direction is valid (assuming 0 for INPUT and 1 for OUTPUT)
	 else if (u8_a_pinDirection > 1) 
	 {
		 en_l_errorState = DIO_INVALID_DIRECTION;
	 }
	else
	{
		/* Setup the pin direction as required */
		switch (u8_a_portNumber)
		{
			case PORTA:
			switch (u8_a_pinDirection)
			{
				case PIN_IN :
				  CLEAR_BIT(MDIO_DDRA,u8_a_pinNumber);
				   break;
				case PIN_OUT:
				  SET_BIT(MDIO_DDRA,u8_a_pinNumber);
				     break;
				default     : 
					en_l_errorState = DIO_INVALID_DIRECTION;
					break;
			}
			break;
			
			case PORTB:
			switch (u8_a_pinDirection)
			{
				case PIN_IN :  
					CLEAR_BIT(MDIO_DDRB,u8_a_pinNumber); 
					break;
				case PIN_OUT:  
					SET_BIT(MDIO_DDRB,u8_a_pinNumber);   
					break;
				default     : 
					en_l_errorState = DIO_INVALID_DIRECTION;
					break;
			}
			break;

			case PORTC:
			switch (u8_a_pinDirection)
			{
				case PIN_IN :  
					CLEAR_BIT(MDIO_DDRC,u8_a_pinNumber); 
					break;
				case PIN_OUT:  
					SET_BIT(MDIO_DDRC,u8_a_pinNumber);   
					break;
				default     : 
					en_l_errorState = DIO_INVALID_DIRECTION;
					break;
			}
			break;

			case PORTD:
			switch (u8_a_pinDirection)
			{
				case PIN_IN :  
					CLEAR_BIT(MDIO_DDRD,u8_a_pinNumber); 
					break;
				case PIN_OUT:  
					SET_BIT(MDIO_DDRD,u8_a_pinNumber);   
					break;
				default     : 
					en_l_errorState = DIO_INVALID_DIRECTION;
					break;
			}
			break;

			default:
				en_l_errorState = DIO_INVALID_PORT;
				break;
		}
	}
	return en_l_errorState;
}




/*
 * Description : This function sets the logical value (HIGH or LOW).
 * It takes the port number, pin number, and the desired value as input parameters.
 * The function validates the input port and pin numbers to ensure they are within ranges.
 * If the input is valid, it sets the specified pin to the desired logical value (HIGH or LOW).
 * If the input port or pin number is invalid, the function returns an error status to indicate failure to handle the request.
 */
EN_dioError_t MDIO_setPinValue     (u8 u8_a_portNumber,u8 u8_a_pinNumber,u8 u8_arg_value)
{   
	EN_dioError_t en_l_errorState = DIO_OK;
	// Check if the port number is valid
	if (u8_a_portNumber > NUM_OF_PORTS)
	{
		en_l_errorState = DIO_INVALID_PORT;
	}

	// Check if the pin number is valid
	else if (u8_a_pinNumber > NUM_OF_PINS)
	{
		en_l_errorState = DIO_INVALID_PIN;
	}

	else
	{
		switch (u8_a_portNumber)
		{
			case PORTA:
			switch (u8_arg_value)
			{
				case PIN_LOW :  
					CLEAR_BIT(MDIO_PORTA,u8_a_pinNumber); 
					break;
				case PIN_HIGH:  
					SET_BIT(MDIO_PORTA,u8_a_pinNumber);   
					break;
				default      : 
					en_l_errorState = DIO_INVALID_VALUE;
					break;
			}
			break;
			
			case PORTB:
			switch (u8_arg_value)
			{
				case PIN_LOW :  
					CLEAR_BIT(MDIO_PORTB,u8_a_pinNumber); 
					break;
				case PIN_HIGH:  
					SET_BIT(MDIO_PORTB,u8_a_pinNumber);   
					break;
				default      : 
					en_l_errorState = DIO_INVALID_VALUE;
					break;
			}
			break;

			case PORTC:
			switch (u8_arg_value)
			{
				case PIN_LOW :  
					CLEAR_BIT(MDIO_PORTC,u8_a_pinNumber); 
					break;
				case PIN_HIGH:  
					SET_BIT(MDIO_PORTC,u8_a_pinNumber);   
					break;
				default      : 
					en_l_errorState = DIO_INVALID_VALUE;
					break;
			}
			break;

			case PORTD:
			switch (u8_arg_value)
			{
				case PIN_LOW :  
					CLEAR_BIT(MDIO_PORTD,u8_a_pinNumber); 
					break;
				case PIN_HIGH:  
					SET_BIT(MDIO_PORTD,u8_a_pinNumber);   
					break;
				default      : 
					en_l_errorState = DIO_INVALID_VALUE;
					break;
			}
			break;

			default:
				en_l_errorState = DIO_INVALID_PORT;
				break;
		}
    }
	return en_l_errorState;
}





/*
 * Description : This function retrieves the logical value (HIGH or LOW).
 * It takes the port number and pin number as input parameters.
 * The function validates the input port and pin numbers to ensure they are within ranges.
 * If the input is valid it reads the logical value of the specified pin (HIGH or LOW) and returns it.
 * If the input port or pin number is invalid the function returns a default value indicating failure to handle the request
 */
u8   MDIO_u8getPinValue       (u8 u8_a_portNumber,u8 u8_a_pinNumber)
{
    u8 u8_l_data = LOGIC_LOW;

	if((u8_a_pinNumber >= NUM_OF_PINS) || (u8_a_portNumber >= NUM_OF_PORTS))
	{
		// Do Nothing 
	}
	else
	{
		/* Read the pin value as required */
		switch (u8_a_portNumber)
		{
		case PORTA:
			u8_l_data=GET_BIT(MDIO_PINA,u8_a_pinNumber);
			break; 
    
		case PORTB:
			u8_l_data=GET_BIT(MDIO_PINB,u8_a_pinNumber);
			break; 

		case PORTC:
			u8_l_data=GET_BIT(MDIO_PINC,u8_a_pinNumber);
			break;

		case PORTD:
			u8_l_data=GET_BIT(MDIO_PIND,u8_a_pinNumber);
			break;

		default:
			break;
		}
	}
    return u8_l_data;
} 





/*
 * Description : This function is responsible for configuring the direction (input or output) of all pins on a specified port.
 * It takes the port number and the desired port direction (input or output) as input parameters.
 * The function validates the input port number and direction to ensure they are within ranges.
 * If the input is valid. it sets the direction of all pins on the specified port. 
 * If the input port number or direction is invalid, the function returns an error status to indicate failure to handle the request
 */
EN_dioError_t MDIO_setPortDirection (u8 u8_a_portNumber,u8 u8_a_pinDirection)
{
	EN_dioError_t en_l_errorState = DIO_OK;
	if (u8_a_portNumber > NUM_OF_PORTS)
	{
		en_l_errorState = DIO_INVALID_PORT;
	}
	else
	{
		/* Setup the port direction as required */
		switch (u8_a_portNumber)
		{
			case PORTA:  
				MDIO_DDRA = u8_a_pinDirection;
				break;
			
			case PORTB:  
				MDIO_DDRB = u8_a_pinDirection; 
				break;

			case PORTC:  
				MDIO_DDRC = u8_a_pinDirection; 
				break;

			case PORTD:  
				MDIO_DDRD = u8_a_pinDirection; 
				break;

			default:
				en_l_errorState = DIO_INVALID_DIRECTION;
				break;
		}	
	}
	return en_l_errorState;
	
}





/*
 * Description : Write the value on the required port and return error status.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
EN_dioError_t MDIO_setPortValue (u8 u8_a_portNumber,u8 u8_arg_value)
{
	EN_dioError_t en_l_errorState = DIO_OK;
	if(u8_a_portNumber >= NUM_OF_PORTS)
	{
		en_l_errorState = DIO_INVALID_PORT;
	}
	else
	{
		/* Write the port value as required */
		switch (u8_a_portNumber)
		{
		case PORTA:   
			MDIO_PORTA = u8_arg_value; 
			break;

		case PORTB:  
			MDIO_PORTB = u8_arg_value; 
			break;

		case PORTC:  
			MDIO_PORTC = u8_arg_value; 
			break;

		case PORTD:  
			MDIO_PORTD = u8_arg_value; 
			break;

		default:
			en_l_errorState = DIO_INVALID_PORT;
			break;
		}
	}
	return en_l_errorState;
}





/*
 * Description : This function toggles the logical value (HIGH to LOW or LOW to HIGH) of a specific pin on a specified port.
 * It takes the port number and pin number as input parameters.
 * The function validates the input port and pin numbers to ensure they are within ranges. 
 * If the input is valid, it toggles the logical value of the specified pin.
 * If the input port or pin number is invalid, the function returns an error status to indicate failure to handle the request
 */
EN_dioError_t MDIO_togglePinValue (u8 u8_a_portNumber,u8 u8_a_pinNumber)
{
	EN_dioError_t en_l_errorState = DIO_OK;
	// Check if the port number is valid
	if (u8_a_portNumber > NUM_OF_PORTS)
	{
		en_l_errorState = DIO_INVALID_PORT;
	}
	// Check if the pin number is valid
	else if (u8_a_pinNumber > NUM_OF_PINS)
	{
		en_l_errorState = DIO_INVALID_PIN;
	}

	else
	{
		/* Toggle the Pin value as required */
		switch (u8_a_portNumber)
		{
			case PORTA:
			TOGGLE_BIT(MDIO_PORTA,u8_a_pinNumber);
			break;

			case PORTB:
			TOGGLE_BIT(MDIO_PORTB,u8_a_pinNumber);
			break;

			case PORTC:
			TOGGLE_BIT(MDIO_PORTC,u8_a_pinNumber);
			break;

			case PORTD:
			TOGGLE_BIT(MDIO_PORTD,u8_a_pinNumber);
			break;

			default:
			en_l_errorState = DIO_INVALID_PORT;
			break;
		}
	}
	return en_l_errorState;
	
}





/*
 * Description : This function retrieves the logical value (HIGH or LOW) of all pins on a specified port.
 * It takes the port number as an input parameter. The function validates the input port number to ensure it is within the range.
 * If the input is valid, it reads and returns the logical value of all pins on the specified port.
 * If the input port number is invalid, the function returns a default value indicating failure to handle the request
 */
u8 MDIO_getPortValue (u8 u8_a_portNumber)
{
    u8 u8_l_data = LOGIC_LOW;
	if(u8_a_portNumber > NUM_OF_PORTS)
	{
		// Do Nothing
	}
	else
	{
		/* Read the port value as required */
		switch (u8_a_portNumber)
		{
		case PORTA: 
			u8_l_data = MDIO_PINA; 
			break; 
    
		case PORTB: 
			u8_l_data = MDIO_PINB; 
			break; 

		case PORTC: 
			u8_l_data = MDIO_PINC; 
			break; 

		case PORTD: 
			u8_l_data = MDIO_PIND; 
			break; 
		default:
			break;
		}
	}
    return u8_l_data;

}





/*
 * Description: This function retrieves the logical value (HIGH or LOW) of all pins on a specified port.
 * It takes the port number as an input parameter and reads the value of all pins on the specified port.
 * The function validates the input port number to ensure it is within the range.
 * If the input port number is valid, it returns the logical value of all pins on the specified port.
 * If the input port number is invalid, the function returns a default value indicating failure to handle the request.
 */
EN_dioError_t MDIO_setPullupResistor (u8 u8_a_portNumber,u8 u8_a_pinNumber)
{
    EN_dioError_t en_l_errorState = DIO_OK;
    // Check if the port number is valid
    if (u8_a_portNumber > NUM_OF_PORTS)
    {
	    en_l_errorState = DIO_INVALID_PORT;
    }
    // Check if the pin number is valid
    else if (u8_a_pinNumber > NUM_OF_PINS)
    {
	    en_l_errorState = DIO_INVALID_PIN;
    }
    else
    {
		switch (u8_a_portNumber)
		{
		case PORTA: 
			if (((MDIO_DDRA>>u8_a_pinNumber)&0x01)==0)
				{
					SET_BIT(MDIO_PORTA,u8_a_pinNumber);
				}
			break;

		case PORTB:
			if (((MDIO_DDRB>>u8_a_pinNumber)&0x01)==0)
				{
					SET_BIT(MDIO_PORTB,u8_a_pinNumber);
				}
			break;
		case PORTC:
			if (((MDIO_DDRC>>u8_a_pinNumber)&0x01)==0)
				{
					SET_BIT(MDIO_PORTC,u8_a_pinNumber);
				}
			break;
		case PORTD:
			if (((MDIO_DDRD>>u8_a_pinNumber)&0x01)==0)
				{
					SET_BIT(MDIO_PORTD,u8_a_pinNumber);
				}
			break;
		default:
			en_l_errorState = DIO_INVALID_PORT;
			break;
		}
	}
	return en_l_errorState;
}