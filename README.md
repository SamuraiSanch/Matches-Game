# 🔥 100 Matches Game

A classic two-player console game built in C++ where you compete against the computer. Strategy and luck decide the winner!

## 📋 Description

**100 Matches** is a turn-based strategy game. A pile starts with 100 matches — you and the computer take turns picking between 1 and 10 matches. The player who takes the **last match loses**.

The computer's moves are powered by a random number generator (`std::mt19937`), making each game unpredictable.

## 🎯 Gameplay Rules

- The pile starts with **100 matches**
- Each turn, a player picks **1 to 10** matches
- You cannot take more matches than what remains in the pile
- The player who takes the **last match loses**
- After each game, you can choose to play again

## 🛠️ Technologies

- **C++11**
- **OOP:** `Game` class with encapsulated state
- **`<random>`:** `std::mt19937` + `std::uniform_int_distribution` for fair random generation
- **Input validation:** `std::cin.fail()` handling with recovery via `cin.clear()` / `cin.ignore()`

## 🚀 How to Run

### Compilation (GCC/Clang):
```bash
g++ -std=c++11 100-matches-game.cpp -o 100-matches-game
./100-matches-game
```

### Compilation (Visual Studio):
1. Open the project in Visual Studio
2. Press `F5` (Run)

## 📂 Project Structure
```
100-matches-game/
└── 100-matches-game.cpp    # Full game logic
```

## 📋 Example Usage

```
We have now 100 matches.
How much matches do you want to take?: 7
Computer takes... 4 matches

We have now 89 matches.
How much matches do you want to take?: 10
Computer takes... 8 matches
...
Computer wins. AI > human now...

Thanks for playing! Do you want to play again? (Y)es, (N)o: Y
```

## 🔧 Future Improvements

- [ ] Smart computer AI (optimal strategy instead of random)
- [ ] Configurable pile size and max pick limit
- [ ] Score tracking across multiple rounds
- [ ] Multiplayer (two human players)
- [ ] GUI version

## 👤 Author

**Oleksandr Kopii**  
GitHub: [@SamuraiSanch](https://github.com/SamuraiSanch)

---

⭐ If you enjoyed this project, feel free to leave a star!
