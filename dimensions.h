#pragma once
class Dimensions
{
private:
	
	int cell_size;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	//NEED TO ADD BANNER HEIGHT TO THIS

public:
	Dimensions(int cell_size):
		cell_size{ cell_size }, SCREEN_WIDTH{ 640 }, SCREEN_HEIGHT{ 480 } {
	}

	int get_cell_size() const {
		return cell_size;
	}

	int get_screen_height() const {
		return SCREEN_HEIGHT;
	}

	int get_screen_width() const {
		return SCREEN_WIDTH;
	}
};

