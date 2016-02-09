#!/usr/bin/env python
import roslib; roslib.load_manifest('ceres_amu')
import rospy
from serial import Serial
from ceres_msgs.msg import * 


class MySerial(Serial):
	
	#Wrapper for Serial
	try:
		import io
	except ImportError:
		# serial.Serial inherits serial.FileLike
		pass
	else:
		def readline(self):
		
		#Overrides io.RawIOBase.readline which cannot handle with '\r' delimiters
		
			ret = ''
			while True:
				c = self.read(1)
				if c == '':
					return ret
				elif c == '\r':
					return ret + c
				else:
					ret += c
				

def talker():
	pub = rospy.Publisher('/AMU_data', AMU_data)
	rospy.init_node('ceres_amu')
	#r = rospy.Rate(20) 
	r = rospy.Rate(50) 
	count=0
		
	ser = MySerial('/dev/ttyUSB0', 38400, timeout=1)
	#ser = MySerial('/dev/ttyUSB1', 38400, timeout=1)
	#ser = MySerial('/dev/USB-amu', 38400, timeout=1)
	#ser = MySerial('/dev/USBamu', 38400, timeout=1)

	#Mode Change(float output)
	ser.write('t05020707\r')

	while not rospy.is_shutdown():
		count+=1
		#str=ser.readline(eol='\r')
		str=ser.readline()
		data=str.split(',')

#		print str	
		amu=AMU_data()
		if len(data)==10:
			
			try:
	    			amu.roll= float(data[0])
			except ValueError:
				print "-------------error roll-------------"
				r.sleep()
				continue
			try:
	    			amu.pitch= -float(data[1])
			except ValueError:
				print "-------------error pitch-------------"
				r.sleep()
				continue
			try:
	    			amu.yaw= -float(data[2])
			except ValueError:
				print "-------------error yaw-------------"
				r.sleep()
				continue
			try:
	    			amu.droll= float(data[3])
			except ValueError:
				print "-------------error droll-------------"
				r.sleep()
				continue
			try:
	    			amu.dpitch= -float(data[4])
			except ValueError:
				print "-------------error dpitch-------------"
				r.sleep()
				continue
			try:
	    			amu.dyaw= -float(data[5])
			except ValueError:
				print "-------------error dyaw-------------"
				r.sleep()
				continue
			try:
				amu.xaccel=float(data[6])
			except ValueError:
				print "-------------error xaccel-------------"
				r.sleep()
				continue
			try:
				amu.yaccel=float(data[7])
			except ValueError:
				print "-------------error yaccel-------------"
				r.sleep()
				continue
			try:
				amu.zaccel=float(data[8])
			except ValueError:
				print "-------------error zaccel-------------"
				r.sleep()
				continue
			
			if ((count%5)==0):
				print 'Roll[deg],Pitch[deg],Yaw[deg],droll[deg/s],dpitch[deg/s],dyaw[deg/s],xaccel[G],yaccel[G],zaccel[G],status'
				print "%8.2f" % amu.roll, "%8.2f" % amu.pitch, "%8.2f" % amu.yaw, "%8.2f" % amu.droll, "    %8.2f" % amu.dpitch, "     %8.2f" % amu.dyaw, "   %8.2f" % amu.xaccel, "%8.2f" % amu.yaccel, "   %8.2f" % amu.zaccel, "   %s" % data[9]
				#rospy.loginfo( data )
			
			amu.header.stamp=rospy.Time.now()
			#print amu
			pub.publish(amu)
			"""
			amu.roll=float(data[0])
			amu.pitch=-float(data[1])
			amu.yaw=-float(data[2])
			amu.droll=float(data[3])
			amu.dpitch=-float(data[4])
			amu.dyaw=-float(data[5])
			amu.xaccel=float(data[6])
			amu.yaccel=float(data[7])
			amu.zaccel=float(data[8])
			"""
			#Error Massage
			if data[9]!='0x0000\r':
				if data[9]=='0x0000\r':
					print '====Error of the X axis gyro====='
				elif data[9]=='0x0001\r':
					print '====Error of the Y axis gyro====='
				elif data[9]=='0x0002\r':
					print '====Error of the Z axis gyro====='
				elif data[9]=='0x0003\r':
					print '====Error of the source voltage====='
				elif data[9]=='0x0004\r':
					print '====Error of the 5V voltage====='
				elif data[9]=='0x0005\r':
					print '====Error of the 3.3V voltage====='
				elif data[9]=='0x0006\r':
					print '====Error of the X axis acceleration sensor====='
				elif data[9]=='0x0007\r':
					print '====Error of the Y axis acceleration sensor====='
				elif data[9]=='0x0008\r':
					print '====Error of the Z axis acceleration sensor====='
				elif data[9]=='0x0009\r':
					print '====Error of the temperature sensor====='
				else:
					print '====Error of the unknown source====='
		else:
			print 'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa'
			r.sleep()
			continue

		r.sleep()
	
	rospy.spin()


if __name__ == '__main__':
	talker()

