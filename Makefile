CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

SRC := $(shell find . \
	-type f \
	-name '*.cpp' \
	-not -path './bin/*' \
	-not -path './source_code/*')

BIN := $(patsubst ./%.cpp,bin/%,$(SRC))

.PHONY: all clean list

all: $(BIN)

bin/%: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@

list:
	@find bin -type f | sort

clean:
	rm -rf bin