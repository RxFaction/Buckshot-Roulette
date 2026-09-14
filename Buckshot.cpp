// Josh Jovovich
// Professor Fowler
// 9/11/26 (Begin), Last Amended: 
// Homework Assignment 1: Personalized C++ Program with Arrays, Functions, and Dynamic Memory

// Program description:
// A terminal based adaptation of Buckshot Roulette where the player faces
// a computer controlled Dealer using randomized live and blank shells.
// The program manages health, dynamically allocated shell loads,
// and cumulative session statistics through a validated menu.

// BUCKSHOT ROULETTE
// Based on one of my favorite games of all time, developed by Mike Klubnika.
// A game about chance. Are you feeling lucky?

// Play this song when engaging with The Dealer. (increases your luck by 4.8%):
// https://open.spotify.com/track/5va3Y5yIaEQ0GxESxA8eSy?si=c1a2a2322d364bc2
// https://github.com/RxFaction
// https://store.steampowered.com/app/2835570/Buckshot_Roulette/
// ^^^ Please play it :) ^^^

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib> // rand() and srand()
#include <ctime> // time()
#include <iomanip> // setw

using namespace std;

// PROTOTYPES
void ProgramGreeting();
string SignWaiver();
void ShowRules();
int GetMenuChoice();
void PlayGame(int sessionStats[]);
void ShowSessionStats(const int sessionStats[], int statCount);
int RandomNumber(int low, int high);
int LoadShells(int shells[], int shellCount);
int GetShotChoice();
void ShowReportRow(string label, int value);
void ShowReportRow(string label, string value);
void ShowMatchResults(int playerHealth, int dealerHealth);
bool AskPlayAgain();

// MAIN FUNCTION
int main()
{
    ProgramGreeting();

    string waiver = SignWaiver();

    cout << "\n=================================================================";
    cout << "\nWELCOME " << waiver
         << ". Now we can begin. May the odds ever be in your favor.\n";

    ShowRules();

    const int STAT_COUNT = 5;
    int sessionStats[STAT_COUNT] = {};
    
    int menuChoice;

    do
    {
        menuChoice = GetMenuChoice();
        switch (menuChoice)
        {
            case 1:
            do
            {
                PlayGame(sessionStats);
            } 
            while (cin && AskPlayAgain());
            break;

            case 2:
            ShowRules();
            break;

            case 3:
            ShowSessionStats(sessionStats, STAT_COUNT);
            break;

            case 4:
            cout << "\nLeaving already " << waiver << "? The Dealer will remember your fear.\n";
            break;
        }
    }

    while (menuChoice != 4);

    return 0;
}

// FUNCTION DEFINITIONS

// The greeting for the game
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

    cout << "You're drunk, in a nightclub you've never been to before.\n";
    cout << " A stranger tells you to go upstairs, and knock on the door.\n";
    cout << " You enter the room. A repurposed Roulette table sits inside, with a shotgun on it.\n";
    cout << " A briefcase with 70k in cash is opened in front of you.\n";
    cout << " A terrifying shadow entity, known only as 'The Dealer' asks you: \n";
    cout << "\n \"Are you feeling lucky?\"\n";
}

// Sign waiver text output and waiver input capture
string SignWaiver()
{
    string waiver;

    cout << "\nFirst, you must sign our General Release of Liability Waiver to play.\n";
    cout << "\nIt indicates you play this game entirely on your own volition.";
    cout << "\nThe club will NOT be held liable for any bodily harm caused to you,";
    cout << "\nup to, and including,";
    cout << "\nYOUR DEATH.\n";
    cout << " \nSign your name on the dotted line:\n";
    cin >> waiver;

    // Easter egg!! Referencing the same Easter egg in the OG game
    while (waiver == "god" || waiver == "God" || waiver == "GOD")
    {
        cout << "\nA blood soaked waiver appears, signed 'God'.\n";
        cout << "The Dealer laughs at you.\n";
        cout << "God played already, and lost.\n";
        cout << "God can't help you here.\n";
        cout << "Are you positive you want to continue?\n";
        cout << "\n*Easter egg found! Good work.*\n";
        cout << "\nChoose a different name:\n";

        cin >> waiver;

    }

    return waiver;

}

// Output of the rules for Buckshot Roulette
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

// Available user choices for the game
int GetMenuChoice()
{
    // Initially went with an int here, but that made my input validation process 
    // messy. If the user entered 2abc, it would still show 2 (show rules), but abc was
    // left to be processed still. I pivoted to a string, and use if and else if statements 
    // to validate the only 4 accepted inputs
    string choice;

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
            return 4;
        }

        // Input validation for this
        if (choice == "1")
            return 1;
        else if (choice == "2")
            return 2;
        else if (choice == "3")
            return 3;
        else if (choice == "4")
            return 4;
        
        cout << "\nThe Dealer doesn't accept your choice. Enter 1, 2, 3, or 4.";
    }
}

