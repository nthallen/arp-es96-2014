# Makefile Generated Thu Jul 26 09:46:23 EDT 2018
MNC=O3
SPECFILE=O3.spec
PCMFILE=O3.pcm
SRC=/usr/local/share/huarp/freemem.tmc base.tmc
SRC+=/usr/local/share/huarp/cpu_usage.tmc
SRC+=/usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc
SRC+=SWData.tmc SWData.h /usr/local/share/huarp/freemem_col.tmc
SRC+=/usr/local/share/huarp/cpu_usage_col.tmc
SRC+=/usr/local/share/huarp/tmdf_col.tmc AI_col.tmc adc_col.tmc
SRC+=/usr/local/share/huarp/DACS_ID.tmc SWData_col.tmc -lsubbus
SRC+=/usr/local/share/huarp/root.cmd
SRC+=/usr/local/share/huarp/getcon.cmd
SRC+=/usr/local/share/huarp/phrtg.cmd dccc.cmd ao.cmd SWData.cmd
SRC+=dstat.tmc adc_conv.tmc /usr/local/share/huarp/flttime.tmc O3.tbl
SRC+=rtg.tmc /usr/local/share/oui/cic.oui O3.tma O3.sws O3eng.cdf
SRC+=raw.cdf O3.doit SerOut.cc SerOut.oui SerOut.tmc O3.pcm
TOOL=O3.spec Makefile
SCRIPT=interact dccc.dccc
OBJ=O3col.cc tm.dac O3coloui.c O3coloui.o O3col.o O3cmd.cc O3cmd.dat
OBJ+=O3srvr.o O3srvroui.c O3srvroui.o O3tbl.tmc O3disp.cc O3dispoui.c
OBJ+=O3dispoui.o O3disp.o O3tblnc.tmc O3dispnc.cc O3dispncoui.c
OBJ+=O3dispncoui.o O3dispnc.o O3sws.tma O3algoa.tmc O3algo.cc
OBJ+=O3algooui.c O3algooui.o O3algo.o O3engextcdf.oui O3engcdf.tmc
OBJ+=O3engext.cc O3engextoui.c O3engextoui.o O3engext.o rawextcdf.oui
OBJ+=rawcdf.tmc rawext.cc rawextoui.c rawextoui.o rawext.o doit.dep
OBJ+=seroutext.cc seroutextoui.c seroutextoui.o seroutext.o SerOut.o
OBJ+=O3clt.o O3cltoui.c O3cltoui.o O3cltnc.o O3cltncoui.c
OBJ+=O3cltncoui.o O3tbl.tmc.dep O3tblnc.tmc.dep
TGT=O3col O3srvr O3disp O3dispnc O3algo O3engext rawext doit
TGT+=seroutext O3clt O3cltnc
IGNORE=
DISTRIB=O3.pcm tm.dac
IDISTRIB=Experiment.config VERSION doit
SRCDIST=O3.tbl O3.tma /usr/local/share/huarp/freemem.tmc base.tmc
SRCDIST+=/usr/local/share/huarp/cpu_usage.tmc
SRCDIST+=/usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc
SRCDIST+=SWData.tmc SWData.h
TMCBASE=/usr/local/share/huarp/freemem.tmc base.tmc
TMCBASE+=/usr/local/share/huarp/cpu_usage.tmc
TMCBASE+=/usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc
TMCBASE+=SWData.tmc SWData.h
CMDBASE=/usr/local/share/huarp/root.cmd
CMDBASE+=/usr/local/share/huarp/getcon.cmd
CMDBASE+=/usr/local/share/huarp/phrtg.cmd dccc.cmd ao.cmd SWData.cmd
CMDBASE+=SWData.h
COLBASE=/usr/local/share/huarp/freemem_col.tmc
COLBASE+=/usr/local/share/huarp/cpu_usage_col.tmc
COLBASE+=/usr/local/share/huarp/tmdf_col.tmc AI_col.tmc adc_col.tmc
COLBASE+=/usr/local/share/huarp/DACS_ID.tmc SWData_col.tmc
SWSBASE=O3.sws
QCLIBASE=
GENUIBASE=
EXTBASE=
SPECDEPBASE=
SPECTGTBASE=
SPECTGTMISS:=$(foreach file,$(SPECTGTBASE),$(if $(wildcard $(file)),,$(file)))
AG_CPPFLAGS=
PHTGT=O3tbl.tmc
SOURCE=$(SRC) $(TOOL) $(SCRIPT)
OBJECT=$(OBJ) *.err
TARGET=$(TGT)
DSTRB=$(TGT) $(DISTRIB) $(SCRIPT)
TGTDIR= $(TGTNODE)/home/ozone
include /usr/local/share/huarp/appgen.mk

.PHONY : all all-dist extdistribution distribution clean clean-dist check_photon

