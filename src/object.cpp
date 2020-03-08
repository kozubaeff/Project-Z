#include "object.h"

Object::Object(float _x, float _y, int h, bool damag, Sprites spr){
    x = _x;
    y = _y;
    hp = h;
    damagable = damag;
    sprite_type = spr;
}

float Object::getX() const {
    return x;
}

float Object::getY() const {
    return y;
}

int Object::getHP() const {
    return hp;
}