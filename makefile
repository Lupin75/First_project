AT = -lsfml-system -lsfml-audio
CXX = g++ -std=c++17
INC = -I"resources/externalDependencies/include"
LI = -L"resources/externalDependencies/lib"
story.o:story.cpp
	$(CXX) story.cpp $(INC) $(LI) $(AT) -o ./BUILD/game
run:
	./BUILD/game