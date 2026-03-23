#include <iostream>
#include <random>

class Game {
private:
    int m_generalMatches;
public:
    Game(const int generalMatches = 100) : m_generalMatches(generalMatches) {}
    void pickUpMatches(const int matches) {
        m_generalMatches -= matches;
        if (m_generalMatches < 0)
            m_generalMatches = 0;
    }
    bool checkWin() {
        return m_generalMatches == 0;
    }
    int getMatches() const {
        return m_generalMatches;
    }
};

int generateNumberToTakeMatches(const int min = 1, const int max = 10) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

int userInputNumberOfMatches(const int minMatchesToTake = 1, const int maxMatchesToTake = 10, const int remainingMatches = 100) {
    int number;
    int maxAllowed = std::min(maxMatchesToTake, remainingMatches);

    do {
        std::cin >> number;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Error. You must enter a number.\n";
            number = -1;
            continue;
        }
        else if (number < minMatchesToTake || number > maxAllowed) {
            std::cerr << "Error. Enter number between " << minMatchesToTake << " && " << maxAllowed << '\n';
            continue;
        }
    } while (number < minMatchesToTake || number > maxAllowed);

    return number;
}

int computerTakeMatches(const int remainingMatches) {
    int take = generateNumberToTakeMatches();
    if (take > remainingMatches)
        take = remainingMatches;
    return take;
}


void playGame() {
    Game newGame;
    bool isPlayerWinner = false;
    while (true) {
        std::cout << "We have now " << newGame.getMatches() << " matches.\n"
            << "How much matches do you want to take?: ";

        newGame.pickUpMatches(userInputNumberOfMatches(1, 10, newGame.getMatches()));
        if (newGame.checkWin())
            break;

        int computerTake = computerTakeMatches(newGame.getMatches());
        newGame.pickUpMatches(computerTake);
        std::cout << "Computer takes... " << computerTake << " matches \n";

        if (newGame.checkWin()) {
            isPlayerWinner = true;
            break;
        }
    }

    if (isPlayerWinner)
        std::cout << "You win! Congratulations!!!\n";
    else
        std::cout << "Computer wins. AI > human now...\n";
}
int main()
{
    char answer;
    do {
        playGame();
        do {
            std::cout << "Thanks for playing! Do you want to play again? (Y)es, (N)o: ";
            std::cin >> answer;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Error. You must enter right answer.\n";
                answer = ' ';
                continue;
            }
        } while (answer != 'N' && answer != 'Y');
    } while (answer != 'N');

    return 0;
}
