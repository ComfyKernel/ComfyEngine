FILES=$(shell find -name "*.cpp" -type f)
OBJS =$(patsubst %.cpp, %.o, $(FILES))
OUT  =tester.out

# add any extra flags if necessary #
CXXFLAGS := $(CFLAGS)

all: $(BUILD)/$(OUT)

$(BUILD)/$(OUT): $(OBJS)
	@echo -en "[\e[34;1m  CXX  \e[0m] -c" $(OBJS) -o $(BUILD)/$(OUT)"\n"
	@$(CC) $(CXXFLAGS) $(OBJS) -Wl,-rpath,$(BUILD) -o $@ -lce

%.o: %.cpp
	@echo -e "[\e[31;1m  CXX  \e[0m] -c" $< -o $@
	@$(CC) $(CXXFLAGS) -c $< -o $@
