// Programmer: Joshua Gollaher and Benjamin Biehl
// Date: 4/28/2023
// File: main.cpp
// Assignment: Final Project
// Purpose: Header file for Jewel class

#ifndef CS1570_FINAL_JEWEL_H
#define CS1570_FINAL_JEWEL_H
#include <utility>
#include <cstdlib>
using namespace std;

class Jewel {
private:

    pair<int, int> m_coordinates;

public:

    Jewel(pair<int, int> coordinates = make_pair(0, 0), int worth = 0) : m_coordinates(coordinates) {}

    // Desc: returns m_coordinates
    // Pre: takes in a pair of ints
    // Post: m_coordinates is returned
    pair<int, int>& coordinates() { return m_coordinates; }

};


#endif //CS1570_FINAL_JEWEL_H
