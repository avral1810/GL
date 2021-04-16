CXX=g++
LDIR=./lib
GLmake: Sources/*.cpp main.cpp
	$(CXX) -std=c++11 -lglew -lglfw -framework OpenGL -framework GLUT -I Headers/ Sources/*.cpp main.cpp -o main