function pES96opdacsm(varargin);
% pES96opdacsm( [...] );
% PDACS Memory
h = timeplot({'freemem'}, ...
      'PDACS Memory', ...
      'Memory', ...
      {'freemem'}, ...
      varargin{:} );
