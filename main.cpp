#include "City.h"
#include "Robber.h"
#include "Police.h"


int main() {
    srand(85);
    City city;

    Robber<Jewel> robbers[4];
    size_t num_robbers = 0;

    Police police;

    //Grader pls don't smite me
    auto sort_robbers = [&]( bool(*predicate)(Robber<Jewel>&) ) -> vector<Robber<Jewel>*> {
        vector<Robber<Jewel>*> sorted_robbers;
        for(int i = 0; i < 4; i++) {
            if(predicate(robbers[i])) {
                sorted_robbers.push_back(&robbers[i]);
            }
        }
        return sorted_robbers;
    };

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

    city.print_grid();

    auto normal_robbers = sort_robbers([](auto& robber) {
        return !robber.is_greedy();
    });

    auto greedy_robbers = sort_robbers([](auto& robber) {
        return robber.is_greedy();
    });

    bool loot_reached = false;
    bool all_caught = false;
    for(int i = 0; i < 30; i++) {

        if(Robber<Jewel>::total_loot() >= 438) {
            loot_reached = true;
            break;
        }

        for(auto* robber : normal_robbers) {
            if(robber->move(city)) {
                police.arrest(*robber);
            }
        }

        for(auto* robber : greedy_robbers) {
            if(robber->move(city)) {
                police.arrest(*robber);
            }
        }

        police.move(city, robbers);


        all_caught = true;
        for(auto& robber : robbers) {
            if(robber.is_active()) {
                all_caught = false;
            }
        }
        if(all_caught) {
            break;
        }

        cout << endl << "Turn " << i+1;
        city.print_grid();
        cout << endl;

    }

    //print out summary of chase at end

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