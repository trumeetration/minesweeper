#include "Field.h"
#include <random>
#include <ctime>

int Field::getRandValue(int max) {
    return 0;
}


void Field::spaceAround(Point bPoint) {
    GameObj *obj;
    for (int i = bPoint.y - 1; i < bPoint.y + 2; i++) {
        for (int j = bPoint.x - 1; j < bPoint.x + 2; j++) {
            try {
                obj = cellField.at(i).at(j).getObj();
            }
            catch (...) {
                continue;
            }
            if (typeid(obj) == typeid(Bomb))
                continue;
            ((Hint*)obj)->setValue(((Hint*)obj)->getValue() + 1);
        }
    }
}

Field::Field(int dimension_x, int dimension_y, int bCount) {
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<> uid_x(0, dimension_x - 1);
    std::uniform_int_distribution<> uid_y(0, dimension_y - 1);
    bombCount = bCount;
    size_X = dimension_x;
    size_Y = dimension_y;
    cellField.resize(size_Y);
    for (int i = 0; i < size_Y; i++)
        cellField[i].resize(size_X);
    for (int i = 0; i < size_Y; i++)
        for (int j = 0; j < size_X; j++) {
            cellField[i][j].setObj(new Hint);
            cellField[i][j].setState(CLOSED);
        }
    cout << "4" << endl; system("pause");
    for (int i = 0; i < bombCount;) {
        Point bPoint = {uid_x(gen), uid_y(gen)};
        cout << endl << "Generated koord [" << bPoint.x << ";" << bPoint.y << "]";
        if (typeid(cellField[bPoint.y][bPoint.x].getObj()) == typeid(Bomb)) {
            cout << endl << "Exists [" << bPoint.x << ";" << bPoint.y << "]";
            continue;
        }
        cellField[bPoint.y][bPoint.x].setObj(new Bomb);
        spaceAround(bPoint);
        i++;
    }
}

void Field::MarkCell(Point point) {
    cellField[point.y][point.x].markCell();
}

bool Field::OpenCell(Point point) {
    return cellField[point.y][point.x].openCell();
}

string Field::showCell(Point point) {
    return cellField[point.y][point.x].printCell();
}