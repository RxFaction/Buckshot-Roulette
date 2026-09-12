// Josh Jovovich
// Professor Fowler
// 9/11/26 (Begin), Last Amended: 
// Homework Assignment 1: Personalized C++ Program with Arrays, Functions, and Dynamic Memory

// BUCKSHOT ROULETTE
// Based on one of my favorite games, developed by Mike Klubnika.
// A game about chance. Are you feeling lucky?
// https://github.com/RxFaction
// https://store.steampowered.com/app/2835570/Buckshot_Roulette/
// ^^^ Please play it :) ^^^

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Prototypes
void ProgramGreeting();
string SignWaiver();
void ShowRules();
int GetMenuChoice();
void PlayGame();
void ShowSessionStats();

int main()
{
    ProgramGreeting();

    string waiver = SignWaiver();

    cout << "\nWELCOME " << waiver
         << ". Now we can begin. May the odds ever be in your favor.\n";

    ShowRules();

    int menuChoice;

    do
    {
        menuChoice = GetMenuChoice();
        switch (menuChoice)
        {
            case 1:
            PlayGame();
            break;

            case 2:
            ShowRules();
            break;

            case 3:
            ShowSessionStats();
            break;

            case 4:
            cout << "\nLeaving already " << waiver << "? The Dealer will remember your fear.\n";
            break;
        }
    }

    while (menuChoice != 4);

    return 0;
}

// Function Definitions

void ProgramGreeting()
{
        cout << R"(
 ============================================================

  BBBB   U   U   CCCC  K   K   SSSS  H   H   OOO   TTTTT
  B   B  U   U  C      K  K   S      H   H  O   O    T
  BBBB   U   U  C      KKK     SSS   HHHHH  O   O    T
  B   B  U   U  C      K  K       S  H   H  O   O    T
  BBBB    UUU    CCCC  K   K  SSSS   H   H   OOO     T

  RRRR    OOO   U   U  L      EEEEE  TTTTT  TTTTT  EEEEE
  R   R  O   O  U   U  L      E        T      T    E
  RRRR   O   O  U   U  L      EEEE     T      T    EEEE
  R  R   O   O  U   U  L      E        T      T    E
  R   R   OOO    UUU   LLLLL  EEEEE    T      T    EEEEE

               [ LIVE ]          [ BLANK ]

            C++ Adaptation by Josh Jovovich
             Original game by Mike Klubnika
                 A game about chance.

 ============================================================
 )";

    cout << "\nAre you feeling lucky?\n";
}

string SignWaiver()
{
    string waiver;

    cout << "\nFirst, you must sign our waiver to play. Enter your name:\n";
    cin >> waiver;

    while (waiver == "god" || waiver == "God")
    {
        cout << "\nA blood soaked waiver appears, signed 'God'.\n";
        cout << "God played already, and lost.\n";
        cout << "Are you positive you want to continue?\n";
        cout << "\n*Easter egg found! Good work.*\n";
        cout << "\nChoose a different name:\n";

        cin >> waiver;
    }

    return waiver;
}

void ShowRules()
{
    cout << "\nHere are the rules. Read them very carefully, your survival depends on it.\n";

    cout  << "\nRULES:\n"
          << "1. At the start of each round, the Dealer will load a shotgun\n"
          << "   with a known number of LIVE and BLANK shells.\n"
          << "2. The exact sequence of the shells is randomized.\n"
          << "3. The starting health will be randomized each round.\n\n"
          << "ON YOUR TURN, YOU CAN:\n"
          << " - Shoot the Dealer:\n"
          << "   * Live Shell  : Deals 1 damage. Turn ends.\n"
          << "   * Blank Shell : No damage. Turn ends.\n\n"
          << " - Shoot Yourself:\n"
          << "   * Live Shell  : Deals 1 damage to YOU. Turn ends.\n"
          << "   * Blank Shell : No damage. YOU TAKE ANOTHER TURN!\n\n"
          << "GOAL:\n"
          << " Clear the shotgun, survive, and reduce\n"
          << " the Dealer's HP to 0 to win.\n\n"
          << " Simple. Right?\n\n";
}

int GetMenuChoice()
{
    int choice;

    cout << "\n========== THE DEALER'S TABLE ==========\n"
         << "1. Play\n"
         << "2. View Rules\n"
         << "3. View Session Statistics\n"
         << "4. Quit\n"
         << "========================================\n";

    while (true)
    {
        cout << "\nChoose an option (1-4): ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "The Dealer expects a number. Enter 1 through 4.\n";
        }
        else if (choice < 1 || choice > 4)
        {
            cout << "That option isn't on the table. Enter 1 through 4.\n";
        }
        else
        {
            return choice;
        }
    }
}

void PlayGame()
{
    cout << "\nThe Dealer is preparing the table. Gameplay coming soon.\n";
}

void ShowSessionStats()
{
    cout << "\nNo session statistics yet. Check back after gameplay is added.\n";
}

