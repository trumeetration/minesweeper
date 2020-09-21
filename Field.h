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
        vector<vector<Cell>> cell;
        int bombCount = 0;
        int size_X = 0;
        int size_Y = 0;
    public:
        Field(int bCount, int dimension_x, int dimension_y);
        bool OpenCell(Point koord);
        void MarkCell(Point koord);
        void ShowCell(Point koord);
};

