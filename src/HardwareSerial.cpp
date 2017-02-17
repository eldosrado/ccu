/**
 *
 */
#include "HardwareSerial.h"

uint16_t HardwareSerial::calcBaudrateRegisterValue(uint32_t baudrate) {
	// BAUD <= F_CPU /( 16*(UBRRn+1) )
	// 16*(UBRRn+1) = F_CPU / BAUD
	// (UBRRn+1) = F_CPU / (BAUD*16)
	// UBRRn = F_CPU/(BAUD*16) -1
	auto ret = F_CPU / (16 * baudrate) + 1;
	return ret;
}

void HardwareSerial::baudrate(uint32_t value) {
	uint16_t regvalue = calcBaudrateRegisterValue(value);
	*this->BaudRateH = regvalue >> 8;
	*this->BaudRateL = regvalue & 0xFF;
}
