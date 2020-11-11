CC = g++ -std=c++14
FLAGS = -g -w
SDL_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
ALL = $(CC) $(FLAGS) 
exe_file = pong.exe
$(exe_file): score.o paddle.o ball.o game.o main.o
	$(ALL) score.o paddle.o ball.o game.o main.o -o $(exe_file) $(SDL_FLAGS)
score.o: score.cpp
	$(ALL) -c score.cpp $(SDL_FLAGS)
paddle.o: paddle.cpp
	$(ALL) -c paddle.cpp $(SDL_FLAGS)
ball.o: ball.cpp
	$(ALL) -c ball.cpp $(SDL_FLAGS)
game.o: game.cpp
	$(ALL) -c game.cpp $(SDL_FLAGS)
main.o: main.cpp
	$(ALL) -c main.cpp $(SDL_FLAGS)

clean:
	rm -f *.o $(exe_file)
cleanw:
	del /Q *.o $(exe_file)
