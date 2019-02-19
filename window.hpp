#ifndef WINDOW_HPP
#define WINDOW_HPP

#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/optional.hpp>
#include <boost/thread.hpp>
#include "serial.hpp"

using namespace std;
using namespace boost;

struct thread_object
{
	protected:
		mutable asio::io_service io_service;

	private:
		optional<asio::io_service::work> work {asio::io_service::work(io_service)};
		thread th {[&]{io_service.run();}};

	protected:
		thread_object() = default;
		~thread_object() {work.reset(); th.join();}
};

struct SerialDevice : thread_object
{
	public:
		Serial serial;

		SerialDevice(): serial(){};

	private:
};

struct Window : thread_object
{
	private:
		SerialDevice& serialDevice;

	public:
		Window(SerialDevice& serialDevice);

};

#endif //WINDOW_HPP