CPP_FILES := $(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp)
OBJ_FILES := $(notdir $(CPP_FILES:.cpp=.o)))
OBJ_FILES := $(patsubst %.cpp,%.o,$(CPP_FILES))
CC_FLAGS := -std=c++11
INCLUDE_DIR :=-Iwpilib 

main.exe: $(OBJ_FILES)
	g++ $(LD_FLAGS) -o $@ $^

%.o: %.cpp
	g++ $(INCLUDE_DIR) -std=c++11 -c -o $@ $<