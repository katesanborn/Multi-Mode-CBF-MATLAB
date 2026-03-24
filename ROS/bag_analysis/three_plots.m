%% choose your file
[fileName, pathName] = uigetfile('*.bag');

bag = rosbag([pathName, fileName]);

%% ego groups
egos = {
    'egocar_original'
    'egocar_heaviside'
    'egocar_multimodal'
};

%% signals to plot
signals = {
    'car/state/vel_x', 'Velocity v_x (m/s)'
    'rel_vel',         'Relative velocity (m/s)'
    'lead_dist',       'Lead distance (m)'
    'cmd_accel',       'Command acceleration (m/s^2)'
};

%% loop over each signal -> one figure
for s = 1:size(signals,1)

    topic_suffix = signals{s,1};
    ylab = signals{s,2};

    figure
    tiledlayout(3,1,'TileSpacing','compact')
    sgtitle(topic_suffix,'Interpreter','none')

    for i = 1:numel(egos)
        ego = egos{i};
        topic = ['/' ego '/' topic_suffix];

        try
            sig_bag = select(bag,'Topic',topic);
            ts = timeseries(sig_bag);

            nexttile
            plot(ts.Time, ts.Data)
            grid on
            ylabel({ego, ylab},'Interpreter','none')

        catch
            nexttile
            text(0.5,0.5,'Topic not found','HorizontalAlignment','center')
            ylabel(ego,'Interpreter','none')
        end
    end

    xlabel('Time (s)')
end
