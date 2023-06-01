#ifndef SRC_UTIL_COORD
#define SRC_UTIL_COORD


class coord{
    public :
        int x;
        int y;
        
};

class coord_map{
    
    public:
        coord get_char_coord();
        coord get_chest_coord();
        coord get_dest_coord();
        void set_coord(int k, int x , int y);
        coord _arr[10];
};

#endif