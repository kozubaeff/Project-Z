#include "subject.h"

Subject::Subject(float _x, float _y, int h)
    : x(_x)
    , y(_y)
    , hp(h)
    {}

float Subject::getX() {
    return x;
}

float Subject::getY(){
    return y;
}

int Subject::getHP() {
    return hp;
}