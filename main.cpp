#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    Game game;
    int dim_x, dim_y, bombCount, action;
    while (true) 
    {
        action = game.menu();
        if (action == 1)
        {
            dim_x = dim_y = 8;
            bombCount = 10;
            break;
        }
        else if (action == 2)
        {
            dim_x = dim_y = 16;
            bombCount = 40;
            break;
        }
        else if (action == 3)
        {
            dim_x = 16;
            dim_y = 30;
            bombCount = 99;
            break;
        }
        else if (action == 1)
        {
            cout << "\nDimension X: ";
            cin >> dim_x;
            cout << endl;
            cout << "\nDimension Y: ";
            cin >> dim_y;
            cout << endl;
            cout << "\nHow much bombs do you want: ";
            cin >> bombCount;
            cout << endl;
            break;
        }
        else
        {
            cout << "\nWrong choice!" << endl;
            continue;
        }
    }
    game.Start();
}
