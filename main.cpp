#include "serial.hpp"
#include <boost/thread.hpp>

using namespace std;

void yeet()
{
	cout << "thread" << endl;
}

int main(int argc, char* argv[]) 
{
	try
	{
		SerialOptions options;

		thread t{yeet};

		Serial arduino(options);

		t.join();

	} catch (boost::system::system_error& e) 
	{
		cout << "error! " << e.what() << endl;

		return 1;
	}
}