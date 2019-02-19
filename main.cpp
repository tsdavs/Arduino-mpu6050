#include "window.hpp"

int main(int argc, char* argv[]) 
{
	try
	{
		//SerialOptions options;

		//Serial device(options);

		Device device;

		Window window(device);

	} catch (boost::system::system_error& e) 
	{
		cout << "error! " << e.what() << endl;
	}

	return 1;

}