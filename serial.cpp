#include "serial.hpp"

Serial::Serial(const SerialOptions options)
: io_service(), serial_port(io_service, options.getDevice())
{
	//setting options
	serial_port.set_option(options.getBaud_Rate());
	serial_port.set_option(options.getParity());
	serial_port.set_option(options.getFlow_Control());
	serial_port.set_option(options.getStop_Bits());
	serial_port.set_option(options.getChar_Size());

	//async_read_some() makes the system call that starts the read
	serial_port.async_read_some(asio::buffer(readBuffer, readBufferSize),
		bind(&Serial::handler, this,
			asio::placeholders::error,
			asio::placeholders::bytes_transferred));

	//runs the io_service to complete the work (async_read_some())
	io_service.run();
};

//io_service checks handler if there is any data to read and then calls handler
void Serial::handler(const system::error_code& error, size_t bytes_transferred)
{
	if(!error)
	{
		cout << string(readBuffer, bytes_transferred);

		//For continous stream of data the handler needs to re-add itself to the work
		serial_port.async_read_some(asio::buffer(readBuffer, readBufferSize),
			bind(&Serial::handler, this,
				asio::placeholders::error,
				asio::placeholders::bytes_transferred));

	}
};

