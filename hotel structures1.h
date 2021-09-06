#include<iostream>
#include<string.h>

 using namespace std;
 
const int numEmp = 20, numRooms = 80; //total number of employees in the hotel
int numMembers = 0, numComments = 0, customersInHotel = 0;
int numAvail = 0, numUnavail = 0,homePage;// number of available and unavailable rooms

struct date
{
	int dd, mm, yy;
};


struct HotelInfo // to record hotel info 
{
    string hotelName;
	string address;
	string RANK;
	HotelInfo() // intialized with a constructor since it is already known information

	{
        hotelName = "Group 2 International Hotel";
        address = "Bole 100 meters away from the airport";
        RANK = "5 STAR";
	}
}hotel;


struct rooms //room attributes
{
	char type[25];
	char describe[60];
	unsigned int roomNo, beds;
	bool AC, InRoomSafe, avail,checkedIn;
	float price;
}room[80];

struct employeeInfo
{
    string employeeName;
	string employeePhone;
    int empID;
    string employeePassword;
    string emergency_contact;
    string shift;
	string status;
    string bloodType;
    
}employees[numEmp];
struct CustInfo
{
	char SocialMedia[10];
	char Allergy[50];
	char Email[20];
	char Comment[100];
	char RoomPref;
};
struct customerReservationInfo
{
	string customerName;
	string customerID;
	//string reservationEmail;
	unsigned int age;
	date reservationDate, checkInDate, checkOutDate;
	date duration;
	CustInfo custom;
	int reservedRoom;
	float roomBill,packageBill;
}customers[numRooms];

struct customerMembershipInfo
{
    string memberName;
    string phoneNum;
    string memberEmail;
    unsigned int memberAge;
    string memberPassword;
    int memberID;
    
}members[300];

struct reviewAndRating
{
    string review;
    int rating;
    string nameReviewer;
}comments[50];
