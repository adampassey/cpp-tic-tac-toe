#include "Input.h"
#include <iostream>

namespace Input {

	vector2 getInput() {
		using namespace std;

		cout << "Enter a number (1-9) to play a tile" << endl;

		int tile = 0;
		cin >> tile;

		//	TODO: sanitize input

		return inputToBoardPosition(tile);
	}

	/*
	00	10	20
	01	11	21
	02	12  22
	*/
	vector2 inputToBoardPosition(int input) {
		switch (input) {
		case 1:
			return vector2{ 0, 0 };
			break;
		case 2:
			return vector2{ 1, 0 };
			break;
		case 3:
			return vector2{ 2, 0 };
			break;
		case 4:
			return vector2{ 0, 1 };
			break;
		case 5:
			return vector2{ 1, 1 };
			break;
		case 6:
			return vector2{ 2, 1 };
			break;
		case 7:
			return vector2{ 0, 2 };
			break;
		case 8:
			return vector2{ 1, 2 };
			break;
		case 9:
			return vector2{ 2, 2 };
		}
	}
}
