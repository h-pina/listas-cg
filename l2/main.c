#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include "text.h"

struct screenConfig{
	int width;
	int height;
};

struct mouseProps{
	int x;
	int y;
};

struct screenConfig g_screenConfig;
struct mouseProps g_mouseProps;

void render() {
	char resolution[100];
	char mp[100];
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	sprintf(resolution, "Screen Resolution: %d x %d", g_screenConfig.width, g_screenConfig.height);
	writeText(GLUT_BITMAP_HELVETICA_18, resolution, 20, 80, 0);
	sprintf(mp, "Mouse Position: %d x %d", g_mouseProps.x, g_mouseProps.y);
	writeText(GLUT_BITMAP_HELVETICA_18, mp, 20, 60, 0);
	glFlush();
}

void resizeCallback(int w, int h) {
	g_screenConfig.width = w;
	g_screenConfig.height= h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboardCallback(unsigned char key, int x, int y) {
	switch (key) {
			case 27:
					exit(0);
	}
}

void mouseMovementCallback(int x, int y){
	g_mouseProps.x = x;	
	g_mouseProps.y = y;	
}

void setupCallbacks(){
	glutReshapeFunc(resizeCallback);
	glutKeyboardFunc(keyboardCallback);
	glutPassiveMotionFunc(mouseMovementCallback);
	glutDisplayFunc(render);
}



void setupWindow(int* argc, char** argv){
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(200, 100);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Fontes usando Freeglut");
}

int main(int argc, char** argv) {
	setupWindow(&argc,argv);
	setupCallbacks();	

	glClearColor(0, 0, 0, 0);
	glutMainLoop();
	return 0;
}
