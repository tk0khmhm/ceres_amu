#include <ros/ros.h>
#include "AMU_server.h"

using namespace std;

int main(int argc, char** argv)
{
	ros::init(argc, argv, "AMU_server");
	ros::NodeHandle n;

	AMU_server t(n);
	t.mainLoop();
}
