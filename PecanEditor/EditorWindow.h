#pragma once

#include "DemoScenes/DemoScene00_Triangle.h"
#include "DemoScenes/DemoScene01_TriangleMovingColored.h"
#include "Renderer.h"

#include <QtOpenGL/QOpenGLWindow>
#include <chrono>

namespace Pecan {

    /// Main window of Pecan's Editor.
    /// It's a Qt window used for rendering OpenGL graphics.
    /// This window contains only the graphics part of the editor
    /// and it should be used together with EditorControlsDialog.
    class EditorWindow : public QOpenGLWindow
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
        /// Time when the editor window was opened.
        /// Used to calculate elapsed time at any given moment.
        std::chrono::high_resolution_clock::time_point startTime;
        /// Pointer to the Renderer instance
        Renderer* renderer = nullptr;
        /// Demo scene to be rendered
        DemoScene01_TriangleMovingColored demoScene;
    };

} // namespace Pecan