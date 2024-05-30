#include "PecanEditorWindow.h"
#include "PecanLogger.h"

#include <QOpenGLContext>

PecanEditorWindow::PecanEditorWindow(QWidget* parent)
	: startTime(std::chrono::high_resolution_clock::now())
{
	QSurfaceFormat format;
	format.setVersion(4, 5);
	format.setProfile(QSurfaceFormat::CoreProfile);
	setFormat(format);
}

PecanEditorWindow::~PecanEditorWindow()
{
	glDeleteVertexArrays(1, &vertexArrayObjectID);
}

void PecanEditorWindow::initializeGL() {
	initializeOpenGLFunctions();
	// Log OpenGL info
	PECAN_LOG_INFO("OpenGL Vendor: " << glGetString(GL_VENDOR));
	PECAN_LOG_INFO("OpenGL Version: " << glGetString(GL_VERSION));
	PECAN_LOG_INFO("OpenGL Renderer: " << glGetString(GL_RENDERER));

	setupTriangle();
}

void PecanEditorWindow::resizeGL(int w, int h) {
	glViewport(0, 0, w, h);
}

float PecanEditorWindow::getTime() const {
	const std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
	const long long elapsedMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
	const float elapsedSeconds = float(elapsedMilliseconds) / 1000.0f;
	return elapsedSeconds;
}

void PecanEditorWindow::setupTriangle() {
	// Create and bind vertex array
	glCreateVertexArrays(1, &vertexArrayObjectID);
	glBindVertexArray(vertexArrayObjectID);
	// Create and bind vertex buffer
	glGenBuffers(1, &vertexBufferObjectID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjectID);
	// Data of triangle's vertices
	const GLfloat vertices[3 * 3] = {
		-0.5f, -0.5f, 0.0f,
		+0.5f, -0.5f, 0.0f,
		+0.0f, +0.5f, 0.0f
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// Declare position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), reinterpret_cast<GLvoid*>(0));
	// Enable position attribute
	glEnableVertexAttribArray(0);
	// Unbind vertex array
	glBindVertexArray(0);
}

void PecanEditorWindow::paintGL() {
	// Draw triangle
	glBindVertexArray(vertexArrayObjectID);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
	// Manually call update() so that paintGL() is immediately called again
	update();
}