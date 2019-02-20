#include "window.hpp"

int main(int argc, char* argv[]) 
{
	try
	{
		Serial serial;

	} catch (boost::system::system_error& e) 
	{
		cout << "error! " << e.what() << endl;
	}

	return 1;

}