#include "EditorWindow.h"
#include "DemoScenes/DemoScenesRegistry.h"

#include <QOpenGLContext>

namespace Pecan {

	EditorWindow::EditorWindow(QWidget* parent) {
		// Specify an OpenGL version
		QSurfaceFormat format;
		format.setVersion(4, 5);
		format.setProfile(QSurfaceFormat::CoreProfile);
		setFormat(format);
	}

	EditorWindow::~EditorWindow() {
		if (demoScene) {
			demoScene->cleanup();
		}
	}

	void EditorWindow::loadScene(int sceneIndex) {
		if (demoScene) {
			demoScene->cleanup();
		}
		demoScene = DemoScenesRegistry::getInstance()->getScenes()[sceneIndex].scene;
		demoScene->setup();
	}

	void EditorWindow::initializeGL() {
		// Retrieve the Renderer instance, initializing OpenGL functions
		renderer = Renderer::getInstance();
		// Log OpenGL info
		Renderer::logOpenGLInfo();
		// Setup demo scene
		if (demoScene) {
			demoScene->setup();
		}
	}

	void EditorWindow::resizeGL(int w, int h) {
		renderer->glViewport(0, 0, w, h);
	}

	void EditorWindow::paintGL() {
		// Draw demo scene
		if (demoScene) {
			demoScene->draw();
		}
		// Manually call update() so that paintGL() is immediately called again
		update();
	}

} // namespace Pecan