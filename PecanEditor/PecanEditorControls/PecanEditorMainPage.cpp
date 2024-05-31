#include "PecanEditorMainPage.h"

PecanEditorMainPage::PecanEditorMainPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.exitButton, &QPushButton::pressed, this, &PecanEditorMainPage::onExitButtonPressed);
}

PecanEditorMainPage::~PecanEditorMainPage()
{}

void PecanEditorMainPage::onExitButtonPressed()
{
	emit exitSignal();
}
