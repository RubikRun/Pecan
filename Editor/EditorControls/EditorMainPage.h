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
		/// Signal to be emitted when user wants to go to demos page.
		/// The editor should listen to this signal and handle it by changing the page to demos page.
		void goToDemosPageSignal();

	private slots:
		/// Slot that's called when the "Exit" button is pressed.
		void onExitButtonPressed();
		/// Slot that's called when the "Demos" button is pressed.
		void onDemosButtonPressed();

	private: /* variables */
		Ui::EditorMainPageClass ui;
	};

} // namespace Pecan