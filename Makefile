CC = g++-4.9 -std=c++11
CXXFLAG = -O0 -Wall -Wextra -W -ggdb3 -DDEBUG -ftemplate-depth=9000
SRC = $(wildcard *.cpp)
SRC_OBJ	= $(SRC:%.cpp=%.out)

all: $(SRC_OBJ)

%.out: %.cpp
	$(CC) $< -o $@ $(CXXFLAG)
	
clean:
	rm -f *.out

rebuild: clean all

.PHONY:	clean rebuild all
