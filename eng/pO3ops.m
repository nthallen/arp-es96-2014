function pO3ops(varargin);
% pO3ops( [...] );
% Pump Status
h = ne_dstat({
  'Pump_On_Off', 'DS813', 7 }, 'Status', varargin{:} );
