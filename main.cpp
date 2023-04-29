// Programmer: Joshua Gollaher and Benjamin Biehl
// Date: 4/28/2023
// File: main.cpp
// Assignment: Final Project
// Purpose: Contains the main function of the project, which simulates
//          a cop and robbers style game.

#include "City.h"
#include "Robber.h"
#include "Police.h"

int main() {
    srand(85);
    City city;

    // Create an array of 4 Robbers.
    Robber<Jewel> robbers[4];
    size_t num_robbers = 0;

    // Initialize police.
    Police police;

    // Grader pls don't smite me.
    auto sort_robbers = [&]( bool(*predicate)(Robber<Jewel>&) ) -> vector<Robber<Jewel>*> {
        vector<Robber<Jewel>*> sorted_robbers;
        for(int i = 0; i < 4; i++) {
            if(predicate(robbers[i])) {
                sorted_robbers.push_back(&robbers[i]);
            }
        }
        return sorted_robbers;
    };

    // Spawns in the robbers and the police.
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            char c = city.get_grid_location(i, j);
            switch(c) {
                case 'r':
                    robbers[num_robbers++] = Robber<Jewel>(make_pair(i, j));
                    break;
                case 'p':
                    police = Police(make_pair(i, j));
                    break;
            }
        }
    }

    // Prints initial grid.
    city.print_grid();

    // Finds the non-greedy robbers.
    auto normal_robbers = sort_robbers([](auto& robber) {
        return !robber.is_greedy();
    });

    // Finds the greedy robbers.
    auto greedy_robbers = sort_robbers([](auto& robber) {
        return robber.is_greedy();
    });

    // Initialize boolean variables.
    bool loot_reached = false;
    bool all_caught = false;

    // Main for loop that repeats each turn unless win condition is met.
    // Checks if total_loot count is greater than 438.
    for(int i = 0; i < 30; i++) {
        if(Robber<Jewel>::total_loot() >= 438) {
            loot_reached = true;
            break;
        }

        // Ordinary robbers move and act if conditions are met.
        for(auto* robber : normal_robbers) {
            if(robber->move(city)) {
                police.arrest(*robber);
            }
        }

        // Greedy robbers move and act if conditions are met.
        for(auto* robber : greedy_robbers) {
            if(robber->move(city)) {
                police.arrest(*robber);
            }
        }

        // Robbers move and act if conditions are met.
        police.move(city, robbers);

        all_caught = true;

        // Game ends if all robbers are caught.
        for(auto& robber : robbers) {
            if(robber.is_active()) {
                all_caught = false;
            }
        }
        if(all_caught) {
            break;
        }

        // Print out grid at end of turn.
        cout << endl << "Turn " << i+1;
        city.print_grid();
        cout << endl;

    }

    // Print out summary of chase at end.
    cout << "Summary of the chase: " << endl;
    if(all_caught) {
        cout << "The police officer wins the chase because all the robbers have been caught" << endl;
    } else if(loot_reached) {
        cout << "The robbers win the chase because confiscated jewels worth more than $438" << endl;
    } else {
        cout << "The robbers win the chase because the maximum turns (30) have been reached" << endl;
    }

    cout << endl;
    cout << "Police id: " << police.id() << endl;
    cout << "\tConfiscated jewels amount: $" << police.total_confiscated() << endl;
    cout << "\tFinal number of robbers caught: " << police.num_robbers_caught() << endl;

    for(const auto & robber : robbers) {
        cout << endl;
        cout << (robber.is_greedy() ? "Greedy" : "Ordinary") << " Robber id: " << robber.id() << endl;
        cout << "\tTotal jewels picked up: " << robber.num_jewels_collected();
        cout << "\tFinal jewel worth: $" << robber.loot_count();
    }

    return 0;
}