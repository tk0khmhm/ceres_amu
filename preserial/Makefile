
libserial.a : serial.o
	ar rc $@ serial.o

serial.o : serial.cpp
	g++ -o $@ -c serial.cpp

clean:
	rm -f serial.o

