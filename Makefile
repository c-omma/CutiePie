CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

TARGET = cutie
SOURCES = 	main.cpp \
			controller/game.cpp controller/level_state.cpp controller/menu_state.cpp \
			model/classes/typeable.cpp \
			model/states/level.cpp model/states/menu.cpp \
			view/background.cpp view/floatable.cpp view/text.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)
	
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run