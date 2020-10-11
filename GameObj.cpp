#include "GameObj.h"


std::string GameObj::showObj(State state) {
    if (state == CLOSED)
        return "*";
    if (state == MARKED)
        return "?";
    if (state == OPENED)
        return 0;
    else return 0;
}

std::string Bomb::showObj(State state) {
    if (state == OPENED)
        return "#";
    else return GameObj::showObj(state);
}

std::string Hint::showObj(State state) {
    if (state == OPENED)
        return std::to_string(value);
    else return GameObj::showObj(state);
}

int Hint::getValue() { return value; }
void Hint::setValue(int value) { this->value = value; }

State Cell::getState() { return state ;}
void Cell::setState(State state) { this->state = state; }

GameObj* Cell::getObj() { return obj; }
void Cell::setObj(GameObj* obj) { this->obj = obj; }

void Cell::markCell() {
    if (state == OPENED) return;
    if (state == MARKED) {
        state = CLOSED;
        return;
    }
    if (state == CLOSED) {
        state = MARKED;
        return;
    }
}

bool Cell::openCell() {
    state = OPENED;
    if (typeid(*obj) == typeid(Bomb))
        return false;
    else return true;
}

std::string Cell::printCell() { return obj->showObj(state); }

