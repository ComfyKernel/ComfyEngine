# Tell it to use a real shell #
SHELL = /bin/bash

# Set up paths #
ORIGIN  := $(shell readlink -f .)
BUILD   := $(ORIGIN)/build
INCLUDE := $(ORIGIN)/include
SOURCE  := $(ORIGIN)/
#TEST    = $(ORIGIN)/test

# Get the main makefiles #
FILES := $(patsubst %/Makefile,%/,$(shell find $(SOURCE) -mindepth 2 -maxdepth 2 -name "Makefile" -type f))

# Set the compile flags #
CFLAGS  := -Wall -Wextra -g -I$(INCLUDE) -L$(BUILD) -std=gnu++17
AFLAGS  := -rvs

# Set the compilers to GCC and G++ #
CC := g++
AR := ar

export ORIGIN
export BUILD
export INCLUDE
export SOURCE
export CC
export AR
export CFLAGS
export AFLAGS

# Get files #

all: $(BUILD)/$(O)
	@echo -en "[\e[34;1m  BUILD  \e[0m] Exiting\n"

info:
	@echo -en "[\e[32;1m  INFO  \e[0m]  [--Build & OS Info--]\n"
	@echo -en "[\e[32;1m  INFO  \e[0m]  Compiler         :" $(CC) "\n"
	@echo -en "[\e[32;1m  INFO  \e[0m]  Compiler Version : "
	@$(CC) -dumpversion
	@echo -en "[\e[32;1m  INFO  \e[0m]  Archive          :" $(AR) "\n"
	@echo -en "[\e[32;1m  INFO  \e[0m]  OS               :" $(shell uname -a)
	@echo -en "\n"
	@echo -en "[\e[32;1m  INFO  \e[0m]  Architecture     :" $(shell uname -m) "\n"
	@echo -en "[\e[32;1m  INFO  \e[0m]\n"
	@echo -en "[\e[32;1m  INFO  \e[0m]  [--Directory Info--]\n"
	@echo -en "[\e[32;1m  INFO  \e[0m]  Origin  :" $(ORIGIN)  "\n"
	@echo -en "[\e[32;1m  INFO  \e[0m]  Build   :" $(BUILD)   "\n"
	@echo -en "[\e[32;1m  INFO  \e[0m]  Include :" $(INCLUDE) "\n"
	@echo -en "[\e[32;1m  INFO  \e[0m]  Source  :" $(SOURCE)  "\n\n"

	@echo -en "[\e[34;1m  BUILD  \e[0m] Starting Build\n\n"

$(BUILD)/$(O): info
	@$(foreach fi,$(FILES),$(MAKE) -C $(fi);)

clean:
	rm -v $(shell find $(SOURCE) -type f -name "*.o") $(shell find $(BUILD) -type f -name "*.o") $(shell find $(BUILD) -type f -name "*.a")

PHONY:
