#ifndef SERIAL_HPP
#define SERIAL_HPP

#pragma once

#include <string>
#include <boost/asio.hpp>


class Serial
{
	private:
		bool connected;

	public:
		Serial() = delete;
		Serial(std::string& portName);
		~Serial();

		//int readSerialPort(char *buffer, unsigned int buf_size);
		bool isConnected();
};


#endif //SERIAL_HPP