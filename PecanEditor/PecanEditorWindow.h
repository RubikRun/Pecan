#pragma once

#include <QtOpenGL/QOpenGLWindow>
#include <QOpenGLFunctions_4_5_Core>

#include <chrono>

class PecanEditorWindow : public QOpenGLWindow, private QOpenGLFunctions_4_5_Core
{
    Q_OBJECT

public:
    PecanEditorWindow(QWidget* parent = nullptr);
    ~PecanEditorWindow();

private: /* functions */
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void setupTriangle();

private: /* variables */
    GLuint vertexArrayObjectID = 0;
    GLuint vertexBufferObjectID = 0;
};
