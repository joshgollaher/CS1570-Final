#include "Functions.h"
#include <iostream>
using namespace std;

City::City() {

    m_jewel_count = 0;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            m_grid[j][i] = ' ';
        }
    }
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

bool City::is_jewel_at(pair<int, int> coordinates) const {
    return coordinates.first >= 0 && coordinates.first < 10 && coordinates.second >= 0 && coordinates.second < 10 && m_grid[coordinates.second][coordinates.first] == 'J';
}

template<typename T>
int Robber<T>::m_total_loot_count = 0;