#include "window.hpp"

Window::Window(SerialDevice& serialDevice): serialDevice(serialDevice)
{
	cout << serialDevice.serial.serial_read_data <<endl;
};
