function ui_O3
f = ne_dialg('ES96 Ozone',1);
f = ne_dialg(f, 'newcol');
f = ne_dialg(f, 'newtab', 'Ozone');
f = ne_dialg(f, 'add', 0, 1, 'gO3oc', 'Cell' );
f = ne_dialg(f, 'add', 1, 0, 'pO3oct', 'Temp' );
f = ne_dialg(f, 'add', 0, 1, 'gO3oled', 'LED' );
f = ne_dialg(f, 'add', 1, 0, 'pO3oledledt', 'LED Temp' );
f = ne_dialg(f, 'add', 1, 0, 'pO3oleddt', 'Dtct Temp' );
f = ne_dialg(f, 'add', 1, 0, 'pO3oledht', 'Hos Temp' );
f = ne_dialg(f, 'add', 1, 0, 'pO3oledri', 'Raw I' );
f = ne_dialg(f, 'add', 1, 0, 'pO3oleds', 'Status' );
f = ne_dialg(f, 'newcol');
f = ne_dialg(f, 'add', 0, 1, 'gO3od', 'Detector' );
f = ne_dialg(f, 'add', 1, 0, 'pO3odri', 'Raw I' );
f = ne_dialg(f, 'add', 1, 0, 'pO3oddt', 'Dtct Temp' );
f = ne_dialg(f, 'add', 1, 0, 'pO3odht', 'Hos Temp' );
f = ne_dialg(f, 'add', 0, 1, 'gO3otc', 'Temp Control' );
f = ne_dialg(f, 'add', 1, 0, 'pO3otcz', 'Zone 1' );
f = ne_dialg(f, 'add', 1, 0, 'pO3otczone_2', 'Zone 2' );
f = ne_dialg(f, 'add', 1, 0, 'pO3otczone_5', 'Zone 5' );
f = ne_dialg(f, 'add', 1, 0, 'pO3otcs', 'Status' );
f = ne_dialg(f, 'newcol');
f = ne_dialg(f, 'add', 0, 1, 'gO3ovs', 'Vlv Srb' );
f = ne_dialg(f, 'add', 1, 0, 'pO3ovsvt', 'Vlv Temp' );
f = ne_dialg(f, 'add', 1, 0, 'pO3ovsst', 'Srb Temp' );
f = ne_dialg(f, 'add', 1, 0, 'pO3ovss', 'Status' );
f = ne_dialg(f, 'add', 0, 1, 'gO3of', 'Flow' );
f = ne_dialg(f, 'add', 1, 0, 'pO3ofp', 'Pressure' );
f = ne_dialg(f, 'add', 1, 0, 'pO3ofr', 'Rate' );
f = ne_dialg(f, 'add', 1, 0, 'pO3ofs', 'Status' );
f = ne_dialg(f, 'add', 1, 0, 'pO3oft', 'Temp' );
f = ne_dialg(f, 'newcol');
f = ne_dialg(f, 'add', 0, 1, 'gO3or', 'Rove' );
f = ne_dialg(f, 'add', 1, 0, 'pO3ort', 'Temp' );
f = ne_dialg(f, 'add', 0, 1, 'gO3opdacs', 'PDACS' );
f = ne_dialg(f, 'add', 1, 0, 'pO3opdacsm', 'Memory' );
f = ne_dialg(f, 'add', 1, 0, 'pO3opdacscpu', 'CPU' );
f = ne_dialg(f, 'add', 1, 0, 'pO3opdacssws', 'SW Stat' );
f = ne_dialg(f, 'newcol');
f = ne_dialg(f, 'newtab', 'Runs');
f = ne_listdirs(f, 'O3_Data', 7);
f = ne_dialg(f, 'newcol');
ne_dialg(f, 'resize');
