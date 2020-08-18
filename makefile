INCLPATH=DotsSource/headers
SRCPATH=DotsSource/sources

vpath %.cpp $(SRCPATH)
vpath %.h $(INCLPATH)

OBJS =  \
 Source.o \
 Dot.o \
 Field.o

all: Dots
 
exec: Dots
	./Dots

Dots: $(OBJS)
	g++ $^ -o Dots  -lsfml-system -lsfml-graphics -lsfml-window 
	rm *.o
%.o : %.cpp
	g++ -c $< -I $(INCLPATH)
