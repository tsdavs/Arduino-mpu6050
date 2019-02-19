#include "window.hpp"

int main(int argc, char* argv[]) 
{
	try
	{
		SerialDevice serialDevice;

		Window window(serialDevice);

	} catch (boost::system::system_error& e) 
	{
		cout << "error! " << e.what() << endl;
	}

	return 1;

}