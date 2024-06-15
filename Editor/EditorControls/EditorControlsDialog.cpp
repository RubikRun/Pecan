#include "EditorControlsDialog.h"

#include "EditorControls/EditorMainPage.h"
#include "EditorControls/EditorDemosPage.h"
#include <QVBoxLayout>

#include "PecanLogger.h"

namespace Pecan {

	EditorControlsDialog::EditorControlsDialog(EditorWindow* editorWindow)
		: editorWindow(editorWindow)
		, mainPage(new EditorMainPage(this))
		, demosPage(new EditorDemosPage(this))
	{
		ui.setupUi(this);
		// Connect main page's exit signal with the controls dialog's exit slot
		connect(mainPage, &EditorMainPage::exitSignal, this, &EditorControlsDialog::onExitSlot);
		// Connect main page's "go to demos" signal with the controls dialog's "go to demos" slot
		connect(mainPage, &EditorMainPage::goToDemosPageSignal, this, &EditorControlsDialog::onGoToDemosPageSlot);

		// Add main page and demos page to layout
		ui.verticalLayout->addWidget(mainPage);
		ui.verticalLayout->addWidget(demosPage);
		// Hide demos page, only main page should be shown in the beginning
		demosPage->hide();
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

	void EditorControlsDialog::onGoToDemosPageSlot() {
		setPage(demosPage);
	}

	void EditorControlsDialog::setPage(QWidget* page) {
		if (page == mainPage) {
			mainPage->show();
			demosPage->hide();
		}
		else if (page == demosPage) {
			demosPage->show();
			mainPage->hide();
		}
	}

} // namespace Pecan