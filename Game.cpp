#include "Game.h"

void Game::Start(int dimension_x, int dimension_y, int bombCount) {
    field = new Field(dimension_x, dimension_y, bombCount);
    this->dim_x = dimension_x;
    this->dim_y = dimension_y;
    this->bCount = bombCount;
    drawField();
    while (isPlaying)
    {
        renderAction();
        drawField();
    }
    cout << "\nEnd!!!" << endl;
}

void Game::drawField() {
    for (int i = 0; i < dim_y; i++)
    {
        cout << "|";
        for (int j = 0; j < dim_x; j++)
        {
            koord.x = j;
            koord.y = i;
            field->ShowCell(koord);
            cout << "|";
        }
        cout << endl;
        for (int j = 0; j < dim_x + 2; j++)
            cout << "_";
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
            if (field->OpenCell(Point {x, y}) == false) {
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