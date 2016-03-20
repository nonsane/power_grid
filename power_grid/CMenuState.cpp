#include "CMenuState.h"

CMenuState::CMenuState() {

}

CMenuState::~CMenuState() {

}


void CMenuState::Enter() {
	data.Attach(&view);
	view.SetData(&data);
	view.Render();

	HandleInput();
}

void CMenuState::Exit() {
	data.Detach(&view);
	std::cout << "Exiting Menu State!\n";
}

void CMenuState::HandleInput() {
	while (data.GetState() == SELECTION_NONE) {
		int input = 0;
		std::cin >> input;

		data.SelectMenuOption(input);
	}

	switch (data.GetState()) {
	case SELECTION_NEW:
		// MAT: Add Logic here to inialize a new game!
		std::cout << "Start new game!\n";
		break;
	case SELECTION_LOAD:
		// MAT: Add Logic here to load last saved game!
		std::cout << "Load last game!\n";
		break;
	default:
		break;
	}
}