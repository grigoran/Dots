INCLPATH=DotsSource/headers
SRCPATH=DotsSource/sources

ADDEPENCE=-lsfml-system\
		-lsfml-graphics\
		-lsfml-window

vpath %.cpp $(SRCPATH)
vpath %.h $(INCLPATH)

all: build


dbg: $(SRCPATH)/*.cpp
	g++ -g $^ -I $(INCLPATH) $(ADDEPENCE) -o Dots
	gdb Dots
 
build: $(SRCPATH)/*.cpp
	g++ $^ -I $(INCLPATH) $(ADDEPENCE) -o Dots


 
exec: build
	./Dots

