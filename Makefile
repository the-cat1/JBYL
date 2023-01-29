# JBYL

# Makefile
# Make项目。

# Version
# JBYLC
CVER_X		= 0
CVER_Y		= 0
CVER_Z		= 1
# JBYLR
RVER_X		= 0
RVER_Y		= 0
RVER_Z		= 1

MAKE		= make -r
CC			= gcc -I./include/
ifeq ($(OS), Windows_NT)
	JBYLC 	= jbylc.exe
	JBYLR 	= jbylr.exe
else
	JBYLC 	= jbylc
	JBYLR 	= jbylr
endif
JBYLC 	= jbylc$(FT)
JBYLR 	= jbylr$(FT)

default :
	$(MAKE) $(JBYLC)
	$(MAKE) $(JBYLR)

$(JBYLC) : jbylc/jbylc.c jbylc/errors.c jbylc/instch.c \
	include/hmsgs.h include/jbylc.h
	$(CC) jbylc/jbylc.c jbylc/errors.c jbylc/instch.c \
		-o $(JBYLC) \
		-D VER_X=$(CVER_X) -D VER_Y=$(CVER_Y) -D VER_Z=$(CVER_Z)

$(JBYLR) : jbylr/jbylr.c jbylr/errors.c jbylr/stack.c\
	include/instbc.h \
	include/hmsgs.h
	$(CC) jbylr/jbylr.c jbylr/errors.c jbylr/stack.c \
		-o $(JBYLR) \
		-D VER_X=$(RVER_X) -D VER_Y=$(RVER_Y) -D VER_Z=$(RVER_Z)

clean :
ifeq ($(OS), Windows_NT)
	if exist $(JBYLC) del $(JBYLC)
	if exist $(JBYLR) del $(JBYLR)
else
	if [ -e $(JBYLC) ]; then
		rm $(JBYLC)
	fi
	if [ -e $(JBYLR) ]; then
		rm $(JBYLR)
	fi
endif
