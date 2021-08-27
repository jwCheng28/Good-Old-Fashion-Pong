CC = g++ -std=c++14 -Iinclude
BUILD_FLAGS = -O3 -w
DEBUG_FLAGS = -Wall -g
WINDOWS = -lmingw32
SDL_FLAGS = -lSDL2main -lSDL2 -lSDL2_ttf
exe_file = pong.exe

$(exe_file): src/*.cpp
	$(CC) $(BUILD_FLAGS) src/*.cpp -o $(exe_file) $(SDL_FLAGS)

debug: src/*.cpp
	$(CC) $(DEBUG_FLAGS) src/*.cpp -o $(exe_file) $(SDL_FLAGS)

windows: src/*.cpp
	$(CC) $(BUILD_FLAGS) src/*.cpp -o $(exe_file) $(WINDOWS) $(SDL_FLAGS)

windebug: src/*.cpp
	$(CC) $(DEBUG_FLAGS) src/*.cpp -o $(exe_file) $(WINDOWS) $(SDL_FLAGS)

clean:
	rm -f *.o $(exe_file)

cleanw:
	del /Q *.o $(exe_file)
