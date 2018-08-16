# Makefile Generated Thu Aug 16 13:52:22 MDT 2018
MNC=O3
SPECFILE=O3.spec
PCMFILE=O3.pcm
SRC=/usr/local/share/huarp/freemem.tmc base.tmc
SRC+=/usr/local/share/huarp/cpu_usage.tmc
SRC+=/usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc
SRC+=pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc
SRC+=/usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc
SRC+=/usr/local/share/huarp/ptrhm.cc SWData.tmc SWData.h
SRC+=/usr/local/share/huarp/freemem_col.tmc
SRC+=/usr/local/share/huarp/cpu_usage_col.tmc
SRC+=/usr/local/share/huarp/tmdf_col.tmc PTRH_col.tmc
SRC+=/usr/local/share/huarp/ptrhm_col.cc AI_col.tmc adc_col.tmc
SRC+=/usr/local/share/huarp/DACS_ID.tmc
SRC+=/usr/local/share/huarp/vl_temp_col.tmc SWData_col.tmc -lsubbus
SRC+=/usr/local/share/huarp/root.cmd
SRC+=/usr/local/share/huarp/getcon.cmd
SRC+=/usr/local/share/huarp/phrtg.cmd dccc.cmd ao.cmd SWData.cmd
SRC+=dstat.tmc adc_conv.tmc pwrmon_conv.tmc
SRC+=/usr/local/share/huarp/flttime.tmc PTRH_conv.tmc HUSCE_CT.tmc
SRC+=O3.tbl O3_2.tbl /usr/local/share/oui/cic.oui rtg.tmc O3.tma
SRC+=O3.sws raw.cdf O3.doit SerOut.cc SerOut.oui SerOut.tmc O3.genui
SRC+=pwrmon.genui PTRH.genui O3.pcm
TOOL=O3.spec Makefile
SCRIPT=interact dccc.dccc
OBJ=O3col.cc tm.dac O3coloui.c O3coloui.o O3col.o ptrhm.o
OBJ+=ptrhm_col.o O3cmd.cc O3cmd.dat O3srvr.o O3srvroui.c O3srvroui.o
OBJ+=O3tbl.tmc O3_2tbl.tmc O3disp.cc O3dispoui.c O3dispoui.o O3disp.o
OBJ+=O3tblnc.tmc O3_2tblnc.tmc O3dispnc.cc O3dispncoui.c
OBJ+=O3dispncoui.o O3dispnc.o O3rtgext.cc O3rtgextoui.c O3rtgextoui.o
OBJ+=O3rtgext.o O3sws.tma O3algoa.tmc O3algo.cc O3algooui.c
OBJ+=O3algooui.o O3algo.o rawextcdf.oui rawcdf.tmc rawext.cc
OBJ+=rawextoui.c rawextoui.o rawext.o doit.dep seroutext.cc
OBJ+=seroutextoui.c seroutextoui.o seroutext.o SerOut.o O3clt.o
OBJ+=O3cltoui.c O3cltoui.o O3cltnc.o O3cltncoui.c O3cltncoui.o
OBJ+=O3engext.cdf O3engextcdf.oui O3engextcdf.tmc O3engext.cc
OBJ+=O3engextoui.c O3engextoui.o O3engext.o O3tbl.tmc.dep
OBJ+=O3_2tbl.tmc.dep O3tblnc.tmc.dep O3_2tblnc.tmc.dep
TGT=O3col O3srvr O3disp O3dispnc O3rtgext O3algo rawext doit
TGT+=seroutext O3clt O3cltnc O3engext
IGNORE=
DISTRIB=SerIn/o3sisrvr SerIn/o3siclt SerIn/o3sicltnc
DISTRIB+=../Uplink/uplink ../Uplink/uplink_rcvr ../Telemetry/serin
DISTRIB+=O3.pcm tm.dac
IDISTRIB=Experiment.config VERSION doit
SRCDIST=O3.tbl O3_2.tbl O3.tma /usr/local/share/huarp/freemem.tmc
SRCDIST+=base.tmc /usr/local/share/huarp/cpu_usage.tmc
SRCDIST+=/usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc
SRCDIST+=pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc
SRCDIST+=/usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc
SRCDIST+=/usr/local/share/huarp/ptrhm.cc SWData.tmc SWData.h
TMCBASE=/usr/local/share/huarp/freemem.tmc base.tmc
TMCBASE+=/usr/local/share/huarp/cpu_usage.tmc
TMCBASE+=/usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc
TMCBASE+=pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc
TMCBASE+=/usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc
TMCBASE+=/usr/local/share/huarp/ptrhm.cc SWData.tmc SWData.h
CMDBASE=/usr/local/share/huarp/root.cmd
CMDBASE+=/usr/local/share/huarp/getcon.cmd
CMDBASE+=/usr/local/share/huarp/phrtg.cmd dccc.cmd ao.cmd SWData.cmd
CMDBASE+=SWData.h
COLBASE=/usr/local/share/huarp/freemem_col.tmc
COLBASE+=/usr/local/share/huarp/cpu_usage_col.tmc
COLBASE+=/usr/local/share/huarp/tmdf_col.tmc PTRH_col.tmc
COLBASE+=/usr/local/share/huarp/ptrhm_col.cc AI_col.tmc adc_col.tmc
COLBASE+=/usr/local/share/huarp/DACS_ID.tmc
COLBASE+=/usr/local/share/huarp/vl_temp_col.tmc SWData_col.tmc
SWSBASE=O3.sws
QCLIBASE=
GENUIBASE=O3.genui pwrmon.genui PTRH.genui
EXTBASE=adc_conv.tmc PTRH_conv.tmc
SPECDEPBASE=
SPECTGTBASE=
SPECTGTMISS:=$(foreach file,$(SPECTGTBASE),$(if $(wildcard $(file)),,$(file)))
AG_CPPFLAGS=
PHTGT=O3tbl.tmc O3_2tbl.tmc
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
O3col : O3col.o ptrhm.o ptrhm_col.o O3coloui.o
	$(LINK.privCXX) O3col.o ptrhm.o ptrhm_col.o O3coloui.o -lsubbus -ltmpp -ltm -lnort
	$(OUIUSE) O3coloui.c
	$(PROMOTE) O3col
