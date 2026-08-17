# Allow user-provided values, otherwise use defaults
CC ?= gcc
CFLAGS ?= -Wall -Wextra -g

PROGRAMS := vuln_overflow vuln_format vuln_intalloc toolbox

all: $(PROGRAMS)

vuln_overflow: vuln_overflow.c
	$(CC) $(CFLAGS) -o $@ $<

toolbox: toolbox.c
	$(CC) $(CFLAGS) -o $@ $<

vuln_format: vuln_format.c
	$(CC) $(CFLAGS) -o $@ $<

vuln_intalloc: vuln_intalloc.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS)
