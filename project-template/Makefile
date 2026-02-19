# Simple Makefile for a terminal-first workflow
#
# Purpose:
#   - Provide convenient, reproducible build targets for a small C++ project
#   - Keep commands explicit to show the compile/link/test/debug cycle
#
# Design goals:
#   - Minimal external dependencies (uses system g++ / clang++)
#   - Separate build, binary, and test directories
#   - Optional sanitizer-enabled build for quick UB/memory checks
#   - Helpful helper targets for formatting and cleaning

# Compiler selection (override by environment: e.g., CXX=clang++ make)
CXX ?= g++

# Default compiler flags (debug-friendly):
#  -std=c++20               : use modern C++ standard
#  -Wall -Wextra -Wpedantic : enable common warnings
#  -g                       : include debug symbols for gdb
#  -O0                      : no optimization (makes debugging easier)
CXXFLAGS ?= -std=c++20 -Wall -Wextra -Wpedantic -g -O0

# Extra flags used for sanitizer builds (appended by the `sanitize` target)
SAN_CXXFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -O1

# Layout directories
INCDIR = include
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Sources and derived objects
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/add.cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Primary application target
TARGET = $(BIN_DIR)/app

# Test target (single-file, dependency-free test harness)
TEST_SRC = tests/test_add.cpp
TEST_OBJ = $(BUILD_DIR)/test_add.o
TEST_TARGET = $(BIN_DIR)/test_add

# Phony targets: these are not real files and should always be executed
.PHONY: all test sanitize run clean format

# Default target: build the main application
all: $(TARGET)

# Link step: produce the executable from object files
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -o $@ $^

# Compile step rule: compile each source into the build directory as an object
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Build the test executable by compiling the test object and linking with the
# implementation
$(TEST_TARGET): $(TEST_OBJ) $(SRC_DIR)/add.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -o $@ $^

# Compile the test source into an object file
$(TEST_OBJ): $(TEST_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Run tests: build test target then execute it. The test binary will exit
# non-zero on failure.
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Sanitize target: append sanitizer flags, rebuild cleanly, and run the app.
# Note: sanitizer builds use -O1 (recommended) and ASan/UBSan flags; they help
# catch memory errors and undefined behavior early during development.
sanitize: CXXFLAGS += $(SAN_CXXFLAGS)
sanitize: clean all
	@echo "Running sanitizer build (no arguments provided)"
	-./$(TARGET) || true
	@echo "Tip: run manually with arguments, e.g.: ./$(TARGET) 2 3"

# Convenience target to build and run the application
run: all
	./$(TARGET)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Format helper: runs clang-format in-place on source and header files if
# available
format:
	if command -v clang-format >/dev/null 2>&1; then \
		clang-format -i $(SRC_DIR)/*.cpp $(INCDIR)/*.hpp tests/*.cpp; \
	else \
		echo "clang-format not found"; \
	fi
