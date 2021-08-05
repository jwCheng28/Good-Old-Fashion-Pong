CC = g++ -std=c++14 -Iinclude -w -O3
SDL_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
exe_file = pong.exe

$(exe_file): src/*.cpp
	$(CC) src/*.cpp -o $(exe_file) $(SDL_FLAGS)

clean:
	rm -f *.o $(exe_file)

cleanw:
	del /Q *.o $(exe_file)
