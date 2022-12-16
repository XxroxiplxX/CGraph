//
// Created by piotrkali on 12/12/22.
//

#ifndef CGRAPH_STATICMAP_H
#define CGRAPH_STATICMAP_H
#include "vector"

template<class Type, class Key>
struct Pair {
    Type element;
    Key key;
    Pair(Type e, Key k) {
        element = e;
        key = k;
    }
};

template<class Type, class Key>
class StaticMap {
public:
   std::vector<Pair<Type, Key>> map;
   Type get_elem(Key key);
   void change_elem(Key key, Type to_change);
};

template<class Type, class Key>
Type StaticMap<Type, Key>::get_elem(Key key) {
    for (int i = 0 ; i < map.size(); i++) {
        if (map[i].key == key) {
            return map[i].element;
        }
    }
}

template<class Type, class Key>
void StaticMap<Type, Key>::change_elem(Key key, Type to_change) {
    for (int i = 0 ; i < map.size(); i++) {
        if (map[i].key == key) {
            map[i].element = to_change;
        }
    }
}


#endif //CGRAPH_STATICMAP_H
