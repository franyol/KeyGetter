LIBS = -lSDL2
OBJS = $(addprefix $(OBJDIR)/,main.o)
OBJDIR = objs
FLAGS = -Wall

.PHONY: clean

main: $(OBJS)
	g++ $^ -o main $(LIBS)

$(OBJDIR)/main.o: src/main.cpp
	g++ -c $< -o $@ $(FLAGS)

clean:
	rm $(OBJS) -v
