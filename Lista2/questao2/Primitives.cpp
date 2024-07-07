#include "GL/freeglut.h"
#include "Primitives.h"

#include "math.h"
#include <cmath>

namespace CG {
		namespace Primitives {

		void drawSquare(Color color, Point center, float lenght, float height){
			float halfLenght = lenght/2;
			float halfHeight = height/2;

			glColor3f(color.R, color.G, color.B);
			glBegin(GL_TRIANGLE_FAN);
				glVertex3f(center.x-halfLenght, center.y-halfHeight, 0);
				glVertex3f(center.x+halfLenght, center.y-halfHeight, 0);
				glVertex3f(center.x+halfLenght, center.y+halfHeight, 0);
				glVertex3f(center.x-halfLenght, center.y+halfHeight, 0);
			glEnd();
		}

		void drawTriangle(Color color, Point center, int sideLenght){
			float halfLenght = (float)sideLenght / 2;
			float height = sqrt(pow(halfLenght,2) + pow(sideLenght,2));

			glColor3f(color.R, color.G, color.B);
			glBegin(GL_TRIANGLE_FAN);
				glVertex3f(center.x-(halfLenght*1.5), center.y - (height/2), 0);
				glVertex3f(center.x+(halfLenght * 1.5), center.y - (height/2), 0);
				glVertex3f(center.x, center.y, 0);
			glEnd();
		}
	}
}
