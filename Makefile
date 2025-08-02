CC = cc

PNAME = base

SRC  = $(shell find src -name "*.c")
OBJ  = $(SRC:.c=.o)
BIN = build

EXEC = $(BIN)/$(PNAME)
INCFLAGS  = -Isrc/

CCFLAGS += $(INCFLAGS)
CCFLAGS += -O0
CCFLAGS += -Wall
CCFLAGS += -Wextra
CCFLAGS += -Werror
CCFLAGS += -Wno-error=padded
CCFLAGS += -Wno-error=unused-parameter
CCFLAGS += -Wno-error=incompatible-pointer-types
CCFLAGS += -Wpadded
CCFLAGS += -pedantic
CCFLAGS += -fanalyzer
CCFLAGS += -fno-omit-frame-pointer

LDFLAGS  = $(INCFLAGS)
LDFLAGS += -lpthread
LDFLAGS += -lrt

INSTALL_PATH = /usr/local/bin

all: build

run: build
	$(BIN)/$(PNAME) $*

build: $(OBJ)
	$(CC) $(CCFLAGS) -ggdb -o $(BIN)/$(PNAME) $(filter %.o,$^) $(LDFLAGS)

clean:
	rm $(BIN)/* $(OBJ) logs.txt

install: build
	cp $(BIN)/$(PNAME) $(INSTALL_PATH)

%.o: %.c
	$(CC) -ggdb -o $@ -c $< $(CCFLAGS)

