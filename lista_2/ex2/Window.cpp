#include "Window.h"


namespace CG {
	Window::Window(const char* title, int width, int height )
		: m_windowConfig{title, width, height}
	{
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    m_window = glutCreateWindow(title); 
	}
	void Window::setWindowSize(int width, int height){
		glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    float razaoAspectoJanela = ((float)width)/height;
    float razaoAspectoMundo = 1.0f;
    if (razaoAspectoJanela < razaoAspectoMundo) {
        // vamos colocar barras verticais (acima e abaixo)
        float hViewport = width / razaoAspectoMundo;
        float yViewport = (height - hViewport)/2;
        glViewport(0, yViewport, width, hViewport);
    }
    // se a janela está mais larga (achatada) do que o mundo (16:9)...
    else if (razaoAspectoJanela > razaoAspectoMundo) {
        // vamos colocar barras horizontais (esquerda e direita)
        float wViewport = ((float)height) * razaoAspectoMundo;
        float xViewport = (width - wViewport)/2;
        glViewport(xViewport, 0, wViewport, height);
    } else {
        glViewport(0, 0, width, height);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
		m_windowConfig.width = width;
		m_windowConfig.height = height;
	}
}
