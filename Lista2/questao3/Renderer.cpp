#include "Renderer.h"
#include "Primitives.h"

#include <GL/freeglut.h>
#include <GL/gl.h>

namespace CG {

	int circleDisplayList;

	void drawGround(){
		Primitives::Point squareCenter = {0, -150};
		Primitives::Color squareColor = {0.161, 0.529, 0.118};
		Primitives::drawSquare(squareColor, squareCenter, 400, 100);
	}

	void drawHouse(){

		Primitives::Point squareCenter = {-75, -50};
		Primitives::Color squareColor = {0.639, 0.239, 0.078};
		Primitives::drawSquare(squareColor, squareCenter, 100, 100);
		
		squareCenter = {-50,-25};
		squareColor = {0.639, 0.5, 0.0};
		Primitives::drawSquare(squareColor, squareCenter, 25, 25);

		squareCenter = {-75,-75};
		squareColor = {0.302, 0.118, 0.047};
		Primitives::drawSquare(squareColor, squareCenter, 25, 50);

		Primitives::Point triangleCenter = {-75, 50};
		Primitives::Color triangleColor = {0.412, 0.161, 0.188};
		Primitives::drawTriangle(triangleColor, triangleCenter, 100 );
	}

	void drawTree(){
		Primitives::Point squareCenter = {75, -50};
		Primitives::Color squareColor = {0.302, 0.118, 0.047};
		Primitives::drawSquare(squareColor, squareCenter, 25, 100);	

		Primitives::Point circleCenter = {75, 0};
		Primitives::Color circleColor = {0.161, 0.529, 0.118};
		Primitives::drawCircle(circleColor,circleCenter, 25, 60);

		circleCenter = {100, 25};
		Primitives::drawCircle(circleColor,circleCenter, 25, 60);
		circleCenter = {75, 50};
		Primitives::drawCircle(circleColor,circleCenter, 25, 60);
		circleCenter = {50, 25};
		Primitives::drawCircle(circleColor,circleCenter, 25, 60);

		circleCenter = {50, 0};
		Primitives::drawCircle(circleColor,circleCenter, 12, 60);
		circleCenter = {50, 50};
		Primitives::drawCircle(circleColor,circleCenter, 12, 60);
		circleCenter = {100, 0};
		Primitives::drawCircle(circleColor,circleCenter, 12, 60);
		circleCenter = {100, 50};
		Primitives::drawCircle(circleColor,circleCenter, 12, 60);
	}

	void drawCloud(float centerx, float centery){
		Primitives::Point circleCenter = {centerx, centery};
		Primitives::Color circleColor = {1, 1, 1};

		Primitives::drawCircle(circleColor,circleCenter, 12, 60);
		circleCenter = {centerx+12, centery-12};
		Primitives::drawCircle(circleColor,circleCenter, 12, 60);
		circleCenter = {centerx-12, centery+12};
		Primitives::drawCircle(circleColor,circleCenter, 12, 60);
		circleCenter = {centerx, centery};
		Primitives::drawCircle(circleColor,circleCenter, 12, 60);
		circleCenter = {centerx+25, centery};
		Primitives::drawCircle(circleColor,circleCenter, 12, 60);
		circleCenter = {centerx, centery+25};
		Primitives::drawCircle(circleColor,circleCenter, 12, 60);
		circleCenter = {centerx, centery+12};
		Primitives::drawCircle(circleColor,circleCenter, 12, 60);
		circleCenter = {centerx+12, centery+12};
		Primitives::drawCircle(circleColor,circleCenter, 12, 60);
		circleCenter = {centerx-12, centery-12};
		Primitives::drawCircle(circleColor,circleCenter, 12, 60);
	}

	void drawSky(){
		Primitives::Point circleCenter = {-150, 150};
		Primitives::Color circleColor = {0.871, 0.812, 0.063};
		Primitives::drawCircle(circleColor,circleCenter, 25, 60);
		
		drawCloud(0, 150);
		drawCloud(25, 150);
		drawCloud(150, 120);
		drawCloud(-150, 50);

	}

	Renderer::Renderer(){

		m_sceneDisplayList = glGenLists(1);
		glNewList(m_sceneDisplayList, GL_COMPILE);
			drawGround();
			drawHouse();
			drawTree();
			drawSky();
		glEndList();
	}


	void Renderer::render(){
		glClearColor(0.176, 0.725, 0.961, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glCallList(m_sceneDisplayList);
		glutSwapBuffers();
	}

}
