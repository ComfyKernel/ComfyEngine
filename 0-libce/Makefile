FILES=$(shell find -name "*.cpp" -type f)
OBJS =$(patsubst %.cpp, %.o, $(FILES))
OUT  =libce.so

# add any extra flags if necessary #
CXXFLAGS := $(CFLAGS) -lstdc++fs -fPIC

all: $(BUILD)/$(OUT)

$(BUILD)/$(OUT): $(OBJS)
	@echo -en "[\e[34;1m  CXX  \e[0m] -shared " $(OBJS) -o $@"\n"
	@$(CC) $(CXXFLAGS) -shared $(OBJS) -o $@

%.o: %.cpp
	@echo -e "[\e[31;1m  CXX  \e[0m] -c" $< -o $@
	@$(CC) $(CXXFLAGS) -c $< -o $@
