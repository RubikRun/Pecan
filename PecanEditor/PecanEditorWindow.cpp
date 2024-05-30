#include "PecanEditorWindow.h"
#include "PecanLogger.h"

#include <QOpenGLContext>

PecanEditorWindow::PecanEditorWindow(QWidget *parent)
{
}

PecanEditorWindow::~PecanEditorWindow()
{}

void PecanEditorWindow::initializeGL() {
    initializeOpenGLFunctions();
    // Log OpenGL info
    PECAN_LOG_INFO("OpenGL Vendor: " << glGetString(GL_VENDOR));
    PECAN_LOG_INFO("OpenGL Version: " << glGetString(GL_VERSION));
    PECAN_LOG_INFO("OpenGL Renderer: " << glGetString(GL_RENDERER));
    // Set clear color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void PecanEditorWindow::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void PecanEditorWindow::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
}