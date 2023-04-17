#include "Functions.h"
#include <iostream>
using namespace std;

City::City() {

}

char City::get_grid_location(int x, int y) {
    if(x < 0 || x > 9 || y < 0 || y > 9) {
        cout << "City::get_grid_location called with out of bound parameters" << endl;
        return -1;
    }
    return m_grid[y][x];
}

void City::set_grid_location(int x, int y, char value) {
    if(x < 0 || x > 9 || y < 0 || y > 9) {
        cout << "City::get_grid_location called with out of bound parameters" << endl;
        return;
    }

    m_grid[y][x] = value;
}

template<typename T>
int Robber<T>::m_loot_count = 0;