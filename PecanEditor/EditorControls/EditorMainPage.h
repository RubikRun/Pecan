#pragma once

#include <QWidget>
#include "ui_EditorMainPage.h"

namespace Pecan {

	/// Main page of Pecan Editor's controls
	/// It consists of
	/// - "Demos" button, for going to the demos page to load a demo scene
	/// - "Exit" button, for exiting Pecan Editor
	class EditorMainPage : public QWidget
	{
		Q_OBJECT

	public:
		EditorMainPage(QWidget* parent = nullptr);
		~EditorMainPage();

	signals:
		/// Signal to be emitted when user wants to exit editor through the main page.
		/// The editor should listen to this signal and handle it by closing itself.
		void exitSignal();

	private slots:
		void onExitButtonPressed();

	private: /* variables */
		Ui::EditorMainPageClass ui;
	};

} // namespace Pecan