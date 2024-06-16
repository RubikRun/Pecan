#pragma once

#include <QWidget>

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

	signals:
		void loadDemoSignal(int sceneIndex);

	private slots:
		void onDemoButtonPressed(int sceneIndex);

	private: /* functions */
		void setupUi();
	};

} // namespace Pecan