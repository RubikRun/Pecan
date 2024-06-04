#include "EditorControlsDialog.h"

#include "EditorControls/EditorMainPage.h"
#include <QVBoxLayout>

#include "PecanLogger.h"

namespace Pecan {

	EditorControlsDialog::EditorControlsDialog(EditorWindow* editorWindow)
		: editorWindow(editorWindow)
	{
		ui.setupUi(this);
		// Create editor's main page
		EditorMainPage* mainPage = new EditorMainPage(this);
		// Connect main page's exit signal with the controls dialog's exit slot
		connect(mainPage, &EditorMainPage::exitSignal, this, &EditorControlsDialog::onExitSlot);
		// Add main page to the layout
		ui.verticalLayout->addWidget(mainPage);
	}

	EditorControlsDialog::~EditorControlsDialog()
	{}

	void EditorControlsDialog::onExitSlot() {
		// If we have a pointer to an editor window we need to close it as well
		if (editorWindow) {
			if (!editorWindow->close()) {
				PECAN_LOG_WARNING("Closed EditorWindow but it has a parent window that should also be closed.");
			}
		}
		close();
	}

} // namespace Pecan