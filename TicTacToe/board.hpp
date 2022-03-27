#ifndef BOARD_H
#define BOARD_H

#include <iostream>

using namespace std;

class Board
{

private:
    char **board;

public:
    Board()
    {
        CreateBoard();
        DefaultInitBoard();
        PrintBoard();
    }
    ~Board()
    {
        DestroyBoard();
    }

private:
    void DefaultInitBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                board[i][j] = '-';
        }
    }

public:
    void CreateBoard()
    {
        board = new char *[3];
        for (int i = 0; i < 3; i++)
        {
            board[i] = new char[3];
        }
    }

    void InitBoard(char symbol)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                board[i][j] = symbol;
        }
    }

    bool BoardIsFull()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '-')
                {
                    // cout << "i: " << i << " j: " << j << endl;
                    return false;
                }
            }
        }
        return true;
    }

    void PrintBoard()
    {
        cout << "............................" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "........  ";
            for (int j = 0; j < 3; j++)
                cout
                    << board[i][j] << "  ";

            cout << "........." << endl;
        }
        cout << "............................" << endl;
    }

    void DestroyBoard()
    {

        for (int i = 0; i < 3; i++)
        {
            delete[] board[i];
        }
        delete[] board;

        cout << "board deleted" << endl;
    }

    void Markboard(int line, int column, Icon value)
    {
        board[line][column] = value;
    }

    void Markboard(int line, int column, char value)
    {
        board[line][column] = value;
    }
    char GetIconPosition(int line, int column)
    {
        return board[line][column];
    }

    char **GetBoard()
    {
        return board;
    }
};

#endif