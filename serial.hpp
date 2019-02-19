#ifndef SERIAL_HPP
#define SERIAL_HPP

#pragma once

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost;

struct Options
{
	private:
		string device;

		asio::serial_port_base::baud_rate baud_rate;
};


class SerialOptions
{
	private:
		string device;

		asio::serial_port_base::baud_rate baud_rate;

	public:
		SerialOptions():device("/dev/ttyACM0"), 
						baud_rate(9600){ cout << "SerialOption create";};

		string getDevice() const
		{return this->device;};

		asio::serial_port_base::baud_rate getBaud_Rate() const
		{return this->baud_rate;};
};


class Serial : Options
{
	private:
		SerialOptions& options;

		asio::io_service io_service;

		asio::serial_port serial_port;

		static const int readBufferSize = 32;

		char readBuffer[readBufferSize];

		string serial_read_data;

	public:
		Serial() = default;

		explicit Serial(const SerialOptions options);

		~Serial(){};

		void handler(const system::error_code& error, size_t bytes_transferred);

		void test();

		void testHandler();
};


#endif //SERIAL_HPP