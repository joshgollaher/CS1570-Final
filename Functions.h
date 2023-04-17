#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <utility>
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

template <typename T>
class Robber{
private:

    int m_robber_id;
    pair<int, int> m_robber_coordinates;
    char m_bag [17];
    static int m_loot_count;
    bool m_active;

    enum RobberType {
        Ordinary,
        Greedy
    };
    RobberType m_type;

public:

};

#endif //FUNCTIONS_H
