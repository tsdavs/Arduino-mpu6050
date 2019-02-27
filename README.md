# Arduino-mpu6050

Inspired from [Mattzzw's Arduino-mpu6050 project](https://github.com/mattzzw/Arduino-mpu6050 "Project link") but in C++. 

6DOF IMU (MPU-6050) breakout component purchased [here](https://www.ebay.com.au/itm/GY-521-MPU-6050-3-Axis-Analogue-Gyroscope-and-Accelerometer/273369131170?hash=item3fa611e8a2:g:08AAAOSwPntcPfPJ:rk:1:pf:1&frcectupt=true) for reference.

[![IMAGE ALT TEXT HERE](https://i.ytimg.com/vi/yqFfmwVufMo/hqdefault.jpg?sqp=-oaymwEjCPYBEIoBSFryq4qpAxUIARUAAAAAGAElAADIQj0AgKJDeAE=&rs=AOn4CLDUQhLYZKAQ-WxJfWnspnev9Ral4g)](https://www.youtube.com/watch?v=yqFfmwVufMo)

## Future Ideas

* Integrate WiFi

## Setup
                                      +-----+
         +----[PWR]-------------------| USB |--+                                MPU 6050
         |                            +-----+  |
         |         GND/RST2  [ ][ ]            |                              +-----------+
         |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |                       5v --> |[ ]VCC     |
         |          5V/MISO2 [ ][ ]  A4/SDA[ ] |                      GND --> |[ ]GND     |
         |                             AREF[ ] |                       A5 --> |[ ]SCL     |
         |                              GND[ ] |                       A4 --> |[ ]SDA     |
         | [ ]N/C                    SCK/13[ ] |                              |[ ]XDA     |
         | [ ]IOREF                 MISO/12[ ] |                              |[ ]XCL     |
         | [ ]RST                   MOSI/11[ ]~|                              |[ ]ADO     |
         | [ ]3V3    +---+               10[ ]~|                       D2 --> |[ ]INT     |
         | [ ]5v    -| A |-               9[ ]~|                              +-----------+
         | [ ]GND   -| R |-               8[ ] |  
         | [ ]GND   -| D |-                    |
         | [ ]Vin   -| U |-               7[ ] |  
         |          -| I |-               6[ ]~|   
         | [ ]A0    -| N |-               5[ ]~|   
         | [ ]A1    -| O |-               4[ ] |   
         | [ ]A2     +---+           INT1/3[ ]~|   
         | [ ]A3                     INT0/2[ ] |   D2
         | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |   
         | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |   
         |            [ ] [ ] [ ]              |
         |  UNO_R3    GND MOSI 5V  ____________/
          \_______________________/
   
   ASCII by: http://busyducks.com/ascii-art-arduinos
