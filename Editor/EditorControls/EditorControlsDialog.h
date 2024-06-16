#pragma once

#include <QDialog>

#include "EditorWindow.h"

namespace Pecan {

	class EditorMainPage;
	class EditorDemosPage;

	/// Dialog with UI controls of Pecan Editor.
	/// This dialog contains QWidgets used to navigate the editor,
	/// change parameters, load scenes, export/load files, etc.
	/// It should be used together with EditorWindow
	/// where the actual graphics are rendered.
	class EditorControlsDialog : public QDialog
	{
		Q_OBJECT

	public:
		/// Creates a new controls dialog
		/// @param editorWindow - Pointer to the editor window that this controls dialog is associated with
		EditorControlsDialog(EditorWindow* editorWindow);
		~EditorControlsDialog();

	private slots:
		/// Slot to be called when the dialog is exited
		void onExitSlot();
		/// Slot to be called when user wants to go to demos page.
		void onGoToDemosPageSlot();
		/// Slot to be called when user wants to load a demo scene
		void onLoadDemoSceneSlot(int sceneIndex);

	private: /* functions */
		/// Sets control dialog's current page.
		void setPage(QWidget* page);

	private: /* variables */
		/// Pointer to the editor window that this controls dialog is associated with
		EditorWindow* editorWindow;
		/// Pointers to the different pages of the controls dialog
		EditorMainPage* mainPage = nullptr;
		EditorDemosPage* demosPage = nullptr;
	};

} // namespace Pecan