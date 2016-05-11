# libmodbus4bbb
libmodbus tweak for working with BeagleboneBlack and WaveShare RS485 cape

This work inspired by following post:
https://github.com/stephane/libmodbus/wiki/Beaglebone-RS485-cape
Someone reported receiving '0x00', breaks libmodbus CRC calculation
https://github.com/stephane/libmodbus/pull/139
By simply ignore the first 0x00 can fix this issue since modbus slave address 
will never be 0.

# links:
RS485 Cape: 
https://detail.tmall.com/item.htm?id=42653508157&spm=a1z09.2.9.12.0GxaLL&_u=v1meru4530c

How to work with RS485 Cape: 
http://blog.sina.com.cn/s/blog_69a2fcfa0102vulx.html

# Note:
Source code is based on libmodbus 3.0.6, it should be easily ported to latest version

# Contact:
slowforce@gmail.com
