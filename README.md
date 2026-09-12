# Buckshot Roulette — C++ Edition

> A game about chance. Are you feeling lucky?

A simple, terminal-based adaptation of Mike Klubnika's **Buckshot Roulette**, developed in C++ by **Josh Jovovich**. Face the Dealer, keep track of the shells, and decide where to aim.

**No items. Just live shells, blanks, and the choices you make.**

## Development Status

This project is a work in progress. The current version displays an ASCII title screen, asks you to sign a waiver, welcomes you by name, and explains the rules. It also includes a small name-entry Easter egg.

The playable turn system, randomized shell loading, health tracking, and Dealer behavior are still to be implemented. The rules below describe the intended game.

## Rules

At the start of each round:

- The Dealer loads a shotgun with a known number of **live** and **blank** shells.
- The shell order is randomized. You know the counts, but not what comes next.
- Starting health is randomized for the round.

On your turn, choose to **shoot the Dealer** or **shoot yourself**:

| Your choice | Shell | Result | What happens next? |
| --- | --- | --- | --- |
| Shoot the Dealer | Live | Dealer takes 1 damage | Your turn ends |
| Shoot the Dealer | Blank | No damage | Your turn ends |
| Shoot yourself | Live | You take 1 damage | Your turn ends |
| Shoot yourself | Blank | No damage | You take another turn |

**The goal:** clear the shotgun, survive, and reduce the Dealer's HP to **0** to win.

There are no items or inventory mechanics in this adaptation.

## Running the Program

You need a C++ compiler with **C++11 or newer** support. The program uses only the C++ standard library; no external libraries are required.

1. Download or clone this repository.
2. Open `Buckshot.cpp` in a C++ IDE or an editor configured with a C++ compiler.
3. Use your environment's **Run** or **Build and Run** command.
4. Play through the terminal or console, with keyboard input enabled.

The project is shared as C++ source code. Your development environment handles compiling the source before running it.

## Project Layout

Buckshot.cpp   Main program: title screen, waiver, and rules
README.md      Project overview and build instructions
LICENSE        MIT license
```

## Credits and License

- **C++ adaptation:** Josh Jovovich (RxFaction)
- **Original game and inspiration:** Buckshot Roulette by Mike Klubnika

This is an unofficial learning project, developed to practice C++ with arrays, functions, and dynamic memory as the game takes shape.

This repository's code is licensed under the [MIT License](LICENSE).
