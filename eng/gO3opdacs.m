function fig = gO3opdacs(varargin);
% gO3opdacs(...)
% PDACS
ffig = ne_group(varargin,'PDACS','pO3opdacsm','pO3opdacscpu','pO3opdacsd','pO3opdacscput','pO3opdacssws','pO3opdacsmfc');
if nargout > 0 fig = ffig; end
