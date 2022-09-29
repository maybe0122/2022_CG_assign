#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>

#define GWIDTH 400
#define GHEIGHT 400

GLvoid drawScene();
GLvoid Reshape(int w, int h);
GLvoid keyboard(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void convertDdeviceXYtoOpenglXY(int x, int y, GLfloat* ox, GLfloat* oy);
void convertOpenglXYtoDeviceXY(int* x, int* y, float ox, float oy);
void drawinit(float red, float green, float blue);
void Motion(int x, int y);
void TimerFunction(int value);

struct Rect
{
	int a[5][2],b[5][2];
};

bool left_button, out_box, in_box, init = true;
int init_x, init_y, dx, dy, current_x, current_y;
GLfloat ox1, ox2, oy1, oy2;
int x1 = (GWIDTH / 5) * 2, x2 = (GWIDTH / 5) * 3, y1 = (GWIDTH / 5) * 3, y2 = (GWIDTH / 5) * 2;

void main(int argc, char** argv) //--- 윈도우 출력하고 콜백함수 설정 
{	//--- 윈도우 생성하기
	glutInit(&argc, argv); // glut 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // 디스플레이 모드 설정
	glutInitWindowPosition(100, 100); // 윈도우의 위치 지정
	glutInitWindowSize(GWIDTH, GHEIGHT); // 윈도우의 크기 지정
	glutCreateWindow("Example1"); // 윈도우 생성(윈도우 이름)
	//--- GLEW 초기화하기
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) // glew 초기화
	{
		printf("Unable to initialize GLEW");
		exit(EXIT_FAILURE);
	}
	else
		printf("GLEW Initialized\n");

	glutDisplayFunc(drawScene); // 출력 함수의 지정
	glutReshapeFunc(Reshape); // 다시 그리기 함수 지정
	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	glutTimerFunc(100, TimerFunction, 1);
	glutMainLoop(); // 이벤트 처리 시작 
}

GLvoid drawScene() //--- 콜백 함수: 그리기 콜백 함수 
{
	convertDdeviceXYtoOpenglXY(x1, y1, &ox1, &oy1);
	convertDdeviceXYtoOpenglXY(x2, y2, &ox2, &oy2);

	float red, green, blue;
	srand((unsigned int)time(NULL));

	red = (float)rand() / (float)RAND_MAX;
	green = (float)rand() / (float)RAND_MAX;
	blue = (float)rand() / (float)RAND_MAX;

	if (init == true)
	{
		drawinit(red, green, blue);
		init = false;
	}
	
	if (in_box == true)
	{
		glColor3f(red, green, blue);
	}
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(ox1, oy1, ox2, oy2);
	glutSwapBuffers(); // 화면에 출력하기
}

GLvoid Reshape(int w, int h) //--- 콜백 함수: 다시 그리기 콜백 함수 
{
	glViewport(0, 0, w, h);
}

void Mouse(int button, int state, int x, int y)
{
	//convertDdeviceXYtoOpenglXY(x, y, &current_ox, &current_oy);
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		current_x = x, current_y = y;
		left_button = true;
	}
	if (state == GLUT_UP)
	{
		left_button = false;
	}
	if ((x > x1 && x < x2) && (y > y1 && y < y2))
	{
		in_box = true;
		out_box = false;
	}

	glutPostRedisplay();
}

void convertDdeviceXYtoOpenglXY(int x, int y, GLfloat* ox, GLfloat* oy) {
	int w = GWIDTH;
	int h = GHEIGHT;
	*ox = (float)((x - (float)w / 2.0) * (float)(1.0 / (float)(w / 2.0)));
	*oy = -(float)((y - (float)h / 2.0) * (float)(1.0 / (float)(h / 2.0)));
}

void convertOpenglXYtoDeviceXY(int* x, int* y, float ox, float oy) {
	float w = GWIDTH;
	float h = GHEIGHT;
	*x = (int)((ox * w + w) / 2);
	*y = (int)((oy * w + w) / 2);
}

void drawinit(float red, float green, float blue)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(red, green, blue);
	glRectf(ox1, oy1, ox2, oy2);
}

GLvoid keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case'a':
		break;
	case 'q':
		exit(1);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void Motion(int x, int y)
{	
	init_x = current_x;
	init_y = current_y;
	dx = x - init_x;
	dy = y - init_y;

	if (left_button)
	{
		x1 += dx, x2 += dx, y2 += dy, y1 += dy; 
	}
	
}

void TimerFunction(int value)
{
	glutPostRedisplay();
	glutTimerFunc(100, TimerFunction, 1);
}

void drawRect()
{

}

void moveRect()
{

}