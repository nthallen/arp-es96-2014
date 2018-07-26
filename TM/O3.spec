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
tmcbase = /usr/local/share/huarp/vl_temp_col.tmc

swsbase = O3.sws

genuibase = O3.genui
genuibase = pwrmon.genui
genuibase = PTRH.genui
extbase = adc_conv.tmc
extbase = PTRH_conv.tmc

SCRIPT = interact dccc.dccc

TGTDIR = $(TGTNODE)/home/ozone

O3col : -lsubbus 
O3srvr : -lsubbus
O3disp : dstat.tmc adc_conv.tmc pwrmon_conv.tmc \
           /usr/local/share/huarp/flttime.tmc \
           PTRH_conv.tmc \
           O3.tbl O3_2.tbl rtg.tmc \
           /usr/local/share/oui/cic.oui
O3algo : O3.tma O3.sws
rawext : raw.cdf

doit : O3.doit

seroutext : SerOut.cc SerOut.oui SerOut.tmc
%%
COLFLAGS=-Haddress.h
address.h : O3col.cc
O3srvr.o : address.h
