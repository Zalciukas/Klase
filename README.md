# Superhero Class

## Overview
The `Superhero` class models a superhero with attributes like name, power level, and ability. It tracks instances, assigns unique IDs, and ensures power levels remain non-negative.

## Features
- Unique ID for each superhero.
- Non-negative power level enforcement.
- Tracks active superhero instances.
- Stores all created superheroes.
- Automatic cleanup on destruction.

## Public Methods
- `Superhero(string n, int p, string a)`: Constructor with power level.
- `Superhero(string n, string a)`: Constructor (power level defaults to 0).
- `~Superhero()`: Destructor updates object count.
- `string toString() const`: Returns superhero details.
- `static int getObjectCount()`: Returns active instances.
- `static int getNextID()`: Returns next available ID.

## Usage Example
```cpp
Superhero hero1("Iron Guardian", -100, "Flight");
hero1.setPowerLevel(120);
cout << hero1.toString() << endl;
```

## Testing
The `main()` function verifies:
- Correct object count updates.
- Non-negative power levels.
- Proper ID assignment.

If successful, prints:
```
All tests passed successfully.
```

## Notes
- No deep copy mechanism implemented.
- Ensure proper memory management.
