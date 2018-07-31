include /usr/local/share/huarp/appgen.mk
CPPFLAGS=-I/usr/local/include
CXXFLAGS=-Wall -g
CFLAGS=-Wall -g
LDFLAGS=-L/usr/local/lib -Wl,-rpath -Wl,/usr/local/lib
CXX=g++
LINK.cxx=$(CXX) $(AG_LDFLAGS) $(LDFLAGS)

serin : serin.o serinoui.o
	/bin/rm -f $@; $(LINK.cxx) -o $@ serin.o serinoui.o -ltmpp -ltm -lnort
	usemsg serin serinoui.c
	/usr/local/sbin/promote serin
serinoui.c : serin.oui
	$(OUI) -o serinoui.c serin.oui

.PHONY : all clean
all : serin
clean :
	rm -f *.o serinoui.c serin
