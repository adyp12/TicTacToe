// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Coding task

The game of Tic-Tac-Toe, or Noughts and Crosses, is played on a 3x3 grid by two players, one represented by a cross (X) and the other by a nought (O). One player goes first then they 
take it in turns to place their symbol on an unoccupied square on the grid. The first player to connect three of their symbols in a line either horizontally, vertically or diagonally 
is the winner. If there are no unoccupied squares left, the game is a draw.

Using C++, write a function which examines a Tic-Tac-Toe board and determines whether the first player won, the second player won or if the game is a draw. Also provide an adequate set
of tests to prove that the function works correctly.

The arguments to the function should be a suitable representation of the Tic-Tac-Toe board and it should return a value of a suitable type indicating the game state.
*/

/*
    Assumptions:
     - Player 1 is Xs & Player 2 is Os
*/
#include "AnalyseGame.h"
#include <iostream>
#include "Constants.h"


int analyseGame(char game[3][3]) {

    //Check Horizontal
    for (size_t i = 0; i < 3; i++) {
        if (game[0][i] == Player1 && game[1][i] == Player1 && game[2][i] == Player1) {
            return Player1Win;
        }
        else if(game[0][i] == Player2 && game[1][i] == Player2 && game[2][i] == Player2) {
            return Player2Win;
        }
    }

    //Check Vertical
    for (size_t i = 0; i < 3; i++) {
        if (game[i][0] == Player1 && game[i][1] == Player1 && game[i][2] == Player1) {
            return Player1Win;
        }
        else if (game[i][0] == Player2 && game[i][1] == Player2 && game[i][2] == Player2) {
            return Player2Win;
        }
    }

    //Check Diagonal
    char firstValLeft = game[0][0];

    if (firstValLeft != NoVal) {
        if (game[0][0] == firstValLeft && game[1][1] == firstValLeft && game[2][2] == firstValLeft) {
            if(firstValLeft == Player1) {
                return Player1Win;
            }
            else {
                return Player2Win;
            }
        }
    }

    char firstValRight = game[0][2];

    if (firstValRight != NoVal) {
        if (game[0][2] == firstValRight && game[1][1] == firstValRight && game[2][0] == firstValRight) {
            if (firstValRight == Player1) {
                return Player1Win;
            }
            else {
                return Player2Win;
            }
        }
    }

    //Check for Draw
    bool spaceRemaining = false;

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (game[i][j] == NoVal) {
                spaceRemaining = true;
                break;
            }
        }
    }

    if (!spaceRemaining) {
        return Draw;
    }

    return GameInProgress;
}

int main() {

    //I had tried to test this with unit tests but there were issues with the linker and i couldnt get the the Projects to talk to each other

    //Game Not Started
    char blank[3][3] =
    {
        NoVal,      NoVal,      NoVal,
        NoVal,      NoVal,      NoVal,
        NoVal,      NoVal,      NoVal
    };

    if (analyseGame(blank) == GameInProgress)
    {
        std::cout << "Blank Test: Test Passed\n\n";
    }
    else
    {
        std::cout << "Blank Test: Test Failed\n\n";
    }

	//Game Incomplete
    char incomplete[3][3] =
    {
	    Player2,	Player1,	Player1,
		NoVal,		Player1,	NoVal,
		Player2,	NoVal,		Player2
	};

    if (analyseGame(incomplete) == GameInProgress)
    {
        std::cout << "Incomplete Test: Test Passed\n\n";
    }
    else
    {
        std::cout << "Incomplete Test: Test Failed\n\n";
    }
	
    //Game Ended In A Draw
	char draw[3][3] = {
	    Player1,	Player2,	Player1,
		Player2,	Player1,	Player1,
		Player2,	Player1,	Player2
	};

    if (analyseGame(draw) == Draw)
    {
        std::cout << "Draw Test: Test Passed\n\n";
    }
    else
    {
        std::cout << "Draw Test: Test Failed\n\n";
    }

    //Player 1 Wins Vertical
	char vertical1[3][3] = {
		NoVal,		Player1,	Player2,
		NoVal,		Player1,	Player2,
		Player2,	Player1,	Player1
	};

    if (analyseGame(vertical1) == Player1Win)
    {
        std::cout << "Vert Player1: Test Passed\n\n";
    }
    else
    {
        std::cout << "Vert Player1: Test Failed\n\n";
    }

    //Player 2 Wins Vertical
	char vertical2[3][3] = {
		Player1,	Player2,	NoVal,
		NoVal,		Player2,	NoVal,
		Player1,	Player2,	Player1
	};

    if (analyseGame(vertical2) == Player2Win)
    {
        std::cout << "Vert Player2: Test Passed\n\n";
    }
    else
    {
        std::cout << "Vert Player2: Test Failed\n\n";
    }

	//Player 1 Wins Horizontal
	char horizontal1[3][3] = {
		Player1,	Player1,	Player1,
		Player2,	Player2,	NoVal,
		NoVal,		Player1,	Player2
	};

    if (analyseGame(horizontal1) == Player1Win)
    {
        std::cout << "Hori Player1: Test Passed\n\n";
    }
    else
    {
        std::cout << "Hori Player1: Test Failed\n\n";
    }

    //Player 2 Wins Horizontal
	char horizontal2[3][3] = {
		NoVal,		NoVal,		Player1,
		Player2,	Player2,	Player2,
		Player1,	Player1,	NoVal
	};

    if (analyseGame(horizontal2) == Player2Win)
    {
        std::cout << "Hori Player2: Test Passed\n\n";
    }
    else
    {
        std::cout << "Hori Player2: Test Failed\n\n";
    }

    //Player 1 Wins Diagonal
	char diag1[3][3] = {
		Player1,	NoVal,		NoVal,
		Player2,	Player1,	Player2,
		Player2,	Player1,	Player1
	};

    if (analyseGame(diag1) == Player1Win)
    {
        std::cout << "Diag Player1: Test Passed\n\n";
    }
    else
    {
        std::cout << "Diag Player1: Test Failed\n\n";
    }

    //Player 2 Wins Diagonal
	char diag2[3][3] = {
		NoVal,		Player1,	Player2,
		NoVal,		Player2,	NoVal,
		Player2,	Player1,	Player1
	};

    if (analyseGame(diag2) == Player2Win)
    {
        std::cout << "Diag Player2: Test Passed\n\n";
    }
    else
    {
        std::cout << "Diag Player2: Test Failed\n\n";
    }

    return 0;
}