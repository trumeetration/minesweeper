#include <iostream>

enum State {
    CLOSED,
    OPENED,
    MARKED
};

class GameObj {
    public:
        virtual void showObj(State state);
};

class Cell {
    private:
    State state = CLOSED;
    GameObj* obj = NULL;
    public:
        State getState();
        GameObj* getObj();
        void setState(State state);
        void setObj(GameObj* obj);
        void markCell();
        void openCell();
        void printCell();
};

class Bomb : GameObj {
    public:
        void showObj(State state);
};

class Hint : GameObj {
    private:
        int value = 10;
    public:
        int getValue();
        void setValue(int value);
};

