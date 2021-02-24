/* 
	 Written by Kristoffer Rakstad Solberg & Øyvind Denvik, Students
	 Copyright (c) 2019 Manta AUV, Vortex NTNU.
	 All rights reserved. */

#include <rclcpp/rclcpp.hpp> 									//modified to ros2											
#include <std_msgs/msg/String.hpp>								//modified to ros2
#include <std_msgs/msg/Header.hpp>								//modified to ros2
#include <std_srvs/srv/Empty.hpp>								//modified to ros2
#include <nav_msgs/msg/Odometry.hpp>							//modified to ros2
#include <sensor_msgs/msg/Imu.hpp>								//modified to ros2
#include <sensor_msgs/msg/FluidPressure.hpp>					//modified to ros2
#include <geometry_msgs/msg/Twist.hpp>							//modified to ros2
#include <geometry_msgs/msg/TwistStamped.hpp>					//modified to ros2
#include <geometry_msgs/msg/TwistWithCovariance.hpp>			//modified to ros2
#include <geometry_msgs/msg/TwistWithCovarianceStamped.hpp>		//modified to ros2
#include <geometry_msgs/msg/PoseWithCovarianceStamped.hpp>		//modified to ros2
#include <geometry_msgs/msg/AccelWithCovariance.hpp>			//modified to ros2


/* Include guard to prevent double declaration of identifiers
   such as types, enums and static variacles */

#ifndef __underwaterOdom_ROS_HH__
#define __underwaterOdom_ROS_HH__

class UnderwaterOdom {

	public:

	// Constructor
	UnderwaterOdom();

	// Destructor
	~UnderwaterOdom(){};

	// Functions
	void pressureCallback(const sensor_msgs::FluidPressure &msg);
	void dvlCallback(const geometry_msgs::TwistWithCovarianceStamped &msg);

	private:

	// Nodehandle	

	//ros::NodeHandle nh_;	
	auto nh_ = rclcpp::Node::makeshared("pubsub");
	
	// Subscribers

	//ros::Subscriber fluid_pressure_sub_;
	auto fluid_pressure_sub_ = nh_->create_subscription<sensor_msgs::msg::FluidPressure>;

	//ros::Subscriber dvl_twist_sub_;
	auto dvl_twist_sub_ = nh_->create_subscription<geometry_msgs::msg::TwistWithCovarianceStamped>;

	// Publishers

	//ros::Publisher depth_odom_pub_;
	//ros::Publisher odom_pub_;
	auto odom_pub_ = nh_->create_publisher<nav_msgs::msg::Odometry>;
	// Variables

	double atmospheric_pressure; // [kPa]
	double water_density; //[kg/m3]
	double earth_gravitation; //[m/s2]

	// Messages
	nav_msgs::msg::Odometry odom;

};


#endif // __underwaterOdom_ROS_HH__
