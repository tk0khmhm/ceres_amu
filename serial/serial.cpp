//---------------------------< /-/ AMSL /-/ >------------------------------
/**
 * file         :       serial.cpp
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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "serial.h"


//#define DEBUG

Serial::Serial(int baudrate, char* modemdevice, int vmin, int lflag)
{
	fd = open(modemdevice, O_RDWR | O_NOCTTY ); 
	if (fd <0) {perror(modemdevice); exit(-1); }

	tcgetattr(fd,&oldtio); /* 現在のポート設定を待避 */

	bzero(&newtio, sizeof(newtio));
	newtio.c_cflag = baudrate | CRTSCTS | CS8 | CLOCAL | CREAD;
	newtio.c_oflag = 0;

	/* set input mode (デフォルトは非カノニカル) */
	newtio.c_lflag = lflag;
 
	if(lflag==0){
		printf("notCanonial\n");
		newtio.c_iflag = IGNPAR;

		newtio.c_cc[VTIME]    = 0;   /* キャラクタ間タイマ未使用*/
		newtio.c_cc[VMIN]     = vmin;   /* vmin文字受け取るまでブロックする*/
	}
	else if(lflag==ICANON){
		printf("Canonial\n");
		//newtio.c_iflag = (IGNPAR | ICRNL);
		newtio.c_iflag = ICRNL;

		newtio.c_cc[VINTR] = 0;
		newtio.c_cc[VQUIT] = 0;
		newtio.c_cc[VERASE] = 0;
		newtio.c_cc[VKILL] = 0;
		newtio.c_cc[VEOF] = 4;
		newtio.c_cc[VTIME] = 0;
		newtio.c_cc[VMIN] = 1;
		newtio.c_cc[VSWTC] = 0;
		newtio.c_cc[VSTART] = 0;
		newtio.c_cc[VSTOP] = 0;
		newtio.c_cc[VSUSP] = 0;
		newtio.c_cc[VEOL] = 0;
		newtio.c_cc[VREPRINT] = 0;
		newtio.c_cc[VDISCARD] = 0;
		newtio.c_cc[VWERASE] = 0;
		newtio.c_cc[VLNEXT] = 0;
		newtio.c_cc[VEOL2] = 0;
	}

	tcflush(fd, TCIFLUSH);	//ポートのクリア
	tcsetattr(fd,TCSANOW,&newtio);	//ポートの設定を有効にする

}


Serial::~Serial()
{
	tcsetattr(fd,TCSANOW,&oldtio);
}


void
Serial::read_serial(char* p, int len)
{
	//printf("read\n");
	//printf("p: %s \n",p);
	//printf("len: %d\n",len);
	read(fd, p, len);
}

void
Serial::write_serial(char* p, int len)
{
	printf("write\n");
	printf("p: %s\n",p);
	printf("len: %d\n",len);
	//int e=write(fd, p, len);
	write(fd, p, len);
	//printf("e: %d\n",e);
	//fputs(p,fd);
}

void
Serial::set_vmin(int vmin) {
 
	newtio.c_iflag = IGNPAR;

	newtio.c_cc[VTIME]    = 1;   /* キャラクタ間タイマ未使用*/
	newtio.c_cc[VMIN]     = vmin;   /* vmin文字受け取るまでブロックする*/

}

#ifdef DEBUG
int main()
{
	char rdata[255];
	char sdata[255];


	Serial test(100, B19200, "/dev/ttyUSB0");

	sprintf(sdata, "V\r");
	
	test.write_serial(sdata, strlen(sdata));

	test.read_serial(rdata);

	printf("%s",rdata);

	return 0;
}


/*

 while (STOP==FALSE) {       // 入力ループ 
   test.res = read(fd,buf,255);   // 5 文字入力されたら戻る 
   buf[res]=0;               // printf を使うために文字列終端をセット 
   printf(":%s:%d\n", buf, res);
   if (buf[0]=='z') STOP=TRUE;
 }
 

 return 0;
}
*/

#endif
