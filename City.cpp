// Programmer: Joshua Gollaher and Benjamin Biehl
// Date: 4/28/2023
// File: main.cpp
// Assignment: Final Project
// Purpose: Functions file for City class

#include "City.h"
#include <iostream>
using namespace std;

City::City() {

    m_jewel_count = 0;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            m_grid[j][i] = ' ';
        }
    }

    auto place_jewel = [&]() {
        while(true) {
            int x = rand() % 10;
            int y = rand() % 10;
            if(m_grid[y][x] == ' ') {
                m_grid[y][x] = 'J';
                break;
            }
        }
    };

    auto place_robber = [&](){
        while(true) {
            int x = rand() % 10;
            int y = rand() % 10;
            if(m_grid[y][x] == ' ') {
                m_grid[y][x] = 'r';
                break;
            }
        }
    };

    auto place_police = [&](){
        while(true) {
            int x = rand() % 10;
            int y = rand() % 10;
            if(m_grid[y][x] ==  ' ') {
                m_grid[y][x] = 'p';
                break;
            }
        }
    };

    for(int i = 0; i < 47; i++) {
        place_jewel();
    }

    for(int i = 0; i < 4; i++) {
        place_robber();
    }

    place_police();
    set_jewel_count(47);
}

void City::print_grid() const {
    for(int i = 0; i < 10; i++) {
        cout << endl;
        for(int j = 0; j < 10; j++) {
            cout << m_grid[j][i];
        }
    }
}

char City::get_grid_location(int x, int y) {
    if(x < 0 || x > 9 || y < 0 || y > 9) {
        cout << "City::get_grid_location called with out of bound parameters" << endl;
        return -1;
    }
    return m_grid[y][x];
}

void City::set_grid_location(int x, int y, char value) {
    if(x < 0 || x > 9 || y < 0 || y > 9) {
        cout << "City::set_grid_location called with out of bound parameters" << endl;
        return;
    }

    m_grid[y][x] = value;
}