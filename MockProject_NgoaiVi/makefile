CXX = g++
CXXFLAGS = -Wall -Wextra -I. -IModel -IView -IController -std=c++17 -pthread
LDFLAGS = -L. $(shell pkg-config --libs taglib SDL2_mixer) -lSDL2 -pthread

SRCS = $(wildcard Model/*.cpp View/*.cpp Controller/*.cpp Uart/*.cpp)
OBJS = $(SRCS:.cpp=.o)
LIBRARY = lib.a

MAIN_SRC = main.cpp
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)

default: music_player.exe sclean

$(LIBRARY): $(OBJS)
	ar rcs $@ $^

$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

music_player.exe: $(MAIN_OBJ) $(LIBRARY)
	$(CXX) -o $@ $(MAIN_OBJ) $(LIBRARY) $(LDFLAGS)

run:
	clear
	./music_player.exe

# Xóa tất cả các file .o
sclean:
	rm -f $(OBJS) $(MAIN_OBJ) $(LIBRARY)

# Xóa tất cả file tạm và chương trình
clean: sclean
	rm -f $(LIBRARY) music_player.exe
