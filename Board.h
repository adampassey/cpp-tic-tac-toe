#pragma once

enum PLAYER {
	X,
	O,
	EMPTY
};

struct vector2 {
	int x;
	int y;
};

class Board {
public:
	Board();
	~Board();

	void render();
	void reset();
	void playTile(vector2 position, PLAYER player);
	bool legalMove(vector2 position);
	bool movesAvailable();
	PLAYER getWinner();
	PLAYER getTile(vector2 position);

	PLAYER tiles[3][3];

private:
	void initialize();
};
