LIBS = -lSDL2 -lSDL2_ttf -lSDL2_image 
OBJS = $(addprefix $(OBJDIR)/,main.o keyboard.o)
OBJDIR = objs
FLAGS = -Wall

.PHONY: clean

main: $(OBJS)
	g++ $^ -o main $(LIBS)

$(OBJDIR)/main.o: src/main.cpp
	g++ -c -I include $< -o $@ $(FLAGS)

$(OBJDIR)/keyboard.o: include/keyboard.cpp include/keyboard.h
	g++ -c $< -o $@

clean:
	rm $(OBJS) -v
