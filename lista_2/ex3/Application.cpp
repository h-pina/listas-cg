#include <GL/glew.h>
#include <GL/freeglut.h>

#include "Application.h"
#include "Renderer.h"
#include "EventHandler.h"

#include <memory>

namespace CG {

	Application::Application(int* argc, char** argv)
	{
    glutInit(argc, argv);
    glutInitContextVersion(4, 6);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	void Application::run(){
		m_window = std::make_unique<Window>("House Scene", 500, 500);
		m_renderer = std::make_unique<Renderer>();

		setupCallbacks();
		glewInit();

		glutMainLoop();
	}

	void Application::setupCallbacks(){
		EventHandler::setInstances(m_window.get(), m_renderer.get());
		EventHandler::setupCallbacks();
	}
}
