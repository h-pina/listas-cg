#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include "text.h"



struct keyboardInfo{
	char keyState[100];
	char mousePosWhenPressed[100];
};

char screenResolution[100];
char mousePos[100];
struct keyboardInfo kbInfo;

void writeInfosToScreen(){

	writeText(GLUT_BITMAP_HELVETICA_18, screenResolution, 20, 80, 0);
	writeText(GLUT_BITMAP_HELVETICA_18, mousePos, 20, 60, 0);
	writeText(GLUT_BITMAP_HELVETICA_18, kbInfo.keyState, 30, 40, 0);
	writeText(GLUT_BITMAP_HELVETICA_18, kbInfo.mousePosWhenPressed, 30, 20, 0);
	
	printf("%s\n", screenResolution); 
	printf("%s\n", mousePos); 
	printf("%s\n", kbInfo.keyState);
	printf("%s\n\n", kbInfo.mousePosWhenPressed); 
}

void render() {
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	writeInfosToScreen();
	glFlush();
}

void resizeCallback(int w, int h) {
	sprintf(screenResolution, "Current Screen Resolution: %d x %d", w, h);
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboardCallback(unsigned char key, int x, int y) {
	sprintf(kbInfo.keyState, "Key '%c' PRESSED", key);
	sprintf(kbInfo.mousePosWhenPressed, "Mouse Position when Key PRESSED : %d x %d", x, y);

	switch (key) {
			case 27:
					exit(0);
	}
	glutPostRedisplay();
}

void keyboardReleaseCallback(unsigned char key, int x, int y) {
	sprintf(kbInfo.keyState, "Key '%c' RELEASED", key);
	sprintf(kbInfo.mousePosWhenPressed, "Mouse Position when Key RELEASED: %d x %d", x, y);
	glutPostRedisplay();
}
void mouseMovementCallback(int x, int y){
	sprintf(mousePos, "Mouse Position: %d x %d", x, y);
	glutPostRedisplay();
}

void setupCallbacks(){
	glutReshapeFunc(resizeCallback);
	
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(keyboardCallback);
	glutKeyboardUpFunc(keyboardReleaseCallback);

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
void initStrings(){
	sprintf(screenResolution, "Current Screen Resolution: ");
	sprintf(mousePos, "Mouse Position: ");
	sprintf(kbInfo.keyState, "No Key Pressed");
	sprintf(kbInfo.mousePosWhenPressed, " ");
}
int main(int argc, char** argv) {
	setupWindow(&argc,argv);
	setupCallbacks();	
	initStrings();

	glClearColor(0, 0, 0, 0);
	glutMainLoop();
	return 0;
}
