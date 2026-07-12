CC = gcc

CFLAGS = -Wall -g

TARGET = Contacts

SOURCES = main.c list_ops.c 

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)