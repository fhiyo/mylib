OBJDIR := objs
CC := g++-5
CFLAGS := -Wall -O2 -std=gnu++1y

SRCS := main.cpp Graph.cpp Traversal.cpp test_traversal.cpp BinarySearch.cpp SieveOfEratosthenes.cpp
OBJS := $(SRCS:%.cpp=%.o)

sample: sample.cpp
	@$(CC) $(CFLAGS) -o sample sample.cpp

main: $(OBJS)
	@$(CC) $(CFLAGS) -o main $(OBJS)

main.o: main.cpp
	@$(CC) $(CFLAGS) -c main.cpp

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $<

clean:
	rm main $(OBJS)

.PHONY:
	all clean
