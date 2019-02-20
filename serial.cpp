#include "serial.hpp"

Serial::Serial()
: io_service(), serial_port(io_service, port)
{
	serial_port.set_option(asio::serial_port_base::baud_rate(9600));

	cout << "Serial\n" << endl; 

	//async_read_some() makes the system call that starts the read
	serial_port.async_read_some(asio::buffer(readBuffer, readBufferSize),
		bind(&Serial::readHandler, this,
			asio::placeholders::error,
			asio::placeholders::bytes_transferred));

	//runs the io_service to complete the work (async_read_some())
	io_service.run();
};

//io_service checks handler if there is any data to read and then calls handler
void Serial::readHandler(const system::error_code& error, size_t bytes_transferred)
{
	if(!error)
	{
		//set output to string
		serial_read_data = string(readBuffer, bytes_transferred);
		
		//run window loop
		io_service.post(bind(&Serial::windowHandler, this));
	}
};

void Serial::windowHandler()
{
	cout << serial_read_data;

	//For continous stream of data the handler needs to re-add itself to the work
	serial_port.async_read_some(asio::buffer(readBuffer, readBufferSize),
		bind(&Serial::readHandler, this,
			asio::placeholders::error,
			asio::placeholders::bytes_transferred));
			
};


