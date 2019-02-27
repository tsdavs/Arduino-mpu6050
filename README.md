# Arduino-mpu6050

Inspired from [Mattzzw's Arduino-mpu6050 project](https://github.com/mattzzw/Arduino-mpu6050 "Project link") but in C++.

[![IMAGE ALT TEXT HERE](https://i.ytimg.com/vi/yqFfmwVufMo/hqdefault.jpg?sqp=-oaymwEjCPYBEIoBSFryq4qpAxUIARUAAAAAGAElAADIQj0AgKJDeAE=&rs=AOn4CLDUQhLYZKAQ-WxJfWnspnev9Ral4g)](https://www.youtube.com/watch?v=yqFfmwVufMo)

## Libraries
* boost
* glut
* opengl
* MPU6050_tockn (modified)

## Equiptment
* [MPU-6050 breakout component](https://www.ebay.com.au/itm/GY-521-MPU-6050-3-Axis-Analogue-Gyroscope-and-Accelerometer/273369131170?hash=item3fa611e8a2:g:08AAAOSwPntcPfPJ:rk:1:pf:1&frcectupt=true)

## Setup
```
          MPU 6050    
        +-----------+
 5v --> |[ ]VCC     |
GND --> |[ ]GND     |
 A5 --> |[ ]SCL     |
 A4 --> |[ ]SDA     |
        |[ ]XDA     |
        |[ ]XCL     |
        |[ ]ADO     |
 D2 --> |[ ]INT     |
        +-----------+
```
