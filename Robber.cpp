// Programmer: Joshua Gollaher and Benjamin Biehl
// Date: 4/28/2023
// File: main.cpp
// Assignment: Final Project
// Purpose: Functions file for Robber class

#include "Robber.h"

template<>
int Robber<Jewel>::m_total_loot_count = 0;

template<>
int Robber<Jewel>::m_robber_id_count = 0;

//template<typename T>
//Robber<Jewel> Robber<T>::robbers[4];