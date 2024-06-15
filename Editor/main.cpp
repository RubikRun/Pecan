#include "EditorWindow.h"
#include "EditorControls/EditorControlsDialog.h"
#include <QtWidgets/QApplication>

// TODO: read from config
const int WINDOW_POSITION_X = 60;
const int WINDOW_POSITION_Y = 60;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int CONTROLS_WIDTH = 300;

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    Pecan::EditorWindow editorWindow;
    editorWindow.resize(WINDOW_WIDTH, WINDOW_HEIGHT);
    editorWindow.setFramePosition(QPoint(WINDOW_POSITION_X, WINDOW_POSITION_Y));
    editorWindow.show();

    Pecan::EditorControlsDialog editorControlsDialog(&editorWindow);
    editorControlsDialog.resize(CONTROLS_WIDTH, WINDOW_HEIGHT);
    editorControlsDialog.move(WINDOW_WIDTH + WINDOW_POSITION_X, WINDOW_POSITION_Y);
    editorControlsDialog.show();

    return application.exec();
}
