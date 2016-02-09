#include <sys/types.h>
#include "AMU_server.h"
#include <iostream>
#include <stdio.h>

using namespace std;

#define OUTGGA
#define OUTGST
#define OUTGSA
#define OUTVTG

const int NCHAR=200;

int chnum(char* tmp);
void Dataset(char* serial_data,ceres_msgs::AMU_data &amu);

void DataSend();



AMU_server::AMU_server(const ros::NodeHandle& node_handle)
: node_handle_(node_handle)
{
 	// publisherの初期化
	pub=node_handle_.advertise<ceres_msgs::AMU_data>("AMU_data", 100);
}



void
AMU_server::mainLoop()
{
	ros::Rate loop_rate(1); // ループの周期 100Hz
	int count = 0;

	//Serial serial(B38400, "/dev/ttyUSB0", 256,ICANON);	
	Serial serial(B38400, "/dev/ttyUSB0", 255,0);	
	//Serial serial(B19200, "/dev/ttyUSB0", 200);	
	//Serial serial(B9600, "/dev/ttyUSB0", 200);	

	//Serial serial(B19200, "/dev/ttyS0", 200);	


	cout<<serial_data<<endl;
	for(int i=0;i<=10;i++){
		//cout<<i<<endl;
	//char start[]="t05020707\r";
	char start[]="t05020707\x0d";
	serial.write_serial(start,sizeof(start));
	}


	while(ros::ok())
	{
		//Serial Data Read
		serial.read_serial(serial_data, 250);	
		cout<<serial_data<<endl;

		//Dataset(serial_data,amu);
		cout<<"publish"<<endl;
		
		pub.publish(amu);

		ROS_INFO("Hello there! This is message No. [ %d ]", count);

		// latch timerのようなもの
		ros::spinOnce();
		//loop_rate.sleep();
		
		++count;
	}

}

