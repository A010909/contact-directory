# Define the C compiler to use
CC = gcc

# Define compiler flags for warnings and debugging
# -Wall: Enables all compiler's warning messages. This is a best practice.
# -g:    Generates debugging information for use with a debugger like GDB.
CFLAGS = -Wall -g

# Define the name of the executable file we want to create
TARGET = Contacts

# Define all C source files
SOURCES = main.c list_ops.c 

# The 'all' target is the default one.
# It depends on our final executable (TARGET).
# So, running 'make' or 'make all' will build our executable.
all: $(TARGET)

# This rule explains how to build the TARGET from the SOURCES.
# The target is 'analyzer', and its dependency is 'main.c'.
# If 'main.c' is newer than 'analyzer', this command will be run.
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# The 'clean' target is used to remove generated files.
# It doesn't build anything, so it has no dependencies.
clean:
# 'rm' is the remove command.
# '-f' means 'force', so it won't complain if the file doesn't exist.
	rm -f $(TARGET)