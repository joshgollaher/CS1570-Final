// Programmer: Joshua Gollaher and Benjamin Biehl
// Date: 4/28/2023
// File: main.cpp
// Assignment: Final Project
// Purpose: Header file for City class

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

    // Desc: sets m_jewel count to jewel_count
    // Pre: takes in an int
    // Post: m_jewel_count is set to jewel_count
    void set_jewel_count(int jewel_count) { m_jewel_count = jewel_count; }

    // Desc: gets the char at the grid location
    // Pre: takes in two ints, one for x, one for y
    // Post:returns the char at the grid location
    char get_grid_location(int x, int y);

    // Desc: sets to grid at x, y to the value of value
    // Pre: takes in two ints and a char
    // Post: The char is placed in the grid
    void set_grid_location(int x, int y, char value);

    // Desc: prints out the grid for user to see
    // Pre: none
    // Post: the grid is displayed to the screen
    void print_grid() const;

};


#endif //CS1570_FINAL_CITY_H
