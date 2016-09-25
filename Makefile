CFLAGS = -g -DGL_GLEXT_PROTOTYPES -DGL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED -DOSX
GLCCFLAGS := `pkg-config --cflags glfw3 glm glew`
GLLDFLAGS := `pkg-config --libs glfw3 glm glew`
INCFLAGS = -I/usr/X11/include $(GLCCFLAGS)
LDFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo \
		-L"/System/Library/Frameworks/OpenGL.framework/Libraries" \
		-lGL -lstdc++ $(GLLDFLAGS)

RM = /bin/rm -f

.PHONY: all
all: glfwStarterProjectBin

glfwStarterProjectBin: main.o Window.o Cube.o
	$(CC) $(CFLAGS) -o glfwStarterProjectBin main.o Window.o Cube.o $(INCFLAGS) $(LDFLAGS)
main.o: Window.o main.cpp main.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c main.cpp
Window.o: Cube.o Window.cpp Window.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c Window.cpp
Cube.o: Cube.cpp Cube.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c Cube.cpp
clean:
	$(RM) *.o glfwStarterProjectBin
