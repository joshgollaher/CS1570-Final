//
// Created by Joshua Gollaher on 4/24/2023.
//

#ifndef CS1570_FINAL_ROBBER_H
#define CS1570_FINAL_ROBBER_H
#include "City.h"
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cmath>

using namespace std;

template <typename T>
class Robber{
private:

    int m_robber_id;

    int m_bag_size = 0;
    T m_bag [17];

    pair<int, int> m_robber_coordinates;
    bool m_active;

    static int m_total_loot_count;
    static int m_robber_id_count;
    int m_loot_count;
    int m_jewels_collected;

    enum class RobberType {
        Ordinary,
        Greedy
    };
    RobberType m_type;

public:

    static Robber<T> robbers[4];

    explicit Robber(pair<int, int> coordinates = make_pair(0,0)) : m_robber_coordinates(std::move(coordinates)), m_robber_id(m_robber_id_count++), m_active(true), m_loot_count(0), m_jewels_collected(0) {}

    void set_active(bool active) {
        m_active = active;
    }

    bool is_active() const {
        return m_active;
    }

    [[nodiscard]] int id() const {
        return m_robber_id;
    }

    static int total_loot() {
        return m_total_loot_count;
    }

    [[nodiscard]] pair<int, int> get_coordinates() const {
        return m_robber_coordinates;
    }

    int pick_up_loot() {

        int x = m_robber_coordinates.first;
        int y = m_robber_coordinates.second;
        const int loot_value = x + y;

        m_total_loot_count += loot_value;
        m_loot_count += loot_value;
        Jewel jewel(m_robber_coordinates, x + y);

        if(m_bag_size < 17){
            m_bag[m_bag_size++] = jewel;
        }

        m_jewels_collected++;

        return loot_value;
    }

    [[nodiscard]] int num_jewels_collected() const {
        return m_jewels_collected;
    }

    [[nodiscard]] int loot_count() const {
        return m_loot_count;
    }

    bool is_greedy() const {
        return m_type == RobberType::Greedy;
    }

    bool is_valid_position(pair<int, int> position){
        const int x = position.first;
        const int y = position.second;

        return x >= 0 && x <= 9 && y >= 0 && y <= 9;
    }

    bool move(City& city, int n_iterations=0) {
        if(n_iterations == 3) return false;
        if(!m_active) return false;

        auto add_pair = [](pair<int, int> p1, pair<int, int> p2) -> pair<int, int> {
            return make_pair(p1.first + p2.first, p1.second + p2.second);
        };

        int delta_x, delta_y = 0;
        do {
            delta_x = rand() % 3 - 1;
            delta_y = rand() % 3 - 1;
        } while((delta_x == 0 && delta_y == 0) || !is_valid_position(add_pair(m_robber_coordinates, make_pair(delta_x, delta_y))));

        bool is_with_other_robbers = city.get_grid_location(m_robber_coordinates.first, m_robber_coordinates.second) == 'R';
        if(is_with_other_robbers) {
            city.set_grid_location(m_robber_coordinates.first, m_robber_coordinates.second, 'r');
        }

        if(city.get_grid_location(m_robber_coordinates.first, m_robber_coordinates.second) == 'r') {
            city.set_grid_location(m_robber_coordinates.first, m_robber_coordinates.second, ' ');
        }

        m_robber_coordinates.first += delta_x;
        m_robber_coordinates.second += delta_y;
        char c = city.get_grid_location(m_robber_coordinates.first, m_robber_coordinates.second);
        switch(city.get_grid_location(m_robber_coordinates.first, m_robber_coordinates.second)) {
            case ' ':
                //Empty
                city.set_grid_location(m_robber_coordinates.first, m_robber_coordinates.second, 'r');
                break;
            case 'J': {
                //Jewel
                const int loot_value = pick_up_loot();
                if (loot_value % 2 == 0) {
                    move(city, n_iterations + 1);
                }
                city.set_grid_location(m_robber_coordinates.first, m_robber_coordinates.second, 'r');
                break;
            }
            case 'r':
                city.set_grid_location(m_robber_coordinates.first, m_robber_coordinates.second, 'R');
            case 'R':
                if(m_type == RobberType::Greedy) { // FIXME: check if active
                    int num_dropped = (int)floor(m_bag_size);
                    for(int i = m_bag_size - 1; i >= m_bag_size-num_dropped; i--) {
                        //TODO: place stuff
                        auto jewel = m_bag[i];
                        if(city.get_grid_location(jewel.coordinates().first, jewel.coordinates().second) == ' ') {
                            city.set_grid_location(jewel.coordinates().first, jewel.coordinates().second, 'J');
                        } else {
                            //Put it at a random location
                            while(true) {
                                int x = rand() % 10;
                                int y = rand() % 10;
                                if(city.get_grid_location(jewel.coordinates().first, jewel.coordinates().second) == ' ') {
                                    city.set_grid_location(jewel.coordinates().first, jewel.coordinates().second, 'J');
                                    break;
                                }
                            }
                        }
                    }
                    m_bag_size -= num_dropped;
                }
                break;
            case 'p':
                m_active = false;
                city.set_grid_location(m_robber_coordinates.first, m_robber_coordinates.second, 'r');
                return true;
            default:
                cout << "Oops!" << endl;
        }
        return false;
    }

public:

};

#endif //CS1570_FINAL_ROBBER_H
