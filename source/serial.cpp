#include "serial.hpp"

Serial::Serial(std::string& portName){

}

Serial::~Serial(){
}

bool Serial::isConnected(){
	return this->connected;
}
