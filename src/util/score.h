#ifndef SRC_UTIL_SCORE
#define SRC_UTIL_SCORE
#include "../object/destination.h"
#include "../views/map.h"
#include <iostream>
#include <vector>

class score{

    public:
        void detect_dest(map _map, std::vector<dest>& _dest);
        int _score = 0;

};

#endif