#ifndef SERIAL_HPP
#define SERIAL_HPP

#pragma once

#include <string>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>

using namespace std;
using namespace boost;

class Serial
{
	private:
		asio::io_service io_service;
		asio::serial_port serial_port;
		bool connected;


	public:
		Serial() = delete;

		Serial(std::string portName, unsigned int baud_rate)
		: io_service(), serial_port(io_service, portName)
		{
			serial_port.set_option(asio::serial_port_base::baud_rate(baud_rate));
			
			if(serial_port.is_open())
				this->connected = true;
		};

		~Serial(){};

		//int readSerialPort(char *buffer, unsigned int buf_size);
		bool isConnected()
		{
			return this->connected;
		};
};


#endif //SERIAL_HPP