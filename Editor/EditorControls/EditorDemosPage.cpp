#include "EditorDemosPage.h"
#include "DemoScenes/DemoScenesRegistry.h"

#include <QVBoxLayout>
#include <QPushButton>

namespace Pecan {
	typedef DemoScenesRegistry::SceneInfo SceneInfo;
	typedef std::vector<SceneInfo> SceneInfoList;

	EditorDemosPage::EditorDemosPage(QWidget* parent)
		: QWidget(parent)
	{
		setupUi();
	}

	EditorDemosPage::~EditorDemosPage()
	{}

	void EditorDemosPage::setupUi() {
		// TODO: read from config
		static const QFont font("Calibri Light", 16);
		static const int minHeight = 50;

		// Setup vertical layout
		QVBoxLayout* layout = new QVBoxLayout(this);
		setLayout(layout);

		const SceneInfoList& scenes = DemoScenesRegistry::getInstance()->getScenes();

		for (int i = 0; i < scenes.size(); i++) {
			const SceneInfo& scene = scenes[i];

			QPushButton* button = new QPushButton(scene.name.c_str(), this);
			button->setFont(font);
			button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
			button->setMinimumHeight(minHeight);
			layout->addWidget(button);
		}
		// Add spacer to push buttons to the top and leave empty space below.
		// Otherwise buttons are evenly positioned across the layout and there is empty space between them.
		QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
		layout->addItem(spacer);
	}

} // namespace Pecan