O3srvr : O3srvr.o O3srvroui.o
	$(LINK.privCXX) O3srvr.o O3srvroui.o -lsubbus -ltmpp -ltm -lnort
	$(OUIUSE) O3srvroui.c
	$(PROMOTE) O3srvr
O3disp : O3disp.o ptrhm.o O3dispoui.o
	$(LINK.normCXX) O3disp.o ptrhm.o O3dispoui.o -ldisp -ltmph -lph -ltmpp -ltm -lnort
	$(OUIUSE) O3dispoui.c
O3dispnc : O3dispnc.o ptrhm.o O3dispncoui.o
	$(LINK.normCXX) O3dispnc.o ptrhm.o O3dispncoui.o -ldispnc -ltmnc -lncurses -ltmpp -ltm -lnort
	$(OUIUSE) O3dispncoui.c
O3rtgext : O3rtgext.o ptrhm.o O3rtgextoui.o
	$(LINK.normCXX) O3rtgext.o ptrhm.o O3rtgextoui.o -ltmpp -ltm -lnort
	$(OUIUSE) O3rtgextoui.c
O3algo : O3algo.o ptrhm.o O3algooui.o
	$(LINK.normCXX) O3algo.o ptrhm.o O3algooui.o -ltmpp -ltm -lnort
	$(OUIUSE) O3algooui.c
rawext : rawext.o ptrhm.o rawextoui.o
	$(LINK.normCXX) rawext.o ptrhm.o rawextoui.o -ltmpp -ltm -lnort
	$(OUIUSE) rawextoui.c
doit : O3.doit
	mkdoit3 -o doit  O3.doit
seroutext : seroutext.o ptrhm.o SerOut.o seroutextoui.o
	$(LINK.normCXX) seroutext.o ptrhm.o SerOut.o seroutextoui.o -ltmpp -ltm -lnort
	$(OUIUSE) seroutextoui.c
O3clt : O3clt.o O3cltoui.o
	$(LINK.normCXX) O3clt.o O3cltoui.o -ltmph -lph -ltmpp -ltm -lnort
	$(OUIUSE) O3cltoui.c
O3cltnc : O3cltnc.o O3cltncoui.o
	$(LINK.normCXX) O3cltnc.o O3cltncoui.o -ltmnc -lncurses -ltmpp -ltm -lnort
	$(OUIUSE) O3cltncoui.c
