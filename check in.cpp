#include <iostream>

using namespace std;

struct date
{
	int dd, mm, yy;
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
struct rooms //room attributes
{
	roomName ro;
	unsigned int roomNo, beds;
	bool AC, InRoomSafe, avail;
	float price;
};
void check_in_check_out(rooms r[])
int main()
{



    return 0;
}
void check_in_check_out(rooms r[])
{
    int days;

    customerReservationInfo cust;

    cout <<"enter customer name: "<<endl;
    cin>>cust.customerName;

    cout<<"enter customer ID: "<<endl;
    cin>>cust.customerID;

    cout <<"enter customer's reservation email: "<<endl;
    cin>>cust.reservationEemail;

    cout <<"enter leaving date: "<<endl;
    cin>>cust.date.dd.mm.yy;


    for (int i = 0; i < 80; i++)
    {
        cout <<"enter reserved room number: "<<endl;
        cin>>r[i].roomNo;
        if




    }

    //check-out information
    cout<<"enter number of days of customer stay : ";
    cin>>days;
    for (int i = 0; i < 80; i++)
    {
       //invoice based on stay

       if (days > 30)
    {
        biilAmount = r[i].price * days -(30/100(r[i].price * days));
        else
            billAmount = r[i].price * days;
    }


    }
    cout <<"\n\t**********checkout information**********";
    cout <<"customer name: "<<cust.customerName;
    cout <<"room number: "<<r[i].roomNo;
    cout <<"customer leaving date: "<<cust.date.dd.mm.yy;
    cout <<"total amount of bill: "<<billAmount;



}
