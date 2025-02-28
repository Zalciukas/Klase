# Superhero Class

## Overview
The `Superhero` class models a superhero with attributes such as name, power level, and special ability. It maintains a count of active superhero objects and assigns unique IDs to each instance. Additionally, a static list tracks all created superheroes.

## Features
- **Unique ID Assignment**: Each superhero instance gets a unique, incrementing ID.
- **Power Level Management**: Ensures power level is always non-negative.
- **Static Object Count**: Tracks the number of active superhero objects.
- **List of Superheroes**: Stores references to all created superheroes.
- **Automatic Cleanup**: Updates the object count and removes the superhero from the list upon destruction.

## Class Members

### Private Attributes
- `name` (string): The superhero's name.
- `ability` (string): The superhero's special power.
- `powerLevel` (int): The hero's power level (non-negative).
- `id` (int): Unique identifier for each instance.
- `static int objectCount`: Tracks the number of active superhero instances.
- `static int highestID`: Keeps track of the highest ID assigned.
- `static vector<Superhero*> superheroList`: Stores pointers to active superhero instances.

### Public Methods
- `Superhero(string n, int p, string a)`: Constructor that initializes a superhero with a name, power level, and ability.
- `Superhero(string n, string a)`: Constructor that initializes a superhero with a name and ability (default power level is 0).
- `~Superhero()`: Destructor that decreases object count and removes the superhero from the list.
- `string getName() const`: Returns the superhero's name.
- `string getAbility() const`: Returns the superhero's ability.
- `int getPowerLevel() const`: Returns the superhero's power level.
- `void setPowerLevel(int p)`: Sets the superhero's power level (ensures it's non-negative).
- `string toString() const`: Returns a formatted string representation of the superhero.
- `static int getObjectCount()`: Returns the number of active superhero instances.
- `static int getNextID()`: Returns the next available ID.

## Usage Example
```cpp
Superhero hero1("Iron Guardian", -100, "Flight");
cout << hero1.toString() << endl; // Outputs: Iron Guardian,1,0,Flight

hero1.setPowerLevel(120);
cout << hero1.getPowerLevel() << endl; // Outputs: 120

Superhero hero2("Shadow Phantom", 80, "Invisibility");
cout << Superhero::getObjectCount() << endl; // Outputs: 2
```

## Testing
The `main()` function contains assertions that verify:
- Object count updates correctly when superheroes are created and destroyed.
- Power level cannot be negative.
- Unique IDs are assigned properly.
- The `toString()` method returns the correct format.

If all tests pass, the program prints:
```
All tests passed successfully.
```

## Notes
- The class manages memory for dynamically allocated superheroes but does not implement a deep copy mechanism.
- Ensure proper cleanup of dynamically allocated objects to prevent memory leaks.
- The class uses a static vector to store all superheroes, which allows tracking but does not provide advanced search functionality.

## License
This project is open-source and free to use and modify.
