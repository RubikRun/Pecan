#include "EditorMainPage.h"

namespace Pecan {

	EditorMainPage::EditorMainPage(QWidget* parent)
		: QWidget(parent)
	{
		ui.setupUi(this);
		// Connect the exit button's pressed signal to the corresponding slot
		connect(ui.exitButton, &QPushButton::pressed, this, &EditorMainPage::onExitButtonPressed);
	}

	EditorMainPage::~EditorMainPage()
	{}

	void EditorMainPage::onExitButtonPressed()
	{
		// Emit the exit signal so that editor's controls dialog can catch it and close the editor
		emit exitSignal();
	}

} // namespace Pecan