#ifndef SERIAL_HPP
#define SERIAL_HPP

#pragma once

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost;

class SerialOptions
{
	private:
		string device;

		asio::serial_port_base::baud_rate baud_rate;

	public:
		SerialOptions():device("/dev/ttyACM1"), 
						baud_rate(9600){};

		string getDevice() const
		{return this->device;};

		asio::serial_port_base::baud_rate getBaud_Rate() const
		{return this->baud_rate;};
};


class Serial
{
	private:
		asio::io_service io_service;

		asio::serial_port serial_port;

		//SerialOptions options;

		static const int readBufferSize = 128;

		char readBuffer[readBufferSize];

		string serial_read_data;

	public:
		explicit Serial(const SerialOptions options);

		void handler(const system::error_code& error, size_t bytes_transferred);

		void test();

		void testHandler();

		/*asio::io_service getIo_Service()
		{
			return io_service;
		};*/
};


#endif //SERIAL_HPP