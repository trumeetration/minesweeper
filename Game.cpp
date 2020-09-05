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