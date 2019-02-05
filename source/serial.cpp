#include "serial.hpp"
#include <boost/asio.hpp>

Serial::Serial(std::string& portName){

}

Serial::~Serial(){
}

bool Serial::isConnected(){
	return this->connected;
}
