
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

/*
*defining a RGB struct to color the pixel
*/

struct Type_rgb
{
	float r;
	float g;
	float b;
};

/*
* pixel variable contain the value of the color pixel in
* the picture.
* pattern is a predefine set of color for a particular
* value.
*/

struct Type_rgb pixels[1024 * 768], pattern[999];

void Juliaset()
{
	/*
	* x :- is the real part of xn value
	*       
	* y :- is the imaginary part of xn value
	*       

	*zreal :- is the real part of z value
	*zimg :- imaginary part of z value

	* iteration :- is to keep control variable of the number
	*       of iteration
	* max_iteration :- maximum number of iteration
	*        (which is one of bailout condition)
	* loc :- represent the location pixel of the
	*       current x,y coordinate.
	*/

	float x0, y0, x, y, xtemp, newRe, newIm, oldRe, oldIm;
	float zoom = 1, moveX = 0, moveY = 0;

	float zreal = -0.5, zimg = 0.37015;
	// creal=-0.7 for different  shape

	int iteration, max_iteration = 1000, loc = 0;
	printf("\nstart");

	for (y0 = 0; y0 < 768; y0 = y0 + 1)
		for (x0 = 0; x0 < 1024; x0 = x0 + 1)
		{
			/*Calculate the initial real and imaginary part of z based on the pixel 
			location and zoom and position values*/

			x = 0.5 * (x0 - 1024 / 2) / (0.5 * zoom * 1024) + moveX;
			y = (y0 - 768 / 2) / (0.5 * zoom * 768) + moveY;

			iteration = 0;

		/*
		* (x*x) + (y*y) < (2*2) is the 2nd bailout condition ie
		* the mandelbrot set is always within a radius of 2.
		*/
			while (((x * x) + (y * y) < (2 * 2)) && iteration < max_iteration)
			{
				//actual iteration, the real and imaginary part are calculated
				xtemp = (x * x) - (y * y) - zreal;
				y = 2 * x * y + zimg;
				x = xtemp;
				iteration = iteration + 1;
			}
			if (iteration >= 999)
			{
			/*
			* setting color pixel to Julia set coordinate
			*to black.
			*/
				pixels[loc].r = 0;
				pixels[loc].g = 0;
				pixels[loc].b = 0;
			}
			else
			{
			/*
			* setting color pixel to the reset of the coordinate by the
			* pattern of no of iteration before bailout.
			*/
				pixels[loc].r = pattern[iteration].r;
				pixels[loc].g = pattern[iteration].g;
				pixels[loc].b = pattern[iteration].b;
			}
			loc = loc + 1;
		}
}

void Init()
{

	glViewport(0, 0, 1024, 768);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1024, 0, 768);

	int i;
	float r, g, b;
	/*
	* Initializing all the pixels to white.
	*/
	for (i = 0; i < 1024 * 768; i++)
	{
		pixels[i].r = 1;
		pixels[i].g = 1;
		pixels[i].b = 1;
	}

	i = 0;
	/*
	* Initializing all the pattern color till 4*4*4
	*/
	for (r = 0.1; r <= 0.9; r = r + 0.1)
		for (g = 0.1; g <= 0.9; g = g + 0.1)
			for (b = 0.1; b <= 0.9; b = b + 0.1)
			{
				pattern[i].r = b;
				pattern[i].g = r;
				pattern[i].b = g;
				i++;
			}
	/*
	* Initializing the rest of the pattern as 9*9*9 is 729.
	* and we need up to 999 pattern as the loop bailout
	* condition is 1000.
	*/

	for (; i <= 999; i++)
	{
		pattern[i].r = 1;
		pattern[i].g = 1;
		pattern[i].b = 1;
	}
	Juliaset();
}

void onDisplay()
{
	/*
	* Clearing the initial buffer
	*/
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	/*
	* Draw the complete Julia set picture.	
	*/
	glDrawPixels(1024, 768, GL_RGB, GL_FLOAT, pixels);
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1024, 768);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Julia Set");
	Init();
	glutDisplayFunc(onDisplay);
	glutMainLoop();
	return 0;
}
