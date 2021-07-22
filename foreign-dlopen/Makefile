

# Compiler flags
# =================================================
# Targeting a 64 bit system
CFLAGS += -DELFCLASS=ELFCLASS64

# Optimize please
CFLAGS += -Os
# =================================================




OBJS := loader.o foreign_dlopen.o read_tpidr_el0.o aarch64_trampo.o

.PHONY: clean all

# Make all objects
all: $(OBJS)

# [Optional] Make a test binary
test: test.o $(OBJS)


clean:
	rm -rf *.o test
