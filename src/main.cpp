/**
 * @file main.cpp
 * @author Eduard Scheske
 * Beer free License
 */

//#include <stdint.h>
//#include <string.h>
#include <avr/io.h>

#include "HardwareSerial.h"


int HardwareSerial::write(uint8_t data) {
	return 0;
}

int HardwareSerial::write(uint8_t* data, int len) {
	return 0;
}

/**
 *
 */
int main(void) {
//	HardwareSerial serial1;
	HardwareSerial serial1(9600);
//	serial1.baudrate = 9600;
	uint8_t data[] = {1,2,3};

	serial1.write(data[0]);
	while(true) {
		serial1.write(data,sizeof(data));
	}

	UDR1 = 0;
}




















