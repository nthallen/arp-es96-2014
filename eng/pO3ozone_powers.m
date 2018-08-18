function pO3ozone_powers(varargin);
% pO3ozone_powers( [...] );
% Power Status
h = ne_dstat({
  'PM0I2_S', 'PM0Stat', 2; ...
	'PM0V2_S', 'PM0Stat', 3; ...
	'PM0TO_S', 'PM0Stat', 4 }, 'Status', varargin{:} );
