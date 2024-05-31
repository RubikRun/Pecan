#pragma once

#include <QDialog>
#include "ui_PecanEditorControlsDialog.h"

class PecanEditorControlsDialog : public QDialog
{
	Q_OBJECT

public:
	PecanEditorControlsDialog(QWidget *parent = nullptr);
	~PecanEditorControlsDialog();

private:
	Ui::PecanEditorControlsDialogClass ui;
};
