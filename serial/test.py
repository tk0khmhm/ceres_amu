from serial import Serial

ser=Serial('/dev/ttyUSB0', 38400,timeout=1)
ser.write('t05020707\r')

while True:
	#print ser.readline(eol='\r')
	str=ser.readline(eol='\r')
	data=str.split(',')
	print data[0]



