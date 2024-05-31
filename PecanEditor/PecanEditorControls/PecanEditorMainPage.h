#pragma once

#include <QWidget>
#include "ui_PecanEditorMainPage.h"

class PecanEditorMainPage : public QWidget
{
	Q_OBJECT

public:
	PecanEditorMainPage(QWidget* parent = nullptr);
	~PecanEditorMainPage();

signals:
	void exitSignal();

private:
	void onExitButtonPressed();

private:
	Ui::PecanEditorMainPageClass ui;
};
