#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

enum Id
{
    P1 = 1,
    P2 = 2
};
enum Icon
{
    X = 'X',
    O = 'O'
};

class Player
{

private:
    Id id;
    Icon icon;

public:
    Player(Id id_, Icon icon_)
    {
        icon = icon_;
        id = id_;

        cout << "JOGADOR: " << id << " | "
             << "ICONE: " << (char)icon << endl;
    }
    Player(){};

public:
    Id GetId()
    {
        return id;
    }
    Icon GetIcon()
    {
        return icon;
    }
};

#endif