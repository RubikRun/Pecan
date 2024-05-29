#pragma once

#include <QtOpenGL/QOpenGLWindow>
#include <QOpenGLFunctions>

class PecanEditorWindow : public QOpenGLWindow, private QOpenGLFunctions
{
    Q_OBJECT

public:
    PecanEditorWindow(QWidget *parent = nullptr);
    ~PecanEditorWindow();

private:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};
