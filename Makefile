CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = Inverted_Search

SRC = main.c database.c fileList.c validate.c
OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q *.o $(TARGET).exe 2>NUL || exit 0

run: $(TARGET)
	./$(TARGET)