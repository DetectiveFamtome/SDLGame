SRC    = main.c draw/solid.c
MAIN   = main.c
OBJ    = $(SRC:.c=.o)

LFLAG  = -lSDL2 $(pkg-config sdl2 --cflags)
CFLAGS = $(LFLAG) -std=c99 -pedantic -fsanitize=address -Werror -Wall -Wextra -Wvla 
CRITER = -lcriterion

EXEC   = Game


prod: $(OBJ) $(MAIN:.c=.o)
	gcc $^ -o $(EXEC) $(CFLAGS)

all: $(OBJ) $(TESTS:.c=.o)
	gcc $^ -o $(EXEC) $(CFLAGS) $(CRITER)

%.o: %.c
	gcc -c $< -o $@ $(CFLAGS) 

debug: $(SRC)
	gcc $^ -o $(EXEC) $(CFLAGS) -g

clean:
	rm -f $(OBJ) $(EXEC)
