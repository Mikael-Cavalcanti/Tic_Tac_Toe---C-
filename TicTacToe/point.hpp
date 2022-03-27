#ifndef POINT_H
#define POINT_H

#include "board.hpp"
#include "player.hpp"
#include <tuple>

using namespace std;

class Point
{
private:
    tuple<int, int> linesWin[8][3] = {
        {make_tuple(0, 0), make_tuple(1, 1), make_tuple(2, 2)}, // diagonal i = 0
        {make_tuple(2, 0), make_tuple(1, 1), make_tuple(0, 2)}, // diagonal i = 1
        {make_tuple(0, 0), make_tuple(0, 1), make_tuple(0, 2)}, // row i = 2
        {make_tuple(1, 0), make_tuple(1, 1), make_tuple(1, 2)}, // row i = 3
        {make_tuple(2, 0), make_tuple(2, 1), make_tuple(2, 2)}, // row i = 4
        {make_tuple(0, 0), make_tuple(1, 0), make_tuple(2, 0)}, // column i = 5
        {make_tuple(0, 1), make_tuple(1, 1), make_tuple(2, 1)}, // column i = 6
        {make_tuple(0, 2), make_tuple(1, 2), make_tuple(2, 2)}, // column i = 7
    };

public:
    Point()
    {
    }

    ~Point()
    {
    }

public:
    bool DoPoint(char **board)
    {
        bool firstEqualSecond = false, secondEqualThird = false;

        for (int i = 0; i < 8; i++)
        {
            // verify if board[line][column] == board[line+1][column+1] based in line Win
            int line = get<0>(linesWin[i][0]);
            int column = get<1>(linesWin[i][0]);
            int lineNext = get<0>(linesWin[i][1]);
            int columnNext = get<1>(linesWin[i][1]);

            firstEqualSecond = (board[line][column] == board[lineNext][columnNext]);

            line = lineNext;
            column = columnNext;
            lineNext = get<0>(linesWin[i][2]);
            columnNext = get<1>(linesWin[i][2]);

            secondEqualThird = (board[line][column] == board[lineNext][columnNext]);

            if (firstEqualSecond && secondEqualThird && board[line][column] != '-')
                return true;
        }

        return false;
    }
};

#endif