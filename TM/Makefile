# Makefile Generated Tue Apr 15 14:30:57 EDT 2014
MNC=ES96
SPECFILE=ES96.spec
SRC=base.tmc ES96.tbl ES96.doit
TOOL=ES96.spec Makefile
SCRIPT=interact
OBJ=ES96col.cc ES96.pcm tm.dac ES96coloui.c ES96coloui.o ES96col.o
OBJ+=ES96cmd.cc ES96cmd.dat ES96srvr.o ES96srvroui.c ES96srvroui.o
OBJ+=ES96tbl.tmc ES96disp.cc ES96dispoui.c ES96dispoui.o ES96disp.o
OBJ+=ES96tblnc.tmc ES96dispnc.cc ES96dispncoui.c ES96dispncoui.o
OBJ+=ES96dispnc.o doit.dep ES96clt.o ES96cltoui.c ES96cltoui.o
OBJ+=ES96cltnc.o ES96cltncoui.c ES96cltncoui.o
TGT=ES96col ES96srvr ES96disp ES96dispnc doit ES96clt ES96cltnc
DISTRIB=ES96.pcm tm.dac
IDISTRIB=Experiment.config VERSION doit
SRCDIST=ES96.tbl /usr/local/share/huarp/freemem.tmc base.tmc
SRCDIST+=/usr/local/share/huarp/cpu_usage.tmc
SRCDIST+=/usr/local/share/huarp/tmdf.tmc
TMCBASE=/usr/local/share/huarp/freemem.tmc base.tmc
TMCBASE+=/usr/local/share/huarp/cpu_usage.tmc
TMCBASE+=/usr/local/share/huarp/tmdf.tmc
CMDBASE=/usr/local/share/huarp/root.cmd
CMDBASE+=/usr/local/share/huarp/getcon.cmd
CMDBASE+=/usr/local/share/huarp/phrtg.cmd
COLBASE=/usr/local/share/huarp/freemem_col.tmc
COLBASE+=/usr/local/share/huarp/cpu_usage_col.tmc
COLBASE+=/usr/local/share/huarp/tmdf_col.tmc
SWSBASE=
QCLIBASE=
PHTGT=ES96tbl.tmc
RCS=$(SRC) $(TOOL) $(SCRIPT)
SOURCE=$(RCS) $(NONRCS)
OBJECT=$(OBJ) *.err
TARGET=$(TGT)
DSTRB=$(TGT) $(DISTRIB) $(SCRIPT)
TGTDIR= $(TGTNODE)/home/es96
include /usr/local/share/huarp/appgen.mk

.PHONY : all extdistribution distribution clean check_photon

all : Makefile check_photon $(TGT) .cvsignore
Makefile : ES96.spec
	appgen ES96.spec
VERSION=`cat VERSION`
extdistribution : $(DSTRB) $(SRCDIST) VERSION
	@[ -d $(TGTDIR)/bin ] || mkdir $(TGTDIR)/bin
	@[ -d $(TGTDIR)/bin/$(VERSION) ] || mkdir $(TGTDIR)/bin/$(VERSION)
	@[ -d  $(TGTDIR)/bin/$(VERSION)/Base ] || mkdir $(TGTDIR)/bin/$(VERSION)/Base
	@distribute $(FORCE) $(TGTDIR)/bin/$(VERSION) $(DSTRB)
	@distribute $(FORCE) $(TGTDIR)/bin/$(VERSION)/Base $(SRCDIST)
distribution : extdistribution
	@distribute $(FORCE) $(TGTDIR) $(IDISTRIB)
check_photon :
ifeq ($(WPHOTON),YES)
	@for tgt in $(PHTGT); do \
	  cmp -s $$tgt /usr/local/share/huarp/nulltbl.tmc && echo Remaking $$tgt && rm -f $$tgt; \
	done; true
endif
ES96col : ES96col.o ES96coloui.o
	$(LINK.privCXX) ES96col.o ES96coloui.o -ltmpp -ltm -lnort
	$(OUIUSE) ES96coloui.c
	$(PROMOTE) ES96col
