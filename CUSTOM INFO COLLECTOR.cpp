#include <iostream>
#include<cstdio>
using namespace std;

struct CustInfo
{
	char SocialMedia[10];
	char Allergy[50];
	char Email[20];
	char Comment[100];
	char RoomPref;
}custom;
char choice,EmailOpt,s_mediaOpt,allergyOpt,infOpt;
int main()
{
	cout<<"\t   Additional information collecting page inorder to make our service more convenient"<<endl;
	
	tryagain1:
	cout<<"\n \n Enter 'Y' if you have any allergies if no enter 'N': \n";
	  cin>>allergyOpt;
	
	if((allergyOpt==121)||(allergyOpt==89))
	{
		cout<<"\n Enter what your allergies are: \n";
		cin>>custom.Allergy;
	}
	else if ((allergyOpt==110)||(allergyOpt==78))
	{
		goto tryagain2;
	}
	else {cout<<"wrong entry! please try again"; goto tryagain1;}
	
	tryagain2:
	cout<<"\n \n Enter 'Y' if you want to add your Email account if no enter 'N': \n";
	  cin>>EmailOpt;
	  	
	
	if((EmailOpt==121)||(EmailOpt==89))
	{
		cout<<"\n Enter your E-mail account: \n";
		cin>>custom.Email;
	}
	else if ((EmailOpt==110)||(EmailOpt==78))
	{
		goto tryagain3;
	}
	else {cout<<"\n wrong entry! please try again"; goto tryagain2;}
	
	tryagain3:
	cout<<"\n\n Enter 'Y' if you want to add your social media account if no enter 'N': \n";
	cin>>s_mediaOpt;
	
	if((s_mediaOpt==121)||(s_mediaOpt==89))
	{
		cout<<"\n Enter your one frequently used social media: "<<endl;
	    cin>>custom.SocialMedia;
	}
	else if ((s_mediaOpt==110)||(s_mediaOpt==78))
	{
		goto tryagain4;
	}
	else{cout<<"\n wrong entry! please try again"; goto tryagain3;}
	
	tryagain4:
	cout<<"\n \n Enter 'A' if you want to have an air conditioner in the room, 'S' if you want a room safe,'B' if you want both, and 'N' if you don't want any enter:\n ";
	  cin>>choice;
	  
	if((choice==97)||(choice==65))
	{
		cout<<"\n \n you will have an air conditioner in your reserved room";
	}
	else if ((choice==115)||(choice==83))
	{
		cout<<"\n \n you will have a room safe in your reserved room";
	}
	else if ((choice==98)||(choice==66))
	{
		cout<<"\n\n you will have both an air conditioner and a room safe in your reserved room";
	}
	else if ((choice==110)||(choice==78))
	{
		cout<<"There will be nither air conditioner or a room safe in your reserved room";
	}
	else {cout<<"wrong entry! please try again"; goto tryagain4;}
	
	tryagain5:
	cout<<"\n\n Enter 'Y' if there is any additional information to add else enter 'N':  \n";
	  cin>>infOpt;
	  	
	
	if((infOpt==121)||(infOpt==89))
	{
		cout<<"\n \n Enter your additional information: \n";
		cin>>custom.Comment;
	}
	/*else if ((infOpt==110)||(infOpt==78))
	{
		
	}*/
	else {cout<<" \n wrong entry! please try again"; goto tryagain5;}
		
	return 0;
}
