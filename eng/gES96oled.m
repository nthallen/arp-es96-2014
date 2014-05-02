function fig = gES96oled(varargin);
% gES96oled(...)
% LED
ffig = ne_group(varargin,'LED','pES96oledledt','pES96oleddt','pES96oledht','pES96oledri','pES96oleds');
if nargout > 0 fig = ffig; end
