#include <ros/ros.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>

#include <moveit/planning_scene_monitor/planning_scene_monitor.h>
#include <moveit/move_group_interface/move_group.h>
#include <geometric_shapes/solid_primitive_dims.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

// MoveIt!
#include <moveit_msgs/PlanningScene.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit_msgs/GetStateValidity.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/RobotState.h>

#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_state/robot_state.h>
#include <moveit/robot_state/conversions.h>

// TF

#include <tf/transform_datatypes.h>

int main(int argc, char **argv)
{
  ros::init (argc, argv, "test_motion");
  ros::AsyncSpinner spinner(3);
  spinner.start();

  // We will use the :planning_scene_interface:`PlanningSceneInterface
  // class to deal directly with the world.
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;  


  ros::NodeHandle nh;

  moveit::planning_interface::MoveGroup group("five_dof_arm");
  group.setPlanningTime(20.0);

  // wait a bit for ros things to initialize
  ros::WallDuration(7.0).sleep();

  // (Optional) Create a publisher for visualizing plans in Rviz.
  ros::Publisher display_publisher = nh.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
  moveit_msgs::DisplayTrajectory display_trajectory;

  //**********************************//

//  geometry_msgs::Pose target_pose ;

//  target_pose.position.x = 0.186607 ;
//  target_pose.position.y = -0.123478 ;
//  target_pose.position.z = 0.334514 ;

//  target_pose.orientation.x = 0.860345 ;
//  target_pose.orientation.y = -0.259267 ;
//  target_pose.orientation.z = -0.420013 ; 
//  target_pose.orientation.w = -0.127185 ;

//  moveit::planning_interface::MoveGroup::Plan my_plan;
//  group.setPoseTarget(target_pose) ;
//  bool success = group.plan(my_plan) ;

//  group.move() ;
//  sleep(5.0) ;

//  //**********************************//

//  target_pose.position.x = 0.192392 ;
//  target_pose.position.y = -0.127216 ;
//  target_pose.position.z = 0.229064 ;

//  target_pose.orientation.x = 0.171493 ;
//  target_pose.orientation.y = 0.689606 ;
//  target_pose.orientation.z = -0.169133 ; 
//  target_pose.orientation.w = 0.682955 ; 

//  group.setPoseTarget(target_pose) ;
//  success = group.plan(my_plan) ;

//  group.move() ;
//  sleep(5.0) ;

//  //***********************************//

//  target_pose.position.x = 0.192305 ;
//  target_pose.position.y = -0.126944 ;
//  target_pose.position.z = 0.162996 ;

//  target_pose.orientation.x = 0.171435 ;
//  target_pose.orientation.y = 0.689546 ;
//  target_pose.orientation.z = -0.169125 ; 
//  target_pose.orientation.w = 0.683033 ;

//  group.setPoseTarget(target_pose) ;
//  success = group.plan(my_plan) ;

//  group.move() ;
//  sleep(5.0) ;

//  //*********************************//

//  target_pose.position.x = 0.186607 ;
//  target_pose.position.y = -0.123478 ;
//  target_pose.position.z = 0.334514 ;

//  target_pose.orientation.x = 0.860345 ;
//  target_pose.orientation.y = -0.259267 ;
//  target_pose.orientation.z = -0.420013 ; 
//  target_pose.orientation.w = -0.127185 ;

//  group.setPoseTarget(target_pose) ;
//  success = group.plan(my_plan) ;

//  group.move() ;
//  sleep(5.0) ;

//  //*********************************//

//  std::vector<double> joint_values;
//  group.getCurrentState()->copyJointGroupPositions(group.getCurrentState()->getRobotModel()->getJointModelGroup(group.getName()),joint_values);

//  joint_values[0] = 0.0 ;
//  
//  group.setJointValueTarget(joint_values);
//  success = group.plan(my_plan);

//  group.move() ;
//  sleep(5.0) ;

//  //********************************//

//  target_pose.position.x = 0.302949 ;
//  target_pose.position.y = 0.0 ;
//  target_pose.position.z = 0.453539 ;

//  target_pose.orientation.x = 0.0 ;
//  target_pose.orientation.y = -0.250106 ;
//  target_pose.orientation.z = 0.0 ; 
//  target_pose.orientation.w = 0.968219 ;

//  group.setPoseTarget(target_pose) ;
//  success = group.plan(my_plan) ;

//  group.move() ;
//  sleep(5.0) ;

//  //*******************************//

//  group.setJointValueTarget(joint_values);
//  success = group.plan(my_plan);

//  group.move() ;
//  sleep(5.0) ; 

//  //******************************//

//  target_pose.position.x = 0.186607 ;
//  target_pose.position.y = -0.123478 ;
//  target_pose.position.z = 0.334514 ;

//  target_pose.orientation.x = 0.860345 ;
//  target_pose.orientation.y = -0.259267 ;
//  target_pose.orientation.z = -0.420013 ; 
//  target_pose.orientation.w = -0.127185 ;

//  group.setPoseTarget(target_pose) ;
//  success = group.plan(my_plan) ;

//  group.move() ;
//  sleep(5.0) ;

//  //***********************************//

//  target_pose.position.x = 0.192305 ;
//  target_pose.position.y = -0.126944 ;
//  target_pose.position.z = 0.162996 ;

//  target_pose.orientation.x = 0.171435 ;
//  target_pose.orientation.y = 0.689546 ;
//  target_pose.orientation.z = -0.169125 ; 
//  target_pose.orientation.w = 0.683033 ;

//  group.setPoseTarget(target_pose) ;
//  success = group.plan(my_plan) ;

//  group.move() ;
//  sleep(5.0) ;

  //********* Move Above Spatula *******************//

  geometry_msgs::Pose target_pose ;

  target_pose.position.x = 0.215216 ;
  target_pose.position.y = 0.136681 ;
  target_pose.position.z = 0.214499 ;

  target_pose.orientation.x = -0.189697 ;
  target_pose.orientation.y = 0.65263 ;
  target_pose.orientation.z = 0.204747 ; 
  target_pose.orientation.w = 0.704391 ;

  moveit::planning_interface::MoveGroup::Plan my_plan;
  group.setPoseTarget(target_pose) ;
  bool success = group.plan(my_plan) ;

  group.move() ;
  sleep(5.0) ;

  //*********** Move Down To Spatula ****************//

  target_pose.position.x = 0.215655 ;
  target_pose.position.y = 0.140632 ;
  target_pose.position.z = 0.177858 ;

  target_pose.orientation.x = -0.200749 ;
  target_pose.orientation.y = 0.675465 ;
  target_pose.orientation.z = 0.202138 ; 
  target_pose.orientation.w = 0.680138 ;

  group.setPoseTarget(target_pose) ;
  success = group.plan(my_plan) ;

  group.move() ;
  sleep(5.0) ;

  //************** Raise Spatula **********************//

  target_pose.position.x =  0.201171 ;
  target_pose.position.y = 0.111921 ;
  target_pose.position.z = 0.458814 ;

  target_pose.orientation.x =  0.0195028 ;
  target_pose.orientation.y =  -0.0749852 ;
  target_pose.orientation.z =  0.250382 ;
  target_pose.orientation.w =  0.965042 ;

  group.setPoseTarget(target_pose) ;
  success = group.plan(my_plan) ;

  group.move() ;
  sleep(5.0) ;
 
  //************* Move On Top of Pan *****************//

  target_pose.position.x = 0.290593 ;
  target_pose.position.y = -0.0388631 ;
  target_pose.position.z = 0.431771 ;

  target_pose.orientation.x = 0.0038246;
  target_pose.orientation.y = 0.057953;
  target_pose.orientation.z = -0.0663112;
  target_pose.orientation.w = 0.996107 ; 

  group.setPoseTarget(target_pose) ;
  success = group.plan(my_plan) ;

  group.move() ;
  sleep(5.0) ;

  //*************** Move Inside Pan ****************//

  target_pose.position.x = 0.323842 ;
  target_pose.position.y = -0.0436582 ;
  target_pose.position.z = 0.311512 ;

  target_pose.orientation.x = 0.0043239 ;
  target_pose.orientation.y = 0.0644582;
  target_pose.orientation.z = -0.0668125;
  target_pose.orientation.w = 0.995672;

  group.setPoseTarget(target_pose) ;
  success = group.plan(my_plan) ;

  group.move() ;
  sleep(5.0) ;

  //****************//

  std::vector<geometry_msgs::Pose> waypoints;
  moveit::planning_interface::MoveGroup::Plan plan;

  target_pose.position.x = 0.323286 ;
  target_pose.position.y = -0.064085 ;
  target_pose.position.z = 0.31122 ;

  target_pose.orientation.x = 0.00624292 ;
  target_pose.orientation.y = 0.0636588 ;
  target_pose.orientation.z = -0.09749 ;
  target_pose.orientation.w = 0.993179 ;

  waypoints.push_back(target_pose) ;

  //****************//

  target_pose.position.x = 0.281562 ;
  target_pose.position.y = -0.0898047 ;
  target_pose.position.z = 0.315693 ;

  target_pose.orientation.x = 0.0095693 ;
  target_pose.orientation.y = 0.0612873 ;
  target_pose.orientation.z = -0.153469 ;
  target_pose.orientation.w = 0.986205 ;

  waypoints.push_back(target_pose) ;

  //****************//

  target_pose.position.x = 0.234376 ;
  target_pose.position.y = -0.0832809 ;
  target_pose.position.z = 0.321495 ;

  target_pose.orientation.x = 0.0104827 ;
  target_pose.orientation.y = 0.0606377 ;
  target_pose.orientation.z = -0.16956 ;
  target_pose.orientation.w = 0.983597 ;

  waypoints.push_back(target_pose) ;

  //****************//

  target_pose.position.x = 0.223659 ;
  target_pose.position.y = -0.0443245 ;
  target_pose.position.z = 0.324421 ;

  target_pose.orientation.x = 0.00624502 ;
  target_pose.orientation.y = 0.0635921 ;
  target_pose.orientation.z = -0.0974667 ;
  target_pose.orientation.w = 0.993185 ;

  waypoints.push_back(target_pose) ;

  //****************//

  target_pose.position.x = 0.219258 ;
  target_pose.position.y = -0.00492512 ;
  target_pose.position.z = 0.32612 ;

  target_pose.orientation.x = 0.00723068 ;
  target_pose.orientation.y = 0.0639073 ;
  target_pose.orientation.z = -0.116235 ;
  target_pose.orientation.w = 0.997862 ;

  waypoints.push_back(target_pose) ;

  //****************//

  target_pose.position.x = 0.264904 ;
  target_pose.position.y = 0.0231531;
  target_pose.position.z = 0.32093 ;

  target_pose.orientation.x = 0.00369308 ;
  target_pose.orientation.y = 0.0638963 ;
  target_pose.orientation.z = 0.0430743 ;
  target_pose.orientation.w = 0.99702 ;

  waypoints.push_back(target_pose) ;

  //****************//

  target_pose.position.x = 0.319381 ;
  target_pose.position.y = 0.0395802 ;
  target_pose.position.z = 0.31399 ;

  target_pose.orientation.x = 0.00257683 ;
  target_pose.orientation.y = 0.0636864 ;
  target_pose.orientation.z = 0.0610732 ;
  target_pose.orientation.w = 0.996096 ;

  waypoints.push_back(target_pose) ;

  //****************//

  target_pose.position.x = 0.323842 ;
  target_pose.position.y = -0.0436582 ;
  target_pose.position.z = 0.311512 ;

  target_pose.orientation.x = 0.0043239 ;
  target_pose.orientation.y = 0.0644582;
  target_pose.orientation.z = -0.0668125;
  target_pose.orientation.w = 0.995672;

  waypoints.push_back(target_pose) ;

  //****************//

  moveit_msgs::RobotTrajectory trajectory_msg;
  double fraction = group.computeCartesianPath(waypoints,
                                             0.01,  // eef_step
       
                                      0.0,   // jump_threshold
                                             trajectory_msg);
  plan.trajectory_ = trajectory_msg;
  ROS_INFO("Visualizing plan 4 (cartesian path) (%.2f%% acheived)",
      fraction * 100.0);
  /* Sleep to give Rviz time to visualize the plan. */
  sleep(3.0);

  group.execute(plan);
  
  sleep(1.0) ;

  fraction = group.computeCartesianPath(waypoints,
                                             0.01,  // eef_step
       
                                      0.0,   // jump_threshold
                                             trajectory_msg);
  plan.trajectory_ = trajectory_msg;
  ROS_INFO("Visualizing plan 4 (cartesian path) (%.2f%% acheived)",
      fraction * 100.0);
  /* Sleep to give Rviz time to visualize the plan. */
  sleep(1.0);

  group.execute(plan);

  ros::waitForShutdown();
  return 0;
}
