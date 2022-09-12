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
    char game[3][3] =
    {
        NoVal, NoVal, NoVal,
        NoVal, NoVal, NoVal,
        NoVal, NoVal, NoVal
    };

    std::cout << analyseGame(game);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
