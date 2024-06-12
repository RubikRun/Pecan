#pragma once

#include <QDialog>
#include "ui_EditorControlsDialog.h"

#include "EditorWindow.h"

namespace Pecan {

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

	private:
		Ui::EditorControlsDialogClass ui;

		/// Pointer to the editor window that this controls dialog is associated with
		EditorWindow* editorWindow;
	};

} // namespace Pecan