

#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void setPixel(int x, int y);
void Bresenham(int x1, int y1, int x2, int y2);
void mouse(int btn, int state, int x, int y);
void display();
void init();

int xi, yi, xf, yf, first = 0;

void setPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void Bresenham(int x1, int y1, int x2, int y2)
{
	int x11, y11, dx, dy, p, m, n, i = 1;
	if (y1 > y2)
		m = -1;
	else
		m = 1;

	if (x1 > x2)
		n = -1;
	else
		n = 1;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);

	glPointSize(2);
	setPixel(x1, y1);

	if (dx > dy)
	{
		p = 2 * dy - dx;
		while (i <= dx)
		{
			if (p < 0)
			{
				p += 2 * dy;
			}
			else
			{
				p += 2 * (dy - dx);
				y1 += m;
			}
			i++;
			x1 += n;

			setPixel(x1, y1);
		}
	}
	else
	{
		p = 2 * dx - dy;
		while (i <= dy)
		{
			if (p < 0)
			{
				p += 2 * dx;
			}
			else
			{
				p += 2 * (dx - dy);
				x1 += n;
			}
			i++;
			y1 += m;

			setPixel(x1, y1);
		}
	}
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
			Bresenham(xi, yi, xf, yf);
			break;
		}
	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_LINES);
		glColor3d(1, 1, 1);
		glVertex2f(250, 0);
		glVertex2f(250, 500);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(0, 250);
		glVertex2f(500, 250);
		glEnd();
		glFlush();
	}
}

void display(void)
{
	glClearColor(0.0, 0.0, 0.0, 1);
	glColor3d(1, 1, 1);

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	glColor3d(1, 1, 1);
	glVertex2f(250, 0);
	glVertex2f(250, 500);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
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
	glutCreateWindow("Bresenhem Line --Quadrant");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
}
