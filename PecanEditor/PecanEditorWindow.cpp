#include "PecanEditorWindow.h"

#include <QOpenGLContext>

PecanEditorWindow::PecanEditorWindow(QWidget *parent)
{
}

PecanEditorWindow::~PecanEditorWindow()
{}

void PecanEditorWindow::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void PecanEditorWindow::resizeGL(int w, int h) {
    // Set the viewport to cover the entire window
    glViewport(0, 0, w, h);
}

void PecanEditorWindow::paintGL() {
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);
}