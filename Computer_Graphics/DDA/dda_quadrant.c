

#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdio.h>

void DDA(int x1, int y1, int x2, int y2);
void mouse(int btn, int state, int x, int y);
void display();
void init();

int first = 0;
int xi, yi, xf, yf;

void DDA(int x1, int y1, int x2, int y2)
{
	int k;
	double dx = (x2 - x1);
	double dy = (y2 - y1);
	double steps;

	if (dx >= dy)
		steps = abs(dx);
	else
		steps = abs(dy);

	double xinc = dx / (float)steps;
	double yinc = dy / (float)steps;
	double x = x1, y = y1;

	glBegin(GL_POINTS);
	glColor3d(0, 0, 0);
	glPointSize(6);
	glVertex2d(x1, y1);

	for (k = 0; k < steps; k++)
	{
		x = x + xinc;
		y = y + yinc;
	
	    glVertex2d(round(x), round(y));
		
	}

	glEnd();
	glFlush();
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		switch (first)
		{
		case 0:
			xi = x;
			yi = 500 - y;
			first = 1;
			break;
		case 1:
			xf = x;
			yf = 500 - y;
			first = 0;
			DDA(xi, yi, xf, yf);
			break;
		}
	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_LINES);
		glColor3d(1, 0, 0);
		glVertex2f(250, 0);
		glVertex2f(250, 500);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex2f(0, 250);
		glVertex2f(500, 250);
		glEnd();
		glFlush();
	}
}

void display(void)
{
	glClearColor(0.2, 0.5, 0.6, 1);
	glColor3d(1, 1, 1);

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	glColor3d(1, 0, 0);
	glVertex2f(250, 0);
	glVertex2f(250, 500);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2f(0, 250);
	glVertex2f(500, 250);
	glEnd();
	glFlush();
}

void init(void)
{

	glViewport(00, 00, 500, 500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(00, 500, 00, 500);
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("DDA Quadrant");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
}
