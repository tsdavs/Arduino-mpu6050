#include "serial.hpp"

Serial::Serial()
: options(), io_service(), serial_port(io_service, options.port)
{
	serial_port.set_option(asio::serial_port_base::baud_rate(9600));

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

		//serial_read_data = string(readBuffer);

		//test();
	}
/*};

void Serial::test()
{
	io_service.post(bind(&Serial::testHandler, this));
};

void Serial::testHandler()
{
	cout << "/";
*/
	//For continous stream of data the handler needs to re-add itself to the work
	serial_port.async_read_some(asio::buffer(readBuffer, readBufferSize),
		bind(&Serial::handler, this,
			asio::placeholders::error,
			asio::placeholders::bytes_transferred));
};


