//
// Created by piotrkali on 12/12/22.
//

#ifndef CGRAPH_STATICMAP_H
#define CGRAPH_STATICMAP_H
namespace Collections {
   /* template<class T, class Keys>
    class StaticMap {
        int size;
        Keys* keys;
        T* types;
    public:
        explicit StaticMap(int size);
        T get_element(Keys key);
        void set_element(Keys key, T to_set);


    };

    template<class T, class Keys>
    StaticMap<T, Keys>::StaticMap(int size) {
        keys = new Keys[size];
        types = new T[size];
        this->size = size;
    }

    template<class T, class Keys>
    T StaticMap<T, Keys>::get_element(Keys key) {

    }

    template<class T, class Keys>
    Keys StaticMap<T, Keys>::get_key(int n) {
        if (n >= size or n < 0) {
            throw "out of range";
        } else {
            return keys[n];
        }
    }

    template<class T, class Keys>
    void StaticMap<T, Keys>::set_element(int n, T to_set) {
        if (n >= size or n < 0) {
            throw "out of range";
        } else {
            types[n] = to_set;
        }
    }

    template<class T, class Keys>
    void StaticMap<T, Keys>::set_key(int n, Keys to_set) {
        if (n >= size or n < 0) {
            throw "out of range";
        } else {
            return keys[n] = to_set;
        }
    }
*/}
#endif //CGRAPH_STATICMAP_H
