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

swsbase = ES96.sws

SCRIPT = interact dccc.dccc

TGTDIR = $(TGTNODE)/home/es96

ES96col : -lsubbus 
ES96srvr : -lsubbus
ES96disp : dstat.tmc adc_conv.tmc \
           /usr/local/share/huarp/flttime.tmc ES96.tbl rtg.tmc \
           /usr/local/share/oui/cic.oui
ES96algo : ES96.tma ES96.sws
ES96engext : adc_conv.tmc ES96eng.cdf
rawext : raw.cdf

doit : ES96.doit

%%
COLFLAGS=-Haddress.h
address.h : ES96col.cc
ES96srvr.o : address.h
ES96eng.cdf : genui.txt
	genui -d ../eng -c genui.txt
