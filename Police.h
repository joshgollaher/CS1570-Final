// Programmer: Joshua Gollaher and Benjamin Biehl
// Date: 4/28/2023
// File: main.cpp
// Assignment: Final Project
// Purpose: Header file for Police class

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

    // Desc: arrests the robber
    // Pre: takes in a robber type Jewel
    // Post: the robber is arrested
    void arrest(Robber<Jewel> &robber);

    // Desc: moves the police officer and checks for robbers
    // Pre: takes in reference to city class and list of robbers
    // Post: the police officer moves and may interact with robber
    void move(City &city, Robber<Jewel> robbers[4]);

    // Desc: returns id
    // Pre: none
    // Post: id is returned
    [[nodiscard]] int id() const;

    // Desc: returns total_confiscated
    // Pre: none
    // Post: total_confiscated is returned
    [[nodiscard]] int total_confiscated() const;

    // Desc: returns num_robbers_caught
    // Pre: none
    // Post: num_robbers_caught is returned
    [[nodiscard]] int num_robbers_caught() const;
};

#endif //CS1570_FINAL_POLICE_H
