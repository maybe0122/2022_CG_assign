#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <gl/glew.h> //--- 필요한 헤더파일 include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>

#define GWIDTH 320
#define GHEIGHT 320

GLvoid drawScene();
GLvoid Reshape(int w, int h);
void Mouse(int button, int state, int x, int y);
void convertDdeviceXYtoOpenglXY(int x, int y, GLfloat* ox, GLfloat* oy);
void convertOpenglXYtoDeviceXY(int* x, int* y, float ox, float oy);
void drawinit(float r, float g, float b, float red, float green, float blue);

bool out_box, in_box, init = true;
GLfloat current_ox, current_oy;
GLfloat ox1, ox2, oy1, oy2;
int x1 = GWIDTH / 4, x2 = (GWIDTH / 4) * 3, y1 = (GHEIGHT / 4) * 3, y2 = GHEIGHT / 4;

void main(int argc, char** argv) //--- 윈도우 출력하고 콜백함수 설정 
{ //--- 윈도우 생성하기
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
	glutMainLoop(); // 이벤트 처리 시작 
}

GLvoid drawScene() //--- 콜백 함수: 그리기 콜백 함수 
{
	convertDdeviceXYtoOpenglXY(x1, y1, &ox1, &oy1);
	convertDdeviceXYtoOpenglXY(x2, y2, &ox2, &oy2);
	float r, g, b;
	float red, green, blue;
	srand((unsigned int)time(NULL));

	r = (float)rand() / (float)RAND_MAX;
	g = (float)rand() / (float)RAND_MAX;
	b = (float)rand() / (float)RAND_MAX;

	red = (float)rand() / (float)RAND_MAX;
	green = (float)rand() / (float)RAND_MAX;
	blue = (float)rand() / (float)RAND_MAX;

	if (init == true)
	{
		drawinit(r, g, b, red, green, blue);
		init = false;
	}
	if (out_box == true)
	{
		glClearColor(r, g, b, 1.0f);
	}
	if (in_box == true)
	{
		glColor3f(red, green, blue);
	}
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
	convertDdeviceXYtoOpenglXY(x, y, &current_ox, &current_oy);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		in_box = false;
		out_box = false;

	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if ((current_ox > ox1 && current_ox < ox2) && (current_oy > oy1 && current_oy < oy2))
		{
			in_box = true;
			out_box = false;
		}
		else
		{
			in_box = false;
			out_box = true;
		}

	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		if ((current_ox > ox1 && current_ox < ox2) && (current_oy > oy1 && current_oy < oy2))
		{
			if (x2 + 10 >= GWIDTH);
			else
				x1 -= 10, y1 += 10, x2 += 10, y2 -= 10;
			
		}
		else
		{
			if (x2 - 10 <= x1 + 10);
			else
				x1 += 10, y1 -= 10, x2 -= 10, y2 += 10;
		}
		in_box = false;
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

void drawinit(float r, float g, float b, float red, float green, float blue)
{
	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(red, green, blue);
	glRectf(ox1, oy1, ox2, oy2);
}