# TankSimulator2D

![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)  [![Ubuntu](https://github.com/ArthurBandaryk/TankSimulator2D/actions/workflows/build.yml/badge.svg)](https://github.com/ArthurBandaryk/TankSimulator2D/actions/workflows/build.yml)

This repo contains a game prototype of 2D tank which is going to be checked as a test task for "C++ game developer course".

## Keypad management

```
w - move up
a - move left
s - move down
d - move right
space - shooting
```

## Building project

In order to build this project just go to the `root` of this workspace and run:
```
./build_game.sh
```
This bash script will automatically create `build` directory if it doesn't exist, run `cmake` commands, which will configure the project, generate a native build system and then build this project.

## Run game

To run this game just type the following command from the root space:
```
./build/game
```
