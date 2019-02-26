output: main.o Cell.o FileHandler.o Map.o Mode.o UserInterface.o 
	g++ main.o Cell.o FileHandler.o Map.o Mode.o UserInterface.o -o output


main.o: main.cpp
	g++ -c main.cpp

Cell.o: Cell.cpp
	g++ -c Cell.cpp

FileHandler.o: FileHandler.cpp
	g++ -c FileHandler.cpp

Map.o: Map.cpp
	g++ -c Map.cpp

Mode.o: Mode.cpp
	g++ -c Mode.cpp

UserInterface.o: UserInterface.cpp
	g++ -c UserInterface.cpp

clean:
	rm *.o output