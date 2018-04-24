/*Implement Cube rotation about vertical axis passing through its centroid*/

#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void specialKeys(int key, int x, int y);
void draw_cube();
void display_T();
void display_R();
void display_S();
void win_init();

double rotate_y = 0;
double rotate_x = 0;
double rotate_z = 0;
double tx = 0;
double ty = 0;
double tz = 0;
double sx = 0;
double sy = 0;

void draw_cube()
{

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.8);
	glVertex3f(0.5, -0.5, -0.5);
	glColor3f(0.0, 0.0, 0.7);
	glVertex3f(0.5, 0.5, -0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.5, 0.5, -0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, 0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.5, 0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.5, 0.5, 0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.1);
	glVertex3f(0.5, -0.5, -0.5);
	glColor3f(0.0, 0.0, 0.1);
	glVertex3f(0.5, 0.5, -0.5);
	glColor3f(0.0, 0.0, 0.1);
	glVertex3f(0.5, 0.5, 0.5);
	glColor3f(0.0, 0.0, 0.1);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.8);
	glVertex3f(-0.5, -0.5, 0.5);
	glColor3f(0.0, 0.0, 0.8);
	glVertex3f(-0.5, 0.5, 0.5);
	glColor3f(0.0, 0.0, 0.7);
	glVertex3f(-0.5, 0.5, -0.5);
	glColor3f(0.0, 0.0, 0.7);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.2);
	glVertex3f(0.5, 0.5, 0.5);
	glColor3f(0.0, 0.0, 0.2);
	glVertex3f(0.5, 0.5, -0.5);
	glColor3f(0.0, 0.0, 0.3);
	glVertex3f(-0.5, 0.5, -0.5);
	glColor3f(0.0, 0.0, 0.3);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, 0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();
}

void display_T()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glRotatef(15, 0.0, 1.0, 0.0);
	glTranslatef(tx, 0.0, 0.0);
	glTranslatef(0.0, ty, 0.0);
	glTranslatef(0.0, 0.0, tz);
	draw_cube();
	glFlush();
	glutSwapBuffers();
}

void display_R()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	draw_cube();
	glFlush();
	glutSwapBuffers();
}

void display_S()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glScalef(sx, sy, 0.0);
	glRotatef(15, 0.0, 1.0, 0.0);
	glRotatef(25, 1.0, 0.0, 0.0);
	glRotatef(5, 0.0, 0.0, 1.0);
	draw_cube();
	glFlush();
	glutSwapBuffers();
}

// specialKeys() Callback Function
void specialKeys(int key, int x, int y)
{

	if (key == GLUT_KEY_RIGHT)
	{
		tx += 0.1;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		tx -= 0.1;
	}
	else if (key == GLUT_KEY_UP)
	{
		ty += 0.1;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		ty -= 0.1;
	}
	else if (key == GLUT_KEY_F9)
	{
		tz += 0.2;
	}
	else if (key == GLUT_KEY_F10)
	{
		tz -= 0.2;
	}
	else if (key == GLUT_KEY_F1)
	{
		rotate_z += 5;
	}
	else if (key == GLUT_KEY_F2)
	{
		rotate_z -= 5;
	}
	else if (key == GLUT_KEY_F3)
	{
		rotate_y += 5;
	}
	else if (key == GLUT_KEY_F4)
	{
		rotate_y -= 5;
	}
	else if (key == GLUT_KEY_F5)
	{
		rotate_x += 5;
	}
	else if (key == GLUT_KEY_F6)
	{
		rotate_x -= 5;
	}
	else if (key == GLUT_KEY_F7)
	{
		sx = 1.5;
		sy = 1.5;
	}
	else if (key == GLUT_KEY_F8)
	{
		sx = 0.5;
		sy = 0.5;
	}
	glutPostRedisplay();
}

void win_init()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3D Cube");
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv[])
{
	int ch;
	glutInit(&argc, argv);
	do
	{
		printf("\n1.Translation \n2.Rotation\n3.Scaling\n4. Exit");
		printf("\nEnter your chioce ->");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			win_init();
			glutDisplayFunc(display_T);
			glutSpecialFunc(specialKeys);
			glutMainLoop();
			break;

		case 2:
			win_init();
			glutDisplayFunc(display_R);
			glutSpecialFunc(specialKeys);
			glutMainLoop();
			break;

		case 3:
			win_init();
			glutDisplayFunc(display_S);
			glutSpecialFunc(specialKeys);
			glutMainLoop();
			break;
		}
	} while (ch != 4);

	return 0;
}
