INCFLAGS  = -I ../GL
INCFLAGS += -I ../vecmath/include

LINKFLAGS  = -lGL -lglut -lGLU
#LINKFLAGS += -L ./include/vecmath -lvecmath

CFLAGS    = -O2 -g
CC        = g++
SRCS      = main.cpp
SRCS += $(wildcard ../vecmath/src/*.cpp)
OBJS      = $(SRCS:.cpp=.o)
PROG      = a0

all: $(SRCS) $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCFLAGS) $(LINKFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -c -o $@ $(INCFLAGS)

depend:
	makedepend $(INCFLAGS) -Y $(SRCS)

clean:
	rm $(OBJS) $(PROG)

