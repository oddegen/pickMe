CC = g++
CFLAGS = -Wall -std=c++11 -Isrc
LDFLAGS = -lgdi32
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
EXEC = $(BIN_DIR)/pickME

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: $(BUILD_DIR) $(BIN_DIR) $(EXEC)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR) $(EXEC)

.PHONY: clean