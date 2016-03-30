function pO3otcs(varargin);
% pO3otcs( [...] );
% Temp Control Status
h = ne_dstat({
  'Z1_HC_A_On_Off', 'DS813', 4; ...
	'Z2_HC_A_On_Off', 'DS813', 5; ...
	'Z5_HC_In_On_Off', 'DS813', 6 }, 'Status', varargin{:} );
