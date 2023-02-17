#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Survivor {
    public:
        // initialize survivor variables
        string name;
        int health;
        int hunger;
        int thirst;
        int attack;
        int defense;

        // create a new survivor instance
        Survivor(string name) {
            this->name = name;
            this->health = 100;
            this->hunger = 100;
            this->thirst = 100;
            this->attack = 10;
            this->defense = 5;
        }

        // update survivor stats
        void updateStats(int health, int hunger, int thirst, int attack, int defense) {
            this->health += health;
            this->hunger += hunger;
            this->thirst += thirst;
            this->attack += attack;
            this->defense += defense;
        }

        // check if the survivor is alive
        bool isAlive() {
            if (this->health <= 0 || this->hunger <= 0 || this->thirst <= 0) {
                return false;
            } else {
                return true;
            }
        }
};

class Game {
    public:
        // initialize game variables
        vector<Survivor*> team;
        vector<string> world;
        string destination;
        int resources;
        int weapons;
        int enemies;

        // create a new game instance
        Game() {
            this->team = createTeam();
            this->world = generateWorld();
            this->destination = setDestination();
            this->resources = gatherResources();
            this->weapons = craftWeapons();
            this->enemies = spawnEnemies();
        }

        // create a team of survivors
        vector<Survivor*> createTeam() {
            vector<Survivor*> team;
            for (int i = 0; i < 3; i++) {
                string name = "Survivor " + to_string(i+1);
                Survivor* survivor = new Survivor(name);
                team.push_back(survivor);
            }
            return team;
        }

        // generate a new world
        vector<string> generateWorld() {
            vector<string> world;
            srand(time(0));
            for (int i = 0; i < 10; i++) {
                string terrain;
                int random = rand() % 3;
                if (random == 0) {
                    terrain = "forest";
                } else if (random == 1) {
                    terrain = "desert";
                } else {
                    terrain = "swamp";
                }
                world.push_back(terrain);
            }
            return world;
        }

        // set the safe haven as the destination
        string setDestination() {
            return "Safe Haven";
        }

        // gather resources to survive
        int gatherResources() {
            return rand() % 100;
        }

        // craft weapons to defend against creatures and raiders
        int craftWeapons() {
            return rand() % 10;
        }

        // spawn mutated creatures and other players acting as raiders
        int spawnEnemies() {
            return rand() % 10;
        }

        // control the team and make decisions
        void playGame() {
            while (!atDestination()) {
                // code for scavenging resources, crafting weapons, and facing enemies
                // update team and game variables
                updateTeamStats();
                updateGameStats();
                // check if the team is alive
                if (!isTeamAlive()) {
                    // game over, death is permanent