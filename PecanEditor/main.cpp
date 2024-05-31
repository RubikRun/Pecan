#include "PecanEditorWindow.h"
#include "PecanEditorControlsDialog.h"
#include <QtWidgets/QApplication>

// TODO: read from config
const int WINDOW_POSITION_X = 60;
const int WINDOW_POSITION_Y = 60;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int CONTROLS_WIDTH = 200;

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    PecanEditorWindow editorWindow;
    editorWindow.resize(WINDOW_WIDTH, WINDOW_HEIGHT);
    editorWindow.setFramePosition(QPoint(WINDOW_POSITION_X, WINDOW_POSITION_Y));
    editorWindow.show();

    PecanEditorControlsDialog editorControlsDialog;
    editorControlsDialog.resize(CONTROLS_WIDTH, WINDOW_HEIGHT);
    editorControlsDialog.move(WINDOW_WIDTH + WINDOW_POSITION_X, WINDOW_POSITION_Y);
    editorControlsDialog.show();

    return application.exec();
}
