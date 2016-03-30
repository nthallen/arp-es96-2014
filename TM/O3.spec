tmcbase = /usr/local/share/huarp/freemem.tmc
tmcbase = base.tmc
tmcbase = /usr/local/share/huarp/cpu_usage.tmc
tmcbase = /usr/local/share/huarp/tmdf.tmc
tmcbase = T30K75KU.tmc T1M250KU.tmc

cmdbase = /usr/local/share/huarp/root.cmd
cmdbase = /usr/local/share/huarp/getcon.cmd
cmdbase = /usr/local/share/huarp/phrtg.cmd
cmdbase = dccc.cmd
cmdbase = ao.cmd


colbase = /usr/local/share/huarp/freemem_col.tmc
colbase = /usr/local/share/huarp/cpu_usage_col.tmc
colbase = /usr/local/share/huarp/tmdf_col.tmc
colbase = AI_col.tmc
colbase = adc_col.tmc
colbase = /usr/local/share/huarp/DACS_ID.tmc

swsbase = O3.sws

SCRIPT = interact dccc.dccc

TGTDIR = $(TGTNODE)/home/ozone

O3col : -lsubbus 
O3srvr : -lsubbus
O3disp : dstat.tmc adc_conv.tmc \
           /usr/local/share/huarp/flttime.tmc O3.tbl rtg.tmc \
           /usr/local/share/oui/cic.oui
O3algo : O3.tma O3.sws
O3engext : adc_conv.tmc O3eng.cdf
rawext : raw.cdf

doit : O3.doit

%%
COLFLAGS=-Haddress.h
address.h : O3col.cc
O3srvr.o : address.h
O3eng.cdf : genui.txt
	genui -d ../eng -c genui.txt
