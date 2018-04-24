
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>

void myinit();
void LineDDA(int x1, int y1, int x2, int y2);
void display();
float round_value(float v);
void mouse(int btn, int state, int x, int y);

int first = 0;
int xi, yi, xf, yf;

float round_value(float v)
{
  return floor(v + 0.5);
}
void LineDDA(int x1, int y1, int x2, int y2)
{
  int k;
  double dx = (x2 - x1);
  double dy = (y2 - y1);
  double steps;
  float xInc, yInc, x = x1, y = y1;

  if (abs(dx) > abs(dy)) /* Find out whether to increment x or y */
    steps = abs(dx);
  else
    steps = abs(dy);

  xInc = dx / (float)steps;
  yInc = dy / (float)steps;

  glClear(GL_COLOR_BUFFER_BIT); /* Clears buffers to preset values */
  glPointSize(2);               /*Point size*/
  glBegin(GL_POINTS);           /* Plot the points */
  glVertex2d(x, y);             /* Plot the first point */

  for (k = 0; k < steps; k++)
  {
    x += xInc;
    y += yInc;

    if (k % 10 > 5)
    {
      glVertex2d(round_value(x), round_value(y));
    }
  }
  glEnd();

  glFlush();
}

void display()
{
  glClearColor(0.2, 0.4, 0.0, 1.0);
  glColor3d(1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
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

      LineDDA(xi, yi, xf, yf);
      first = 0;
      break;
    }
  }
}
void myinit()
{
  glViewport(0, 0, 500, 500);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble)500, 0.0, (GLdouble)500);
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("DDA LINE - DASHED PATTERN");
  glutDisplayFunc(display);
  myinit();
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}
