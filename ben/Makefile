ROOT=..
PLATFORM=linux
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS =	fig1_3 fig1_4 fig1_5 fig1_6 fig1_7 fig1_8

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