ES96srvr : ES96srvr.o ES96srvroui.o
	$(LINK.privCXX) ES96srvr.o ES96srvroui.o -ltmpp -ltm -lnort
	$(OUIUSE) ES96srvroui.c
	$(PROMOTE) ES96srvr
ES96disp : ES96disp.o ES96dispoui.o
	$(LINK.normCXX) ES96disp.o ES96dispoui.o -ldisp -ltmph -lph -ltmpp -ltm -lnort
	$(OUIUSE) ES96dispoui.c
ES96dispnc : ES96dispnc.o ES96dispncoui.o
	$(LINK.normCXX) ES96dispnc.o ES96dispncoui.o -ldispnc -ltmnc -lncurses -ltmpp -ltm -lnort
	$(OUIUSE) ES96dispncoui.c
doit : ES96.doit
	mkdoit3 -o doit  ES96.doit
ES96clt : ES96clt.o ES96cltoui.o
	$(LINK.normCXX) ES96clt.o ES96cltoui.o -ltmph -lph -ltmpp -ltm -lnort
	$(OUIUSE) ES96cltoui.c
ES96cltnc : ES96cltnc.o ES96cltncoui.o
	$(LINK.normCXX) ES96cltnc.o ES96cltncoui.o -ltmnc -lncurses -ltmpp -ltm -lnort
	$(OUIUSE) ES96cltncoui.c
ES96col.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc /usr/local/share/huarp/freemem_col.tmc /usr/local/share/huarp/cpu_usage_col.tmc /usr/local/share/huarp/tmdf_col.tmc
	$(TMC.col) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc /usr/local/share/huarp/freemem_col.tmc /usr/local/share/huarp/cpu_usage_col.tmc /usr/local/share/huarp/tmdf_col.tmc
ES96coloui.c : $(OUIDIR)/collect.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/collect.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/msg.oui
ES96coloui.o : ES96coloui.c
ES96col.o : ES96col.cc
ES96cmd.cc : /usr/local/share/huarp/root.cmd /usr/local/share/huarp/getcon.cmd /usr/local/share/huarp/phrtg.cmd
	$(CMDGEN) -d ES96cmd.dat /usr/local/share/huarp/root.cmd /usr/local/share/huarp/getcon.cmd /usr/local/share/huarp/phrtg.cmd
ES96srvr.o : ES96cmd.cc
	$(COMPILE.srvr) ES96cmd.cc
ES96srvroui.c : $(OUIDIR)/cis.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/cis.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/msg.oui
ES96srvroui.o : ES96srvroui.c
ES96tbl.tmc : ES96.tbl
ES96disp.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc /usr/local/share/huarp/flttime.tmc ES96tbl.tmc
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc /usr/local/share/huarp/flttime.tmc ES96tbl.tmc
ES96dispoui.c : $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
ES96dispoui.o : ES96dispoui.c
ES96disp.o : ES96disp.cc
ES96tblnc.tmc : ES96.tbl
ES96dispnc.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc /usr/local/share/huarp/flttime.tmc ES96tblnc.tmc
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc /usr/local/share/huarp/flttime.tmc ES96tblnc.tmc
ES96dispncoui.c : $(OUIDIR)/nctable.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/nctable.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
ES96dispncoui.o : ES96dispncoui.c
ES96dispnc.o : ES96dispnc.cc
doit.dep : ES96.doit
	mkdoit3 -M -o doit  ES96.doit
-include doit.dep
ES96clt.o : ES96cmd.cc
	$(COMPILE.clt) ES96cmd.cc
ES96cltoui.c : $(OUIDIR)/kbdclt.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/kbdclt.oui $(OUIDIR)/msg.oui
ES96cltoui.o : ES96cltoui.c
ES96cltnc.o : ES96cmd.cc
	$(COMPILE.cltnc) ES96cmd.cc
ES96cltncoui.c : $(OUIDIR)/kbdclt.oui $(OUIDIR)/nctable.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/kbdclt.oui $(OUIDIR)/nctable.oui $(OUIDIR)/msg.oui
ES96cltncoui.o : ES96cltncoui.c

tidy :
	rm -f $(OBJECT)
clean : tidy
	rm -f $(TARGET)
.cvsignore : Makefile
	@for i in $(OBJECT) $(TARGET); do echo "$$i"; done >.cvsignore
