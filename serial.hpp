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

		asio::serial_port_base::parity parity;

		asio::serial_port_base::flow_control flow_control;

		asio::serial_port_base::stop_bits stop_bits;

		asio::serial_port_base::character_size char_size;

	public:
		SerialOptions():device("/dev/ttyACM0"), 
						baud_rate(9600),
						parity(asio::serial_port_base::parity::none),
						flow_control(asio::serial_port_base::flow_control::none),
						stop_bits(asio::serial_port_base::stop_bits::one),
						char_size(asio::serial_port_base::character_size(8)){};

		string getDevice() const
		{return this->device;};

		asio::serial_port_base::baud_rate getBaud_Rate() const
		{return this->baud_rate;};

		asio::serial_port_base::parity getParity() const
		{return this->parity;};

		asio::serial_port_base::flow_control getFlow_Control() const
		{return this->flow_control;};

		asio::serial_port_base::stop_bits getStop_Bits() const
		{return this->stop_bits;};

		asio::serial_port_base::character_size getChar_Size() const
		{return this->char_size;};
};


class Serial
{
	private:
		asio::io_service io_service;

		asio::serial_port serial_port;

		SerialOptions options;

		static const int readBufferSize = 128;

		char readBuffer[readBufferSize];

		string serial_read_data;

	public:
		explicit Serial(const SerialOptions options);

		void handler(const system::error_code& error, size_t bytes_transferred);
};


#endif //SERIAL_HPP