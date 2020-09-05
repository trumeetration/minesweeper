#include "Field.h"

class Game {
    private:
        Field* field;
        bool isPlaying;
        Point koord;
        int dim_x, dim_y, bCount;
    public:
        bool isRunning();
        int menu();
        void drawField(); //+ 
        void renderAction();
        void Start(int dimension_x, int dimension_y, int bombCount); // +
};