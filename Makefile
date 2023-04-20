CC = g++ -std=c++14 -Iinclude
BUILD_FLAGS = -O3 -w -s
DEBUG_FLAGS = -Wall -g
WINDOWS = -lmingw32 -lSDL2main -DWIN
SDL_FLAGS = -lSDL2 -lSDL2_ttf
exe_file = pong.exe
out = pong.out

$(out): src/*.cpp
	$(CC) $(BUILD_FLAGS) src/*.cpp -o $(out) $(SDL_FLAGS)

debug: src/*.cpp
	$(CC) $(DEBUG_FLAGS) src/*.cpp -o $(out) $(SDL_FLAGS)

windows: src/*.cpp
	$(CC) $(BUILD_FLAGS) src/*.cpp -o $(exe_file) $(WINDOWS) $(SDL_FLAGS)

windebug: src/*.cpp
	$(CC) $(DEBUG_FLAGS) src/*.cpp -o $(exe_file) $(WINDOWS) $(SDL_FLAGS)

clean:
	rm -f *.o $(out)

cleanw:
	del /Q *.o $(exe_file)
