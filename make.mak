EXEC_SOURCE:=src/main.c
TEST_SOURCE:=src/test.c

CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LIBS=-lm

COMMON_SRCS := $(filter-out $(TEST_SOURCE) $(EXEC_SOURCE),$(wildcard *.c))

DEPS=$(DEPS:.h=.c)
OBJ=$(OBJ:.o=.c)


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(TEST_SOURCE) $(COMMON_SRCS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

cas: $(EXEC_SOURCE) $(COMMON_SRCS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
