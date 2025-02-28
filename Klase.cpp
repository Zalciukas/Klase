#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

class Superhero {
public:
    string name;
private:
    string ability;
    static int objectCount;
    static int highestID;
    int id;
    int powerLevel;
    static vector<Superhero*> superheroList;

public:
    Superhero(string n, int p, string a) 
        : name(n), powerLevel(p >= 0 ? p : 0), ability(a), id(++highestID) 
    {
        if (p < 0) {
            cerr << "Warning: Power level cannot be negative. Setting to 0.\n";
        }
        objectCount++;
        superheroList.push_back(this);
    }

    Superhero(string n, string a) 
        : name(n), powerLevel(0), ability(a), id(++highestID) 
    {
        objectCount++;
        superheroList.push_back(this);
    }

    ~Superhero() {
        objectCount--;
        for (size_t i = 0; i < superheroList.size(); ++i) {
            if (superheroList[i]->id == this->id) {
                superheroList.erase(superheroList.begin() + i);
                break;
            }
        }
    }

    string getName() const { 
        return name; 
    }
    string getAbility() const { 
        return ability; 
    }
    int getPowerLevel() const {
        return powerLevel;
    }
    void setPowerLevel(int p) {
        if(p >= 0) {
            powerLevel = p;
        }   else {
            cerr << "Warning: Power level cannot be negative. Setting to 0.\n";
            powerLevel = 0;
            }
    }

    string toString() const {
        return name + "," + id + "," + to_string(powerLevel) + "," + ability;
    }

    static int getObjectCount() {
        return objectCount;
    }

    static int getNextID() {
        return highestID + 1;
    }
};

int Superhero::objectCount = 0;
int Superhero::highestID = 0;
vector<Superhero*> Superhero::superheroList;

int main() {
    assert(Superhero::getObjectCount() == 0);

    {
        Superhero hero1("Iron Guardian", -100, "Flight");
        assert(hero1.getPowerLevel() == 0);
        assert(Superhero::getObjectCount() == 1);

        hero1.setPowerLevel(120);
        assert(hero1.getPowerLevel() == 120);

        Superhero hero2("Shadow Phantom", 80, "Invisibility");
        assert(hero2.getPowerLevel() == 80);
        assert(Superhero::getObjectCount() == 2);

        Superhero* hero3 = new Superhero("Temp Hero", 50, "Speed");
        assert(hero3->getPowerLevel() == 50);
        assert(Superhero::getObjectCount() == 3);

        delete hero3;
        assert(Superhero::getObjectCount() == 2);

        Superhero hero4("New Hero", "Strength");
        assert(hero4.getPowerLevel() == 0);
        assert(Superhero::getObjectCount() == 3);
    }

    assert(Superhero::getObjectCount() == 0);

    cout << "All tests passed successfully.\n";

    return 0;
}
