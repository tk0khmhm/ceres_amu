#!/usr/bin/env python
# coding: utf-8
import roslib; roslib.load_manifest('ceres_amu')
import rospy
import numpy as np
from scipy import constants
from ceres_msgs.msg import * 
from std_msgs.msg import Bool 
from std_msgs.msg import Int32


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
g_offset = -1.00085	# AMUのz-accelのoffset 実験値

def amuCallback(data):
	#global count	# for DEBUG
	global vcount
	global nsecs
	global g
	global v
	global h
	global amu_flag
	global floor
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
		#print vcount,
		#print dt,
		#print g,	# for DEBUG
		#print v,	# for DEBUG
		#print h*pfh+1	# for DEBUG
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

	nsecs = data.header.stamp.nsecs
	#count += 0.02	# for DEBUG
	



if __name__ == '__main__':
	rospy.init_node('floor_estimator')
	amu_sub = rospy.Subscriber("/AMU_data", AMU_data, amuCallback)
	floor_pub = rospy.Publisher("/floor", Int32, queue_size=10)
	r = rospy.Rate(2) 

	floor = first_floor
	
	while not rospy.is_shutdown():

		floor_pub.publish(floor)
			
		r.sleep()
	rospy.spin()

