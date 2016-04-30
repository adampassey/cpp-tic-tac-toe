#include <iostream>
#include "Board.h"
#include "Input.h"
#include "AI.h"

using namespace std;

void main() {

	//	construct a board and render
	//	it empty
	Board board = Board();
	board.render();
	
	//	this will hold our winner
	PLAYER winner;

	//	game loop
	while (true) {
		
		//	get input from player and play at
		//	their specified position
		//	TODO: make sure the input is valid
		vector2 positionToPlay = Input::getInput();
		if (!board.legalMove(positionToPlay)) {
			cout << "Illegal move, try again." << endl;
			continue;
		}

		//	play that tile
		board.playTile(positionToPlay, X);

		//	render the board
		board.render();

		//	check for winner
		winner = board.getWinner();
		if (winner == X) {
			cout << "Player X Wins!" << endl;
			board.reset();
			continue;
		}

		//	if there are no moves available, this is 
		//	a stale mate. notify and reset.
		if (!board.movesAvailable()) {
			cout << "Stale mate!" << endl;
			board.reset();
			continue;
		}

		//	determine opponent move
		vector2 aiPosition = AI::prefferedMove(board);
		board.playTile(aiPosition, O);
		
		//	render opponent move
		board.render();

		//	check for opponent winner
		winner = board.getWinner();
		if (winner == O) {
			cout << "Player O Wins!" << endl;
			board.reset();
			continue;
		}
	}
}

