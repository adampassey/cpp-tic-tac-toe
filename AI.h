#pragma once
#include "Board.h"

namespace AI {

	struct Row {
		vector2 tiles[3];
	};
	
	vector2 prefferedMove(Board board);

	int calculateScore(Board board, Row row);
}

