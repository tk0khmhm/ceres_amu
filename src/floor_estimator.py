#!/usr/bin/env python
# coding: utf-8
import roslib; roslib.load_manifest('ceres_amu')
import rospy
import numpy as np
from scipy import constants
from ceres_msgs.msg import * 
from std_msgs.msg import Bool 
from std_msgs.msg import Int32
from nav_msgs.msg import Odometry


first_floor = 1		# 最初にいる階
floor_height = 4.17	# 1階分の高さ (D Building)
pfh = 1.0/floor_height

count = 0.0
vcount = 0
g = 0.0
v = 0.0		# 現在の速度
h = (first_floor-1) * floor_height		# 現在の高さ
nsecs = 0.0
amu_flag = False
floor = Int32
ev_flag = Bool
tiny_flag = Bool
g_offset = -1.00085	# AMUのz-accelのoffset 実験値

def amuCallback(data):
        if tiny_flag == False:
            return 0

	#global count	# for DEBUG
	global vcount
	global nsecs
	global g
	global v
	global h
	global amu_flag
	global floor
        global ev_flag
	if data.zaccel != 1 :
		g = data.zaccel + g_offset
	else:
		g = data.zaccel - 1.0

	if amu_flag:
		dt = data.header.stamp.nsecs - nsecs
		dt *= 0.000000001
		if dt<0:
			dt += 1.0;
		v += dt*(g)*constants.g
		h += dt*v
		#print count,	# for DEBUG
		#print dt,
		print g,	# for DEBUG
		print v,	# for DEBUG
		print h*pfh+1	# for DEBUG
		print vcount,
	else:
		amu_flag = True
	
	if np.abs(g) < 0.003:
		vcount += 1
	else:
		vcount = 0

	if vcount > 30 and np.abs(v) < 0.3:
		v = 0
		if 0.0 < np.abs(h) and np.abs(h) < 2.0:
			h = 0

	floor = h*pfh + 1.5

        #print "floor", floor
        if 4 <= floor and floor < 5:
            ev_flag = True
        else:
            ev_flag = False
	nsecs = data.header.stamp.nsecs
	#count += 0.02	# for DEBUG
	

def tinyCallback(data):
    global tiny_flag
    if np.abs(data.twist.twist.linear.x) > 0.001:
        tiny_flag = False
    else:
        tiny_flag = True



if __name__ == '__main__':
	rospy.init_node('floor_estimator')
	amu_sub = rospy.Subscriber("/AMU_data", AMU_data, amuCallback)
	tiny_sub = rospy.Subscriber("/tinypower/odom", Odometry, tinyCallback)
	floor_pub = rospy.Publisher("/floor", Int32, queue_size=10)
	ev_flag_pub = rospy.Publisher("/ev_flag", Bool, queue_size=10)
	r = rospy.Rate(2) 

	floor = first_floor
        ev_flag = False
        tiny_flag = True
	
	while not rospy.is_shutdown():

		floor_pub.publish(floor)
                ev_flag_pub.publish(ev_flag)
			
		r.sleep()
	rospy.spin()

