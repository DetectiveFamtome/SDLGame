SRC    = main.c draw/solid.c utils/utils.c
MAIN   = main.c
OBJ    = $(SRC:.c=.o)

INCL   = -I includes 

LFLAG  = $(shell pkg-config --libs sdl3)
CFLAGS = $(LFLAG) -std=c99 -pedantic  -Werror -Wall -Wextra -Wvla -fsanitize=address
CRITER = -lcriterion

COMPL  = $(EXEC) $(INCL) $(CFLAGS)

EXEC   = SLDGame

prod: $(EXEC)

$(EXEC): $(OBJ) $(MAIN:.c=.o)
	gcc $^ -o $(COMPL)

all: $(OBJ) $(TESTS:.c=.o)
	gcc $^ -o $(COMPL) $(CRITER)

%.o: %.c
	gcc -c $< -o $@ $(INCL) $(CFLAGS)

debug: $(SRC)
	gcc $^ -o $(COMPL) -g

clean:
	rm -f $(OBJ) $(EXEC)
