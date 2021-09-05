#include <iostream>
#include "StructureDefinitions.h"
#include "FunctionDefinitions.h"

using namespace std;

void check_in_check_out(rooms [], string, string, int);

int main()
{
    check_in_check_out(room);

    return 0;
}
void getReservationInfo()
{

	date dateOfReservation;
    int number;
    string email, name;

	cout <<"enter reserved room number: "<<endl;
    cin>>number;

    cout <<"enter customer name: "<<endl;
    cin >> name;

    cout <<"enter customer's reservation email: " <<endl;
    cin >> email;

    cout <<"enter reservation date: "<<endl;
    cin >> dateOfReservation.dd >> dateOfReservation.mm >> dateOfReservation.yy;


    check_in_check_out(r, name, email, roomNo);

}

void check_in_check_out(rooms r[], string NAME, string EMAIL, int roomNo)
{
    int daysStayed;
    float billAmount;

    {
        cout <<"enter reserved room number: "<<endl;
        cin>>roomNo;

        if (r[roomNo].avail==true && r[roomNo].reservationEmail == email){
                cout<<"room checked in successfully you can go to your room"<<endl;}
        else {
            cout <<"you entered wrong reservation info"<<endl;
            getReservationInfo();
        }

   }

    //check-out information and invoice based on stay

     if(r[roomNo].checkInDate.mm== r[roomNo].checkOutDate.mm)
     	daysStayed = r[roomNo].checkOutDate.dd - r[roomNo].checkInDate.dd;
     else
	 	 daysStayed = r[roomNo].checkOutDate.dd + (30 - r[roomNo].checkInDate.dd)

      if (daysStayed > 30)
    {
        billAmount = r[i].price * days -(30/100*(r[i].price) * (days));
    }
   	   else
        {

            billAmount = r[roomNo].price * days;
       }



    cout <<"\n\t**********checkout information**********\n\n";
    cout <<"customer name: "<< NAME << endl;
    cout <<"room number: "<< roomNo << endl;
    cout <<"total amount of bill: "<< billAmount;


    }



