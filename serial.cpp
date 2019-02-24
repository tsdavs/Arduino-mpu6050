#include "serial.hpp"

Serial::Serial()
: io_service(), serial_port(io_service, port)
{
	serial_port.set_option(asio::serial_port_base::baud_rate(9600));
};

void Serial::read()
{
	//async_read_some() makes the system call that starts the read
	serial_port.async_read_some(asio::buffer(readBuffer, readBufferSize),
		bind(&Serial::readHandler, this,
			asio::placeholders::error,
			asio::placeholders::bytes_transferred));

	io_service.run();

	//'reset()' must be called for subsequent 'run()' post 'glutPostRedisplay()'
	io_service.reset();
}

//io_service checks handler if there is any data to read and then calls handler
void Serial::readHandler(const system::error_code& error, size_t bytes_transferred)
{
	if(!error)
	{
		//set output to string
		serial_read_data = string(readBuffer, bytes_transferred);

		cout << serial_read_data;

	}
};
