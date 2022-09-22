#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <gl/glew.h> //--- 필요한 헤더파일 include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>

GLvoid drawScene(unsigned char key);
GLvoid Reshape(int w, int h);
GLvoid Keyboard(unsigned char key, int x, int y);
void TimerFunction(int value);

bool flag = true;

void main(int argc, char** argv) //--- 윈도우 출력하고 콜백함수 설정 
{ //--- 윈도우 생성하기
	glutInit(&argc, argv); // glut 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // 디스플레이 모드 설정
	glutInitWindowPosition(100, 100); // 윈도우의 위치 지정
	glutInitWindowSize(250, 250); // 윈도우의 크기 지정
	glutCreateWindow("Example1"); // 윈도우 생성(윈도우 이름)
	//--- GLEW 초기화하기
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) // glew 초기화
	{
		printf("Unable to initialize GLEW");
		exit(EXIT_FAILURE);
	}
	printf("GLEW Initialized\n");
	glutDisplayFunc(drawScene); // 출력 함수의 지정
	glutReshapeFunc(Reshape); // 다시 그리기 함수 지정
	glutKeyboardFunc(Keyboard);
	glutMainLoop(); // 이벤트 처리 시작 
}

GLvoid drawScene(unsigned char key) //--- 콜백 함수: 그리기 콜백 함수 
{
	srand((unsigned int)time(NULL));
	float r, g, b, al;
	r = (float)rand() / (float)RAND_MAX;
	g = (float)rand() / (float)RAND_MAX;
	b = (float)rand() / (float)RAND_MAX;
	al = (float)rand() / (float)RAND_MAX;
	switch (key)
	{
	case 'r':
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		break;
	case 'g':
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		break;
	case 'b':
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		break;
	case 'a':
		glClearColor(r, g, b, al);
		break;
	case 'w':
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		break;
	case 'k':
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		break;
	default:
		break;
	}
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers(); // 화면에 출력하기
}
GLvoid Reshape(int w, int h) //--- 콜백 함수: 다시 그리기 콜백 함수 
{
	glViewport(0, 0, w, h);
}

GLvoid Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'R':
	case 'r':
		drawScene('r');
		break;
	case 'G':
	case 'g':
		drawScene('g');
		break;
	case 'B':
	case 'b':
		drawScene('b');
		break;
	case 'A': // random
	case 'a':
		drawScene('a');
		break;
	case 'W': // white
	case 'w':
		drawScene('w');
		break;
	case 'K': // black
	case 'k':
		drawScene('k');
		break;
	case 'T': // set timer & random color
	case 't':
		glutTimerFunc(100, TimerFunction, 1);
		break;
	case 'S': // end timer
	case 's':
		flag = false;
		break;
	case 'Q':
	case 'q':
		exit(1);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void TimerFunction(int value)
{
	if (!flag)
	{
		glutPostRedisplay();
		flag = true;
	}
	else {
		drawScene('a');
		glutPostRedisplay();
		glutTimerFunc(100, TimerFunction, 1);
	}
}