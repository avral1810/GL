CXX=g++
LDIR=./lib
GLmake: Sources/*.cpp main.cpp
	$(CXX)  -lglew -lglfw -framework OpenGL -framework GLUT -I Headers/ -I  Sources/*.cpp main.cpp -o main