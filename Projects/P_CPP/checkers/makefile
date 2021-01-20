#Based on https://opensource.com/article/18/8/what-how-makefile

SRCS := $(wildcard *.cpp)
OBJ := $(SRCS:%.cpp=%.o)

.PHONY = all run clean

all: ${OBJ}
	@echo "Linking"
	$(LINUX_GCC) -g -o ./main.out ${OBJ}

run: all
	@echo "Running"
	@./main.out

%.o: %.cpp %.h
	g++ -c $<

clean:
	@echo "Cleaning"
	rm *.out
	rm *.o