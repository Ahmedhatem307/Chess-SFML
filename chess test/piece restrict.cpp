#include "header_test.h"
//successful
bool ChessBoard::piece_restrict(int x0, int y0, int x1, int y1) {

	//////////////////////
	/// 
	///
	///make the if only on pawns because all pieces move alike
	/// rook like rook bishop like boshop, black queen like white queen
	///
	///
	///
	/////////////////////

	if (arr_value(x0, y0) > 0)
	{
		if (turn)
		{
			switch (arr_value(x0, y0))
			{
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
			case 16:
			{
				// white pawn
				if (y0 - y1 == 1 && x1 - x0 == 0 || y0 - y1 == 2 && x1 - x0 == 0 && !whitePieces[(arr_value(x0, y0) - 1)].isMoved)
				{
					//when moves isMoved always true
					if (!whitePieces[(arr_value(x0, y0) - 1)].isMoved)
					{
						whitePieces[(arr_value(x0, y0) - 1)].isMoved = !whitePieces[(arr_value(x0, y0) - 1)].isMoved;
					}
					turn = false;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case 1:
			case 8:
			{
				//rook
				if (x1 - x0 != 0 && y1 - y0 == 0 || x1 - x0 == 0 && y1 - y0 != 0)
				{
					turn = false;
					return true;
				}
				else {
					return false;
				}
			}
			case 2:
			case 7:
			{
				//knight
				if (abs(x1 - x0) == 2 && abs(y1 - y0) == 1 || abs(x1 - x0) == 1 && abs(y1 - y0) == 2)
				{
					turn = false;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case 3:
			case 6:
			{
				//bishop
				if (abs(x1 - x0) == abs(y1 - y0))
				{
					turn = false;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case 4:
			{
				//king
				if (abs(x1 - x0) == 1 && abs(y1 - y0) == 1 || abs(x1 - x0) == 1 && abs(y1 - y0) == 0 || abs(x1 - x0) == 0 && abs(y1 - y0) == 1)
				{
					turn = false;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case 5:
			{
				//queen
				if (abs(x1 - x0) == abs(y1 - y0) || x1 - x0 != 0 && y1 - y0 == 0 || x1 - x0 == 0 && y1 - y0 != 0)
				{
					turn = false;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			}
		}
		else
		{
			return false;
		}
	}
	else if (arr_value(x0, y0) < 0) {
		if (turn == false)
		{
			switch (arr_value(x0, y0))
			{
				//black pawns
			case -9:
			case -10:
			case -11:
			case -12:
			case -13:
			case -14:
			case -15:
			case -16:
			{
				if (y1 - y0 == 1 && x1 - x0 == 0 || y1 - y0 == 2 && x1 - x0 == 0 && !blackPieces[abs((arr_value(x0, y0)) - 1)].isMoved)
				{
					if (!blackPieces[abs((arr_value(x0, y0)) - 1)].isMoved)
					{
						blackPieces[abs((arr_value(x0, y0)) - 1)].isMoved = !blackPieces[abs((arr_value(x0, y0)) - 1)].isMoved;
					}
					turn = true;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case -1:
			case -8:
			{
				//rook
				if (x1 - x0 != 0 && y1 - y0 == 0 || x1 - x0 == 0 && y1 - y0 != 0)
				{
					turn = true;
					return true;
				}
				else {
					return false;
				}
			}
			case -2:
			case -7:
			{
				//knight
				if (abs(x1 - x0) == 2 && abs(y1 - y0) == 1 || abs(x1 - x0) == 1 && abs(y1 - y0) == 2)
				{
					turn = true;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case -3:
			case -6:
			{
				//bishop
				if (abs(x1 - x0) == abs(y1 - y0))
				{
					turn = true;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case -4:
			{
				//king
				if (abs(x1 - x0) == 1 && abs(y1 - y0) == 1 || abs(x1 - x0) == 1 && abs(y1 - y0) == 0 || abs(x1 - x0) == 0 && abs(y1 - y0) == 1)
				{
					turn = true;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case -5:
			{
				//queen
				if (abs(x1 - x0) == abs(y1 - y0) || x1 - x0 != 0 && y1 - y0 == 0 || x1 - x0 == 0 && y1 - y0 != 0)
				{
					turn = true;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			}
		}
		else
		{
			return false;
		}
	}


}
//successful add knight as value in the parameters and put it and the if condition

int ChessBoard::move_vector(int x0, int y0, int x1, int y1, int arr_value) {
	int deltax = x1 - x0;
	int deltay = y1 - y0;
	if (arr_value == -2 && arr_value == -7 && arr_value == 7 && arr_value == 2) { return 9; }
	else if (abs(deltax) == abs(deltay))
	{
		if (deltax > 0 && deltay > 0) {
			cout << "diagonal down right";
			return 4;
		}
		else if (deltax < 0 && deltay > 0) {
			cout << "diagonal down left";
			return 6;
		}
		else if (deltax < 0 && deltay < 0) {
			cout << "diagonal up left";
			return 8;
		}
		else if (deltax > 0 && deltay < 0) {
			cout << "diagonal up right";
			return 2;
		}
	} if (deltax == 0 && deltay != 0 || deltay == 0 && deltax != 0) {
		if (deltax == 0 && deltay > 0) {
			cout << "down";
			return 5;
		}
		else if (deltax == 0 && deltay < 0) {
			cout << "up";
			return 1;
		}
		else if (deltay == 0 && deltax < 0) {
			cout << "left";
			return 7;
		}
		else if (deltay == 0 && deltax > 0) {
			cout << "right";
			return 3;
		}
	}
}
// remove break after return
//successful
int ChessBoard::obstacle(int x0, int y0, int move_vector) {
	//number of places that have zero value
	//this function return the position of obstacle
	int counter = 1;
	switch (move_vector)
	{
		case 1:
		{
			//up
			int i = 1;
			while ((y0 - i) >= 0)
			{
				if (board[(x0 + ((y0 - i) * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];
					break;
				}
				else if (board[(x0 + ((y0 - i) * 8))] == 0){
					counter++;
				 }
				i++;
				cout << endl << "move_vector up value of position :" << counter << endl;

			}

			return counter;
			break;
		}
		case 5:
		{
			//down
			int i = 1;
			while (y0 + i <= 7)
			{
				if (board[(x0 + ((y0 + i) * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];

					break;

				}
				else if (board[(x0 + ((y0 + i) * 8))] == 0) {
					counter++;
					
				}
				i++;
			}

			return counter;
			break;
		}
		case 3:
		{
			//right
			int i = 1;
			while (x0 + i <= 7)
			{
				if (board[((x0 + i) + (y0 * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];
					break;

				}
				else if (board[((x0 + i) + (y0 * 8))] == 0){
					counter++;
				 }
				i++;
			}

			return counter;
			break;
		}
		case 7:
		{
			//left
			int i = 1;
			while (x0 - i >= 0)
			{
				
				if (board[((x0 - i) + (y0 * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];
					break;
				}
				else if (board[((x0 - i) + (y0 * 8))] == 0) {
					counter++;				
				}
				i++;
			}

			return counter;
			break;
		}
		case 4:
		{
			//down right
			int i = 1;
			while (x0 + i <= 7 && y0 + i <= 7)
			{
				if (board[((x0 + i) + ((y0 + i) * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];
					break;
				}
				else if (board[((x0 + i) + ((y0 + i) * 8))] == 0) { counter++; }
				i++;
			}

			return counter;
			break;
		}
		case 2:
		{
			//up right
			int i = 1;
			while (x0 + i <= 7 && y0 - i >= 0)
			{
				if (board[((x0 + i) + ((y0 - i) * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];
					break;

				}
				else if (board[((x0 + i) + ((y0 - i) * 8))] == 0) { counter++; }
				i++;
			}

			return counter;
			break;
		}
		case 8:
		{
			//up left
			int i = 1;
			while (x0 - i >= 0 && y0 - i >= 0)
			{
				if (board[((x0 - i) + ((y0 - i) * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];
					break;

				}
				else if(board[((x0 - i) + ((y0 - i) * 8))] == 0) {
					counter++; }
				i++;
			}

			return counter;
			break;
		}
		case 6:
		{
			//down left
			int i = 1;
			while (x0 - i >= 0 && y0 + i <= 7)
			{
				if (board[((x0 - i) + ((y0 + i) * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];
					break;
				}
				else if (board[((x0 - i) + ((y0 + i) * 8))] == 0) {
					counter++;
				}
				i++;
			}

			return counter;
			break;
		}
	}
}
//successful
int ChessBoard::num_moves(int x0, int y0, int x1, int y1) {
	if (abs(x1-x0) == abs(y1 - y0))
	{
		return abs(x1 - x0);
	}
	else if (x1 - x0 != 0) {
		return abs(x1 - x0);
	}
	else if (y1 - y0 != 0) {
		return abs(y1 - y0);
	}
}

bool ChessBoard::jump_restrict(int num_move, int obstacle) {
	if (abs(num_move) > obstacle)
	{
		return false;
	}
	else {
		return true;
	}

}

bool ChessBoard::move(int x0, int y0, int x1, int y1) {
	//normal moving function
	if (arr_value(x1, y1) == 0)
	{
		//knight move
		if (arr_value(x0, y0) == 2 || arr_value(x0, y0) == -2 || arr_value(x0, y0) == 7 || arr_value(x0, y0) == -7) {

			if (arr_empty(x1, y1) && piece_restrict(x0, y0, x1, y1))
			{
				int value = board[x0 + (y0 * 8)];
				board[x1 + (y1 * 8)] = board[x0 + (y0 * 8)];
				board[x0 + (y0 * 8)] = 0;
				if (board[x1 + (y1 * 8)] < 0)
				{
					blackPieces[abs(value) - 1].place.x = x1;
					blackPieces[abs(value) - 1].place.y = y1;
					blackPieces[abs(value) - 1].square.setPosition(blackPieces[abs(value) - 1].place.x * 64, blackPieces[abs(value) - 1].place.y * 64);

				}
				else {
					whitePieces[abs(value) - 1].place.x = x1;
					whitePieces[abs(value) - 1].place.y = y1;
					whitePieces[abs(value) - 1].square.setPosition(whitePieces[abs(value) - 1].place.x * 64, whitePieces[abs(value) - 1].place.y * 64);

				}
				return true;
			}
			else { return false; }
		}
		//move when empty
		else if (arr_empty(x1, y1) && piece_restrict(x0, y0, x1, y1) && jump_restrict(num_moves(x0, y0, x1, y1), obstacle(x0, y0, move_vector(x0, y0, x1, y1, arr_value(x0, x1)))))
		{

			int value = board[x0 + (y0 * 8)];
			board[x1 + (y1 * 8)] = value;
			board[x0 + (y0 * 8)] = 0;
			if (board[x1 + (y1 * 8)] < 0)
			{
				blackPieces[abs(value) - 1].place.x = x1;
				blackPieces[abs(value) - 1].place.y = y1;
				blackPieces[abs(value) - 1].square.setPosition(blackPieces[abs(value) - 1].place.x * 64, blackPieces[abs(value) - 1].place.y * 64);

			}
			else {
				whitePieces[abs(value) - 1].place.x = x1;
				whitePieces[abs(value) - 1].place.y = y1;
				whitePieces[abs(value) - 1].square.setPosition(whitePieces[abs(value) - 1].place.x * 64, whitePieces[abs(value) - 1].place.y * 64);

			}

			return true;
		}
		//when it is empty and u move wrong [jump or not in the domain of the piece]
		else { return false; }
	}
	//eating piece
	else if (arr_value(x0, y0) > 0 && arr_value(x1, y1) < 0 || arr_value(x0, y0) < 0 && arr_value(x1, y1) > 0 ) {
		//all pieces without pawns
		if ( piece_restrict(x0, y0, x1, y1) && jump_restrict(num_moves(x0, y0, x1, y1), obstacle(x0, y0, move_vector(x0, y0, x1, y1, arr_value(x0, x1)))) && arr_value(x0,y0) < 9 && arr_value(x0,y0) > -9)
		{
			int value = board[x0 + (y0 * 8)];
			temp = board[x1 + (y1 * 8)];
			cout << endl << temp << endl << endl;
			board[x1 + (y1 * 8)] = value;
			board[x0 + (y0 * 8)] = 0;
			//whne moving a black piece
			if (value < 0)
			{
				blackPieces[abs(value) - 1].place.x = x1;
				blackPieces[abs(value) - 1].place.y = y1;
				blackPieces[abs(value) - 1].square.setPosition(blackPieces[abs(value) - 1].place.x * 64, blackPieces[abs(value) - 1].place.y * 64);

			}
			//when moving a white piece
			else {

				whitePieces[abs(value) - 1].place.x = x1;
				whitePieces[abs(value) - 1].place.y = y1;
				whitePieces[abs(value) - 1].square.setPosition(whitePieces[abs(value) - 1].place.x * 64, whitePieces[abs(value) - 1].place.y * 64);

			}

			return true;
		}
		
		//eating with pawn 
			//black eating piece
		else if (abs(x1-x0) == 1 && y1-y0 == 1 && arr_value(x0,y0) < -9) {
			int value = board[x0 + (y0 * 8)];
			temp = board[x1 + (y1 * 8)];
			cout << endl << temp << endl << endl;
			board[x1 + (y1 * 8)] = value;
			board[x0 + (y0 * 8)] = 0;
			
				blackPieces[abs(value) - 1].place.x = x1;
				blackPieces[abs(value) - 1].place.y = y1;
				blackPieces[abs(value) - 1].square.setPosition(blackPieces[abs(value) - 1].place.x * 64, blackPieces[abs(value) - 1].place.y * 64);

				turn = true;
			return true;
		}
		//white
		else if (abs(x1 - x0) == 1 && y0 - y1 == 1 && arr_value(x0,y0) >= 9 ) {
			int value = board[x0 + (y0 * 8)];
			temp = board[x1 + (y1 * 8)];
			cout << endl << temp << endl << endl;
			board[x1 + (y1 * 8)] = value;
			board[x0 + (y0 * 8)] = 0;
			
				whitePieces[abs(value) - 1].place.x = x1;
				whitePieces[abs(value) - 1].place.y = y1;
				whitePieces[abs(value) - 1].square.setPosition(whitePieces[abs(value) - 1].place.x * 64, whitePieces[abs(value) - 1].place.y * 64);

				turn = false;
			return true;
		}
		else { return false; }


	}else {
		return false;
	}

}

void ChessBoard::black_board_check() {
	//clear array
	black_checkmate = false;
	for (int i = 0; i < 64; i++)
	{
		black_board[i] = 0;
	}
	//set king position
	black_board[blackPieces[3].place.x + (8 * blackPieces[3].place.y)] = -8;
	//set pieces
	for (int i = 0; i < 16; i++)
	{
		// black pieces
		if (blackPieces[i].value != 0 && blackPieces[i].value != -4)
		{
			black_board[whitePieces[i].place.x + (8 * blackPieces[i].place.y)] = -3;
		}
		//white pieces
		if (whitePieces[i].value != 0)
		{
			black_board[whitePieces[i].place.x + (8 * whitePieces[i].place.y)] = -2;
		}
		black_board[whitePieces[0].place.x + (8 * whitePieces[0].place.y)] = -2;
	}
	black_board[whitePieces[4].place.x + (8 * whitePieces[4].place.y)] = -2;
	//available
	for (int i = 0; i < 16; i++)
	{
		for (int i = 0; i < 8; i++)
		{
			vector_arr[i] = 0;
		}
		vector_arr_setter(whitePieces[i].value);
		black_check_obstacle(whitePieces[i].place.x, whitePieces[i].place.y);
	}
	vector_arr_setter(whitePieces[4].value);
	black_check_obstacle(whitePieces[4].place.x, whitePieces[4].place.y);
	black_king_checker();
}

//king 8 white_pieces 3 black_pieces 2 avalible_move 1
void ChessBoard::white_board_check()
{
	//clear array
	white_checkmate = false;
	for (int i = 0; i < 64; i++)
	{
		white_board[i] = 0;
	}
	//set king position
	white_board[whitePieces[3].place.x + (8 * whitePieces[3].place.y)] = 8;
	//set pieces
	for (int i = 0; i < 16; i++)
	{
		// white pieces
		if (whitePieces[i].value != 0 && whitePieces[i].value != 4)
		{
			white_board[whitePieces[i].place.x + (8 * whitePieces[i].place.y)] = 3;
		}
		//black pieces
		if (blackPieces[i].value != 0)
		{
			white_board[blackPieces[i].place.x + (8 * blackPieces[i].place.y)] = 2;
		}
		white_board[blackPieces[0].place.x + (8 * blackPieces[0].place.y)] = 2;
	}
	white_board[blackPieces[4].place.x + (8 * blackPieces[4].place.y)] = 2;
	//available
	for (int i = 0; i < 16; i++)
	{
		for (int i = 0; i < 8; i++)
		{
			vector_arr[i] = 0;
		}
		vector_arr_setter(blackPieces[i].value);
		white_check_obstacle(blackPieces[i].place.x, blackPieces[i].place.y);
	}
	vector_arr_setter(blackPieces[4].value);
	white_check_obstacle(blackPieces[4].place.x, blackPieces[4].place.y);
	white_king_checker();
}


void ChessBoard::vector_arr_setter(int piece_value) {

	switch (abs(piece_value))
	{
		//rook
	case 1:
	case 8:
	{
		//rook
		vector_arr[0] = 1;
		vector_arr[1] = 3;
		vector_arr[2] = 5;
		vector_arr[3] = 7;

		break;
	}
	case 2:
	case 7: {
		//horse
		vector_arr[0] = 9;

		break;
	}
	case 3:
	case 6:
	{
		//bishop
		vector_arr[0] = 2;
		vector_arr[1] = 4;
		vector_arr[2] = 6;
		vector_arr[3] = 8;
		break;
	}
	case 5:
	{
		//queen
		vector_arr[0] = 1;
		vector_arr[1] = 2;
		vector_arr[2] = 3;
		vector_arr[3] = 4;
		vector_arr[4] = 5;
		vector_arr[5] = 6;
		vector_arr[6] = 7;
		vector_arr[7] = 8;
		break;
	}
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	{
		//pawns
		vector_arr[0] = 10;
		break;
	}
	case 4:
	{
		//king
		vector_arr[0] = 100;
		break;
	}

	}


}


void ChessBoard::white_check_obstacle(int x, int y)
{

	cout << arr_value(x, y) << "the x value  " << x << "y value " << y << endl;
	for (int i = 0; i < 8; i++)
	{
		if (vector_arr[i] != 0) {
			cout << vector_arr[i] << " ";

			switch (vector_arr[i])
			{
				cout << "  " << vector_arr[i] << "  heloooooooooo";
			case 1:
			{
				cout << "up";

				//up
				int i = 1;
				while ((y - i) >= 0)
				{
					if (board[(x + ((y - i) * 8))] == 4) {
						white_checkmate = true;
					}
					else  if (board[(x + ((y - i) * 8))] != 0)
					{
						break;
					}
					else if (board[(x + ((y - i) * 8))] == 0) {
						white_board[x + ((y - i) * 8)] = 1;
					}
					i++;

				}

				break;
			}
			case 2:
			{
				cout << "up right";
				//up right
				int i = 1;
				while (x + i <= 7 && y - i >= 0)
				{
					if (board[((x + i) + ((y - i) * 8))] == 4) {
						white_checkmate = true;
					}
					else  if (board[((x + i) + ((y - i) * 8))] != 0)
					{
						break;
					}
					else if (board[((x + i) + ((y - i) * 8))] == 0) {
						white_board[((x + i) + ((y - i) * 8))] = 1;
					}
					i++;
				}

				break;
			}
			case 3:
			{
				cout << "right";
				//right
				int i = 1;
				while ((x + i) <= 7)
				{
					if (board[((x + i) + (y * 8))] == 4) {
						white_checkmate = true;
					}
					else if (board[((x + i) + (y * 8))] != 0)
					{
						break;
					}
					else if (board[((x + i) + (y * 8))] == 0) {
						white_board[((x + i) + (y * 8))] = 1;
					}
					i++;

				}

				break;
			}
			case 4:
			{
				cout << "down right";
				//up right
				int i = 1;
				while (x + i <= 7 && y + i <= 7)
				{
					if (board[((x + i) + ((y + i) * 8))] == 4) {
						white_checkmate = true;
					}
					else if (board[((x + i) + ((y + i) * 8))] != 0)
					{
						break;
					}
					else if (board[((x + i) + ((y + i) * 8))] == 0) {
						white_board[((x + i) + ((y + i) * 8))] = 1;
					}
					i++;
				}

				break;
			}
			case 5:
			{
				cout << "down";

				//down
				int i = 1;
				while ((y + i) <= 7)
				{
					if (board[(x + ((y + i) * 8))] == 4) {
						white_checkmate = true;
					}
					else if (board[(x + ((y + i) * 8))] != 0)
					{
						break;
					}
					else if (board[(x + ((y + i) * 8))] == 0) {
						white_board[x + ((y + i) * 8)] = 1;
					}
					i++;

				}

				break;
			}
			case 6:
			{
				cout << "down left";
				//down left
				int i = 1;
				while (x - i >= 0 && y + i <= 7)
				{
					if (board[((x - i) + ((y + i) * 8))] == 4) {
						white_checkmate = true;
					}
					else if (board[((x - i) + ((y + i) * 8))] != 0)
					{
						break;
					}
					else if (board[((x - i) + ((y + i) * 8))] == 0) {
						white_board[((x - i) + ((y + i) * 8))] = 1;
					}
					i++;
				}

				break;
			}
			case 7:
			{
				cout << "left";
				//left
				int i = 1;
				while ((x - i) >= 0)
				{
					if (board[((x - i) + (y * 8))] == 4) {
						white_checkmate = true;
					}
					else if (board[((x - i) + (y * 8))] != 0)
					{
						break;
					}
					else if (board[((x - i) + (y * 8))] == 0) {
						white_board[((x - i) + (y * 8))] = 1;
					}
					i++;

				}

				break;
			}
			case 8:
			{
				cout << "down left";
				//down left
				int i = 1;
				while (x - i >= 0 && y - i >= 0)
				{
					if (board[((x - i) + ((y - i) * 8))] == 4) {
						white_checkmate = true;
					}
					else if (board[((x - i) + ((y - i) * 8))] != 0)
					{
						break;
					}
					else if (board[((x - i) + ((y - i) * 8))] == 0) {
						white_board[((x - i) + ((y - i) * 8))] = 1;
					}
					i++;
				}

				break;
			}
			case 9:
			{//knight
				for (int i = -2; i <= 2; i += 4)
				{
					for (int j = -1; j <= 1; j += 2) {
						if (x + i >= 0 && x + i <= 7 && y + j >= 0 && y + j <= 7)
						{
							if (board[(x + i) + (8 * (y + j))] == 4) {
								white_checkmate = true;
							}
							else if (board[(x + i) + (8 * (y + j))] == 0) {
								white_board[(x + i) + (8 * (y + j))] = 1;
							}

						}

					}
				}
				for (int i = -1; i <= 1; i += 2)
				{
					for (int j = -2; j <= 2; j += 4) {

						if (x + i >= 0 && x + i <= 7 && y + j >= 0 && y + j <= 7)
						{
							if (board[(x + i) + (8 * (y + j))] == 4) {
								white_checkmate = true;
							}
							else if (board[(x + i) + (8 * (y + j))] == 0) {
								white_board[(x + i) + (8 * (y + j))] = 1;
							}

						}

					}
				}
				break;

			}
			case 10:
			{
				if (x - 1 >= 0 && y + 1 <= 7)
				{
					if (board[((x - 1) + ((y + 1) * 8))] == 4) {
						white_checkmate = true;
					}
					else if (board[((x - 1) + ((y + 1) * 8))] == 0) {
						white_board[((x - 1) + ((y + 1) * 8))] = 1;
					}
				}
				if (x + 1 <= 7 && y + 1 <= 7)
				{
					if (board[((x + 1) + ((y + 1) * 8))] == 4) {
						white_checkmate = true;
					}
					else if (board[((x + 1) + ((y + 1) * 8))] == 0) {
						white_board[((x + 1) + ((y + 1) * 8))] = 1;
					}
				}
				break;
			}
			}
		}
	}
	cout << endl;
}

void ChessBoard::black_check_obstacle(int x, int y)
{
	cout << arr_value(x, y) << "the x value  " << x << "y value " << y << endl;
	for (int i = 0; i < 8; i++)
	{
		if (vector_arr[i] != 0) {
			cout << vector_arr[i] << " ";

			switch (vector_arr[i])
			{
				cout << "  " << vector_arr[i] << "  heloooooooooo";
			case 1:
			{
				cout << "up";

				//up
				int i = 1;
				while ((y - i) >= 0)
				{
					if (board[(x + ((y - i) * 8))] == -4) {
						black_checkmate = true;
					}
					else  if (board[(x + ((y - i) * 8))] != 0)
					{
						break;
					}
					else if (board[(x + ((y - i) * 8))] == 0) {
						black_board[x + ((y - i) * 8)] = -1;
					}
					i++;

				}

				break;
			}
			case 2:
			{
				cout << "up right";
				//up right
				int i = 1;
				while (x + i <= 7 && y - i >= 0)
				{
					if (board[((x + i) + ((y - i) * 8))] == -4) {
						black_checkmate = true;
					}
					else  if (board[((x + i) + ((y - i) * 8))] != 0)
					{
						break;
					}
					else if (board[((x + i) + ((y - i) * 8))] == 0) {
						black_board[((x + i) + ((y - i) * 8))] = -1;
					}
					i++;
				}

				break;
			}
			case 3:
			{
				cout << "right";
				//right
				int i = 1;
				while ((x + i) <= 7)
				{
					if (board[((x + i) + (y * 8))] == -4) {
						black_checkmate = true;
					}
					else if (board[((x + i) + (y * 8))] != 0)
					{
						break;
					}
					else if (board[((x + i) + (y * 8))] == 0) {
						black_board[((x + i) + (y * 8))] = -1;
					}
					i++;

				}

				break;
			}
			case 4:
			{
				cout << "down right";
				//up right
				int i = 1;
				while (x + i <= 7 && y + i <= 7)
				{
					if (board[((x + i) + ((y + i) * 8))] == -4) {
						black_checkmate = true;
					}
					else if (board[((x + i) + ((y + i) * 8))] != 0)
					{
						break;
					}
					else if (board[((x + i) + ((y + i) * 8))] == 0) {
						black_board[((x + i) + ((y + i) * 8))] = -1;
					}
					i++;
				}

				break;
			}
			case 5:
			{
				cout << "down";

				//down
				int i = 1;
				while ((y + i) <= 7)
				{
					if (board[(x + ((y + i) * 8))] == -4) {
						black_checkmate = true;
					}
					else if (board[(x + ((y + i) * 8))] != 0)
					{
						break;
					}
					else if (board[(x + ((y + i) * 8))] == 0) {
						black_board[x + ((y + i) * 8)] = -1;
					}
					i++;

				}

				break;
			}
			case 6:
			{
				cout << "down left";
				//down left
				int i = 1;
				while (x - i >= 0 && y + i <= 7)
				{
					if (board[((x - i) + ((y + i) * 8))] == -4) {
						black_checkmate = true;
					}
					else if (board[((x - i) + ((y + i) * 8))] != 0)
					{
						break;
					}
					else if (board[((x - i) + ((y + i) * 8))] == 0) {
						black_board[((x - i) + ((y + i) * 8))] = -1;
					}
					i++;
				}

				break;
			}
			case 7:
			{
				cout << "left";
				//left
				int i = 1;
				while ((x - i) >= 0)
				{
					if (board[((x - i) + (y * 8))] == -4) {
						black_checkmate = true;
					}
					else if (board[((x - i) + (y * 8))] != 0)
					{
						break;
					}
					else if (board[((x - i) + (y * 8))] == 0) {
						black_board[((x - i) + (y * 8))] = -1;
					}
					i++;

				}

				break;
			}
			case 8:
			{
				cout << "down left";
				//down left
				int i = 1;
				while (x - i >= 0 && y - i >= 0)
				{
					if (board[((x - i) + ((y - i) * 8))] == -4) {
						black_checkmate = true;
					}
					else if (board[((x - i) + ((y - i) * 8))] != 0)
					{
						break;
					}
					else if (board[((x - i) + ((y - i) * 8))] == 0) {
						black_board[((x - i) + ((y - i) * 8))] = -1;
					}
					i++;
				}

				break;
			}
			case 9:
			{//knight
				for (int i = -2; i <= 2; i += 4)
				{
					for (int j = -1; j <= 1; j += 2) {
						if (x + i >= 0 && x + i <= 7 && y + j >= 0 && y + j <= 7)
						{
							if (board[(x + i) + (8 * (y + j))] == 4) {
								black_checkmate = true;
							}
							else if (board[(x + i) + (8 * (y + j))] == 0) {
								black_board[(x + i) + (8 * (y + j))] = -1;
							}

						}

					}
				}
				for (int i = -1; i <= 1; i += 2)
				{
					for (int j = -2; j <= 2; j += 4) {

						if (x + i >= 0 && x + i <= 7 && y + j >= 0 && y + j <= 7)
						{
							if (board[(x + i) + (8 * (y + j))] == -4) {
								black_checkmate = true;
							}
							else if (board[(x + i) + (8 * (y + j))] == 0) {
								black_board[(x + i) + (8 * (y + j))] = -1;
							}

						}

					}
				}
				break;

			}
			case 10:
			{
				if (x - 1 >= 0 && y + 1 <= 7)
				{
					if (board[((x - 1) + ((y + 1) * 8))] == -4) {
						black_checkmate = true;
					}
					else if (board[((x - 1) + ((y + 1) * 8))] == 0) {
						black_board[((x - 1) + ((y + 1) * 8))] = -1;
					}
				}
				if (x + 1 <= 7 && y + 1 <= 7)
				{
					if (board[((x + 1) + ((y + 1) * 8))] == -4) {
						black_checkmate = true;
					}
					else if (board[((x + 1) + ((y + 1) * 8))] == 0) {
						black_board[((x + 1) + ((y + 1) * 8))] = -1;
					}
				}
				break;
			}
			}
		}
	}
	cout << endl;
}



bool ChessBoard::white_king_checker()
{
	return false;
}
bool ChessBoard::black_king_checker()
{
	return false;
}


/*
		for (int i = 0; i < 32; i++)
		{
			square[i].setSize(Vector2f(64, 64));
			square[i + 32].setSize(Vector2f(64, 64));
			square[i * 2].setFillColor(Color::Blue);
			square[(i * 2) + 1].setFillColor(Color::White);
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				square[j + (i * 8)].setPosition(64 * j, 64 * i);
			}
		}



		[main window (play,credit,exit)]
[window (take names)]

class pieces {
	int value;
	RectangleShape rc[32];
	void pieces_size() {
		for (int i = 0; i < 32; i++)
		{
			rc[i].setSize(Vector2f(64,64));
		}
	}

};








=====
board [show names, show died pieces]
turns
select-deselect
move - restrict
jump restrict
eating
upgrade
check draw
======
[show winner screen]
*/

