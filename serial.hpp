#ifndef SERIAL_HPP
#define SERIAL_HPP

#pragma once

#include <string>
#include <boost/asio.hpp>

using namespace std;
using namespace boost;

class SerialOptions
{
	private:
		string device;
		unsigned int baud_rate;

	public:
		SerialOptions();

		SerialOptions(const string& device, unsigned int baud_rate);

		void setDevice(const string& device);

		string getDevice() const;

		void setBaud_Rate(const unsigned int baud_rate);

		unsigned int getBaud_Rate() const;
};


class Serial
{
	private:
		asio::io_service io_service;
		
		asio::serial_port serial_port;

		SerialOptions options;

		bool connected;


	public:
		Serial(SerialOptions options);

		bool isConnected();
};


#endif //SERIAL_HPP