// Random number function
int RandomNumber (int low, int high)
{
    static bool initialized = false;

    if (!initialized)
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        initialized = true;
    }

    return low + rand() % (high - low + 1);
}

// Fills and shuffles the shellCount elements of the game
// shellCount must be >= 2
int LoadShells(int shells[], int shellCount)
{
    const int LIVE = 1;
    const int BLANK = 0;

    int liveCount = RandomNumber(1, shellCount -1);

    // Fill array
    for (int i = 0; i < shellCount; i++)
    {
        if (i < liveCount)
        {
            shells[i] = LIVE;
        }
        else
        {
            shells[i] = BLANK;
        }
    }

    // Shuffle array by swapping each position with a random pos from 0 to i
    for (int i = shellCount - 1; i > 0; i--)
    {
        int randomIndex = RandomNumber(0, i);

        int temp = shells[i];
        shells[i] = shells[randomIndex];
        shells[randomIndex] = temp;
    }

    return liveCount;
}

// Returns 1 for shooting the dealer or 2 for shooting yourself
// Returns 0 if the input stream terminates
int GetShotChoice()
{
    string choice;

    while (true)
    {
        cout << "\n1. Shoot the Dealer\n"
             << "2. Shoot yourself\n"
             <<"Choose your target: ";

        if (!(cin >> choice))
        {
            return 0;
        }

        if (choice == "1")
        {
            return 1;
        }

        if (choice == "2")
        {
            return 2;
        }

        cout << "\nThe Dealer grows impatient with you. Enter 1 or 2.";
    }
}


// Core game logic loop
void PlayGame(int sessionStats[])
{
    const int MATCHES_COMPLETED = 0;
    const int PLAYER_WINS = 1;
    const int DEALER_WINS = 2;
    const int LIVE_SHOTS = 3;
    const int BLANK_SHOTS = 4;
    
    const int MIN_HEALTH = 2;
    const int MAX_HEALTH = 4;
    const int MIN_SHELLS = 2;
    const int MAX_SHELLS = 8;
    const int LIVE = 1;

    int startingHealth = RandomNumber(MIN_HEALTH, MAX_HEALTH);
    int playerHealth = startingHealth;
    int dealerHealth = startingHealth;

    bool playerTurn = true;
    bool inputEnded = false;

    cout << "\nThe dealer slides two defibrillators onto the table, and hands you one.\n";
    cout << "\"Equal chances. See? I play fair.\"\n";

    // Load shells until someone loses
    while (playerHealth > 0 && dealerHealth > 0)
    {
        int shellCount = RandomNumber(MIN_SHELLS, MAX_SHELLS);
        int* shells = new int[shellCount];

        int liveCount = LoadShells(shells, shellCount);
        int blankCount = shellCount - liveCount;

        cout << "\nThe dealer places shells on the table.\n";
        cout << "LIVE shells: " << liveCount << '\n';
        cout << "BLANK shells: " << blankCount << '\n';
        cout << "Total shells: " << shellCount << '\n';

        cout << "\nThe Dealer loads the shells into the shotgun, in a random order.\n";
        cout << "Neither The Dealer, nor you, is aware of the load order.\n";

        int shellIndex = 0;

        // Play through this load until it empties or someone loses
        while (shellIndex < shellCount &&
               playerHealth > 0 && dealerHealth > 0)
        {
            cout << "\nYour health: " << playerHealth
                 << " | Dealer health: " << dealerHealth << '\n';

            int choice;

            if (playerTurn)
            {
                cout << "\nYour turn.\n";
                choice = GetShotChoice();

                if (choice == 0)
                {
                    inputEnded = true;
                    break;
                }
            }
            else
            {
                cout << "\nThe dealer takes the shotgun.\n";
                choice = RandomNumber(1, 2);
            }

            // 1 means shoot the opponent and 2 means shoot yourself
            bool shootSelf = (choice == 2);
            bool liveShell = (shells[shellIndex] == LIVE);

            shellIndex++;

            if (playerTurn)
            {
                if (shootSelf)
                    cout << "You aim at yourself.\n";
                else
                    cout << "You aim at the dealer.\n";
            }
            else
            {
                if (shootSelf)
                    cout << "The Dealer aims at himself.\n";
                else
                    cout << "The Dealer aims at you.\n";
            }

            if (liveShell)
            {
                sessionStats[LIVE_SHOTS]++;

                cout << "BANG! A live shell. One health point lost.\n";

                if (playerTurn)
                {
                    if (shootSelf)
                    {
                        playerHealth--;

                        if (playerHealth > 0)
                            cout << "Your defibrillator is used to revive you. Get back in the game.\n";

                        if (playerHealth == 1)
                            cout << "The Dealer leans forward. \"Careful now...\"\n";
                    }
                    else
                    {
                        dealerHealth--;

                        if (dealerHealth > 0)
                            cout << "The Dealer's defibrillator is used to revive him.\n";
                    }
                }
                else
                {
                    if (shootSelf)
                    {
                        dealerHealth--;

                        if (dealerHealth > 0)
                            cout << "The Dealer's defibrillator is used to revive him.\n";
                    }
                    else
                    {
                        playerHealth--;

                        if (playerHealth > 0)
                            cout << "Your defibrillator is used to revive you. Get back in the game.\n";

                        if (playerHealth == 1)
                            cout << "The Dealer leans forward. \"Careful now...\"\n";
                    }
                }
            }
            else
            {
                sessionStats[BLANK_SHOTS]++;

                cout << "Click! A blank.\n";
            }

            // Keep the turn only for a blank aimed at yourself
            if (shootSelf && !liveShell)
            {
                cout << "Take another turn.\n";
            }
            else
            {
                playerTurn = !playerTurn;
            }
        }

        // Release this array before reloading or leaving the game
        delete[] shells;

        if (inputEnded)
        {
            return;
        }

        if (playerHealth > 0 && dealerHealth > 0)
        {
            cout << "\nEmpty. The Dealer reaches for another load.\n";
        }
    }

    if (playerHealth > 0)
    {
        sessionStats[PLAYER_WINS]++;
        sessionStats[MATCHES_COMPLETED]++;

        cout << "\nThe Dealer falls. You survived. You are handed the briefcase full of cash.\n";
    }
    else
    {
        sessionStats[DEALER_WINS]++;
        sessionStats[MATCHES_COMPLETED]++;

        cout << "\nEverything goes dark. The Dealer wins.\n";
    }

    ShowMatchResults(playerHealth, dealerHealth);
}

