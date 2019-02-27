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
         |                   [ ][ ]            |                              +-----------+
         |                   [ ][ ]        [ ] |                       5v --> |[ ]VCC     |
         |                   [ ][ ]        [ ] |                      GND --> |[ ]GND     |
         |                                 [ ] |                       A5 --> |[ ]SCL     |
         |                                 [ ] |                       A4 --> |[ ]SDA     |
         | [ ]                             [ ] |                              |[ ]XDA     |
         | [ ]                             [ ] |                              |[ ]XCL     |
         | [ ]                             [ ] |                              |[ ]ADO     |
         | [ ]       +---+                 [ ] |                       D2 --> |[ ]INT     |
         | [ ] 5V   -| A |-                [ ] |                              +-----------+
         | [ ] GND  -| R |-                [ ] |  
         | [ ]      -| D |-                    |
         | [ ]      -| U |-                [ ] |  
         |          -| I |-                [ ] |   
         | [ ]      -| N |-                [ ] |   
         | [ ]      -| O |-                [ ] |   
         | [ ]       +---+                 [ ] |   
         | [ ]                          D2 [ ] |  
         | [ ] A4/SDA                      [ ] |   
         | [ ] A5/SCL [ ] [ ] [ ]          [ ] |   
         |            [ ] [ ] [ ]              |
         |  UNO_R3                 ____________/
          \_______________________/
   
   ASCII by: http://busyducks.com/ascii-art-arduinos
