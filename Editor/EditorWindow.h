#pragma once

#include "Renderer.h"
#include "TimeUtils.h"

#include <QtOpenGL/QOpenGLWindow>

namespace Pecan {

    class IDemoScene;

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

        void loadScene(int sceneIndex);

    private: /* functions */
        void initializeGL() override;
        void resizeGL(int w, int h) override;
        void paintGL() override;

    private: /* variables */
        /// Timer keeping track of elapsed time since the creation of editor window
        TimeUtils::Timer timer;
        /// Pointer to the Renderer instance
        Renderer* renderer = nullptr;
        /// Demo scene to be rendered
        IDemoScene* demoScene = nullptr;
    };

} // namespace Pecan