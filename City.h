//
// Created by Joshua Gollaher on 4/24/2023.
//

#ifndef CS1570_FINAL_CITY_H
#define CS1570_FINAL_CITY_H
#include <utility>
#include <cstdlib>
#include <vector>
#include "Jewel.h"

using namespace std;

class City {
private:

    char m_grid[10][10];
    int m_jewel_count;



public:
    City();

    [[nodiscard]] int jewel_count() const { return m_jewel_count; }
    void set_jewel_count(int jewel_count) { m_jewel_count = jewel_count; }

    char get_grid_location(int x, int y);
    void set_grid_location(int x, int y, char value);

    bool is_jewel_at(pair<int, int> coordinates) const;

};


#endif //CS1570_FINAL_CITY_H
