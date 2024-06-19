#include "Config/Config.h"
#include "EditorWindow.h"
#include "EditorControls/EditorControlsDialog.h"
#include <QtWidgets/QApplication>

using namespace Pecan;

int main(int argc, char *argv[])
{
    // Initialize config variables
    Config::init();
    // Get variables from config that are needed for window positioning and size
    const int windowPositionX = Config::getWindowPositionX();
    const int windowPositionY = Config::getWindowPositionY();
    const int windowWidth = Config::getWindowWidth();
    const int windowHeight = Config::getWindowHeight();
    const int controlsDialogWidth = Config::getControlsDialogWidth();
    // Create a Qt application
    QApplication application(argc, argv);
    // Create an editor window, set its position and size, and show it
    EditorWindow editorWindow;
    editorWindow.resize(windowWidth, windowHeight);
    editorWindow.setFramePosition(QPoint(windowPositionX, windowPositionY));
    editorWindow.show();
    // Create a dialog with editor's controls, set its position and size, and show it
    EditorControlsDialog editorControlsDialog(&editorWindow);
    editorControlsDialog.resize(controlsDialogWidth, windowHeight);
    editorControlsDialog.move(windowWidth + windowPositionX, windowPositionY);
    editorControlsDialog.show();
    // Run the Qt application showing the window and dialog
    return application.exec();
}
