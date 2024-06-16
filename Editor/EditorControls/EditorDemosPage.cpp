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

	void EditorDemosPage::onDemoButtonPressed(int sceneIndex) {
		emit loadDemoSignal(sceneIndex);
	}

	void EditorDemosPage::setupUi() {
		// TODO: read from config
		static const QFont font("Calibri Light", 16);
		static const int minHeight = 50;

		// Setup vertical layout
		QVBoxLayout* layout = new QVBoxLayout(this);
		setLayout(layout);
		// Get list of demo scenes
		const SceneInfoList& scenes = DemoScenesRegistry::getInstance()->getScenes();
		// Loop over demo scenes
		for (int sceneIdx = 0; sceneIdx < scenes.size(); sceneIdx++) {
			const SceneInfo& scene = scenes[sceneIdx];
			// For each demo scene, create a button with the scene's name
			QPushButton* button = new QPushButton(scene.name.c_str(), this);
			button->setFont(font);
			button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
			button->setMinimumHeight(minHeight);
			// Connect button's pressed signal with the corresponding slot.
			// But we cannot connect it directly because we need to pass the index of the demo scene,
			// so we define a lambda function which captures the index and calls the slot with the index
			connect(button, &QPushButton::clicked, this, [this, sceneIdx]() { onDemoButtonPressed(sceneIdx); });
			layout->addWidget(button);
		}
		// Add spacer to push buttons to the top and leave empty space below.
		// Otherwise buttons are evenly positioned across the layout and there is empty space between them.
		QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
		layout->addItem(spacer);
	}

} // namespace Pecan