/**
 * @file HardwareSerial.h
 * @author Eduard Scheske
 * @date 2016-12-12
 *
 * This class represent the build-in usart in avr microcontrollers.
 */

#include <avr/io.h>

struct interface0 {
};

/**
 * @class HardwareSerial
 * needed settings
 * baud rates:
 * - 2400
 * - 4800
 * - 9600
 * - 14.4k
 * - 19.2k
 * - 28.8k
 * - 38.4k
 * - 57.6k
 * - 76.8k
 * - 115.2k
 * - 230.4k
 * - 250k
 *
 * Frame Formats:
 * - 1 start bit
 * - 5, 6, 7, 8, or 9 data bits
 * - no, even or odd parity bit
 * - 1 or 2 stop bits
 *
 * This implementation only supports:
 * - 8 bytes, no parity, 1 stop bit aka. 8N1
 *
 * No Hardware Flow Control!
 */
//template<typename InterfaceNumber>
class HardwareSerial {
private:
	// TODO need registers here:
	volatile uint8_t* DataRegister = reinterpret_cast<volatile uint8_t*>( UDR1 );
	volatile uint8_t* ControlStatus1 = reinterpret_cast<volatile uint8_t*>( UCSR1A );
	volatile uint8_t* ControlStatus2 = reinterpret_cast<volatile uint8_t*>( UCSR1B );
	volatile uint8_t* ControlStatus3 = reinterpret_cast<volatile uint8_t*>( UCSR1C );
	volatile uint8_t* ControlStatus4 = reinterpret_cast<volatile uint8_t*>( 0xCB );
	volatile uint8_t* BaudRateH = reinterpret_cast<volatile uint8_t*>( UBRR1L );
	volatile uint8_t* BaudRateL = reinterpret_cast<volatile uint8_t*>( UBRR1H );

	uint16_t calcBaudrateRegisterValue(uint32_t baudrate);
public:

	HardwareSerial() {
		baudrate(9600);
	}

	HardwareSerial(uint32_t rate) {
		baudrate(rate);
	}
	// set baud rate
	void baudrate(uint32_t value);
	// write one byte
	int write(uint8_t data);
	// write array one byte at a time
	int write(uint8_t* data, int len);

};




















