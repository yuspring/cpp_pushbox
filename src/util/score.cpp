#include "score.h"

void score::detect_dest(map _map, std::vector<dest> &_dest){
    for(int i = 0; i < _dest.size(); i++){
        //std::cout << "chest " << i << " " << _dest[i].up_chest << " " << _dest[i].chest_up(_map) << '\n';
        if(_dest[i].up_chest == false && _dest[i].chest_up(_map)){
            _dest[i].chest(true);
            this->_score++;
        }
        else if(_dest[i].up_chest == true && !_dest[i].chest_up(_map)){
            _dest[i].chest(false);
            this->_score--;
        }
        //std::cout << "chest " << i << " " << _dest[i].up_chest << " " << _dest[i].chest_up(_map) << '\n';
        //std::cout<< this->_score << "\n";
    }
    
    
}
