function fig = gO3oled(varargin);
% gO3oled(...)
% LED
ffig = ne_group(varargin,'LED','pO3oledledt','pO3oleddt','pO3oledht','pO3oledri','pO3oleds');
if nargout > 0 fig = ffig; end
