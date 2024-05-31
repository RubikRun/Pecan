#include "PecanEditorControlsDialog.h"

#include "PecanEditorControls/PecanEditorMainPage.h"
#include <QVBoxLayout>

#include "PecanLogger.h"

PecanEditorControlsDialog::PecanEditorControlsDialog(PecanEditorWindow* editorWindow)
	: editorWindow(editorWindow)
{
	ui.setupUi(this);
	// Create editor's main page
	PecanEditorMainPage* mainPage = new PecanEditorMainPage(this);
	connect(mainPage, &PecanEditorMainPage::exitSignal, this, &PecanEditorControlsDialog::onExitSlot);
	ui.verticalLayout->addWidget(mainPage);
}

PecanEditorControlsDialog::~PecanEditorControlsDialog()
{}

void PecanEditorControlsDialog::onExitSlot() {
	if (editorWindow) {
		if (!editorWindow->close()) {
			PECAN_LOG_WARNING("Closed PecanEditorWindow but it has a parent window that should also be closed.");
		}
	}
	close();
}
