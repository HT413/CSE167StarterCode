CFLAGS = -g --std=c++14 -DGL_GLEXT_PROTOTYPES -DGL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
GLCCFLAGS := `pkg-config --cflags glfw3 glm glew`
GLLDFLAGS := `pkg-config --libs glfw3 glm glew`
INCFLAGS = -I/usr/X11/include $(GLCCFLAGS)
LDFLAGS = -lGL -lstdc++ $(GLLDFLAGS)

RM = /bin/rm -f

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
endif
ifeq ($(UNAME_S),Darwin)
	LDFLAGS += \
		-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo \
		-L"/System/Library/Frameworks/OpenGL.framework/Libraries"
endif


.PHONY: all
all: glfwStarterProjectBin

glfwStarterProjectBin: main.o Window.o Cube.o OBJObject.o
	$(CC) $(CFLAGS) -o glfwStarterProjectBin main.o Window.o Cube.o $(INCFLAGS) $(LDFLAGS)
main.o: Window.o main.cpp gl-inl.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c main.cpp
Window.o: Cube.o Window.cpp Window.h gl-inl.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c Window.cpp
Cube.o: Cube.cpp Cube.h gl-inl.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c Cube.cpp
OBJObject.o: OBJObject.h gl-inl.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c OBJObject.cpp
clean:
	$(RM) *.o glfwStarterProjectBin
