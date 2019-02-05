main:  src/main.cpp src/Board.cpp
	g++ -c src/main.cpp src/Board.cpp
sfml: src/main.o src/main.o
	g++  main.o  -o sfml-app -lsfml-graphics -lsfml-window -lsfml-window -lsfml-system
