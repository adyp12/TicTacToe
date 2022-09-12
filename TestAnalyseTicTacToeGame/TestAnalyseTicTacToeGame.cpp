#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/AnalyseGame.h"
#include "../ConsoleApplication1/Constants.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestAnalyseTicTacToeGame
{
	TEST_CLASS(TestAnalyseTicTacToeGame)
	{
	public:
		
		TEST_METHOD(TestPreGame)
		{
			char game[3][3] = {
				NoVal,		NoVal,		NoVal,
				NoVal,		NoVal,		NoVal,
				NoVal,		NoVal,		NoVal
			};

			Assert::AreEqual(GameInProgress, analyseGame(game));
		}

		TEST_METHOD(TestIncompleteGame)
		{
			char game[3][3] = {
				Player2,	Player1,	Player1,
				NoVal,		Player1,	NoVal,
				Player2,	NoVal,		Player2
			};

			Assert::AreEqual(GameInProgress, analyseGame(game));
		}

		TEST_METHOD(TestDraw)
		{
			char game[3][3] = {
				Player1,	Player2,	Player1,
				Player2,	Player1,	Player1,
				Player2,	Player1,	Player2
			};

			Assert::AreEqual(Draw, analyseGame(game));
		}

		TEST_METHOD(TestWinVert)
		{
			char game1[3][3] = {
				NoVal,		Player1,	Player2,
				NoVal,		Player1,	Player2,
				Player2,	Player1,	Player1
			};

			Assert::AreEqual(Player1Win, analyseGame(game1));

			char game2[3][3] = {
				Player1,	Player2,	NoVal,
				NoVal,		Player2,	NoVal,
				Player1,	Player2,	Player1
			};

			Assert::AreEqual(Player2Win, analyseGame(game2));
		}

		TEST_METHOD(TestWinHori)
		{
			char game1[3][3] = {
				Player1,	Player1,	Player1,
				Player2,	Player2,	NoVal,
				NoVal,		Player1,	Player2
			};

			Assert::AreEqual(Player1Win, analyseGame(game1));

			char game2[3][3] = {
				NoVal,		NoVal,		Player1,
				Player2,	Player2,	Player2,
				Player1,	Player1,	NoVal
			};

			Assert::AreEqual(Player2Win, analyseGame(game2));
		}

		TEST_METHOD(TestWinDiag)
		{
			char game1[3][3] = {
				Player1,	NoVal,		NoVal,
				Player2,	Player1,	Player2,
				Player2,	Player1,	Player1
			};

			Assert::AreEqual(Player1Win, analyseGame(game1));

			char game2[3][3] = {
				NoVal,		Player1,	Player2,
				NoVal,		Player2,	NoVal,
				Player2,	Player1,	Player1
			};

			Assert::AreEqual(Player2Win, analyseGame(game2));
		}
	};
}
