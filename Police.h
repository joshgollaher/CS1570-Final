//
// Created by Joshua Gollaher on 4/24/2023.
//

#ifndef CS1570_FINAL_POLICE_H
#define CS1570_FINAL_POLICE_H
#include <utility>
#include <cstdlib>

#include "Robber.h"

using namespace std;

class Police {
private:

    int m_id;
    static int ID_COUNT;
    pair<int, int> m_coordinates;
    int m_robbers_caught;
    int m_total_confiscated;

public:

    explicit Police(pair<int, int> coordinates = make_pair(0, 0)) : m_robbers_caught(0), m_id(ID_COUNT++), m_coordinates(std::move(coordinates)), m_total_confiscated(0) {}

    void arrest(Robber<Jewel> &robber);

    void move(City &city, Robber<Jewel> robbers[4]);

    [[nodiscard]] int id() const;

    [[nodiscard]] int total_confiscated() const;

    [[nodiscard]] int num_robbers_caught() const;
};


#endif //CS1570_FINAL_POLICE_H
