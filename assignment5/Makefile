CC = g++
SRCS = $(wildcard ./src/*.cpp)
SRCS += $(wildcard ../vecmath/src/*.cpp)
OBJS = $(SRCS:.cpp=.o)
PROG = a5
CFLAGS = -O2 -Wall -Wextra -g
INCFLAGS = -I../vecmath/include

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LINKFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -c -o $@ $(INCFLAGS)

clean:
	rm -f *.bak vecmath/src/*.o ./src/*.o core.* $(PROG) 
