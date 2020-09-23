#include <iostream>

enum State {
    CLOSED,
    OPENED,
    MARKED
};

class GameObj {
    public:
        virtual std::string showObj(State state);
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
        bool openCell();
        std::string printCell();
};

class Bomb : public GameObj {
    public:
        std::string showObj(State state);
};

class Hint : public GameObj {
    private:
        int value = 0;
    public:
        std::string showObj(State state); 
        int getValue();
        void setValue(int value);
};

