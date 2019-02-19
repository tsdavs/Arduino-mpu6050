#ifndef SERIAL_HPP
#define SERIAL_HPP

#pragma once

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost;

//went with stuct to have option of adding more later
struct Options
{
	public:
		string port = "/dev/ttyACM0";

		//asio::serial_port_base::baud_rate baud_rate(unsigned int rate = 9600);
};

class Serial : Options
{
	private:
		Options options;

		asio::io_service io_service;

		asio::serial_port serial_port;

		static const int readBufferSize = 32;

		char readBuffer[readBufferSize];

	public:
		Serial();

		void handler(const system::error_code& error, size_t bytes_transferred);

		void test();

		void testHandler();

		string serial_read_data;

};

#endif //SERIAL_HPP