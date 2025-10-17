CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -O2
INCLUDES=-Isrc
SRCS=src/main.c src/utils.c src/book.c src/data.c src/reader.c src/reader.data.c
OBJS=$(SRCS:.c=.o)
TARGET=library_manager

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "🗑️  Removing old executable if exists..."
	@rm -f $(TARGET)
	@echo "🔨 Linking executable..."
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	@echo "✅ Build complete!"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	@echo "🚀 Running $(TARGET)..."
	./$(TARGET)

# Build and run in one command
build-run: clean all
	@echo "🚀 Running $(TARGET)..."
	./$(TARGET)

.PHONY: all clean run build-run