O3engext : O3engext.o ptrhm.o O3engextoui.o
	$(LINK.normCXX) O3engext.o ptrhm.o O3engextoui.o -ltmpp -ltm -lnort
	$(OUIUSE) O3engextoui.c
O3col.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc /usr/local/share/huarp/freemem_col.tmc /usr/local/share/huarp/cpu_usage_col.tmc /usr/local/share/huarp/tmdf_col.tmc PTRH_col.tmc AI_col.tmc adc_col.tmc /usr/local/share/huarp/DACS_ID.tmc /usr/local/share/huarp/vl_temp_col.tmc SWData_col.tmc VERSION
	$(TMC.col) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc /usr/local/share/huarp/freemem_col.tmc /usr/local/share/huarp/cpu_usage_col.tmc /usr/local/share/huarp/tmdf_col.tmc PTRH_col.tmc AI_col.tmc adc_col.tmc /usr/local/share/huarp/DACS_ID.tmc /usr/local/share/huarp/vl_temp_col.tmc SWData_col.tmc
O3coloui.c : $(OUIDIR)/collect.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/subbus.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/collect.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/subbus.oui $(OUIDIR)/msg.oui
O3coloui.o : O3coloui.c SWData.h
O3col.o : O3col.cc SWData.h
ptrhm.o : /usr/local/share/huarp/ptrhm.cc SWData.h
	$(COMPILE.cc) /usr/local/share/huarp/ptrhm.cc
ptrhm_col.o : /usr/local/share/huarp/ptrhm_col.cc SWData.h
	$(COMPILE.cc) /usr/local/share/huarp/ptrhm_col.cc
O3cmd.cc : /usr/local/share/huarp/root.cmd /usr/local/share/huarp/getcon.cmd /usr/local/share/huarp/phrtg.cmd dccc.cmd ao.cmd SWData.cmd
	$(CMDGEN) -d O3cmd.dat /usr/local/share/huarp/root.cmd /usr/local/share/huarp/getcon.cmd /usr/local/share/huarp/phrtg.cmd dccc.cmd ao.cmd SWData.cmd
O3srvr.o : O3cmd.cc SWData.h
	$(COMPILE.srvr) O3cmd.cc
O3srvroui.c : $(OUIDIR)/cis.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/subbus.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/cis.oui $(OUIDIR)/seteuid.oui $(OUIDIR)/subbus.oui $(OUIDIR)/msg.oui
O3srvroui.o : O3srvroui.c SWData.h
O3tbl.tmc : O3.tbl
-include O3tbl.tmc.dep
O3_2tbl.tmc : O3_2.tbl
-include O3_2tbl.tmc.dep
O3disp.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc dstat.tmc adc_conv.tmc pwrmon_conv.tmc /usr/local/share/huarp/flttime.tmc PTRH_conv.tmc HUSCE_CT.tmc O3tbl.tmc O3_2tbl.tmc VERSION
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc dstat.tmc adc_conv.tmc pwrmon_conv.tmc /usr/local/share/huarp/flttime.tmc PTRH_conv.tmc HUSCE_CT.tmc O3tbl.tmc O3_2tbl.tmc
O3dispoui.c : /usr/local/share/oui/cic.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) /usr/local/share/oui/cic.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
O3dispoui.o : O3dispoui.c SWData.h
O3disp.o : O3disp.cc SWData.h
O3tblnc.tmc : O3.tbl
-include O3tblnc.tmc.dep
O3_2tblnc.tmc : O3_2.tbl
-include O3_2tblnc.tmc.dep
O3dispnc.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc dstat.tmc adc_conv.tmc pwrmon_conv.tmc /usr/local/share/huarp/flttime.tmc PTRH_conv.tmc HUSCE_CT.tmc O3tblnc.tmc O3_2tblnc.tmc VERSION
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc dstat.tmc adc_conv.tmc pwrmon_conv.tmc /usr/local/share/huarp/flttime.tmc PTRH_conv.tmc HUSCE_CT.tmc O3tblnc.tmc O3_2tblnc.tmc
O3dispncoui.c : /usr/local/share/oui/cic.oui $(OUIDIR)/nctable.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) /usr/local/share/oui/cic.oui $(OUIDIR)/nctable.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
O3dispncoui.o : O3dispncoui.c SWData.h
O3dispnc.o : O3dispnc.cc SWData.h
O3rtgext.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc adc_conv.tmc pwrmon_conv.tmc PTRH_conv.tmc HUSCE_CT.tmc rtg.tmc VERSION
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc adc_conv.tmc pwrmon_conv.tmc PTRH_conv.tmc HUSCE_CT.tmc rtg.tmc
O3rtgextoui.c : $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
O3rtgextoui.o : O3rtgextoui.c SWData.h
O3rtgext.o : O3rtgext.cc SWData.h
O3sws.tma : O3.sws
	$(COMPILE.sws) O3.sws
