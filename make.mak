all: test cas
TEST_SOURCE:=src/test.c
EXEC_SOURCE:=src/main.c

IDIR := include/
CC=gcc
CFLAGS=-I$(IDIR)
LDIR =lib/
ODIR=obj

COMMON_SRCS := $(filter-out $(TEST_SOURCE) $(EXEC_SOURCE),$(wildcard src/*.c))

$(DEPS:.h=.c)
$(OBJ:.o=.c)


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(TEST_SOURCE) $(COMMON_SRCS)
	$(CC) -o $@ $^ $(CFLAGS)

cas: $(EXEC_SOURCE) $(COMMON_SRCS)
	$(CC) -o $@ $^ $(CFLAGS)