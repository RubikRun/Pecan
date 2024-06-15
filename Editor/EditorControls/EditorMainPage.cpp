#include "EditorMainPage.h"

namespace Pecan {

	EditorMainPage::EditorMainPage(QWidget* parent)
		: QWidget(parent)
	{
		ui.setupUi(this);
		// Connect the "Cxit" button's pressed signal to the corresponding slot
		connect(ui.exitButton, &QPushButton::pressed, this, &EditorMainPage::onExitButtonPressed);
		// Connect the "Demos" button's pressed signal to the corresponding slot
		connect(ui.demosButton, &QPushButton::pressed, this, &EditorMainPage::onDemosButtonPressed);
	}

	EditorMainPage::~EditorMainPage()
	{}

	void EditorMainPage::onExitButtonPressed() {
		// Emit the exit signal so that editor's controls dialog can catch it and close the editor
		emit exitSignal();
	}

	void EditorMainPage::onDemosButtonPressed() {
		emit goToDemosPageSignal();
	}

} // namespace Pecan