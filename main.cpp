#include "City.h"
#include "Robber.h"


int main() {
    srand(85);
    City city;
    Robber<Jewel> robbers[4];

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {

            char c = city.get_grid_location(i, j);
            switch(c) {
                case 'r':
                    break;
                case 'p':
                    break;
            }

        }
    }

    for(int i = 0; i < 30; i++) {
        //if total worth >= $438 robbers win and game ends
            // police release all robbers and keep confiscated loot

        //if police and robber are on same coordinate, robber is arrested and loot is confiscated
        //if two robbers are on same coordinate, update the grid to display 'R' instead of 'r' (only includes active robbers)

    }

    //print out summary of chase at end

    return 0;
}