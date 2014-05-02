function pES96ofs(varargin);
% pES96ofs( [...] );
% Flow Status
h = ne_dstat({
  'Pump_On_Off', 'DS813', 7 }, 'Status', varargin{:} );
