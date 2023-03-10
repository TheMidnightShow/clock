CC=g++
CCFLAGS=-std=c++20

O=./objects
SRC=../clock

OBJ=							\
		$(O)/main.o		\
		$(O)/clock.o	\

clock: $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $@

$(O)/%.o: $(SRC)/%.cpp
	$(CC) $(CCFLAGS) -c $< -o $@