IGNOREFILE=.gitignore
all : check_photon $(TGT) $(IGNOREFILE)
all-dist : all $(DSTRB) $(SRCDIST) VERSION
Makefile $(SPECTGTMISS) : O3.spec $(SPECDEPBASE)
	appgen O3.spec
VERSION=`cat VERSION`
extdistribution : all-dist
	@[ -d $(TGTDIR)/bin ] || mkdir $(TGTDIR)/bin
	@[ -d $(TGTDIR)/bin/$(VERSION) ] || mkdir $(TGTDIR)/bin/$(VERSION)
	@[ -d $(TGTDIR)/bin/$(VERSION)/Base ] || mkdir $(TGTDIR)/bin/$(VERSION)/Base
	@[ ! -f $(TGTDIR)/bin/$(VERSION)/$(PCMFILE) ] || \
	  cmp -s $(TGTDIR)/bin/$(VERSION)/$(PCMFILE) $(PCMFILE) || \
	  ( echo "$(PCMFILE) changed without VERSION update"; false )
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
O3col : O3col.o O3coloui.o
	$(LINK.privCXX) O3col.o O3coloui.o -lsubbus -ltmpp -ltm -lnort
	$(OUIUSE) O3coloui.c
	$(PROMOTE) O3col
O3srvr : O3srvr.o O3srvroui.o
	$(LINK.privCXX) O3srvr.o O3srvroui.o -lsubbus -ltmpp -ltm -lnort
	$(OUIUSE) O3srvroui.c
	$(PROMOTE) O3srvr
O3disp : O3disp.o O3dispoui.o
	$(LINK.normCXX) O3disp.o O3dispoui.o -ldisp -ltmph -lph -ltmpp -ltm -lnort
	$(OUIUSE) O3dispoui.c
O3dispnc : O3dispnc.o O3dispncoui.o
	$(LINK.normCXX) O3dispnc.o O3dispncoui.o -ldispnc -ltmnc -lncurses -ltmpp -ltm -lnort
	$(OUIUSE) O3dispncoui.c
O3algo : O3algo.o O3algooui.o
	$(LINK.normCXX) O3algo.o O3algooui.o -ltmpp -ltm -lnort
	$(OUIUSE) O3algooui.c
O3engext : O3engext.o O3engextoui.o
	$(LINK.normCXX) O3engext.o O3engextoui.o -ltmpp -ltm -lnort
	$(OUIUSE) O3engextoui.c
rawext : rawext.o rawextoui.o
	$(LINK.normCXX) rawext.o rawextoui.o -ltmpp -ltm -lnort
	$(OUIUSE) rawextoui.c
doit : O3.doit
	mkdoit3 -o doit  O3.doit
seroutext : seroutext.o SerOut.o seroutextoui.o
	$(LINK.normCXX) seroutext.o SerOut.o seroutextoui.o -ltmpp -ltm -lnort
	$(OUIUSE) seroutextoui.c
O3clt : O3clt.o O3cltoui.o
	$(LINK.normCXX) O3clt.o O3cltoui.o -ltmph -lph -ltmpp -ltm -lnort
	$(OUIUSE) O3cltoui.c
O3cltnc : O3cltnc.o O3cltncoui.o
	$(LINK.normCXX) O3cltnc.o O3cltncoui.o -ltmnc -lncurses -ltmpp -ltm -lnort
	$(OUIUSE) O3cltncoui.c
O3col.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc SWData.tmc /usr/local/share/huarp/freemem_col.tmc /usr/local/share/huarp/cpu_usage_col.tmc /usr/local/share/huarp/tmdf_col.tmc AI_col.tmc adc_col.tmc /usr/local/share/huarp/DACS_ID.tmc SWData_col.tmc VERSION
	$(TMC.col) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc SWData.tmc /usr/local/share/huarp/freemem_col.tmc /usr/local/share/huarp/cpu_usage_col.tmc /usr/local/share/huarp/tmdf_col.tmc AI_col.tmc adc_col.tmc /usr/local/share/huarp/DACS_ID.tmc SWData_col.tmc
O3coloui.c : $(OUIDIR)/collect.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/subbus.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/collect.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/subbus.oui $(OUIDIR)/msg.oui
O3coloui.o : O3coloui.c SWData.h
O3col.o : O3col.cc SWData.h
O3cmd.cc : /usr/local/share/huarp/root.cmd /usr/local/share/huarp/getcon.cmd /usr/local/share/huarp/phrtg.cmd dccc.cmd ao.cmd SWData.cmd
	$(CMDGEN) -d O3cmd.dat /usr/local/share/huarp/root.cmd /usr/local/share/huarp/getcon.cmd /usr/local/share/huarp/phrtg.cmd dccc.cmd ao.cmd SWData.cmd
O3srvr.o : O3cmd.cc SWData.h
	$(COMPILE.srvr) O3cmd.cc
