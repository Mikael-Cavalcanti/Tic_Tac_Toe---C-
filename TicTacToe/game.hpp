#ifndef GAME_H
#define GAME_H

#include "player.hpp"
#include "board.hpp"
#include "point.hpp"

using namespace std;

enum GameState
{
    GAMELOOP,
    FINISHGAME
};

class GameManager
{
private: // references
    GameState state;
    Player *playerOne;
    Player *playerTwo;
    Board *board;
    Point *verifyPoint;

private:
    int amountOfPlay;
    Player *currentPlayer;
    string playerWinner;
    bool tieGame;

private: // inputs
    int row;
    int column;

public:
    GameManager()
    {
        AwakeGame();
    }

    ~GameManager()
    {
        delete playerOne;
        delete playerTwo;
        delete board;
        delete verifyPoint;
        delete currentPlayer;

        FinishGame();
    }

public:
    void StartGame()
    {
        state = GAMELOOP;

        UpdateGame();
    }

private:
    void AwakeGame()
    {
        cout << endl
             << "BEM VINDO AO JOGO DA VELHA" << endl
             << endl;
        SetSettings(); // create the instace of players and board
    }
    void SetSettings()
    {
        playerOne = new Player(P1, X);
        playerTwo = new Player(P2, O);
        board = new Board();
        verifyPoint = new Point();

        amountOfPlay = 0;
        playerWinner = " ";
        currentPlayer = playerOne;
        tieGame = true;
    }

    void UpdateGame()
    {
        bool doPoint = false;

        do
        {
            for (int i = 0; i < 2; i++)
            {
                currentPlayer = ((Id)(i + 1) == playerOne->GetId()) ? playerOne : playerTwo;
                cout << endl
                     << "JOGADOR " << currentPlayer->GetId()
                     << " ESCOLHA UMA LINHA E UMA COLUNA DO TABULEIRO" << endl
                     << "ESCOLHA NUMERO DE 1 A 2 PARA LINHA E COLUNA" << endl;

                cout << "DIGITE A LINHA: ";
                cin >> row;
                cout << "DIGITE A COLUNA: ";
                cin >> column;

                if ((row < 1 && row > 3) && (column < 1 && column > 3) ||
                    board->GetIconPosition(row - 1, column - 1) != '-')
                    Reaload();

                // cout << "line: " << row << " | "
                //      << "column: " << column << endl;

                board->Markboard(row - 1, column - 1, currentPlayer->GetIcon());

                board->PrintBoard();

                amountOfPlay++;
                // cout << "numero de jogadas: " << amountOfPlay << endl;

                if (amountOfPlay > 4)
                {
                    if (verifyPoint->DoPoint(board->GetBoard()))
                    {
                        state = FINISHGAME;
                        tieGame = false;
                        break;
                    }

                    if (board->BoardIsFull())
                    {
                        state = FINISHGAME;
                        break;
                    }
                }
            }

        } while (state == GAMELOOP);

        if (tieGame)
            cout << "EMPATE!!" << endl;
        else
            cout << "VITORIA DO JOGADOR " << currentPlayer->GetId() << endl;
    }

    void Reaload()
    {
        bool isError = true;
        while (isError)
        {
            cout << "OPS!!" << endl;
            cout << "VOCE DIGITOU UMA LINHA OU COLUNA INEXISTENTE" << endl;
            cout << "OU POSICAO DO TABULEIRO ESCOLHIDA JA FOI PREENCHIDA" << endl;
            cout << "PLAYER " << currentPlayer->GetId() << " DIGITE NOVAMENTE" << endl;
            cout << "DIGITE A LINHA: ";
            cin >> row;
            cout << "DIGITE A COLUNA: ";
            cin >> column;

            if ((row > 0 && row < 4) && (column > 0 && column < 4) ||
                board->GetIconPosition(row - 1, column - 1) == '-')
                isError = false;
        }
    }

    void FinishGame()
    {
        cout << "FIM DE JOGO" << endl;

        board->~Board();
    }
};
#endif