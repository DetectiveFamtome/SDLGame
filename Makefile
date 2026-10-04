SRC    = main.c draw/solid.c utils/utils.c
MAIN   = main.c
OBJ    = $(SRC:.c=.o)

INCL   = -I includes 

LFLAG  = $(shell pkg-config --libs sdl3)
CFLAGD = -fsanitize=address
CFLAGS = $(LFLAG) -std=c99 -pedantic -Werror -Wall -Wextra -Wvla 
CRITER = -lcriterion

EXEC   = SLDGame
EDEV   = $(EXEC)-dev.out
FINAL  = $(EXEC).out
TEST   = $(EXEC)-test.out

COMPL  = $(INCL) $(CFLAGS)

dev: $(EDEV)

prod: $(FINAL)

test: $(TEST)

$(EDEV): $(OBJ) $(MAIN:.c=.o)
	gcc $^ -o $@ $(COMPL) $(CFLAGD)

$(FINAL): $(OBJ) $(MAIN:.c=.o) 
	gcc $^ -o $@ $(COMPL)

$(TEST): $(OBJ) $(TESTS:.c=.o)
	gcc $^ -o $@ $(COMPL) $(CRITER)

%.o: %.c
	gcc -c $< -o $@ $(COMPL)

debug: $(SRC)
	gcc $^ -o $@ $(COMPL) -g

clean:
	rm -f $(OBJ) $(EXEC)*
