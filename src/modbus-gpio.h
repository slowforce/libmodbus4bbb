#ifndef MODBUS_GPIO_H
#define MODBUS_GPIO_H

int gpio_export(void);
int gpio_unexport(int fd);
int gpio_set_dir(int fd, unsigned int out_flag);
int gpio_set_value(int fd, unsigned int value);

#endif
