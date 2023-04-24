//
// Created by Joshua Gollaher on 4/24/2023.
//

#ifndef CS1570_FINAL_JEWEL_H
#define CS1570_FINAL_JEWEL_H
#include <utility>
#include <cstdlib>
using namespace std;

class Jewel {
private:

    int m_worth;
    pair<int, int> m_coordinates;

public:

    [[nodiscard]] int worth() const { return m_worth; }
    void set_worth(int worth) { m_worth = worth; }

    pair<int, int>& coordinates() { return m_coordinates; }

};


#endif //CS1570_FINAL_JEWEL_H
