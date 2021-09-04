#include<iostream>
#include<string.h>

using namespace std;

const int numEmp = 20; //total number of employees in the hotel
int numMembers = 0, numComments = 0;

struct date
{
	int dd, mm, yy;
};
struct HotelInfo // to record hotel info
{
    string hotelName;
	string address;
	string RANK;
	HotelInfo()
	{
        hotelName = "Group 2 International Hotel";
        address = "Bole 100 meters away from the airport";
        RANK = "5 STAR";
	}

}hotel;

struct RoomType
{
	float price;
	unsigned int numBeds;
	string roomName;
	bool AC;
	bool WIFI;

};

struct customerReservationInfo
{
	string customerName;
	string customerID;
	string reservationEemail;
	unsigned int age;
	date reservationDate, checkInDate, checkOutDate;
	date duration;

};

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

struct employeeInfo
{
    string employeeName;
    int empID;
    string employeePassword;
}employees[numEmp];

string names[numEmp][15] = {"Ruth", "Ruhama", "Rediet", "Paulos", "Abebe", "Kebede", "Ayele", "Chala", "Saba", "Samrawit",
                    "Wengelawit", "Sara", "Kidus", "Spencer", "Emily", "Hannah", "Alison", "Ariel", "Mike", "Caleb"};
string passWord[numEmp][8] = {"@Ruth#12", "@Ruha21*", "Redi@34", "Raul89$%","Abe123^*", "Kebe!%09", "Ayel56$*", "Chal53@~", "Saba#3$4", "Samr46&*",
                    "Weng@(21", "Sara#$57", "Kidu__19", "Spen()88", "Emil##33", "Hann(*98", "Alis07$$", "Arie09)(", "Mike67%$", "Cale::55"};