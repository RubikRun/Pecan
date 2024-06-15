#include "EditorMainPage.h"

#include <QVBoxLayout>

namespace Pecan {

	EditorMainPage::EditorMainPage(QWidget* parent)
		: QWidget(parent)
	{
		setupUi();
	}

	EditorMainPage::~EditorMainPage()
	{}

	void EditorMainPage::onExitButtonPressed() {
		// Emit the exit signal so that editor's controls dialog can catch it and close the editor
		emit exitSignal();
	}

	void EditorMainPage::onDemosButtonPressed() {
		emit goToDemosPageSignal();
	}

	void EditorMainPage::setupUi() {
		// TODO: read from config
		static const QFont font("Calibri Light", 16);
		static const int minHeight = 50;

		// Setup vertical layout
		QVBoxLayout* layout = new QVBoxLayout(this);
		setLayout(layout);
		// Create "Demos" button
		QPushButton* demosButton = new QPushButton("Demos", this);
		demosButton->setFont(font);
		demosButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
		demosButton->setMinimumHeight(minHeight);
		layout->addWidget(demosButton);
		// Connect the "Demos" button's pressed signal to the corresponding slot
		connect(demosButton, &QPushButton::pressed, this, &EditorMainPage::onDemosButtonPressed);
		// Create "Exit" button
		QPushButton* exitButton = new QPushButton("Exit", this);
		exitButton->setFont(font);
		exitButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
		exitButton->setMinimumHeight(minHeight);
		layout->addWidget(exitButton);
		// Connect the "Exit" button's pressed signal to the corresponding slot
		connect(exitButton, &QPushButton::pressed, this, &EditorMainPage::onExitButtonPressed);
		// Add spacer to push buttons to the top and leave empty space below.
		// Otherwise buttons are evenly positioned across the layout and there is empty space between them.
		QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
		layout->addItem(spacer);
	}

} // namespace Pecan