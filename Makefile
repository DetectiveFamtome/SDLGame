SRC := main.c draw/solid.c
LIB := $(sdl2-config --cflags --libs) -lSDL2
FLAGS :=-Wall -Wextra -Werror -fsanitize=address

all:
	gcc $(SRC) -o SDLGames $(LIB) $(FLAGS)