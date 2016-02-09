//---------------------------< /-/ AMSL /-/ >------------------------------
/**
 * file         :       serial.h
 *
 *
 * Environment  :       g++
 * Latest Update:       2008/07/07
 *
 * Designer(s)  :       m.sanpei (AMSL)
 * Author(s)    :       m.sanpei (AMSL)
 *
 * CopyRight    :       2007, Autonomous Mobile Systems Laboratory, Meiji Univ.
 *
 * Revision     :       2007/08/23
 *
 */
//-----------------------------------------------------------------------------
#ifndef _SERIAL_H
#define _SERIAL_H

/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
*/
#include <termios.h>
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
*/

#define MODEMDEVICE1 "/dev/ttyS0"
#define MODEMDEVICE_USB0 "/dev/ttyUSB0"
#define MODEMDEVICE_USB1 "/dev/ttyUSB1"
#define _POSIX_SOURCE 1 /* POSIX 準拠のソース */
#define FALSE 0
#define TRUE 1

//volatile int STOP=FALSE; 

//#define DEBUG

class Serial
{
	private:

		int fd,c, res;
		struct termios oldtio,newtio;
//		char buf[255];


	public:

		Serial(int baudrate, char* modemdevice, int vmin=0, int lflag=0);

		~Serial();

		void read_serial(char* p, int len);
		void write_serial(char* p, int len);
		void set_vmin(int vmin);  // non canonical 時のreadで待つ最低限の文字数

};

#endif //_SERIAL_H
