AT = -lsfml-system -lsfml-audio
CXX = g++ -std=c++17
FLAGS = -c -std=c++17
INC = -I"resources/externalDependencies/include"
LI = -L"resources/externalDependencies/lib"
game:story.o
	$(CXX) story.o -o BUILD/game  $(INC) $(LI) $(AT)
story.o:story.cpp
	$(CXX) $(FLAGS) story.cpp $(INC) $(LI) $(AT)
run:
	./BUILD/game