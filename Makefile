CC = gcc

CFLAGS = -c -Wall -Wextra -pedantic
LDFLAGS =

INCDIR =  inc
SRCDIR = src
OBJDIR = obj

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

TARGET = LIST
ARCHIVE = list.a

debug:		CFLAGS += -g
release:	CFLAGS += -O3 -fno-strict-aliasing

all: $(SRC) $(TARGET)
archive: $(SRC) $(ARCHIVE)
debug:	$(SRC) $(TARGET)
release: $(SRC) $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

$(ARCHIVE): $(OBJ)
	ar -rsc $@ $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@ -I$(INCDIR)

clean:
	rm -f $(OBJ) $(TARGET) $(ARCHIVE)
