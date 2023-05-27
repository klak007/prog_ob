CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = wektor.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = wektor

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
