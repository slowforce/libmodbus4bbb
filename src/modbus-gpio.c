/********************************************************************
 * This file is based on:
 * https://developer.ridgerun.com/wiki/index.php/Gpio-int-test.c
 * It is intended to allow use GPIO pins on beaglebone boards instead
 * of RTS for RS485 communication.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

/****************************************************************
 * Constants
 ****************************************************************/
 
#define	RTS_READ  0
#define	RTS_WRITE 1
#define RS485_CTRL_DEV "/dev/ctl_io"

int send=3;
int receive=4;

/****************************************************************
 * RS485 RTS Control export
 ****************************************************************/
int gpio_export(void)
{
	int fd;

	fd = open(RS485_CTRL_DEV, O_WRONLY);
	if (fd < 0) {
	    perror("rs485/rts");
	    return fd;
	}
 
	return fd;
}

/****************************************************************
 * gpio_unexport
 ****************************************************************/
int gpio_unexport(int fd)
{
	close(fd);
	return 0;
}

/****************************************************************
 * gpio_set_dir
 ****************************************************************/
int gpio_set_dir(int fd, unsigned int out_flag)
{
	return 0;
}

/****************************************************************
 * gpio_set_value
 ****************************************************************/
int gpio_set_value(int fd, unsigned int value)
{
	if (fd < 0)
	    return -1;
 
	if (value == RTS_READ)
	    write(fd, &receive, 4);
	else
            write(fd, &send, 4);
 
	usleep(100);

	return 0;
}
