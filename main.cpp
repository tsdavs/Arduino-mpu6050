#include "serial.hpp"

using namespace std;

int main(int argc, char* argv[]) 
{
	try
	{
		SerialOptions options;

		Serial arduino(options);


	} catch (boost::system::system_error& e) 
	{
		cout << "error! " << e.what() << endl;

		return 1;
	}
}