function replay_three_egos_stacked(lead, egos, varargin)
% replay_three_egos_stacked
% Animate 3 ego vehicles following the same lead vehicle in stacked views.
%
% Inputs
%   lead  : lead car longitudinal position (timeseries / timetable / Nx2 / struct)
%   egos  : cell array {ego1, ego2, ego3}
%
% Name-Value
%   'Labels'   : cellstr, ego labels
%   'LeadLabel': string
%   'L','W'    : car dimensions
%   'Speed'    : playback speed
%   'Window'   : x-span [m]

% ---------- Parse ----------
p = inputParser;
p.addParameter('Labels', {'Ego 1','Ego 2','Ego 3'});
p.addParameter('LeadLabel','Lead');
p.addParameter('L',4.0);
p.addParameter('W',1.8);
p.addParameter('Speed',1);
p.addParameter('Window',80);
p.parse(varargin{:});

labels = string(p.Results.Labels);
leadLabel = string(p.Results.LeadLabel);
L = p.Results.L;
W = p.Results.W;
spd = p.Results.Speed;
win = p.Results.Window;

assert(numel(egos)==3,'Provide exactly 3 ego vehicles.');

% ---------- Extract & unify time ----------
[tL, xL] = get_tx(lead); [tL,xL] = sort_tx(tL,xL);
t0 = tL(1);
tLs = to_seconds(tL,t0);

xE = cell(3,1); tEs = cell(3,1);
for i = 1:3
    [tE, xEi] = get_tx(egos{i});
    [tE, xEi] = sort_tx(tE, xEi);
    tEs{i} = to_seconds(tE,t0);
    xE{i} = xEi;
end

tu = unique([tLs; tEs{1}; tEs{2}; tEs{3}]);

xLu = interp1(tLs, xL, tu, 'linear','extrap');
xEu = cellfun(@(t,x) interp1(t,x,tu,'linear','extrap'), ...
              tEs, xE, 'uni',0);

% ---------- Figure ----------
clf
figure('Color','w','Name','Three Ego Vehicles Following Same Lead');

n = 3;
left = 0.08; right = 0.04; top = 0.05; bottom = 0.06; vgap = 0.04;
H = (1-top-bottom-(n-1)*vgap)/n;

ax = gobjects(n,1);
Tlead = gobjects(n,1);
Tego  = gobjects(n,1);

carXY = [ -L/2 -W/2; L/2 -W/2; L/2 W/2; -L/2 W/2 ];

for i = 1:n
    ypos = bottom + (n-i)*(H+vgap);
    ax(i) = axes('Position',[left ypos 1-left-right H]);
    hold(ax(i),'on'); grid(ax(i),'on'); axis(ax(i),'equal');

    ylim(ax(i),[-3 3]);
    xlabel(ax(i),'x [m]');
    title(ax(i),labels(i));

    % Lead (top lane)
    Tlead(i) = hgtransform('Parent',ax(i));
    patch('XData',carXY(:,1),'YData',carXY(:,2),'Parent',Tlead(i), ...
          'FaceColor',[0.2 0.6 1],'EdgeColor','k');

    % Ego (bottom lane)
    Tego(i) = hgtransform('Parent',ax(i));
    patch('XData',carXY(:,1),'YData',carXY(:,2),'Parent',Tego(i), ...
          'FaceColor',[1 0.5 0.2],'EdgeColor','k');

    text(ax(i),xLu(1), 1.2, leadLabel,'FontWeight','bold');
    text(ax(i),xEu{i}(1),-1.2, labels(i),'FontWeight','bold');
end

% ---------- Animate ----------
N = numel(tu);
for k = 1:N
    for i = 1:n
        set(Tlead(i),'Matrix',makehgtform('translate',[xLu(k)+L/2 1 0]));
        set(Tego(i),'Matrix', makehgtform('translate',[xEu{i}(k)-L/2 -1 0]));

        egoX = xEu{i}(k);
        xlim(ax(i),[egoX-win/2 egoX+win/2]);
    end

    drawnow limitrate nocallbacks

    if k < N
        dt = (tu(k+1)-tu(k))/spd;
        if dt > 0, pause(min(dt,0.05)); end
    end
end
end


% ===== Helpers =====
function [t, x] = get_tx(s)
    if isa(s, 'timeseries')
        t = s.Time;  x = s.Data;
    elseif istimetable(s)
        if width(s) ~= 1
            error('Timetable must have exactly one variable.');
        end
        t = s.Properties.RowTimes;
        x = s{:,1};
    elseif isnumeric(s)
        if size(s,2) < 2
            error('Numeric input must be Nx2 [t, x].');
        end
        t = s(:,1);
        x = s(:,2);
    elseif isstruct(s) && isfield(s,'t') && isfield(s,'x')
        t = s.t;
        x = s.x;
    else
        error('Unsupported input type.');
    end

    t = t(:);
    x = x(:);
end

function [t, x] = sort_tx(t, x)
    if isnumeric(t)
        [t, idx] = sort(t);
    elseif isdatetime(t) || isduration(t)
        [t, idx] = sort(t);
    else
        error('Unsupported time format.');
    end
    x = x(idx);
end

function ts = to_seconds(t, t0)
    if isdatetime(t) || isduration(t)
        ts = seconds(t - t0);
    else
        ts = t - t0;
    end
    ts = ts(:);
end
