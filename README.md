# GL
To run using C++ in Mac

1. Download Homebrew
	
	/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

2. Make sure you have xcode command line tools installed

	if not use the following command

	sudo xcode-select --install

	put in your password

3. Install glfw and glew using brew commands
	

	brew install glfw

	brew install glew

	This will install glfw3 and glew to /usr/Local/Cellar/ (default dir for homebrew)


4. Create a softlink to glfw and glew from step 2 into you project.  ./lib/

	ln -s /usr/Local/Cellar/glfw/{version}/lib/libglfw{version}.dylib

	ln -s /usr/Local/Cellar/glew/{version}/lib/libglew{version}.dylib

	example if you have glfw version 3.3.2 and glew version 2.2.0

	ln -s /usr/Local/Cellar/glfw/3.2.2/lib/libglfw.3.3.dylib

	ln -s /usr/Local/Cellar/glfw/2.2.0/lib/libglew.2.2.0.dylib

	Make sure to run this command from your project directory


5. Compile using 

	g++ main.cpp -std=c++11 -o test.o -c

	Link Using 

	g++ test.o -std=c++11 -lglew -lglfw -framework OpenGL -framework GLUT -o ans 

	or in one line

	g++ main.cpp -std=c++11 -lglew -lglfw -framework OpenGL -framework GLUT -o ans