O3algoa.tmc : O3.tma O3sws.tma O3srvr
	$(SERVER) ./O3srvr
	$(TMCALGO) -V "`./O3srvr -R`" O3.tma O3sws.tma
O3algo.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc O3algoa.tmc VERSION
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc O3algoa.tmc
O3algooui.c : $(OUIDIR)/tma.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) $(OUIDIR)/tma.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
O3algooui.o : O3algooui.c SWData.h
O3algo.o : O3algo.cc SWData.h
rawextcdf.oui : raw.cdf
	$(EDF2OUI) raw.cdf
rawcdf.tmc : raw.cdf
	$(EDF2EXT) raw.cdf
rawext.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc rawcdf.tmc VERSION
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc rawcdf.tmc
rawextoui.c : rawextcdf.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) rawextcdf.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
rawextoui.o : rawextoui.c SWData.h
rawext.o : rawext.cc SWData.h
doit.dep : O3.doit
	mkdoit3 -M -o doit  O3.doit
-include doit.dep
seroutext.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc SerOut.tmc VERSION
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc SerOut.tmc
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
O3engext.cdf : O3.genui pwrmon.genui PTRH.genui
	$(GENUI2ENG) O3.genui pwrmon.genui PTRH.genui
O3engextcdf.oui : O3engext.cdf
	$(EDF2OUI) O3engext.cdf
O3engextcdf.tmc : O3engext.cdf
	$(EDF2EXT) O3engext.cdf
O3engext.cc : /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc adc_conv.tmc PTRH_conv.tmc O3engextcdf.tmc VERSION
	$(TMC) /usr/local/share/huarp/freemem.tmc base.tmc /usr/local/share/huarp/cpu_usage.tmc /usr/local/share/huarp/tmdf.tmc T30K75KU.tmc T1M250KU.tmc pwrmon.tmc /usr/local/share/huarp/vl_temp.tmc /usr/local/share/huarp/ebx11_temp.tmc PTRH.tmc SWData.tmc adc_conv.tmc PTRH_conv.tmc O3engextcdf.tmc
O3engextoui.c : O3engextcdf.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
	$(OUI) O3engextcdf.oui $(OUIDIR)/dc.oui $(OUIDIR)/msg.oui
O3engextoui.o : O3engextoui.c SWData.h
O3engext.o : O3engext.cc SWData.h
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
model_atmos.o : model_atmos.h
TM_lowpass.o : TM_lowpass.h

.PHONY : all-SerIn clean-SerIn
all-dist : all-SerIn
all-SerIn :
	cd SerIn && make
SerIn/o3sisrvr SerIn/o3siclt SerIn/o3sicltnc :
	cd SerIn && make
clean-dist : clean-SerIn
clean-SerIn :
	cd SerIn && make clean

.PHONY : all-Uplink clean-Uplink
all-dist : all-Uplink
all-Uplink :
	cd ../Uplink && make
../Uplink/uplink ../Uplink/uplink_rcvr :
	cd ../Uplink && make
clean-dist : clean-Uplink
clean-Uplink :
	cd ../Uplink && make clean

.PHONY : all-Telemetry clean-Telemetry
all-dist : all-Telemetry
all-Telemetry :
	cd ../Telemetry && make
../Telemetry/serin :
	cd ../Telemetry && make
clean-dist : clean-Telemetry
clean-Telemetry :
	cd ../Telemetry && make clean


distribution : distribution-serin
distribution-serin :
	@[ -d $(TGTDIR)/SerIn ] || mkdir $(TGTDIR)/SerIn
	@for i in VERSION bin doit src; do ln -fs ../$$i $(TGTDIR)/SerIn/$$i; done
	@distribute $(FORCE) $(TGTDIR)/SerIn SerIn/Experiment.config

