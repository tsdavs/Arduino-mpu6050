#include <iostream>
#include <string>
#include <fstream>
#include "serial.hpp"

using namespace std;

int main(int argc, char* argv[]) 
{
	try
	{
		std::string portName = "/dev/ttyACM0";

		unsigned int baud_rate = 9600;

		Serial arduino(portName, baud_rate);

		std::cout << arduino.isConnected() << std::endl;

	} catch (boost::system::system_error& e) 
	{
		cout << e.what() << endl;
		return 1;
	}
}