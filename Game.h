#include "Field.h"

class Game {
    private:
        Field* field;
        bool isPlaying;
        Point koord;
    public:
        bool isRunning();
        int menu();
        void drawField();
        void renderAction();
        void Start();
};