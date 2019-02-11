#include "serial.hpp"

string SerialOptions::getDevice() const
{return this->device;};

unsigned int SerialOptions::getBaud_Rate() const
{return this->baud_rate;};

Serial::Serial(const SerialOptions options)
: io_service(), serial_port(io_service, options.getDevice())
{
	serial_port.set_option(asio::serial_port_base::baud_rate(options.getBaud_Rate()));

	serial_port.async_read_some(asio::buffer(readBuffer, readBufferSize),
		bind(&Serial::handler, this,
			asio::placeholders::error,
			asio::placeholders::bytes_transferred));

	io_service.run();

};

void Serial::handler(const system::error_code& error, size_t bytes_transferred)
{
	while(serial_port.is_open())
	{
		char c;

		read(serial_port, asio::buffer(&c, 1));

		std::cout << c;
	}

};

