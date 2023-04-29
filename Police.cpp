// Programmer: Joshua Gollaher and Benjamin Biehl
// Date: 4/28/2023
// File: main.cpp
// Assignment: Final Project
// Purpose: Functions file for Police class

#include "Police.h"

int Police::ID_COUNT = 0;

void Police::arrest(Robber<Jewel> &robber) {
    m_robbers_caught++;
    m_total_confiscated += robber.loot_count();
    robber.set_active(false);
}

static bool is_valid_position(pair<int, int> position){
    const int x = position.first;
    const int y = position.second;

    return x >= 0 && x <= 9 && y >= 0 && y <= 9;
}

void Police::move(City &city, Robber<Jewel> robbers[4]) {

    auto add_pair = [](pair<int, int> p1, pair<int, int> p2) -> pair<int, int> {
        return make_pair(p1.first + p2.first, p1.second + p2.second);
    };

    auto robbers_at_location = [&](pair<int, int> location) -> std::vector<Robber<Jewel>> {
        std::vector<Robber<Jewel>> robbers;

        for(auto& robber : robbers) {
            if(robber.get_coordinates() == location) {
                robbers.push_back(robber);
            }
        }

        return robbers;
    };

    int delta_x, delta_y = 0;
    do {
        delta_x = rand() % 3 - 1;
        delta_y = rand() % 3 - 1;
    } while((delta_x == 0 && delta_y == 0) || !is_valid_position(add_pair(m_coordinates, make_pair(delta_x, delta_y))));


    if(city.get_grid_location(m_coordinates.first, m_coordinates.second) == 'p') {
        city.set_grid_location(m_coordinates.first, m_coordinates.second, ' ');
    }

    m_coordinates.first += delta_x;
    m_coordinates.second += delta_y;

    switch(city.get_grid_location(m_coordinates.first, m_coordinates.second)) {
        case 'r':
        case 'R':
            for(auto& robber : robbers_at_location(m_coordinates)) {
                arrest(robber);
            }
            break;
        case 'J':
            m_total_confiscated += m_coordinates.first + m_coordinates.second;
            city.set_grid_location(m_coordinates.first, m_coordinates.second, ' ');
            break;
        default:
            break;
    }

    city.set_grid_location(m_coordinates.first, m_coordinates.second, 'p');

}

int Police::id() const {
    return m_id;
}

int Police::total_confiscated() const {
    return m_total_confiscated;
}

int Police::num_robbers_caught() const {
    return m_robbers_caught;
}
