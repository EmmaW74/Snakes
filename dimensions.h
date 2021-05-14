#pragma once
class Dimensions
{
private:
	
	int cell_size;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	int banner_height;
	int initial_snake_length;
	int initial_snake_speed;
	

public:
	Dimensions(int cell_size, int banner_height, int length, int speed):
		cell_size{ cell_size }, SCREEN_WIDTH{ 640 }, SCREEN_HEIGHT{ 480 }, banner_height{ banner_height }, initial_snake_length{ length }, initial_snake_speed{ speed } {
	}

	int get_cell_size() const {
		return cell_size;
	}

	int get_banner_height() const {
		return banner_height;
	}

	int get_screen_height() const {
		return SCREEN_HEIGHT;
	}

	int get_screen_width() const {
		return SCREEN_WIDTH;
	}

	int get_length() const {
		return initial_snake_length;
	}

	int get_speed() const {
		return initial_snake_speed;
	}
};

