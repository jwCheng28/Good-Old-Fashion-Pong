# Good Old Fashion Pong
As the title suggest, this project that aims to recreated the classic Pong Game.

## What it currently looks like
![GIF](./gifs/demo_ai.gif)

## Try It Out
Windows:
 - If you're using windows and you have mingw installed, you can compile the program with `mingw32-make` and run the executable `pong.exe`
 - If you don't have mingw, you can compile the program manually with `g++ -std=c++14 -Iinclude -w -O3 src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -o pong.exe`

Linux:
 - If you're using linux, simply use `make` and ran the executable `pong.exe`

## To Do
- Different Modes
