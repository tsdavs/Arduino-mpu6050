#include "serial.hpp"
#include "GL/freeglut.h"
#include "GL/gl.h"

Serial serial;

void update(void)
{
	serial.read();

	/*
	 *drawing code here
	*/

	//creates a loop to read and draw
	glutPostRedisplay();
}

int main(int argc, char* argv[]) 
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowSize(500, 500);

	glutInitWindowPosition(100, 100);

	glutCreateWindow("arduino_mpu6050");

	glutIdleFunc(update);

	glutMainLoop();

	return EXIT_SUCCESS;

}