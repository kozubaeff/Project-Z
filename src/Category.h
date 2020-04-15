#ifndef THEGAME_CATEGORY_H
#define THEGAME_CATEGORY_H

namespace Category
{
    enum Type
    {
        None				= 0,
        Scene				= 1 << 0,
        Hero		        = 1 << 1,
        AlliedHero		    = 1 << 2,
        EnemyHero		    = 1 << 3,
    };
}
#endif //THEGAME_CATEGORY_H
