function pES96ovss(varargin);
% pES96ovss( [...] );
% Vlv Srb Status
h = ne_dstat({
  'Vlv_UnScb_A_Open_Close', 'DS813', 1; ...
	'Vlv_Scb_A_Open_Close', 'DS813', 2; ...
	'Scrub_FH_A_On_Off', 'DS813', 3 }, 'Status', varargin{:} );