// Current session stats
void ShowSessionStats(const int sessionStats[], int statCount)
{
    const string labels[] = 
    {
        "Matches completed",
        "Player wins",
        "Dealer wins",
        "Live shells fired",
        "Blank shells fired"
    };

    cout << "\nTHE DEALER'S LEDGER\n";
    cout << "Session totals since the program started.\n\n";

    cout << "+----------------------------+------------+\n";
    cout << "| " << left << setw(26) << "Statistic"
         << " | " << right << setw(10) << "Total" << " |\n";
    cout << "+----------------------------+------------+\n";

    for (int i = 0; i < statCount; i++)
    {
       ShowReportRow(labels[i], sessionStats[i]);
    }

    cout << "+----------------------------+------------+\n";
}

// Displays a labeled integer in an aligned and bordered report row
void ShowReportRow(string label, int value)
{
    cout << "| " << left << setw(26) << label << " | " << right << setw(10) << value << " |\n";
}

// Displays labeled text in the same report format
void ShowReportRow(string label, string value)
{
    cout << "| " << left << setw(26) << label << " | " << right << setw(10) << value << " |\n";
}

void ShowMatchResults(int playerHealth, int dealerHealth)
{
    string winner;

    if (playerHealth > 0)
    {
        winner = "Player";
    }
    else
    {
        winner = "Dealer";
    }

    cout << "\nTHE FINAL VERDICT\n";
    cout << "+----------------------------+------------+\n";

    ShowReportRow("Result", string("Value"));

    cout << "+----------------------------+------------+\n";

    ShowReportRow("Winner", winner);
    ShowReportRow("Your remaining health", playerHealth);
    ShowReportRow("Dealer remaining health", dealerHealth);

    cout << "+----------------------------+------------+\n";
}

// Returns true to play again, or false to return back to the menu
bool AskPlayAgain()
{
    string answer;
    
    while (true)
    {
        cout << "\nThe table is cleared, and ready for another match.\n";
        cout << "Play again? (Y = another match, N = main menu): ";

        if (!(cin >> answer))
        {
            return false;
        }

        if (answer == "y" || answer == "Y")
        {
            return true;
        }
        else if (answer == "n" || answer == "N")
        {
            return false;
        }

        // This was a fun reference back to you being drunk when you started, lol
        cout << "\nEnter Y or N. Sober up, the Dealer needs a clearer answer.\n";
    }
}