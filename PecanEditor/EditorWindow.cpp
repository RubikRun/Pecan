#include "EditorWindow.h"
#include "Renderer.h"

#include <QOpenGLContext>

namespace Pecan {

	EditorWindow::EditorWindow(QWidget* parent)
		: startTime(std::chrono::high_resolution_clock::now())
	{
		// Specify an OpenGL version
		QSurfaceFormat format;
		format.setVersion(4, 5);
		format.setProfile(QSurfaceFormat::CoreProfile);
		setFormat(format);
	}

	EditorWindow::~EditorWindow()
	{
		demoScene.cleanup();
	}

	void EditorWindow::initializeGL() {
		// Log OpenGL info
		Renderer::logOpenGLInfo();

		demoScene.setup();
	}

	void EditorWindow::resizeGL(int w, int h) {
		Renderer::setViewport(0, 0, w, h);
	}

	float EditorWindow::getTime() const {
		const std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
		const long long elapsedMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
		const float elapsedSeconds = float(elapsedMilliseconds) / 1000.0f;
		return elapsedSeconds;
	}

	void EditorWindow::paintGL() {
		demoScene.draw();
		// Manually call update() so that paintGL() is immediately called again
		update();
	}

} // namespace Pecan