# AWAPI_AWIV_ADAPTER

## get topic

### /awapi/vehicle/get/status

- get vehicle status
- MessageType: awapi_awiv_adapter/AwapiVehicleStatus.msg

| type                      | name                     | unit                                          | note                                         |
| :------------------------ | :----------------------- | :-------------------------------------------- | :------------------------------------------- |
| std_msgs/Header           | header                   |                                               |                                              |
| geometry_msgs/Pose        | pose                     | [m](position)                                 |                                              |
| awapi_awiv_adapter/Euler  | eulerangle               | [rad]                                         | roll/pitch/yaw                               |
| awapi_awiv_adapter/Latlon | latlon                   |                                               | lat/lon/alt                                  |
| float64                   | velocity                 | [m/s]                                         |                                              |
| float64                   | acceleration             | [m/ss]                                        | calculate from velocity in awapi_adapter     |
| float64                   | steering                 | [rad]                                         |                                              |
| float64                   | steering_velocity        | [rad/s]                                       | calculate from steering in awapi_adapter     |
| float64                   | angular_velocity         | [rad/s]                                       |                                              |
| int32                     | gear                     | accroding to autoware_vehicle_msgs/Shift      |                                              |
| float64                   | distance_to_empty        |                                               | <font color="Red">**not implemented**</font> |
| int32                     | turn_signal              | accroding to autoware_vehicle_msgs/TurnSignal |                                              |
| float64                   | target_velocity          | [m/s]                                         |                                              |
| float64                   | target_acceleration      | [m/ss]                                        |                                              |
| float64                   | target_steering          | [rad]                                         |                                              |
| float64                   | target_steering_velocity | [rad/s]                                       |                                              |

### /awapi/autoware/get/status

- get autoware status
- MessageType: awapi_awiv_adapter/AwapiVehicleStatus.msg

| type                               | name                 | unit                                           | note                                                   |
| :--------------------------------- | :------------------- | :--------------------------------------------- | :----------------------------------------------------- |
| std_msgs/Header                    | header               |                                                |                                                        |
| string                             | autoware_state       |                                                |                                                        |
| int32                              | control_mode         | accroding to autoware_vehicle_msgs/ControlMode | manual/auto (changed by /awapi/autoware/put/engage)    |
| int32                              | gate_mode            | autoware_vehicle_msgs/GateMode                 | auto/remote (it is valid only when control_mode=auto)) |
| bool                               | emergency_stopped    | True in emergency mode                         |                                                        |
| StopReasonArray???                 | stop_reason          |                                                | <font color="Red">**not implemented**</font>           |
| diagnostic_msgs/DiagnosticStatus[] | diagnostics          |                                                |                                                        |
| bool                               | autonomous_overriden |                                                | <font color="Red">**not implemented**</font>           |

### /awapi/autoware/get/route

- get route
- MessageType: autoware_planning_msgs/Route

### /awapi/prediction/get/objects

- get predicted object
- MessageType: autoware_perception_msgs/DynamicObjectArray

### /awapi/lane_change/get/status

- get lane change information
- MessageType: awapi_awiv_adapter/LaneChangeStatus.msg

| type                        | name                        | unit                                     | note                                                                               |
| :-------------------------- | :-------------------------- | :--------------------------------------- | :--------------------------------------------------------------------------------- |
| std_msgs/Header             | header                      |                                          |                                                                                    |
| bool                        | force_lane_change_available | True when lane change is avilable        | available: Physically lane changeable state (do not consider other vehicle)        |
| bool                        | lane_change_ready           | True when lane change is ready           | ready: State that ego-vehicle can change lane without collision with other vehicle |
| autoware_planning_msgs/Path | candidate_path              | according to autoware_planning_msgs/Path |                                                                                    |

### /awapi/object_avoidance/get/status

- get obstacle avoidance information
- MessageType: awapi_awiv_adapter/ObstacleAvoidanceStatus.msg

| type                              | name                     | unit                                           | note                                                  |
| :-------------------------------- | :----------------------- | :--------------------------------------------- | :---------------------------------------------------- |
| std_msgs/Header                   | header                   |                                                |                                                       |
| bool                              | obstacle_avoidance_ready | True when obstacle avoidance is ready          |                                                       |
| autoware_planning_msgs/Trajectory | candidate_path           | according to autoware_planning_msgs/Trajectory | Msg type is different from lane change candidate path |

### /awapi/traffic_light/get/status

- get recognition result of traffic light
- MessageType: autoware_perception_msgs/TrafficLightStateArray

## put topic

### /awapi/vehicle/put/velocity

- set upper velocity
- MessageType: std_msgs/Float32

### /awapi/autoware/put/gate_mode

- send gate mode (auto/remote)
- MessageType: autoware_control_msgs/GateMode

### /awapi/autoware/put/emergency

- send emergency signal
- MessageType: std_msgs/Bool
- <font color="Cyan">**Emergency stop does work only in Remote Mode. (not work in Auto Mode)**</font>

### /awapi/autoware/put/engage

- send engage signal (both of autoware/engage and vehicle/engage)
- MessageType: std_msgs/Bool

### /awapi/autoware/put/goal_pose

- send goal pose
- MessageType: geometry_msgs/PoseStamped

### /awapi/lane_change/put/approval

- send lane change approval flag
- send True: start lane change when **lane_change_ready** is true
- MessageType: std_msgs/Bool

### /awapi/lane_change/put/force

- send force lane change flag
- send True: start lane change when **force_lane_change_available** is true
- MessageType: std_msgs/Bool

### /awapi/object_avoidance/put/approval

- send object avoidance approval flag
- MessageType: std_msgs/Bool

### /awapi/object_avoidance/put/force

- send force object avoidance flag
- <font color="Red">**not implemented (Autoware does not have corresponded topic)**</font>

### /awapi/traffic_light/put/traffic_light

- Overwrite the recognition result of traffic light
- <font color="Red">**not implemented (Autoware does not have corresponded topic)**</font>