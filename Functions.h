#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <utility>
#include <cstdlib>
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

class Jewel {
private:

    int m_worth;
    pair<int, int> m_coordinates;

public:

    [[nodiscard]] int worth() const { return m_worth; }
    void set_worth(int worth) { m_worth = worth; }

    pair<int, int>& coordinates() { return m_coordinates; }

};

class Police {
private:

    int m_id;
    static int ID_COUNT;
    pair<int, int> m_coordinates;
    int m_robbers_caught;

public:


};

template <typename T>
class Robber{
private:

    int m_robber_id;
    int m_bag_size = 0;

    T m_bag [17];

    pair<int, int> m_robber_coordinates;
    bool m_active;

    static int m_total_loot_count;

    enum class RobberType {
        Ordinary,
        Greedy
    };
    RobberType m_type;

    void pick_up_loot(T loot) {
        if(m_bag_size < 17){
            m_bag[m_bag_size++] = loot;
        }
    }

    bool is_valid_position(pair<int, int> position){
        const int x = position.first;
        const int y = position.second;

        return x >= 0 && x <= 9 && y >= 0 && y <= 9;
    }

    bool near_jewel(City& city) const;

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
                //TODO: check if greedy
                break;
            case 'C':
                //Cop
                break;
            default:
                cerr << "Oops!" << endl;
        }
    }

public:

};

#endif //FUNCTIONS_H
