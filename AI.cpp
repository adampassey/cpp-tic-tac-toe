#include "AI.h"
#include <map>
#include <iostream>

using namespace std;

namespace AI {

	/*
		Suggest a move for the AI opponent given a board.
		Scores rows based on what has been played in them.
	*/
	vector2 prefferedMove(Board board) {

		//	this will hold all of our moves, key
		//	will be the rowscore, and the value
		//	will be the row (array of vector2's)
		map<int, Row> moves;
		vector2 move;
		Row row;
		int rowScore;

		//	calculate each row, horizontal first
		row = { {vector2{0, 0}, vector2{1, 0}, vector2{2, 0} } };
		rowScore = calculateScore(board, row);
		moves[rowScore] = row;

		row = { { vector2{ 0, 1 }, vector2{ 1, 1 }, vector2{ 2, 1 } } };
		rowScore = calculateScore(board, row);
		moves[rowScore] = row;

		row = { { vector2{ 0, 2 }, vector2{ 1, 2 }, vector2{ 2, 2 } } };
		rowScore = calculateScore(board, row);
		moves[rowScore] = row;

		//	vertical
		row = { { vector2{ 0, 0 }, vector2{ 0, 1 }, vector2{ 0, 2 } } };
		rowScore = calculateScore(board, row);
		moves[rowScore] = row;

		row = { { vector2{ 1, 0 }, vector2{ 1, 1 }, vector2{ 1, 2 } } };
		rowScore = calculateScore(board, row);
		moves[rowScore] = row;

		row = { { vector2{ 2, 0 }, vector2{ 2, 1 }, vector2{ 2, 2 } } };
		rowScore = calculateScore(board, row);
		moves[rowScore] = row;

		//	diagonals
		row = { { vector2{ 0, 0 }, vector2{ 1, 1 }, vector2{ 2, 2 } } };
		rowScore = calculateScore(board, row);
		moves[rowScore] = row;

		row = { { vector2{ 0, 2 }, vector2{ 1, 1 }, vector2{ 2, 0 } } };
		rowScore = calculateScore(board, row);
		moves[rowScore] = row;

		//	get the highest score
		int highestRow = 0;
		Row bestRow;
		for (auto it = moves.begin(); it != moves.end(); ++it) {
			cout << it->first << endl;
			if (abs(it->first) >= highestRow) {
				highestRow = abs(it->first);
				bestRow = it->second;
			}
		}

		//	get the first tile in this row that is empty
		for (int i = 0; i < 3; i++) {
			if (board.getTile(bestRow.tiles[i]) == EMPTY) {
				return bestRow.tiles[i];
			}
		}

		return move;
	}

	/*
		Calculate a score for a given row. This will
		give the most weight to rows where the computer `O` 
		can win, and second most weight to rows where
		the player can be blocked.

		If no winning or blocking moves, will score based
		on number of empty tiles.
	*/
	int calculateScore(Board board, Row row) {

		int rowScore = 0, xCount = 0, oCount = 0, emptyCount = 0;

		//	add the number of tiles for each player so
		//	we can score this row
		for (int i = 0; i < 3; i++) {
			PLAYER tile = board.tiles[row.tiles[i].x][row.tiles[i].y];
			if (tile == X) {
				xCount++;
			}
			else if (tile == O) {
				oCount++;
			}
			else {
				emptyCount++;
			}
		}

		//	if there are no empty tiles this
		//	score should be horrible
		if (emptyCount == 0) {
			rowScore = 0;
		}

		//	if this is a winning row, let's 
		//	weight it high
		else if (oCount > 1) {
			rowScore = 3;
		}

		//	if it's a row that the player will
		//	win on next turn, weight it second highest
		else if (xCount > 1) {
			rowScore = 2;
		}

		//	otherwise we have a mixed row. meh.
		else {
			rowScore = 1;
		}

		return rowScore;
	}
}
