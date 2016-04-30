#include "Board.h"
#include <iostream>

Board::Board() {
	initialize();
}

Board::~Board() {
}

void Board::playTile(vector2 position, PLAYER player) {
	tiles[position.x][position.y] = player;
}

bool Board::legalMove(vector2 position) {
	if (tiles[position.x][position.y] == EMPTY) {
		return true;
	}
	return false;
}

bool Board::movesAvailable() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (tiles[x][y] == EMPTY) {
				return true;
			}
		}
	}

	return false;
}

PLAYER Board::getTile(vector2 position) {
	return tiles[position.x][position.y];
}

void Board::render() {
	using namespace std;

	system("cls");

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cout << " ";

			if (tiles[x][y] == X) {
				cout << "X";
			}
			else if (tiles[x][y] == O) {
				cout << "O";
			}
			else if (tiles[x][y] == EMPTY) {
				cout << " ";
			}
			cout << " |";
		}

		cout << endl;
	}
}

void Board::reset() {
	initialize();
}

void Board::initialize() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			tiles[x][y] = EMPTY;
		}
	}
}

PLAYER Board::getWinner() {
	//	horizontal rows
	if (tiles[0][0] != EMPTY && (tiles[0][0] == tiles[1][0] && tiles[1][0] == tiles[2][0])) {
		return tiles[0][0];
	}

	if (tiles[0][1] != EMPTY && (tiles[0][1] == tiles[1][1] && tiles[1][1] == tiles[2][1])) {
		return tiles[0][1];
	}

	if (tiles[0][2] != EMPTY && (tiles[0][2] == tiles[1][2] && tiles[1][2] == tiles[2][2])) {
		return tiles[0][2];
	}

	//	vertical rows
	if (tiles[0][0] != EMPTY && (tiles[0][0] == tiles[0][1] && tiles[0][1] == tiles[0][2])) {
		return tiles[0][0];
	}

	if (tiles[1][0] != EMPTY && (tiles[1][0] == tiles[1][1] && tiles[1][1] == tiles[1][2])) {
		return tiles[1][0];
	}

	if (tiles[2][0] != EMPTY && (tiles[2][0] == tiles[2][1] && tiles[2][1] == tiles[2][2])) {
		return tiles[2][0];
	}

	//	diagonals
	if (tiles[0][0] != EMPTY && (tiles[0][0] == tiles[1][1] && tiles[1][1] == tiles[2][2])) {
		return tiles[0][0];
	}

	if (tiles[0][2] != EMPTY && (tiles[0][2] == tiles[1][1] && tiles[1][1] == tiles[2][0])) {
		return tiles[0][2];
	}

	return EMPTY;
}
