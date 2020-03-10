#include "subject.h"

Subject::Subject(float _x, float _y, int h, SubjectSprites sprite)
    : x(_x)
    , y(_y)
    , hp(h)
    , sprite_type(sprite)
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