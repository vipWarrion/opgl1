#include <glut.h>
#include <math.h>
int win_w = 800, win_h = 600;
int frame_id = 28;

void reshape(int w, int h)
{
	win_w = w;
	win_h = h;
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display()
{
	int speed = 130;
	glClearColor(0.8, 0.8, 0.8, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.4, 0.4, 0.4);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	// —глаживание линий
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	// —глаживание полигонов    
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_POINT_SMOOTH);

	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex2i(0, 0);
	glVertex2i(0, 150);
	glVertex2i(win_w, 150);
	glVertex2i(win_w, 0);
	glEnd();

	glPopMatrix();

	glDisable(GL_BLEND);
	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_POLYGON_SMOOTH);
	glDisable(GL_POINT_SMOOTH);



	glutSwapBuffers();
	if (frame_id == 168 * speed)
		frame_id = 0;
}

void key(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '0':
		frame_id = 20;
		break;

	case '1':
		frame_id = 21;
		break;

	case '2':
		frame_id = 22;
		break;

	case '3':
		frame_id = 23;
		break;

	case '4':
		frame_id = 24;
		break;

	case '5':
		frame_id = 25;
		break;

	case '6':
		frame_id = 26;
		break;

	case '7':
		frame_id = 27;
		break;

	case '8':
		frame_id = 28;
		break;

	case '9':
		frame_id = 19;
		break;
	}
}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); /*¬ключаем двойную буферизацию и четырехкомпонентный цвет*/

	glutInitWindowSize(win_w, win_h);
	glutCreateWindow("OpenGL lesson 1");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(key);

	glutMainLoop();

	return 0;
}