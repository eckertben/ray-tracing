# Define the link target
linkTarget = qbRay

#define the libraries
LIBS = -lSDL2

#define flags
CFLAGS = -std=c++17

#define object files used
objects = main.o \
		  CApp.o \
		  $(patsubst %.cpp, %.0, $(wildard ./qbRayTrace/*.cpp))

#define the rebuildables
rebuildables = $(objects) $(linkTarget)

#rule to perform the build
$(linkTarget): $(objects)
	g++ -g -o $(linkTarget) $(objects) $(LIBS) $(CFLAGS)

#rule for the .o (object) file creations
%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS)

.PHONEY:
clean:
	rm $(rebuildables)