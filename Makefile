CC = gcc

CFLAGS = -c -Wall -Wextra -pedantic
LDFLAGS =

INCDIR =  inc
SRCDIR = src
OBJDIR = obj

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

TESTSRCDIR = test/src
TESTINCDIR = test/inc
TESTOBJDIR = test/obj
TESTSRC = $(wildcard $(TESTSRCDIR)/*.c)
TESTOBJ = $(TESTSRC:$(TESTSRCDIR)/%.c=$(TESTOBJDIR)/%.o)

TARGET = LIST
TEST = LIST_TEST
ARCHIVE = list.a

test: CFLAGS += -DTEST
debug:		CFLAGS += -g
release:	CFLAGS += -O3 -fno-strict-aliasing

all: $(SRC) $(TARGET)
test: $(SRC) $(TEST)
archive: $(SRC) $(ARCHIVE)
debug:	$(SRC) $(TARGET)
release: $(SRC) $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

$(TEST): $(OBJ) $(TESTOBJ)
	$(CC) $(OBJ) $(TESTOBJ) $(LDFLAGS) -o $@

$(ARCHIVE): $(OBJ)
	ar -rsc $@ $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@ -I$(INCDIR)

$(TESTOBJDIR)/%.o: $(TESTSRCDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@ -I$(INCDIR) -I$(TESTINCDIR) -g

clean:
	rm -f $(OBJ) $(TESTOBJ) $(TARGET) $(TEST) $(ARCHIVE)
