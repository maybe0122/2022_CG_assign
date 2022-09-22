#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <gl/glew.h> //--- �ʿ��� ������� include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>

GLvoid drawScene(unsigned char key);
GLvoid Reshape(int w, int h);
GLvoid Keyboard(unsigned char key, int x, int y);
void TimerFunction(int value);

bool flag = true;

void main(int argc, char** argv) //--- ������ ����ϰ� �ݹ��Լ� ���� 
{ //--- ������ �����ϱ�
	glutInit(&argc, argv); // glut �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // ���÷��� ��� ����
	glutInitWindowPosition(100, 100); // �������� ��ġ ����
	glutInitWindowSize(250, 250); // �������� ũ�� ����
	glutCreateWindow("Example1"); // ������ ����(������ �̸�)
	//--- GLEW �ʱ�ȭ�ϱ�
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) // glew �ʱ�ȭ
	{
		printf("Unable to initialize GLEW");
		exit(EXIT_FAILURE);
	}
	printf("GLEW Initialized\n");
	glutDisplayFunc(drawScene); // ��� �Լ��� ����
	glutReshapeFunc(Reshape); // �ٽ� �׸��� �Լ� ����
	glutKeyboardFunc(Keyboard);
	glutMainLoop(); // �̺�Ʈ ó�� ���� 
}

GLvoid drawScene(unsigned char key) //--- �ݹ� �Լ�: �׸��� �ݹ� �Լ� 
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
	glutSwapBuffers(); // ȭ�鿡 ����ϱ�
}
GLvoid Reshape(int w, int h) //--- �ݹ� �Լ�: �ٽ� �׸��� �ݹ� �Լ� 
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