O3srvroui.c : $(OUIDIR)/cis.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/subbus.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/cis.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/subbus.oui $(OUIDIR)/msg.oui
O3srvroui.o : O3srvroui.c SWData.h
O3tbl.tmc : O3.tbl
-include O3tbl.tmc.dep
O3disp.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc SWData.tmc dstat.tmc adc_conv.tmc /usr/local/share/huarp/flttime.tmc O3tbl.tmc rtg.tmc VERSION
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc SWData.tmc dstat.tmc adc_conv.tmc /usr/local/share/huarp/flttime.tmc O3tbl.tmc rtg.tmc
O3dispoui.c : /usr/local/share/oui/cic.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) /usr/local/share/oui/cic.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
O3dispoui.o : O3dispoui.c SWData.h
O3disp.o : O3disp.cc SWData.h
O3tblnc.tmc : O3.tbl
-include O3tblnc.tmc.dep
O3dispnc.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc SWData.tmc dstat.tmc adc_conv.tmc /usr/local/share/huarp/flttime.tmc O3tblnc.tmc rtg.tmc VERSION
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc SWData.tmc dstat.tmc adc_conv.tmc /usr/local/share/huarp/flttime.tmc O3tblnc.tmc rtg.tmc
O3dispncoui.c : /usr/local/share/oui/cic.oui $(OUIDIR)/nctable.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) /usr/local/share/oui/cic.oui $(OUIDIR)/nctable.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
O3dispncoui.o : O3dispncoui.c SWData.h
O3dispnc.o : O3dispnc.cc SWData.h
O3sws.tma : O3.sws
	$(COMPILE.sws) O3.sws
O3algoa.tmc : O3.tma O3sws.tma O3srvr
	$(SERVER) ./O3srvr
	$(TMCALGO) -V "`./O3srvr -R`" O3.tma O3sws.tma
O3algo.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc SWData.tmc O3algoa.tmc VERSION
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc SWData.tmc O3algoa.tmc
O3algooui.c : $(OUIDIR)/tma.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/tma.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
O3algooui.o : O3algooui.c SWData.h
O3algo.o : O3algo.cc SWData.h
O3engextcdf.oui : O3eng.cdf
	$(EDF2OUI) O3eng.cdf
O3engcdf.tmc : O3eng.cdf
	$(EDF2EXT) O3eng.cdf
O3engext.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc SWData.tmc adc_conv.tmc O3engcdf.tmc VERSION
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc SWData.tmc adc_conv.tmc O3engcdf.tmc
O3engextoui.c : O3engextcdf.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) O3engextcdf.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
O3engextoui.o : O3engextoui.c SWData.h
O3engext.o : O3engext.cc SWData.h
rawextcdf.oui : raw.cdf
	$(EDF2OUI) raw.cdf
rawcdf.tmc : raw.cdf
	$(EDF2EXT) raw.cdf
rawext.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc SWData.tmc rawcdf.tmc VERSION
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc SWData.tmc rawcdf.tmc
rawextoui.c : rawextcdf.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) rawextcdf.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
rawextoui.o : rawextoui.c SWData.h
rawext.o : rawext.cc SWData.h
doit.dep : O3.doit
	mkdoit3 -M -o doit  O3.doit
-include doit.dep
seroutext.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc SWData.tmc SerOut.tmc VERSION
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc SWData.tmc SerOut.tmc
seroutextoui.c : SerOut.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) SerOut.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
seroutextoui.o : seroutextoui.c SWData.h
seroutext.o : seroutext.cc SWData.h
SerOut.o : SerOut.cc SWData.h
O3clt.o : O3cmd.cc SWData.h
	$(COMPILE.clt) O3cmd.cc
O3cltoui.c : $(OUIDIR)/kbdclt.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/kbdclt.oui $(OUIDIR)/msg.oui
O3cltoui.o : O3cltoui.c SWData.h
O3cltnc.o : O3cmd.cc SWData.h
	$(COMPILE.cltnc) O3cmd.cc
O3cltncoui.c : $(OUIDIR)/kbdclt.oui $(OUIDIR)/nctable.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/kbdclt.oui $(OUIDIR)/nctable.oui $(OUIDIR)/msg.oui
O3cltncoui.o : O3cltncoui.c SWData.h
SWData.h SWData.tmc SWData_col.tmc SWData.cmd :  O3.sws
	swscomp -o SWData  O3.sws

tidy :
	rm -f $(OBJECT)
clean : tidy
	rm -f $(TARGET)
clean-dist : clean
$(IGNOREFILE) : Makefile
	@for i in $(OBJECT) $(IGNORE) $(TARGET); do echo "$$i"; done >$(IGNOREFILE)
COLFLAGS=-Haddress.h
address.h : O3col.cc
O3srvr.o : address.h
O3eng.cdf : genui.txt
	genui -d ../eng -c genui.txt
