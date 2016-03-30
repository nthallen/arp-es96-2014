% O3 startup.m
% This file should be copied to the O3 data directory along with getrun
% and renamed 'startup.m'. After transferring data, getrun invokes Matlab
% in that directory, and it expects to find startup.m there.
%
% This file should not be renamed in the directory with the rest of the
% engineering plot m-files. That directory should be in your Matlab PATH,
% and you don't want this startup script executed every time you start
% Matlab
[fd,msg] = fopen('runs.dat','r');
if fd > 0
    tline = fgetl(fd);
    while ischar(tline)
        fprintf(1,'Processing: "%s"\n', tline);
        if exist(tline,'dir') == 7
            oldfolder = cd(tline);
            csv2mat;
            delete *.csv
            cd(oldfolder);
        end
        tline = fgetl(fd);
    end
    fclose(fd);
    delete runs.dat
end
ui_O3;
