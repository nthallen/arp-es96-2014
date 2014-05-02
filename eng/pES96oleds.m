function pES96oleds(varargin);
% pES96oleds( [...] );
% LED Status
h = ne_dstat({
  'LED_A_On_Off', 'DS813', 0 }, 'Status', varargin{:} );
