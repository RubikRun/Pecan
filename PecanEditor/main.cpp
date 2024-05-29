#include "PecanEditorWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    PecanEditorWindow window;
    window.resize(1200, 800);
    window.show();
    return application.exec();
}
