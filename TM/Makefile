# Makefile Generated Sat May 03 12:24:22 EDT 2014
MNC=ES96
SPECFILE=ES96.spec
SRC=base.tmc SWData.tmc SWData.h AI_col.tmc adc_col.tmc
SRC+=SWData_col.tmc dccc.cmd ao.cmd SWData.cmd dstat.tmc T30K75KU.tmc
SRC+=T1M1M.tmc ES96.tbl rtg.tmc ES96.tma ES96eng.cdf ES96.doit
TOOL=ES96.spec Makefile
SCRIPT=interact dccc.dccc
OBJ=ES96col.cc ES96.pcm tm.dac ES96coloui.c ES96coloui.o ES96col.o
OBJ+=ES96cmd.cc ES96cmd.dat ES96srvr.o ES96srvroui.c ES96srvroui.o
OBJ+=ES96tbl.tmc ES96disp.cc ES96dispoui.c ES96dispoui.o ES96disp.o
OBJ+=ES96tblnc.tmc ES96dispnc.cc ES96dispncoui.c ES96dispncoui.o
OBJ+=ES96dispnc.o ES96algoa.tmc ES96algo.cc ES96algooui.c
OBJ+=ES96algooui.o ES96algo.o ES96engextcdf.oui ES96engext.tmc
OBJ+=ES96engext.cc ES96engextoui.c ES96engextoui.o ES96engext.o
OBJ+=doit.dep ES96clt.o ES96cltoui.c ES96cltoui.o ES96cltnc.o
OBJ+=ES96cltncoui.c ES96cltncoui.o
TGT=ES96col ES96srvr ES96disp ES96dispnc ES96algo ES96engext doit
TGT+=ES96clt ES96cltnc
DISTRIB=ES96.pcm tm.dac
IDISTRIB=Experiment.config VERSION doit
SRCDIST=ES96.tbl ES96.tma /usr/local/share/huarp/freemem.tmc
SRCDIST+=base.tmc /usr/local/share/huarp/cpu_usage.tmc
SRCDIST+=/usr/local/share/huarp/tmdf.tmc SWData.tmc SWData.h
TMCBASE=/usr/local/share/huarp/freemem.tmc base.tmc
TMCBASE+=/usr/local/share/huarp/cpu_usage.tmc
TMCBASE+=/usr/local/share/huarp/tmdf.tmc SWData.tmc SWData.h
CMDBASE=/usr/local/share/huarp/root.cmd
CMDBASE+=/usr/local/share/huarp/getcon.cmd
CMDBASE+=/usr/local/share/huarp/phrtg.cmd dccc.cmd ao.cmd SWData.cmd
COLBASE=/usr/local/share/huarp/freemem_col.tmc
COLBASE+=/usr/local/share/huarp/cpu_usage_col.tmc
COLBASE+=/usr/local/share/huarp/tmdf_col.tmc AI_col.tmc adc_col.tmc
COLBASE+=SWData_col.tmc
SWSBASE=ES96.sws
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
	$(LINK.privCXX) ES96col.o ES96coloui.o -lsubbus -ltmpp -ltm -lnort
	$(OUIUSE) ES96coloui.c
	$(PROMOTE) ES96col
ES96srvr : ES96srvr.o ES96srvroui.o
	$(LINK.privCXX) ES96srvr.o ES96srvroui.o -lsubbus -ltmpp -ltm -lnort
	$(OUIUSE) ES96srvroui.c
	$(PROMOTE) ES96srvr
ES96disp : ES96disp.o ES96dispoui.o
	$(LINK.normCXX) ES96disp.o ES96dispoui.o -ldisp -ltmph -lph -ltmpp -ltm -lnort
	$(OUIUSE) ES96dispoui.c
ES96dispnc : ES96dispnc.o ES96dispncoui.o
	$(LINK.normCXX) ES96dispnc.o ES96dispncoui.o -ldispnc -ltmnc -lncurses -ltmpp -ltm -lnort
	$(OUIUSE) ES96dispncoui.c
ES96algo : ES96algo.o ES96algooui.o
	$(LINK.normCXX) ES96algo.o ES96algooui.o -ltmpp -ltm -lnort
	$(OUIUSE) ES96algooui.c
ES96engext : ES96engext.o ES96engextoui.o
	$(LINK.normCXX) ES96engext.o ES96engextoui.o -ltmpp -ltm -lnort
	$(OUIUSE) ES96engextoui.c
doit : ES96.doit
	mkdoit3 -o doit  ES96.doit
ES96clt : ES96clt.o ES96cltoui.o
	$(LINK.normCXX) ES96clt.o ES96cltoui.o -ltmph -lph -ltmpp -ltm -lnort
	$(OUIUSE) ES96cltoui.c
