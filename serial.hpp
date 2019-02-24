#ifndef SERIAL_HPP
#define SERIAL_HPP

#pragma once

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost;

class Serial
{
	private:
		string port = "/dev/ttyACM0";

		asio::io_service io_service;

		asio::serial_port serial_port;

		static const int readBufferSize = 32;

		char readBuffer[readBufferSize];

	public:
		Serial();

		void read();

		void readHandler(const system::error_code& error, size_t bytes_transferred);

		string serial_read_data;
};

#endif //SERIAL_HPP