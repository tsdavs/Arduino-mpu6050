#include <iostream>
#include <string>
#include <fstream>
#include "serial.hpp"

using namespace std;

int main(int argc, char* argv[]) 
{
	try
	{
		//std::string device = "/dev/ttyACM0";

		//unsigned int baud_rate = 9600;

		SerialOptions options;

		Serial arduino(options);

		std::cout << arduino.isConnected() << std::endl;

		//options.setDevice(device);

		//cout << options.getBaud_Rate() << endl;


	} catch (boost::system::system_error& e) 
	{
		cout << e.what() << endl;
		return 1;
	}
}