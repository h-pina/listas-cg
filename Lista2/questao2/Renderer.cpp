#include "Renderer.h"
#include "Primitives.h"

#include <GL/freeglut.h>

namespace CG {
	void Renderer::render(){
		glClear(GL_COLOR_BUFFER_BIT);

		Primitives::Point squareCenter = {0, -0.25};
		Primitives::Color squareColor = {0.639, 0.239, 0.078};
		Primitives::drawSquare(squareColor, squareCenter, 1, 1);
		
		squareCenter = {0.25,0};
		squareColor = {0.639, 0.5, 0.0};
		Primitives::drawSquare(squareColor, squareCenter, 0.25, 0.25);

		squareCenter = {0,-0.5};
		squareColor = {0.302, 0.118, 0.047};
		Primitives::drawSquare(squareColor, squareCenter, 0.25, 0.5);

		Primitives::Point triangleCenter = {0, 0.75};
		Primitives::Color triangleColor = {0.412, 0.161, 0.188};
		Primitives::drawTriangle(triangleColor, triangleCenter, 1 );

		glutSwapBuffers();
	}
}
