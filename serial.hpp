#ifndef SERIAL_HPP
#define SERIAL_HPP

#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost;

class SerialOptions
{
	private:
		string device;

		unsigned int baud_rate;

	public:
		SerialOptions(): device("/dev/ttyACM0"), baud_rate(9600){};

		SerialOptions(const string& device, unsigned int baud_rate){};

		string getDevice() const;

		unsigned int getBaud_Rate() const;
};


class Serial
{
	private:
		asio::io_service io_service;

		asio::serial_port serial_port;

		SerialOptions options;

		static const int readBufferSize = 512;

		char readBuffer[readBufferSize];

	public:
		explicit Serial(const SerialOptions options);

		void handler(const system::error_code& error, size_t bytes_transferred);
};


#endif //SERIAL_HPP