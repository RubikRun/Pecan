#pragma once

#include <QWidget>
#include "ui_EditorDemosPage.h"

namespace Pecan {

	/// Demos page of Pecan Editor's controls
	/// It consists of buttons in a vertical layout,
	/// where each button represents one of the existing demo scenes.
	/// Clicking a button launches the corresponding demo scene on the Editor Window.
	class EditorDemosPage : public QWidget
	{
		Q_OBJECT

	public:
		EditorDemosPage(QWidget* parent = nullptr);
		~EditorDemosPage();

	private:
		Ui::EditorDemosPageClass ui;
	};

} // namespace Pecan