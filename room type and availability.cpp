#include<iostream>
#include<iomanip>
#include<string.h>
#include<cstring>

using namespace std;
struct roomName //structure for room name and description
{
	char type[25];
	char describe[60];
};
struct rooms //room attributes
{
	roomName ro;
	unsigned int roomNo, beds;
	bool AC, InRoomSafe, avail;
	float price;
};

void roomStat (rooms r[]);//function for printing the existing rooms with their status;
void roomDescription(rooms r[]);//function for initializing all the types of rooms with their respective attributes

int main()
{
	rooms R[80];//80 rooms created
	roomDescription(R);//initializing all rooms
	cout<<"status\n";
	roomStat(R);//displays all the room's status
	return 0;
}
void roomDescription(rooms r[])
{
	for(int i=0;i<80;i++)
	{
		if(i>=0 && i<10)
		{
			strcpy(r[i].ro.type,"Single Room");//naming a specific range of rooms
		strcpy(r[i].ro.describe,"single bed for single occupancy");//describing the room type
			r[i].roomNo=i+1;
			r[i].beds=1;
			r[i].price=500.00;
			if(i>=0 &&i<5)
				{r[i].AC=true; r[i].price+=30;}//providing Ac for half the rooms
			else 
				{r[i].AC=false;}
			if(i>=3 && i<8)
			 {r[i].InRoomSafe=true;r[i].price+=40;}//providing  inroom safe for 5 rooms, some have AC and some don't
			else 
				{r[i].InRoomSafe=false;}
			r[i].avail=true;
		}
		
	else if(i>=10 && i<20)
		{
				strcpy(r[i].ro.type,"Twin room");
			strcpy(r[i].ro.describe,"single beds for double occupancy");
			r[i].roomNo=i+1;
			r[i].beds=2;
			r[i].price=700.00;
			
			if(i>=10 &&i<15)
				{r[i].AC=true; r[i].price+=30;}
			else 
				{r[i].AC=false;}
			if(i>=13 && i<18)
			 {r[i].InRoomSafe=true;r[i].price+=40;}
			else 
				{r[i].InRoomSafe=false;}
			
			r[i].avail=true;
		}
		else if(i>=20 && i<30)
		{
				strcpy(r[i].ro.type,"Double Room");
			strcpy(r[i].ro.describe,"single bed for double occupancy");
			r[i].roomNo=i+1;
			r[i].beds=1;
			r[i].price=750.00;
			
			if(i>=20 &&i<25)
				{r[i].AC=true; r[i].price+=30;}
			else 
				{r[i].AC=false;}
			if(i>=23 && i<28)
			 {r[i].InRoomSafe=true;r[i].price+=40;}
			else 
				{r[i].InRoomSafe=false;}
		
			r[i].avail=true;
		}
		else if(i>=30 && i<40)
		{
				strcpy(r[i].ro.type,"Double & Double Room");
			strcpy(r[i].ro.describe,"double beds for 4 people");
			r[i].roomNo=i+1;
			r[i].beds=2;
			r[i].price=800.00;
			
			if(i>=30 &&i<35)
				{r[i].AC=true; r[i].price+=30;}
			else 
				{r[i].AC=false;}
			if(i>=33 && i<38)
			 {r[i].InRoomSafe=true;r[i].price+=40;}
			else 
				{r[i].InRoomSafe=false;}
		
			r[i].avail=true;
		}
		else if(i>=40 && i<50)
		{
				strcpy(r[i].ro.type,"Triple Room");
			strcpy(r[i].ro.describe,"single beds for 3 people");
			r[i].roomNo=i+1;
			r[i].beds=3;
			r[i].price=850.00;
			
			if(i>=40 &&i<45)
				{r[i].AC=true; r[i].price+=30;}
			else 
				{r[i].AC=false;}
			if(i>=43 && i<48)
			 {r[i].InRoomSafe=true;r[i].price+=40;}
			else 
				{r[i].InRoomSafe=false;}
		
			r[i].avail=true;
		}
		else if(i>=50 && i<60)
		{
				strcpy(r[i].ro.type,"King Room");
			strcpy(r[i].ro.describe,"6ftX6ft king sized bed");
			r[i].roomNo=i+1;
			r[i].beds=1;
			r[i].price=900.00;
			
				if(i>=50 &&i<55)
				{r[i].AC=true; r[i].price+=30;}
			else 
				{r[i].AC=false;}
			if(i>=53 && i<58)
			 {r[i].InRoomSafe=true;r[i].price+=40;}
			else 
				{r[i].InRoomSafe=false;}
		
			r[i].avail=true;
		}
		else if(i>=60 && i<70)
		{
				strcpy(r[i].ro.type,"Queen Room");
			strcpy(r[i].ro.describe,"5ftX6ft queen sized bed");
			r[i].roomNo=i+1;
			r[i].beds=1;
			r[i].price=870.00;
				
			if(i>=60 &&i<65)
				{r[i].AC=true; r[i].price+=30;}
			else 
				{r[i].AC=false;}
			if(i>=63 && i<68)
			 {r[i].InRoomSafe=true;r[i].price+=40;}
			else 
				{r[i].InRoomSafe=false;}
		
			r[i].avail=true;
		}
		else if(i>=70 && i<80)
		{
				strcpy(r[i].ro.type,"Interconnecting Room");
			strcpy(r[i].ro.describe,"2 rooms with a common wall and door");
			r[i].roomNo=i+1;
			r[i].beds=2;
			r[i].price=950.00;
				
			if(i>=70 &&i<75)
				{r[i].AC=true; r[i].price+=30;}
			else 
				{r[i].AC=false;}
			if(i>=73 && i<78)
			 {r[i].InRoomSafe=true;r[i].price+=40;}
			else 
				{r[i].InRoomSafe=false;}
		
			r[i].avail=true;
		}
	}
}
void roomStat (rooms r[])
{
	cout<<" "<<setfill('_')<<setw(132)<<"_"<<setfill(' ')<<endl;
	cout<<setw(7)<<"|Room NO|"<<setw(25)<<"Room Type|"<<setw(38)<<"   Description  |"<<setw(11)<<"price(ETB)|"<<setw(12)<<"NO of beds|"<<setw(8)<<"AC|"<<setw(16)<<"In room safe|"<<setw(15)<<"availability|"<<endl;
	cout<<"|"<<setfill('=')<<setw(8)<<"|"<<setw(25)<<"|"<<setw(38)<<"|"<<setw(11)<<"|"<<setw(12)<<"|"<<setw(8)<<"|"<<setw(16)<<"|"<<setw(15)<<"|"<<setfill(' ')<<endl;
	for(int i=0;i<80;i++)
	{
		cout<<"| "<<left<<setw(5)<<r[i].roomNo<<right<<" |"<<setw(24)<<r[i].ro.type<<"|"<<right<<setw(37)<<r[i].ro.describe<<"|"<<setw(10)<<r[i].price<<"|"<<setw(11)<<r[i].beds<<"|";
		if(r[i].AC==true)
			{cout<<setw(8)<<"AC|";}
		else 
			{cout<<setw(8)<<"no AC|";}
		if(r[i].InRoomSafe==true) 
			{cout<<setw(16)<<"available|";}
		else
			{cout<<setw(16)<<"not available|";}
			
		if(r[i].avail=true)
			{cout<<setw(15)<<"vacant|"<<endl;}
		else
			{cout<<setw(15)<<"reserved|"<<endl;}
	}
		cout<<"'"<<setfill('-')<<setw(8)<<"'"<<setw(25)<<"'"<<setw(38)<<"'"<<setw(11)<<"'"<<setw(12)<<"'"<<setw(8)<<"'"<<setw(16)<<"'"<<setw(15)<<"'"<<setfill(' ')<<endl;
}

