#ifndef _AMU_SREVER_H
#define _AMU_SREVER_H

#include <ros/ros.h>
#include <ceres_msgs/AMU_data.h>
#include <serial.h>


class AMU_server
{
	private:
		ceres_msgs::AMU_data amu;
		char serial_data[255];
	public:

	ros::NodeHandle node_handle_;
	ros::Publisher pub;

	AMU_server(const ros::NodeHandle& node_handle);

	// メインループ
	void mainLoop();

};

#endif //_AMU_SREVER_H

