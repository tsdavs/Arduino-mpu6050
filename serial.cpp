#include "serial.hpp"

/**
 * SerialOptions constructor
 */
SerialOptions::SerialOptions()
: device("/dev/ttyACM0"), baud_rate(9600)
{

};

SerialOptions::SerialOptions(const string& device, unsigned int baud_rate)
{

};

void SerialOptions::setDevice(const string& device)
{this->device = device;};

string SerialOptions::getDevice() const
{return this->device;};

void SerialOptions::setBaud_Rate(const unsigned int baud_rate)
{this->baud_rate = baud_rate;};

unsigned int SerialOptions::getBaud_Rate() const
{return this->baud_rate;};

/**
 * Serial constructor
 */
Serial::Serial(SerialOptions options)
: io_service(), serial_port(io_service, options.getDevice())
{
	serial_port.set_option(asio::serial_port_base::baud_rate(options.getBaud_Rate()));
	
	if(serial_port.is_open())
		this->connected = true;
};

bool Serial::isConnected()
{
	return this->connected;
};