void Dataset(char* serial_data, ceres_msgs::AMU_data &amu){ 
	cout<<"Data set"<<endl;

	char* tmp;
	tmp = new char[NCHAR];
	tmp=serial_data;

	cout<<tmp<<endl;
	
	//tmp = strstr(serial_data, "GPGGA");
	//tmp = strchr(tmp, ',');

	if(tmp!=NULL){
		cout<<"neko"<<endl;
		//Roll
		tmp=strchr(tmp,',');
		if(tmp != NULL){
			cout<<tmp<<endl;
			printf("%s\n",tmp);
			amu.roll = strtod(tmp+2, NULL);
			cout<<"Roll[deg]:"<<amu.roll<<endl;
		}
		else{
			return;
		}
/*
		//Latitude
		tmp=strchr(tmp+1, ',');
		f=chnum(tmp);
		if(tmp != NULL&&f!=0){
			//Convert to degree
			sprintf(tmpla,"%c%c",tmp[1],tmp[2]);
//			gps->Lat = atof(tmpla) + strtod(tmp+3, NULL) / 60;
			gps.Lat = atof(tmpla) + strtod(tmp+3, NULL) / 60;
			#ifdef OUTGGA
//			cout<<"Lat:"<<gps->Lat<<endl;
//			cout<<"Lat:"<<gps.Lat<<endl;
			printf("Lat=%3.8f",gps.Lat);
			#endif
		}
		else{
			return;
		}

		//Longitude
		tmp=strchr(tmp+1,',');
		tmp=strchr(tmp+1,',');
		f=chnum(tmp);
		if(tmp != NULL&&f!=0){
			sprintf(tmplo,"%c%c%c",tmp[1],tmp[2],tmp[3]);
//			gps->Lon = atof(tmplo) + strtod(tmp+4, NULL) / 60;
			gps.Lon = atof(tmplo) + strtod(tmp+4, NULL) / 60;
			#ifdef OUTGGA
//			cout<<"Lon:"<<gps->Lon<<endl;
//			cout<<"Lon:"<<gps.Lon<<endl;
			printf("Lon=%3.8f",gps.Lon);
			#endif
		}
		else{
			return;
		}


		//Precision
		//Fix quality: 0 = invalid 
 		//			   1 = GPS fix (SPS) 
		//             2 = DGPS fix 
	    //             3 = PPS fix 
		//    		   4 = Real Time Kinematic 
		//             5 = Float RTK 
		// 			   6 = estimated (dead reckoning) (2.3 feature) 
		//			   7 = Manual input mode
		//			   8 = Simulation mode 
		tmp= strchr(tmp+1,',');
		tmp= strchr(tmp+1,',');

		f=chnum(tmp);
		if(tmp != NULL&&f!=0){
//			gps->Precision = strtol(tmp+1, NULL, 10);
			gps.Precision = strtol(tmp+1, NULL, 10);
			#ifdef OUTGGA
//			cout<<"Precision:"<<gps->Precision<<endl;
			cout<<"Precision:"<<gps.Precision<<endl;
			#endif
		}
		else{ 
			return;
		}
		
		//The number of Satelites
		tmp= strchr(tmp+1,',');
		f=chnum(tmp);
		if(tmp != NULL&&f!=0){
//			gps->Satelites = strtol(tmp+1, NULL, 10);
			gps.Satelites = strtol(tmp+1, NULL, 10);
			#ifdef OUTGGA
//			cout<<"Satelites:"<<gps->Satelites<<endl;
			cout<<"Satelites:"<<gps.Satelites<<endl;
			#endif
		}
		else{ 
			return;
		}


		//Horizontal dilution of position
		tmp= strchr(tmp+1,',');
		f=chnum(tmp);
		if(tmp != NULL&&f!=0){
//			gps->HDOP = strtod(tmp+1, NULL);
			gps.HDOP = strtod(tmp+1, NULL);
			#ifdef OUTGGA
//			cout<<"HDOP:"<<gps->HDOP<<endl;
			cout<<"HDOP:"<<gps.HDOP<<endl;
			#endif

		}
		else{ 
			return;
		}


		//Altitude(Meters) above mean sea level
		tmp= strchr(tmp+1,',');
		f=chnum(tmp);
		if(tmp != NULL&&f!=0){
//			gps->Alt = strtod(tmp+1, NULL);
			gps.Alt = strtod(tmp+1, NULL);
			#ifdef OUTGGA
//			cout<<"Alt:"<<gps->Alt<<endl;
			cout<<"Alt:"<<gps.Alt<<endl;
			#endif
		}
		else{ 
			return;
		}

		//Height of geoid (mean sea level) above WGS84 
		tmp= strchr(tmp+1,',');
		tmp= strchr(tmp+1,',');
		f=chnum(tmp);
		if(tmp != NULL&&f!=0){
//			gps->Geo = strtod(tmp+1, NULL);
			gps.Geo = strtod(tmp+1, NULL);
			#ifdef OUTGGA
//			cout<<"Geo:"<<gps->Geo<<endl;
			cout<<"Geo:"<<gps.Geo<<endl;
			#endif
		}
		else{ 
			return;
		}

		//Time in seconds since last DGPS update
		tmp= strchr(tmp+1,',');
		tmp= strchr(tmp+1,',');
		f=chnum(tmp);
		if(tmp != NULL&&f!=0){
//			gps->Lack = strtol(tmp+1, NULL, 10);
			gps.Lack = strtol(tmp+1, NULL, 10);
			#ifdef OUTGGA
//			cout<<"Lack:"<<gps->Lack<<endl;
			cout<<"Lack:"<<gps.Lack<<endl;
			#endif
		}
		else{ 
			return;
		}

		//DGPS station ID number
		tmp= strchr(tmp+1,',');
		f=chnum(tmp);
		if(tmp != NULL&&f!=0){
//			gps->Station_ID = strtol(tmp+1, NULL, 10);
			gps.Station_ID = strtol(tmp+1, NULL, 10);
			#ifdef OUTGGA
//			cout<<"Station_ID:"<<gps->Station_ID<<endl;
			cout<<"Station_ID:"<<gps.Station_ID<<endl;
			#endif
		}
		else{ 
			return;
		}

		//The checksum data of GGA
		tmp= strchr(tmp+1,'*');
		f=chnum(tmp);
		if(tmp != NULL&&f!=0){
//			gps->Ch_sum = strtol(tmp+1, NULL, 10);
			gps.Ch_sum = strtol(tmp+1, NULL, 10);
			#ifdef OUTGGA
//			cout<<"Ch_sum:"<<gps->Ch_sum<<endl;
			cout<<"Ch_sum:"<<gps.Ch_sum<<endl;
			#endif
		}
		else{ 
			return;
		}
	}

//	printf("GPS = %.8f\t%.8f\t%d\t%d\n",gps->Lat,gps->Lon,gps->Satelites,gps->Precision);
	printf("GPS = %.8f\t%.8f\t%d\t%d\n",gps.Lat,gps.Lon,gps.Satelites,gps.Precision);
	


	#ifdef OUTGGA
//	cout<<gps->Time<<" "<<gps->Lat<<" "<<gps->Lon<<" "<<gps->Precision<<" "<<gps->Satelites<<" "<<gps->HDOP<<" "<<gps->Alt<<endl;
	cout<<"OUTGGA"<<gps.Time<<" "<<gps.Lat<<" "<<gps.Lon<<" "<<gps.Precision<<" "<<gps.Satelites<<" "<<gps.HDOP<<" "<<gps.Alt<<endl;
	#endif
	cout<<"End GGA"<<endl;

	delete [] tmp;
	cout<<"delete tmp"<<endl;

//	delete [] &endstr;
//	cout<<"delete endstr"<<endl;

*/
	}
	return;
}



