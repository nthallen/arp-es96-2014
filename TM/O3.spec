tmcbase = /usr/local/share/huarp/freemem.tmc
tmcbase = base.tmc
tmcbase = /usr/local/share/huarp/cpu_usage.tmc
tmcbase = /usr/local/share/huarp/tmdf.tmc
tmcbase = T30K75KU.tmc T1M250KU.tmc
tmcbase = pwrmon.tmc
tmcbase = /usr/local/share/huarp/vl_temp.tmc
tmcbase = /usr/local/share/huarp/ebx11_temp.tmc
tmcbase = PTRH.tmc
tmcbase = /usr/local/share/huarp/ptrhm.cc

cmdbase = /usr/local/share/huarp/root.cmd
cmdbase = /usr/local/share/huarp/getcon.cmd
cmdbase = /usr/local/share/huarp/phrtg.cmd
cmdbase = dccc.cmd
cmdbase = ao.cmd


colbase = /usr/local/share/huarp/freemem_col.tmc
colbase = /usr/local/share/huarp/cpu_usage_col.tmc
colbase = /usr/local/share/huarp/tmdf_col.tmc
colbase = PTRH_col.tmc
colbase = /usr/local/share/huarp/ptrhm_col.cc
colbase = AI_col.tmc
colbase = adc_col.tmc
colbase = /usr/local/share/huarp/DACS_ID.tmc
colbase = /usr/local/share/huarp/vl_temp_col.tmc

swsbase = O3.sws

genuibase = O3.genui
genuibase = pwrmon.genui
genuibase = PTRH.genui
extbase = adc_conv.tmc
extbase = PTRH_conv.tmc

DISTRIB = SerIn/o3sisrvr SerIn/o3siclt SerIn/o3sicltnc
DISTRIB = ../Uplink/uplink ../Uplink/uplink_rcvr
DISTRIB = ../Telemetry/serin
SCRIPT = interact dccc.dccc

TGTDIR = $(TGTNODE)/home/ozone

O3col : -lsubbus 
O3srvr : -lsubbus
O3disp : dstat.tmc adc_conv.tmc pwrmon_conv.tmc \
           /usr/local/share/huarp/flttime.tmc \
           PTRH_conv.tmc HUSCE_CT.tmc \
           O3.tbl O3_2.tbl \
           /usr/local/share/oui/cic.oui
O3rtgext : adc_conv.tmc pwrmon_conv.tmc PTRH_conv.tmc \
           HUSCE_CT.tmc rtg.tmc
O3algo : O3.tma O3.sws
rawext : raw.cdf

doit : O3.doit

seroutext : SerOut.cc SerOut.oui SerOut.tmc
%%
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

