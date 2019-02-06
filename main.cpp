#include <iostream>
#include <string>
#include <fstream>
#include "serial.hpp"

using namespace std;

int main(void) {

	std::string portName = "/dev/ttyACM0";

	Serial *arduino = new Serial(portName);

	std::cout << arduino->isConnected() << std::endl;

	return(0);

}