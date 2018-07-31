TGTDIR = /home/hcl16
cmdbase = /usr/local/share/huarp/root.cmd
cmdbase = /usr/local/share/huarp/playback.cmd
cmdbase = /usr/local/share/huarp/getcon.cmd
cmdbase = /usr/local/share/huarp/phrtg.cmd
cmdbase = cmdout.cmd SWcmds.cmd

%%
SWcmds.cmd : ../SWData.cmd
	sed -ne '/^&SWStat/,$$ p' ../SWData.cmd >SWcmds.cmd

