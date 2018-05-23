FILES=$(shell find -name "*.cpp" -type f)
OBJS =$(patsubst %.cpp, %.o, $(FILES))
OUT  =libce.a

# add any extra flags if necessary #
CXXFLAGS := $(CFLAGS)

all: $(BUILD)/$(OUT)

$(BUILD)/$(OUT): $(OBJS)
	@echo -en "[\e[34;1m  AR  \e[0m] -c" $(OBJS) -o $(BUILD)/$(OUT)
	@$(shell $(AR) $(AFLAGS) $@ $(OBJS) > /dev/null)
	@echo -e " \e[32;1mSUCCESS\e[0m"

%.o: %.cpp
	@echo -e "[\e[31;1m  CXX  \e[0m] -c" $< -o $@
	@$(CC) $(CXXFLAGS) -c $< -o $@
