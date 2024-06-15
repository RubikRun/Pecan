#include "EditorDemosPage.h"

#include <QPushButton>

namespace Pecan {

	EditorDemosPage::EditorDemosPage(QWidget* parent)
		: QWidget(parent)
	{
		ui.setupUi(this);

		QPushButton* button = new QPushButton("DemoScene00", this);
		ui.verticalLayout->addWidget(button);
	}

	EditorDemosPage::~EditorDemosPage()
	{}

} // namespace Pecan