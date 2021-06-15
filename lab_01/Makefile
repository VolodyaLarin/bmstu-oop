CPP = g++

TARGET = app.exe
LIBRIES =  -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS = -Wall -Wextra -Werror

SRCS = 	src/main.cpp \
		src/io.cpp \
		src/project.cpp \
		src/rotate.cpp \
		src/scale.cpp \
		src/translate.cpp \
		src/drawer.cpp \
		src/model.cpp 


HDRS_DIR = inc/

.PHONY:all clean

all: app.exe

app.exe: $(SRCS)
	$(CPP) -o $(TARGET) $(CFLAGS) $(SRCS) $(LIBRIES) -I $(HDRS_DIR) -O2

debug.exe: $(SRCS)
	$(CPP) -o debug.exe $(CFLAGS) $(SRCS) $(LIBRIES) -I $(HDRS_DIR) -g -ggdb 

clean:
	rm -rf $(TARGET) *.gcov *.gcda *.gcno *.exe
