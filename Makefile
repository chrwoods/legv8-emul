CC = gcc
ECHO = echo
RM = rm -f

CFLAGS = -Wall -Werror -ggdb -funroll-loops

ODIR = obj
SDIR = src
BIN = main
OBJS = main.o io.o tree.o instruction.o emulator.o
OBJ = $(patsubst %,$(ODIR)/%,$(OBJS))

VPATH = $(SDIR):$(SDIR)/instructions

all: $(BIN) #etags

$(BIN): $(OBJ)
	@$(ECHO) Linking $@
	@$(CC) $^ -o $@

-include $(OBJS:.o=.d)

$(OBJ): $(ODIR)/%.o: %.c
	@$(ECHO) Compiling $<
	@$(CC) $(CFLAGS) -MMD -MF $(ODIR)/$*.d -o $@ -c $<

.PHONY: all clean clobber 

clean:
	@$(ECHO) Removing all generated files
	@$(RM) $(ODIR)/*.o $(BIN) $(ODIR)/*.d TAGS core vgcore.* gmon.out

clobber:
	@$(ECHO) Removing backup files
	@$(RM) *~ \#* *pgm
