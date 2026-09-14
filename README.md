<img width="463" height="216" alt="image" src="https://github.com/user-attachments/assets/09932a7c-a9b2-4fbb-96cb-6e637880aeef" />


# Buckshot Roulette: C++ Edition

> A game about chance. Are you feeling lucky?

A simple, terminal-based adaptation of Mike Klubnika's **Buckshot Roulette**, developed in C++ by **Josh Jovovich**. Face the Dealer, keep track of the shells, and decide where to aim.

**No items. Just live shells, blanks, and the choices you make.**

## Development Status

The core gameplay loop is implemented and fully playable. After the ASCII title screen and name entry waiver (including a small Easter egg!), the main menu lets you play, review the rules, view the session statistics, or quit.

Games include randomized health and shell loading, player and Dealer turns, health tracking, automatic reloads, session stat tracking, and win/loss outcomes. After a game ends, you return to the main menu and can play again.

Going forward, I would eventually like to add the "Double or Nothing" mode, with items. 

## Rules

At the start of each game, you and the Dealer receive the same randomized starting health of **2–4 HP**. You take the first turn.

For each load:

- The Dealer loads **2–8 shells**, with at least one **live** shell and one **blank**.
- The live and blank counts are shown before play begins with that load.
- The shell order is randomized. You know the counts, but not what comes next.

On your turn, choose to **shoot the Dealer** or **shoot yourself**:

| Your choice | Shell | Result | What happens next? |
| --- | --- | --- | --- |
| Shoot the Dealer | Live | Dealer takes 1 damage | Your turn ends |
| Shoot the Dealer | Blank | No damage | Your turn ends |
| Shoot yourself | Live | You take 1 damage | Your turn ends |
| Shoot yourself | Blank | No damage | You take another turn |

The Dealer randomly chooses whether to shoot you or himself and follows the same damage and turn rules. Health is displayed before each shot.

When the shotgun empties and both participants are still alive, it is reloaded. Health and whose turn is next carry over, health is only reset when you start a new game.

**The goal:** reduce the Dealer's HP to **0** before yours reaches **0**. The game ends as soon as either participant runs out of health.

There are no items or inventory mechanics in this adaptation.

## Controls

- **Main menu:** enter `1` to play, `2` to view the rules, `3` to view the session statistics placeholder, or `4` to quit.
- **Your turn:** enter `1` to shoot the Dealer or `2` to shoot yourself.
- Confirm each entry with **Enter**. Invalid menu and target choices prompt you to try again.

## Running the Program

You need a C++ compiler with **C++11 or newer** support. The program uses only the C++ standard library; no external libraries are required.

1. Download or clone this repository.
2. Open `Buckshot.cpp` in a C++ IDE or an editor configured with a C++ compiler.
3. Use your environment's **Run** or **Build and Run** command.
4. Play through the terminal or console, with keyboard input enabled.

The project is shared as C++ source code. Your development environment handles compiling the source before running it.

## Project Layout

```text
Buckshot.cpp   Main program: intro, menus, rules, and core gameplay loop
README.md      Project overview and build instructions
LICENSE        MIT license
```

## Credits and License

- **C++ adaptation:** Josh Jovovich (RxFaction)
- **Original game and inspiration:** Buckshot Roulette by Mike Klubnika

This is an unofficial learning project, developed to practice C++ with arrays, functions, and dynamic memory as the game takes shape.

This repository's code is licensed under the [MIT License](LICENSE).
