#pragma once

#include <QDialog>
#include "ui_PecanEditorControlsDialog.h"

#include "PecanEditorWindow.h"

class PecanEditorControlsDialog : public QDialog
{
	Q_OBJECT

public:
	PecanEditorControlsDialog(PecanEditorWindow* editorWindow);
	~PecanEditorControlsDialog();

private slots:
	void onExitSlot();

private:
	Ui::PecanEditorControlsDialogClass ui;

	PecanEditorWindow* editorWindow;
};
