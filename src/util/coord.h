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

        coord get_char_coord();
        coord get_chest_coord();
        coord get_dest_coord();
        void set_coord(int k, int x , int y);
        coord _arr[10];
};

#endif