#ifndef SRC_UTIL_COORD
#define SRC_UTIL_COORD

#include <vector>
#include "../views/map.h"
#include "../object/chest.h"
#include "../object/destination.h"

class coord{
    public :
        int x;
        int y;
        
};

class coord_map{
    
    public:
        std::vector<dest> init_dest(map _map);
        std::vector<chest> init_chest(map _map);
        coord get_player_coord(map _map);

};

#endif