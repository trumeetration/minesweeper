#include "Game.h"

void Game::Start(int dimension_x, int dimension_y, int bombCount) {
    field = new Field(dimension_x, dimension_y, bombCount);
    this->dim_x = dimension_x;
    this->dim_y = dimension_y;
    this->bCount = bombCount;
    drawField();
    while (isRunning())
    {
        renderAction();
        drawField();
    }
    cout << "\nEnd!!!" << endl;
}

void Game::drawField() {
    cout << endl << "   ";
    for (int i = 0; i < dim_x; i++)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < dim_y; i++)
    {
        cout << i << " |";
        for (int j = 0; j < dim_x; j++)
        {
            cout << field->showCell(koord = {j, i});
            cout << "|";
        }
        cout << endl;
    }
}

bool Game::isRunning() {
    return isPlaying;
}

void Game::renderAction() {
    int action;
    while (true) {
        cout << "\nAction (1 - open, 2 - mark/unmark, 3 - quit): ";
        cin >> action;
        if (action != 1 && action != 2 && action != 3) {
            cout << "\nWrong choice!";
            continue;
        }
        break;
    }
    int x;
    int y;
    if (action == OPENED || action == MARKED) {
        while (true) {
            cout << "\nX: ";
            cin >> x;
            cout << "\nY: ";
            cin >> y;
            if (!(x >= 0 && x < dim_x && y >= 0 && y < dim_y)) {
                cout << "\nOut of range!";
                continue;
            }
            break;
        }
        if (action == OPENED) {
            bool tmp = field->OpenCell(Point {x, y});
            cout << endl << tmp << endl; 
            if (tmp == false) {
                //Мина! Конец
                isPlaying = false;
                finishReason = BOOM;
            }
        }
        if (action == MARKED) {
            field->MarkCell(Point {x, y});
        }
    }
    if (action == 3) {
        isPlaying = false;
        finishReason = QUIT;
    }
}

int Game::menu() {
    int ch;
    cout << endl << "1 - 8x8 and 10 bombs" << endl
    << "1 - 16x16 and 40 bombs" << endl
    << "1 - 16x30 and 99 bombs" << endl
    << "4 - custom" << endl
    << "Choice: ";
    cin >> ch;
    return ch;
}