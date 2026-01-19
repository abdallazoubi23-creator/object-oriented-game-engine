# ⚔️ Mtmchkin: C++ Object-Oriented RPG Engine

A robust, text-based Role-Playing Game (RPG) engine built from scratch in C++. This project serves as a comprehensive demonstration of **Object-Oriented Programming (OOP)** principles, modern C++ memory management, and advanced design patterns.

## 🚀 Key Technical Features

### 1. Advanced Polymorphism & Inheritance
The game relies heavily on polymorphic hierarchies to manage diverse game entities uniformly:
* **Card Hierarchy:** An abstract base class `Card` derives into specialized types like `Encounter`, `Event`, and `Treasure`.
* **Player Hierarchy:** The abstract `Player` class defines the interface, while derived classes `Warrior` and `Sorcerer` implement unique combat calculations and special abilities.
* **Heterogeneous Collections:** The game deck is managed as a `std::deque<std::shared_ptr<Card>>`, allowing the engine to process any card type generically at runtime.

### 2. Group Strategy & Composite Logic (Gangs)
Beyond individual threats, the game implements a **Group Strategy** mechanic using a Composite-like structure:
* **The Gang System:** The `Gang` class aggregates multiple `Monster` objects into a single cohesive unit.
* **Aggregate Logic:** The game treats a Gang as a single `Encounter`, automatically summing the power, loot, and damage of all its member monsters. This allows complex "Swarm" behaviors without changing the core combat loop.

### 3. Modern Memory Management (Smart Pointers)
Manual memory management (`new`/`delete`) is entirely replaced by **Smart Pointers** to ensure memory safety and prevent leaks:
* **`std::shared_ptr`**: Used extensively for sharing game objects (Players, Cards) between different game systems without copying overhead.
* **Automatic Cleanup:** The `Gang` class manages a dynamic group of monsters using `std::vector<std::shared_ptr<Monster>>`, ensuring all resources are freed automatically when a gang is defeated.

### 4. Design Patterns
* **Strategy Pattern:** Implemented in the `Behavior` system. Players are composed with a `Behavior` object (e.g., `RiskTaking`, `Responsible`), allowing their decision-making logic to be swapped dynamically at runtime without changing the `Player` class.
* **Composite Pattern:** Used in the `Gang` implementation to treat a group of Monsters as a single logical entity during combat calculation.

## 🛠️ Architecture Overview

### The Game Loop
The `Mtmchkin` class acts as the Game Manager. It initializes the deck and players, tracks the turn count, and executes the main loop:
1.  **Draw Card:** A card is drawn from the polymorphic deck.
2.  **Apply Effect:** The card interacts with the current `Player` via double-dispatch or virtual methods (e.g., `combat`, `solarEclipse`).
3.  **Update State:** Player stats (HP, Coins, Level) are updated based on the outcome.

### Class Structure
```text
Card (Abstract)
├── Event
│   ├── SolarEclipse
│   └── PotionsMerchant
└── Encounter
    ├── Monster (Goblin, Giant, Dragon)
    └── Gang (Composite: Collection of Monsters)

Player (Abstract)
├── Warrior (Bonus combat power)
└── Sorcerer (Bonus magic power)
```
## 💻 How to Build and Run
Clone the repository:

Bash

git clone [https://github.com/your-username/mtmchkin-cpp-rpg.git](https://github.com/your-username/mtmchkin-cpp-rpg.git)
Compile:

Bash

g++ -std=c++11 -o mtmchkin *.cpp
Run:
Bash
./mtmchkin deck.txt players.txt
## 👨‍💻 Author
Abdalla Zoubi
