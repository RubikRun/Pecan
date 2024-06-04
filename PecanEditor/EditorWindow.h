#pragma once

#include "DemoScenes/DemoScene00_Triangle.h"

#include <QtOpenGL/QOpenGLWindow>
#include <QOpenGLFunctions_4_5_Core>

#include <chrono>

namespace Pecan {

    /// Main window of Pecan's Editor.
    /// It's a Qt window used for rendering OpenGL graphics.
    /// This window contains only the graphics part of the editor
    /// and it should be used together with EditorControlsDialog.
    class EditorWindow : public QOpenGLWindow, private QOpenGLFunctions_4_5_Core
    {
        Q_OBJECT

    public:
        EditorWindow(QWidget* parent = nullptr);
        ~EditorWindow();

    private: /* functions */
        void initializeGL() override;
        void resizeGL(int w, int h) override;
        void paintGL() override;

        /// Returns the currently elapsed time in seconds, since the construction of this class
        float getTime() const;

    private: /* variables */
        std::chrono::high_resolution_clock::time_point startTime;

        DemoScene00_Triangle demoScene;
    };

} // namespace Pecan