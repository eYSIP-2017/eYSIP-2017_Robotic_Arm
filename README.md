# eYSIP-2017_Robotic_Arm

This repo contains three ROS packages:

1. robotic_arm_description

This package contains the URDF file of the robotic arm. To view the robotic arm in RViz clone this package to your workspace and type the following command:

        roslaunch robotic_arm_description view_arm.launch
        
2. robotic_arm_config

This package is generated using the MoveIt! Setup Assistant. It contains the srdf and the configuration files used by MoveIt! to start motion planning in RViz. There is a demo launch file in the package to explore all the functionalities of this package.

         roslaunch robotic_arm_config demo.launch

3. robotic_arm_gazebo

This package is used to interface the robotic arm in Gazebo with MoveIt!. We can start motion planning inside RViz and execute in Gazebo using the following commands:

This launch file spawns the robot model in Gazebo, publishes the joint states and attaches the trajectory controller to the joints.

        roslaunch robotic_arm_gazebo robotic_arm_bringup_gazebo.launch
        
This launch file will start the MoveIt! nodes along with RViz.

        roslaunch robotic_arm_gazebo robotic_arm_bringup_rviz.launch
        
