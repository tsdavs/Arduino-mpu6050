#include "serial.hpp"

Serial::Serial()
: io_service(), serial_port(io_service, port)
{
	serial_port.set_option(asio::serial_port_base::baud_rate(9600));
};

void Serial::read()
{
	//async_read_until() makes the system call that starts the read
	asio::async_read_until(serial_port, streambuf, "\n",
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
		istream is(&streambuf);

		getline(is, serial_read_data);
		
		variablSanitizer(serial_read_data);
	}
};

void Serial::variablSanitizer(string serial_read_data)
{
	angles.clear();

	stringstream sstream(serial_read_data);

	string temp;

	char delim = ' ';

	while(getline(sstream, temp, delim))
	{
		if(isReading)
		{
			angles.push_back(stof(temp));
		}

		if(temp.compare(reading) == 0)
		{
			isReading = true;
		}
	}
};