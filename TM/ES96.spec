tmcbase = /usr/local/share/huarp/freemem.tmc
tmcbase = base.tmc
tmcbase = /usr/local/share/huarp/cpu_usage.tmc
tmcbase = /usr/local/share/huarp/tmdf.tmc

cmdbase = /usr/local/share/huarp/root.cmd
cmdbase = /usr/local/share/huarp/getcon.cmd
cmdbase = /usr/local/share/huarp/phrtg.cmd


colbase = /usr/local/share/huarp/freemem_col.tmc
colbase = /usr/local/share/huarp/cpu_usage_col.tmc
colbase = /usr/local/share/huarp/tmdf_col.tmc
colbase = adc_col.tmc

swsbase = ES96.sws

SCRIPT = interact

TGTDIR = $(TGTNODE)/home/es96

ES96col : -lsubbus 
ES96srvr :
ES96disp : /usr/local/share/huarp/flttime.tmc ES96.tbl rtg.tmc \
/usr/local/share/oui/cic.oui

doit : ES96.doit