ES96cltnc : ES96cltnc.o ES96cltncoui.o
	$(LINK.normCXX) ES96cltnc.o ES96cltncoui.o -ltmnc -lncurses -ltmpp -ltm -lnort
	$(OUIUSE) ES96cltncoui.c
ES96col.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc SWData.tmc /usr/local/share/huarp/freemem_col.tmc /usr/local/share/huarp/cpu_usage_col.tmc /usr/local/share/huarp/tmdf_col.tmc AI_col.tmc adc_col.tmc SWData_col.tmc
	$(TMC.col) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc SWData.tmc /usr/local/share/huarp/freemem_col.tmc /usr/local/share/huarp/cpu_usage_col.tmc /usr/local/share/huarp/tmdf_col.tmc AI_col.tmc adc_col.tmc SWData_col.tmc
ES96coloui.c : $(OUIDIR)/collect.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/subbus.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/collect.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/subbus.oui $(OUIDIR)/msg.oui
ES96coloui.o : ES96coloui.c SWData.h
ES96col.o : ES96col.cc SWData.h
ES96cmd.cc : /usr/local/share/huarp/root.cmd /usr/local/share/huarp/getcon.cmd /usr/local/share/huarp/phrtg.cmd dccc.cmd ao.cmd SWData.cmd
	$(CMDGEN) -d ES96cmd.dat /usr/local/share/huarp/root.cmd /usr/local/share/huarp/getcon.cmd /usr/local/share/huarp/phrtg.cmd dccc.cmd ao.cmd SWData.cmd
ES96srvr.o : ES96cmd.cc
	$(COMPILE.srvr) ES96cmd.cc
ES96srvroui.c : $(OUIDIR)/cis.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/subbus.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/cis.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/subbus.oui $(OUIDIR)/msg.oui
ES96srvroui.o : ES96srvroui.c
ES96tbl.tmc : ES96.tbl
ES96disp.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc SWData.tmc dstat.tmc T30K75KU.tmc T1M1M.tmc /usr/local/share/huarp/flttime.tmc ES96tbl.tmc rtg.tmc
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc SWData.tmc dstat.tmc T30K75KU.tmc T1M1M.tmc /usr/local/share/huarp/flttime.tmc ES96tbl.tmc rtg.tmc
ES96dispoui.c : /usr/local/share/oui/cic.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) /usr/local/share/oui/cic.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
ES96dispoui.o : ES96dispoui.c SWData.h
ES96disp.o : ES96disp.cc SWData.h
ES96tblnc.tmc : ES96.tbl
ES96dispnc.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc SWData.tmc dstat.tmc T30K75KU.tmc T1M1M.tmc /usr/local/share/huarp/flttime.tmc ES96tblnc.tmc rtg.tmc
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc SWData.tmc dstat.tmc T30K75KU.tmc T1M1M.tmc /usr/local/share/huarp/flttime.tmc ES96tblnc.tmc rtg.tmc
ES96dispncoui.c : /usr/local/share/oui/cic.oui $(OUIDIR)/nctable.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) /usr/local/share/oui/cic.oui $(OUIDIR)/nctable.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
ES96dispncoui.o : ES96dispncoui.c SWData.h
ES96dispnc.o : ES96dispnc.cc SWData.h
ES96algoa.tmc : ES96.tma ES96srvr
	$(SERVER) ./ES96srvr
	$(TMCALGO) -V "`./ES96srvr -R`" ES96.tma
ES96algo.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc SWData.tmc ES96algoa.tmc
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc SWData.tmc ES96algoa.tmc
ES96algooui.c : $(OUIDIR)/tma.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/tma.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
ES96algooui.o : ES96algooui.c SWData.h
ES96algo.o : ES96algo.cc SWData.h
ES96engextcdf.oui : ES96eng.cdf
	$(EDF2OUI) ES96eng.cdf
ES96engext.tmc : ES96eng.cdf
	$(EDF2EXT) ES96eng.cdf
ES96engext.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc SWData.tmc T30K75KU.tmc T1M1M.tmc ES96engext.tmc
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc SWData.tmc T30K75KU.tmc T1M1M.tmc ES96engext.tmc
ES96engextoui.c : ES96engextcdf.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) ES96engextcdf.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
ES96engextoui.o : ES96engextoui.c SWData.h
ES96engext.o : ES96engext.cc SWData.h
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
SWData.h SWData.tmc SWData_col.tmc SWData.cmd :  ES96.sws
	swscomp -o SWData  ES96.sws

tidy :
	rm -f $(OBJECT)
clean : tidy
	rm -f $(TARGET)
.cvsignore : Makefile
	@for i in $(OBJECT) $(TARGET); do echo "$$i"; done >.cvsignore
COLFLAGS=-Haddress.h
address.h : ES96col.cc
ES96srvr.o : address.h
ES96eng.cdf : genui.txt
	genui -d ../eng -c genui.txt
