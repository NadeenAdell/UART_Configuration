/*
 * dio_interface.h
 *
 * Created: 10/3/2023 10:09:02 AM
 *  Author: MarioSaad
 */ 

#include "../../Lib/STD_Types.h"
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7

#define PIN_IN                 0
#define PIN_OUT                1

#define PIN_LOW                0
#define PIN_HIGH               1

#define PORT_OUT               0xff
#define PORT_IN                0x00

#define NUM_OF_PORTS           3      //From 0 to 3
#define NUM_OF_PINS            7      //From 0 to 7

#define LOGIC_LOW	0
#define LOGIC_HIGH	1

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	DIO_OK,
	DIO_INVALID_PORT,
	DIO_INVALID_PIN,
	DIO_INVALID_DIRECTION,
	DIO_INVALID_VALUE
}EN_dioError_t;
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description : This function is responsible for configuring the direction (input or output) of a specific pin on a given port.
 * It validates the input port number, pin number, and desired pin direction and sets the direction.
 * If the input port number or pin number is invalid, the function returns an error.
 */
EN_dioError_t MDIO_setPinDirection (u8 u8_a_portNum,u8 u8_a_pinNumberber,u8 u8_a_pinDirection);

/*
 * Description : This function sets the logical value (HIGH or LOW).
 * It takes the port number, pin number, and the desired value as input parameters.
 * The function validates the input port and pin numbers to ensure they are within ranges.
 * If the input is valid, it sets the specified pin to the desired logical value (HIGH or LOW).
 * If the input port or pin number is invalid, the function returns an error status to indicate failure to handle the request.
 */
EN_dioError_t MDIO_setPinValue     (u8 u8_a_portNum,u8 u8_a_pinNumberber,u8 u8_a_value);

/*
 * Description : This function toggles the logical value (HIGH to LOW or LOW to HIGH) of a specific pin on a specified port.
 * It takes the port number and pin number as input parameters.
 * The function validates the input port and pin numbers to ensure they are within ranges. 
 * If the input is valid, it toggles the logical value of the specified pin.
 * If the input port or pin number is invalid, the function returns an error status to indicate failure to handle the request
 */
EN_dioError_t MDIO_togglePinValue (u8 u8_a_portNumber,u8 u8_a_pinNumber);


/*
 * Description : This function retrieves the logical value (HIGH or LOW).
 * It takes the port number and pin number as input parameters.
 * The function validates the input port and pin numbers to ensure they are within ranges.
 * If the input is valid it reads the logical value of the specified pin (HIGH or LOW) and returns it.
 * If the input port or pin number is invalid the function returns a default value indicating failure to handle the request
 */
u8   MDIO_u8getPinValue (u8 u8_a_portNumber,u8 u8_a_pinNumber); 


/*
 * Description : This function is responsible for configuring the direction (input or output) of all pins on a specified port.
 * It takes the port number and the desired port direction (input or output) as input parameters.
 * The function validates the input port number and direction to ensure they are within ranges.
 * If the input is valid. it sets the direction of all pins on the specified port. 
 * If the input port number or direction is invalid, the function returns an error status to indicate failure to handle the request
 */
EN_dioError_t MDIO_setPortDirection (u8 u8_a_portNumber,u8 u8_a_pinDirection);


/*
 * Description : Write the value on the required port and return error status.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
EN_dioError_t MDIO_setPortValue (u8 u8_a_portNumber,u8 u8_a_value);


/*
 * Description : This function retrieves the logical value (HIGH or LOW) of all pins on a specified port.
 * It takes the port number as an input parameter. The function validates the input port number to ensure it is within the range.
 * If the input is valid, it reads and returns the logical value of all pins on the specified port.
 * If the input port number is invalid, the function returns a default value indicating failure to handle the request
 */
u8 MDIO_getPortValue (u8 u8_a_portNumber);


/*
 * Description: This function retrieves the logical value (HIGH or LOW) of all pins on a specified port.
 * It takes the port number as an input parameter and reads the value of all pins on the specified port.
 * The function validates the input port number to ensure it is within the range.
 * If the input port number is valid, it returns the logical value of all pins on the specified port.
 * If the input port number is invalid, the function returns a default value indicating failure to handle the request.
 */
EN_dioError_t MDIO_setPullupResistor (u8 u8_a_portNumber,u8 u8_a_pinNumber);
#endif /* DIO_INTERFACE_H_ */