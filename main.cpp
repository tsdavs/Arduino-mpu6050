#include "window.hpp"
#include "GL/freeglut.h"
#include "GL/gl.h"

int main(int argc, char* argv[]) 
{
	try
	{
		glutInit(&argc, argv);

		glutInitDisplayMode(GLUT_SINGLE);

		glutInitWindowSize(500, 500);

		glutInitWindowPosition(100, 100);

		glutCreateWindow("arduino_mpu6050");

		Serial serial;

	} catch (boost::system::system_error& e) 
	{
		cout << "error! " << e.what() << endl;
	}

	return 1;

}