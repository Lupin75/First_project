AT = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
INC = -I"include"
LI = -L"lib"
CXX = g++ -std=c++17 -D_WIN32_WINNT=0x0A00
all:jump.cpp
	$(CXX) -o jump jump.cpp $(INC) $(LI) $(AT)
run:
	./jump
