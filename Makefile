CMP = g++
SRC = ./src
EXEC = stars
FLAGS = -lncursesw
INCLUDE = ./include
OBJ = ./obj

all:
	cd $(OBJ) && $(CMP) -c -I.$(INCLUDE) .$(SRC)/*.cpp $(FLAGS)
	$(CMP) -o $(EXEC) $(OBJ)/*.o $(FLAGS)
	xterm -e ./$(EXEC)

obj:
	cd $(OBJ) &&	$(CMP) -c -I.$(INCLUDE) .$(SRC)/*.cpp $(FLAGS)

clean:
	rm $(OBJ)/*.o
	rm $(EXEC)
