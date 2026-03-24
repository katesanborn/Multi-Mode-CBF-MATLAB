[fileName, pathName] = uigetfile('*.bag');

bag = rosbag([pathName, fileName]);




lead_odom = bag_float64_tx(bag, '/leadcar/odom_x');

ego_heaviside  = bag_float64_tx(bag, '/egocar_heaviside/odom_x');
ego_multimodal = bag_float64_tx(bag, '/egocar_multimodal/odom_x');
ego_original   = bag_float64_tx(bag, '/egocar_original/odom_x');

figure
replay_three_egos_stacked( ...
    lead_odom, ...
    {ego_heaviside, ego_multimodal, ego_original}, ...
    'Labels', {'Heaviside','Multimodal','Original'}, ...
    'LeadLabel','Lead Car', ...
    'Window', 100, ...
    'Speed', 1.0);

% ===== Helpers =====
function tx = bag_float64_tx(bag, topic)
    bsel = select(bag, 'Topic', topic);

    % Read messages (no Header inside std_msgs/Float64)
    msgs = readMessages(bsel, 'DataFormat','struct');

    % ROS time comes from the bag, not the message
    t = bsel.MessageList.Time;   % seconds (double)
    n = numel(msgs);

    x = zeros(n,1);
    for i = 1:n
        x(i) = msgs{i}.Data;
    end

    tx = [t x];   % Nx2 [time, value]
end