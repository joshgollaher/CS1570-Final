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

    enum class RobberType {
        Ordinary,
        Greedy
    };
    RobberType m_type;
public:

    explicit Robber(pair<int, int> coordinates) : m_robber_coordinates(std::move(coordinates)), m_robber_id(m_robber_id_count++), m_active(true) {}

    void pick_up_loot() {

        int x = m_robber_coordinates.first;
        int y = m_robber_coordinates.second;

        Jewel jewel(m_robber_coordinates, x + y);

        if(m_bag_size < 17){
            m_bag[m_bag_size++] = jewel;
        }
    }

    bool is_valid_position(pair<int, int> position){
        const int x = position.first;
        const int y = position.second;

        return x >= 0 && x <= 9 && y >= 0 && y <= 9;
    }

    void move(City& city) {

        auto add_pair = [](pair<int, int>& p1, pair<int, int>& p2) -> pair<int, int> {
            return make_pair(p1.first + p2.first, p1.second + p2.second);
        };

        int delta_x, delta_y = 0;

        do {
            delta_x = rand() % 3 - 1;
            delta_y = rand() % 3 - 1;
        } while(delta_x == 0 && delta_y == 0 && is_valid_position(add_pair(m_robber_coordinates, make_pair(delta_x, delta_y))));

        m_robber_coordinates.first += delta_x;
        m_robber_coordinates.second += delta_y;

        switch(city.get_grid_location(m_robber_coordinates.first, m_robber_coordinates.second)) {
            case ' ':
                //Empty
                break;
            case 'J':
                //Jewel
                pick_up_loot();
                break;
            case 'R':
                if(m_type == RobberType::Greedy) { // FIXME: check if active
                    int num_dropped = (int)floor(m_bag_size);
                    for(int i = m_bag_size - 1; i >= m_bag_size-num_dropped; i--) {
                        //TODO: place stuff
                        auto jewel = m_bag[i];
                        if(city.get_grid_location(jewel.coordinates.first, jewel.coordinates.second) == ' ') {
                            city.set_grid_location(jewel.coordinates.first, jewel.coordinates.second, 'J');
                        } else {
                            //Put it at a random location
                            while(true) {
                                int x = rand() % 10;
                                int y = rand() % 10;
                                if(city.get_grid_location(jewel.coordinates.first, jewel.coordinates.second) == ' ') {
                                    city.set_grid_location(jewel.coordinates.first, jewel.coordinates.second, 'J');
                                    break;
                                }
                            }
                        }
                    }
                    m_bag_size -= num_dropped;
                }
                break;
            case 'C':
                //Cop
                m_active = false;

                break;
            default:
                cout << "Oops!" << endl;
        }
    }

public:

};

#endif //CS1570_FINAL_ROBBER_H
