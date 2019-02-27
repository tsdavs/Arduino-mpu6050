#ifndef SERIAL_HPP
#define SERIAL_HPP

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
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

		asio::streambuf streambuf;

		string serial_read_data;

		string reading = "read";

	public:
		Serial();

		void read();

		void readHandler(const system::error_code& error, size_t bytes_transferred);

		void variablSanitizer(string serial_read_data);

		//x, y, z
		vector<float> angles;

		bool isReading = false;
};

#endif //SERIAL_HPP