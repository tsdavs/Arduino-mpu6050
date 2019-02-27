#include "serial.hpp"
#include "GL/freeglut.h"
#include "GL/gl.h"

Serial serial;

void DrawCube(void)
{
	glMatrixMode(GL_MODELVIEW);

	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	glTranslatef(0.0,0.0,-10.5);
	
	if(serial.isReading)
	{
		glRotatef(serial.angles.at(0),1.0,0.0,0.0); //x

		glRotatef(serial.angles.at(1),0.0,1.0,0.0); //y

		glRotatef(serial.angles.at(2),0.0,0.0,1.0); //z

		glBegin(GL_QUADS);//Draw The Cube Using quads
			glColor3f(0.0f,1.0f,0.0f);//Color Blue
			glVertex3f( 1.0f, 1.0f,-1.0f);	//Top Right Of The Quad (Top)
			glVertex3f(-1.0f, 1.0f,-1.0f);	//Top Left Of The Quad (Top)
			glVertex3f(-1.0f, 1.0f, 1.0f);	//Bottom Left Of The Quad (Top)
			glVertex3f( 1.0f, 1.0f, 1.0f);	//Bottom Right Of The Quad (Top)

			glColor3f(1.0f,0.5f,0.0f);//Color Orange
			glVertex3f( 1.0f,-1.0f, 1.0f);	//Top Right Of The Quad (Bottom)
			glVertex3f(-1.0f,-1.0f, 1.0f);	//Top Left Of The Quad (Bottom)
			glVertex3f(-1.0f,-1.0f,-1.0f);	//Bottom Left Of The Quad (Bottom)
			glVertex3f( 1.0f,-1.0f,-1.0f);	//Bottom Right Of The Quad (Bottom)

			glColor3f(1.0f,0.0f,0.0f);//Color Red    
			glVertex3f( 1.0f, 1.0f, 1.0f);	//Top Right Of The Quad (Front)
			glVertex3f(-1.0f, 1.0f, 1.0f);	//Top Left Of The Quad (Front)
			glVertex3f(-1.0f,-1.0f, 1.0f);	//Bottom Left Of The Quad (Front)
			glVertex3f( 1.0f,-1.0f, 1.0f);	//Bottom Right Of The Quad (Front)

			glColor3f(1.0f,1.0f,0.0f);//Color Yellow
			glVertex3f( 1.0f,-1.0f,-1.0f);	//Top Right Of The Quad (Back)
			glVertex3f(-1.0f,-1.0f,-1.0f);	//Top Left Of The Quad (Back)
			glVertex3f(-1.0f, 1.0f,-1.0f);	//Bottom Left Of The Quad (Back)
			glVertex3f( 1.0f, 1.0f,-1.0f);	//Bottom Right Of The Quad (Back)

			glColor3f(0.0f,0.0f,1.0f);//Color Blue
			glVertex3f(-1.0f, 1.0f, 1.0f);	//Top Right Of The Quad (Left)
			glVertex3f(-1.0f, 1.0f,-1.0f);	//Top Left Of The Quad (Left)
			glVertex3f(-1.0f,-1.0f,-1.0f);	//Bottom Left Of The Quad (Left)
			glVertex3f(-1.0f,-1.0f, 1.0f);	//Bottom Right Of The Quad (Left)

			glColor3f(1.0f,0.0f,1.0f);//Color Violet
			glVertex3f( 1.0f, 1.0f,-1.0f);	//Top Right Of The Quad (Right)
			glVertex3f( 1.0f, 1.0f, 1.0f);	//Top Left Of The Quad (Right)
			glVertex3f( 1.0f,-1.0f, 1.0f);	//Bottom Left Of The Quad (Right)
			glVertex3f( 1.0f,-1.0f,-1.0f);	//Bottom Right Of The Quad (Right)
		glEnd();//End Drawing The Cube
	}

	glFlush();
}

void update(void)
{
	serial.read();

	DrawCube();
}

void resize(int x, int y)
{
	if (y == 0 || x == 0) return;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);

	glMatrixMode(GL_MODELVIEW);

	glViewport(0,0,x,y);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowPosition(100, 100);

	glutCreateWindow(argv[0]);

	glClearColor(0,0,0,0);

	glutIdleFunc(update);

	glutDisplayFunc(DrawCube);

	glutReshapeFunc(resize);

	glutMainLoop();

	return EXIT_SUCCESS;
}