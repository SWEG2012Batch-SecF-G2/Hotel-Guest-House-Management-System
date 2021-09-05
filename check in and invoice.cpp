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
	char type[25];
	char describe[60];
	unsigned int roomNo, beds;
	bool AC, InRoomSafe, avail;
	float price;
}room[80];
void check_in_check_out(rooms r[]);
int main()
{
    check_in_check_out(room);



    return 0;
}
void check_in_check_out(rooms r[])
{
    int days;
    float billAmount;
    int i;

    customerReservationInfo cust;

    cout <<"enter customer name: "<<endl;
    cin>>cust.customerName;

    cout<<"enter customer ID: "<<endl;
    cin>>cust.customerID;

    cout <<"enter customer's reservation email: "<<endl;
    cin>>cust.reservationEemail;

    cout <<"enter leaving date: "<<endl;
    cin>>cust.duration.dd;


    for (int i = 0; i < 80; i++)
    {
        cout <<"enter reserved room number: "<<endl;
        cin>>r[i].roomNo;
        if (r[i].avail==true){
                cout<<"room checked in successfully you can go to your room"<<endl;}
        else {
            cout <<"you entered wrong reservation info"<<endl;
        }

}

    //check-out information and  invoice based on stay
    cout<<"enter number of days of customer stay : ";
    cin>>days;
    for (int i = 0; i < 80; i++)
    {
      if (days > 30)
    {
        billAmount = r[i].price * days -(30/100*(r[i].price) * (days));
    }
        else
        {

            billAmount = r[i].price * days;
    }

}

    cout <<"\n\t**********checkout information**********";
    cout <<"customer name: "<<cust.customerName;
    cout <<"room number: "<<r[i].roomNo;
    cout <<"customer leaving date: "<<cust.duration.dd;
    cout <<"total amount of bill: "<<billAmount;


    }



