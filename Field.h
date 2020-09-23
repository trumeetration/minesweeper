#include <iostream>
#include <vector>
#include "GameObj.h"

using namespace std;

struct Point {
    int x;
    int y;
};

class Field {
    private:
        vector<vector<Cell>> cellField;
        int bombCount = 0;
        int size_X = 0;
        int size_Y = 0;
        int getRandValue(int max);
        void spaceAround(Point bPoint);
    public:
        Field(int dimension_x, int dimension_y, int bCount);
        bool OpenCell(Point point);
        void MarkCell(Point point);
        string showCell(Point point);
};

