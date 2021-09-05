#include<iostream>
#include<iomanip>
#include<string.h>
#include<cstring>
#include "StructureDefinitions.h"

using namespace std;

void InitializeWebpage();
void DisplayEmployeeMenu();
void displayHomepage (int HOMEPAGE);
void RoomChoice();
void roomDescription(roomInfo r[]);
void DisplayCustomerMenu(int option);
void AssignEmployeesInfo(employeeInfo theEmployees[numEmp]);
void EmployeeNextPage(int IDnumber);
void roomReservation(int roomNum);
void EmployeeNextPage(int IDnumber);
void CustomerNextPage(int NEXTPAGE);
void DisplayPreviousPage(char choice);


void InitializeWebpage()
{
	cout << setw(90) << "Welcome to " << hotel.hotelName << "\n";
	cout << "\n\n" << hotel.hotelName << " is one of the few finest Five Star Hotels in \nthe capital city Addis Ababa, Ethiopia. Located "
		<< "just minutes \naway from Bole International Airport, Group 2 Hotel is a great \naccessible place with open main"
		<< " road to and from different parts \nof the city; thus, the hotel is an ideal location for the activities \nhappening in Addis Ababa.";
		
	cout << "If you are a customer exploring our hotel, please press 1 \n";
	cout << "If you are an employee logging in, please press 0:  ";
	cin >> homePage;
	displayHomepage(homePage);
}

void DisplayEmployeeMenu()
{
	string password;
		int ID;
		cout << "Welcome to your hotel's log in page!\n";
		cout << "Please enter your employee ID:  ";
		cin >> ID;
		cout << "Please enter your password:  ";
		cin >> password;
		
			
		while(employees[--ID].employeePassword != password)
		{
			cout << "Incorrect ID or password please try again!\n";
			cout << "Please enter your employee ID:  ";
			cin >> ID;
			cout << "Please enter your password:  ";
			cin >> password;
		}

		EmployeeNextPage(ID);

}

void displayHomepage (int HOMEPAGE)
{
	if(HOMEPAGE == 1)
		DisplayCustomerMenu(HOMEPAGE);

	else if(HOMEPAGE == 0)
		DisplayEmployeeMenu();
	
    else
	{
		cout << "Please enter a valid option! \nIf you are a customer exploring our hotel, please press 1 \n";
		cout << "If you are an employee please press 0 to log in: ";
		cin >> homePage;
		displayHomepage(homePage);

	}
}

void DisplayCustomerMenu(int option)
{
	
	int nextPage;
			cout << "\n\nEnter 1 for Bar and restaurant \n2 for Fitness and Gym \n3 for Rooms and Accommodation \n4 for Services";
			cout << "\n5 for Special Offers \n6 for Meeting and Events \n7 for Review and Rating \n8 for Member Registration\n";
			cin >> nextPage;
			CustomerNextPage(nextPage);
}

void CustomerNextPage(int NEXTPAGE)
{
	char backPage;
	switch(NEXTPAGE)
	{
	case 1:
		cout << setw(50) << "BAR AND RESTAURANT\n\n";
		cout << "Welcome to our hotel's dining. We provide \na whole range of cultural foods and drinks \nin our cultural bar.";
        cout << "The restaurant service \nincludes a lot of international cuisines ranging \nfrom Mexican dish to Indian dish.\\";
        cout << "\n\nEnter # to get back to the main menu \n";
        cin >> backPage;
        DisplayPreviousPage(backPage);
		break;
	case 2:
		cout << setw(50) << "FITNESS AND GYM\n\n";
		cout << "Welcome to our hotel's fitness center! Our fitness center \nincludes a fully equiped gym with an indoor swimming pool.\n";
		cout << "Besides it has a motivation group led by fitness coaches and \nnutritionists so you could reach your health and figure goals.\n";
		cout << "\n\nEnter # to get back to the main menu \n";
        cin >> backPage;
        DisplayPreviousPage(backPage);
		break;
	case 3:
		cout << setw(50) << "ROOMS AND ACCOMMODATION\n\n";
		cout << "Welcome to our hotel's accommodation center! We have 8 types of rooms.";
		cout << "\n\nEnter # to get back to the main menu \n";
        cin >> backPage;
        DisplayPreviousPage(backPage);
		break;
	case 4:
		cout << setw(50) << "SERVICES\n\n";
		cout << "Our hotel offers free wifi, underground parking, \nlaundary and dry cleaning sevices. It \nalso provides free baggage storage.\n";
		cout << "\n\nEnter # to get back to the main menu \n";
        cin >> backPage;
        DisplayPreviousPage(backPage);
		break;
	case 5:
		cout << setw(50) << "PACKAGES AND SPECIAL OFFERS\n\n";
		cout << "\n\nEnter # to get back to the main menu \n";
        cin >> backPage;
        DisplayPreviousPage(backPage);
		break;
	case 6:
		cout << setw(50) << "MEETINGS AND EVENTS\n\n";
		cout << "The conference rooms and meeting spaces at our hotel \nare supported by an array of professional";
		cout << "audiovisual equipment, \nwireless high-speed internet and on-site assistance with any \nspecial requirements.";
		cout << "In addition to meetings, weddings and \nother parties are highly celebrated in our 8 conference \nrooms occupying 16,533 sq ft event space.\n";
		cout << "\n\nEnter # to get back to the main menu \n";
        cin >> backPage;
        DisplayPreviousPage(backPage);
		break;
	case 7:
		cout << setw(50) << "REVIEWS AND RATINGS\n\n";// allow the user to write review and rating + see previous ratings and reviews
		for(int i = 0; i < numComments; i++)
		{
			cout << "\nComment " << i + 1 << ": " << comments[i].review << endl;
			cout << "Rating: " << comments[i].rating << " * ";
			cout << " \n\n";
		}
		cout << "Please enter your review. \nComment: ";
		cin.ignore();
		getline(cin, comments[numComments].review);

		cout << "PLease enter a number from 1 to 5 for rating. \nRating: ";
		cin.ignore();
		comments[numComments].rating;



		cout << "Thank You for your time! \n\n";
		cout << "Your rating: " << comments[numComments].rating << endl;
		cout << "Your comment: " << comments[numComments].review;


		numComments++;

		cout << "\n\nEnter # to get back to the main menu \n";
        cin >> backPage;
        DisplayPreviousPage(backPage);
		break;
    case 8:
    	cout << setw(50) << "MEMBER REGISTRATION\n\n";
    	cout << "Thank You for choosing to be a member of " << hotel.hotelName <<"! \nWe promise to serve you to your heart's satisfaction.";
    	cout << "\nPlease enter your full name: ";
    	getline(cin, members[numMembers].memberName);
    	cin.ignore();
    	cout << "Enter your phone number with country code: ";
    	getline(cin, members[numMembers].phoneNum);
    	cin.ignore();
    	cout << "Enter your email: ";
    	getline(cin, members[numMembers].memberEmail);
    	cin.ignore(2);
    	cout << "Enter your age: ";
    	cin.ignore();
    	cin >> members[numMembers].memberAge;
    	cin.ignore();
    	cout << "Enter 8 digit password with digits, symbols, uppercase and lowercase letters: ";
    	cin >> members[numMembers].memberPassword;
    	cin.ignore();
    	if(members[numMembers].memberAge > 18)
		{
			cout << "Registration is successful!\n";
    		members[numMembers].memberID = numMembers + 1;
    		numMembers++;
		}
		else
		{
			cout << "Registration failed. Below the allowed age.\n\n";
		}
    	cout << "\n\nEnter # to get back to the Main Menu. \n";
        cin >> backPage;
        DisplayPreviousPage(backPage);
		break;
	}
}

void DisplayPreviousPage(char choice)
{
	if(choice == '#')
		DisplayCustomerMenu(1);

}

void AssignEmployeesInfo(employeeInfo theEmployees[numEmp])
{
	for(int i = 0; i < numEmp; i++)
        theEmployees[i].empID = i + 1;
    
    
	string names[numEmp][15] = {"Ruth", "Ruhama", "Rediet", "Paulos", "Abebe", "Kebede", "Ayele", "Chala", "Saba", "Samrawit",
                    "Wengelawit", "Sara", "Kidus", "Spencer", "Emily", "Hannah", "Alison", "Ariel", "Mike", "Caleb"};
	string passWord[numEmp][8] = {"@Ruth#12", "@Ruha21*", "Redi@34", "Paul89$%","Abe123^*", "Kebe!%09", "Ayel56$*", "Chal53@~", "Saba#3$4", "Samr46&*",
                    "Weng@(21", "Sara#$57", "Kidu__19", "Spen()88", "Emil##33", "Hann(*98", "Alis07$$", "Arie09)(", "Mike67%$", "Cale::55"};
	string Phone[numEmp][20] = {"(251) 9 111 222 33", "(251) 9 111 222 30", "(251) 9 111 222 31", "(251) 9 111 222 32", "(251) 9 111 222 34", "(251) 9 111 222 35", "(251) 9 111 222 36",
							"(251) 9 111 222 37", "(251) 9 111 222 38", "(251) 9 111 222 39", "(251) 9 111 222 40", "(251) 9 111 222 41", "(251) 9 111 222 42", "(251) 9 111 222 43", 
							"(251) 9 111 222 44", "(251) 9 111 222 45", "(251) 9 111 222 46", "(251) 9 111 222 47", "(251) 9 111 222 48", "(251) 9 111 222 49"};
	string emergencyNumber[numEmp][20] = {"(251) 9 000 222 33", "(251) 9 000 222 30", "(251) 9 000 222 31", "(251) 9 000 222 32", "(251) 9 000 222 34", "(251) 9 000 222 35", "(251) 9 000 222 36",
							"(251) 9 000 222 37", "(251) 9 000 222 38", "(251) 9 000 222 39", "(251) 9 000 222 40", "(251) 9 000 222 41", "(251) 9 000 222 42", "(251) 9 000 222 43", 
							"(251) 9 000 222 44", "(251) 9 000 222 45", "(251) 9 000 222 46", "(251) 9 000 222 47", "(251) 9 000 222 48", "(251) 9 000 222 49"};


	for (int i = 0; i < numEmp; i++)
    	theEmployees[i].employeeName = names[0][i];

	for(int i = 0; i < numEmp; i++)
   	    theEmployees[i].employeePassword = passWord[0][i];
   	
   	for (int i = 0; i < numEmp; i++)
    	theEmployees[i].employeePhone = Phone[0][i];

	for(int i = 0; i < numEmp; i++)
   	    theEmployees[i].emergency_contact = emergencyNumber[0][i];
   	
   	

	for(int i = 0; i < numEmp; i++)
	{
		if(i % 2 == 0)
			theEmployees[i].shift = "Day";
		else
			theEmployees[i].shift = "Night"; 
	}
	for(int i = 0; i < numEmp; i++)
	{
		if(i == 0)
			theEmployees[i].status = "receptionist";
		else if(i > 0 && i <3)
			theEmployees[i].status = "chef";
		else if(i >= 3 && i < 6)
			theEmployees[i].status = "guard";
		else if(i >= 6 && i < 10)
			theEmployees[i].status = "waiter";
		else if(i >= 10 && i < 15 )
			theEmployees[i].status = "janitor";
		else if(i >= 15 && i < 18)
			theEmployees[i].status = "bar man";
		else 
			theEmployees[i].status = "chauffeur";
	}
	for(int i = 0; i < numEmp; i++)
	{
		if(i == 0)
			theEmployees[i].bloodType = "B";
		else if(i > 0 && i <3)
			theEmployees[i].bloodType = "B-";
		else if(i >= 3 && i < 6)
			theEmployees[i].bloodType = "A-";
		else if(i >= 6 && i < 10)
			theEmployees[i].bloodType = "B+";
		else if(i >= 10 && i < 15 )
			theEmployees[i].bloodType = "A+";
		else 
			theEmployees[i].bloodType = "AB";
	
	}
}

void EmployeeNextPage(int IDnumber) // employee's page sfter log in
{	
	char nextPage;
	cout << "Hello " << employees[IDnumber].employeeName << "!\n\n";
	cout << "Welcome to your profile page!\n\n";
	
	cout << "ID" << setw(24) << employees[IDnumber].empID << endl; // display employee personal info
	cout << "Phone number" << setw(30) << employees[IDnumber].employeePhone << endl;
	cout << "Blood Type" << setw(15) << employees[IDnumber].bloodType << endl;
	cout << "Emergency Contact" << setw(25) << employees[IDnumber].emergency_contact << endl;
	cout << "Work Status" << setw(25) << employees[IDnumber].status << endl;
	cout << "Work Shift" << setw(17) << employees[IDnumber].shift;
	
	cout << "\n\nEnter * to log out: ";
	cin >> nextPage;
	cout << "\n Log out Successful!";
	InitializeWebpage();
	
}

void roomDescription(roomInfo r[])
{
	for(int i = 0; i < numRooms; i++)
	{
		if(i >= 0 && i < 10)
		{
			strcpy(r[i].type,"Single Room");//naming a specific range of rooms
			strcpy(r[i].describe,"single bed for single occupancy");//describing the room type
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
		}
		
	else if(i>=10 && i<20)
		{
			strcpy(r[i].type,"Twin room");
			strcpy(r[i].describe,"single beds for double occupancy");
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
			
		}
		else if(i>=20 && i<30)
		{
				strcpy(r[i].type,"Double Room");
			strcpy(r[i].describe,"single bed for double occupancy");
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
			
		}
		else if(i>=30 && i<40)
		{
				strcpy(r[i].type,"Double & Double Room");
			strcpy(r[i].describe,"double beds for 4 people");
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
			
		}
		else if(i>=40 && i<50)
		{
				strcpy(r[i].type,"Triple Room");
			strcpy(r[i].describe,"single beds for 3 people");
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
		}
		else if(i>=50 && i<60)
		{
				strcpy(r[i].type,"King Room");
			strcpy(r[i].describe,"6ftX6ft king sized bed");
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
		
		}
		else if(i>=60 && i<70)
		{
				strcpy(r[i].type,"Queen Room");
			strcpy(r[i].describe,"5ftX6ft queen sized bed");
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
			
		}
		else if(i>=70 && i<80)
		{
			strcpy(r[i].type,"Interconnecting Room");
			strcpy(r[i].describe,"2 rooms with a common wall and door");
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
		}
	}
}

void RoomChoice() // proving room choice for reservation
{
int option;
	cout << "press 0 to view all room types \n";
	cout << "press 1 to display room with your budget range: ";
	cin >> option;
	
	if(option == 0)
		roomStat (room);
	else if(option == 1)
	{
		int budget, roomChoice;
		cout << "Enter 1 for budget range 500 - 700\n";
		cout << "Enter 2 for budget range 701 - 900\n";
		cout << "Enter 3 for budget range 901 - 1100\n";
		cin >> budget;
		
		cout<<" "<<setfill('_')<<setw(132)<<"_"<<setfill(' ')<<endl;
		cout<<setw(7)<<"|Room NO|"<<setw(25)<<"Room Type|"<<setw(38)<<"   Description  |"<<setw(11)<<"price(ETB)|"<<setw(12)<<"NO of beds|"<<setw(8)<<"AC|"<<setw(16)<<"In room safe|"<<setw(15)<<"availability|"<<endl;
		cout<<"|"<<setfill('=')<<setw(8)<<"|"<<setw(25)<<"|"<<setw(38)<<"|"<<setw(11)<<"|"<<setw(12)<<"|"<<setw(8)<<"|"<<setw(16)<<"|"<<setw(15)<<"|"<<setfill(' ')<<endl;

		
		switch(budget)
		{	
			case 1:
				for(int i = 0; i < numRooms; i++)
				{
					if(room[i].price >= 500 && room[i].price <= 700)
					{
						cout<<"| "<<left<<setw(5)<<room[i].roomNo<<right<<" |"<<setw(24)<<room[i].type<<"|"<<right<<setw(37)<<room[i].describe<<"|"<<setw(10)<<room[i].price<<"|"<<setw(11)<<room[i].beds<<"|";
						
						if(room[i].AC==true)
							{cout<<setw(8)<<"AC|";}
			   		   	else 
							{cout<<setw(8)<<"no AC|";}
								
						if(room[i].InRoomSafe==true) 
				   		   	{cout<<setw(16)<<"available|";}
				   		else
				   		   	{cout<<setw(16)<<"not available|";}
			
			   		   	if(room[i].avail=true)
				   		   	{cout<<setw(15)<<"vacant|"<<endl;}
						else
							{cout<<setw(15)<<"reserved|"<<endl;}
					}
				}
				cout<<"'"<<setfill('-')<<setw(8)<<"'"<<setw(25)<<"'"<<setw(38)<<"'"<<setw(11)<<"'"<<setw(12)<<"'"<<setw(8)<<"'"<<setw(16)<<"'"<<setw(15)<<"'"<<setfill(' ')<<endl;				
				cout << "Enter room number for reservation: ";
				cin >> roomChoice;
				roomReservation(roomChoice);
				break;
			case 2:
				for(int i = 0; i < numRooms; i++)
				{
					if(room[i].price >= 701 && room[i].price <= 900)
					{
						cout<<"| "<<left<<setw(5)<<room[i].roomNo<<right<<" |"<<setw(24)<<room[i].type<<"|"<<right<<setw(37)<<room[i].describe<<"|"<<setw(10)<<room[i].price<<"|"<<setw(11)<<room[i].beds<<"|";
						
						if(room[i].AC==true)
							{cout<<setw(8)<<"AC|";}
			   		   	else 
							{cout<<setw(8)<<"no AC|";}
								
						if(room[i].InRoomSafe==true) 
				   		   	{cout<<setw(16)<<"available|";}
				   		else
				   		   	{cout<<setw(16)<<"not available|";}
			
			   		   	if(room[i].avail=true)
				   		   	{cout<<setw(15)<<"vacant|"<<endl;}
						else
							{cout<<setw(15)<<"reserved|"<<endl;}
					}
				}
				cout<<"'"<<setfill('-')<<setw(8)<<"'"<<setw(25)<<"'"<<setw(38)<<"'"<<setw(11)<<"'"<<setw(12)<<"'"<<setw(8)<<"'"<<setw(16)<<"'"<<setw(15)<<"'"<<setfill(' ')<<endl;				
				cout << "Enter room number for reservation: ";
				cin >> roomChoice;
				roomReservation(roomChoice);
				break;
			case 3:
				for(int i = 0; i < numRooms; i++)
				{
					if(room[i].price >= 901 && room[i].price <= 1050)
					{
						cout<<"| "<<left<<setw(5)<<room[i].roomNo<<right<<" |"<<setw(24)<<room[i].type<<"|"<<right<<setw(37)<<room[i].describe<<"|"<<setw(10)<<room[i].price<<"|"<<setw(11)<<room[i].beds<<"|";
						
						if(room[i].AC==true)
							{cout<<setw(8)<<"AC|";}
			   		   	else 
							{cout<<setw(8)<<"no AC|";}
								
						if(room[i].InRoomSafe==true) 
				   		   	{cout<<setw(16)<<"available|";}
				   		else
				   		   	{cout<<setw(16)<<"not available|";}
			
			   		   	if(room[i].avail=true)
				   		   	{cout<<setw(15)<<"vacant|"<<endl;}
						else
							{cout<<setw(15)<<"reserved|"<<endl;}
					}
				}
				cout<<"'"<<setfill('-')<<setw(8)<<"'"<<setw(25)<<"'"<<setw(38)<<"'"<<setw(11)<<"'"
				<<setw(12)<<"'"<<setw(8)<<"'"<<setw(16)<<"'"<<setw(15)<<"'"<<setfill(' ')<<endl;				
				cout << "Enter room number for reservation: ";
				cin >> roomChoice;
				roomReservation(roomChoice);
				break;
		}
	};
		
}

void roomReservation(int roomNum)
{
	if(room[--roomNum].avail == 1)
	{
		cout << "Enter your name: ";
		getline(cin, customers[customersInHotel].customerName);
		cout << "Enter your email: ";
		cin >> customers[customersInHotel].reservationEmail;
		cout << "Enter your kebele ID number: ";
		cin >> customers[customersInHotel].customerID;		
		cout << "Enter your age: ";
		cin >> customers[customersInHotel].age;	
		cout << "Enter reservation date(dd-mm-yyyy): ";
		cin >> customers[customersInHotel].reservationDate.dd >> customers[customersInHotel].reservationDate.mm >> customers[customersInHotel].reservationDate.yy;
		cout << "Enter check in date(dd-mm-yyyy): ";
		cin >> customers[customersInHotel].checkInDate.dd >> customers[customersInHotel].checkInDate.mm >> customers[customersInHotel].checkInDate.yy;
		cout << "Enter check out date(dd-mm-yyyy): ";
		cin >> customers[customersInHotel].checkOutDate.dd >> customers[customersInHotel].checkOutDate.mm >> customers[customersInHotel].checkOutDate.yy;
		
		
		if(customers[customersInHotel].age < 18)
		{
			cout << "Reservation failed! Below the allowed age limit. Taking you to the home page.";
			DisplayCustomerMenu(1);
		}
		
		if(0 <= customers[customersInHotel].reservationDate.dd > 30 || 0 <= customers[customersInHotel].reservationDate.mm > 12 || customers[customersInHotel].reservationDate.yy != 2021 )
		{
			cout << "Invalid Reservation Date! Please try again.\n";
			cout << "Enter reservation date(dd-mm-yyyy): ";
		    cin >> customers[customersInHotel].reservationDate.dd >> customers[customersInHotel].reservationDate.mm >> customers[customersInHotel].reservationDate.yy;				
		}
		
		if(0 <= customers[customersInHotel].checkInDate.dd > 30 || 0 <= customers[customersInHotel].checkInDate.mm > 12 || customers[customersInHotel].checkInDate.yy != 2021 )
		{
			cout << "Invalid check in Date! Please try again.\n";
			cout << "Enter check in date(dd-mm-yyyy): ";
		    cin >> customers[customersInHotel].checkInDate.dd >> customers[customersInHotel].checkInDate.mm >> customers[customersInHotel].checkInDate.yy;				
		}
		if(0 <= customers[customersInHotel].checkOutDate.dd > 30 || 0 <= customers[customersInHotel].checkOutDate.mm > 12 || customers[customersInHotel].checkOutDate.yy != 2021 )
		{
			cout << "Invalid check out Date! Please try again.\n";
			cout << "Enter check out date(dd-mm-yyyy): ";
		    cin >> customers[customersInHotel].checkOutDate.dd >> customers[customersInHotel].checkOutDate.mm >> customers[customersInHotel].checkOutDate.yy;				
		}	
 
	 	if(customers[customersInHotel].checkOutDate.dd <= customers[customersInHotel].checkInDate.dd || customers[customersInHotel].checkOutDate.mm < customers[customersInHotel].checkInDate.mm)
		 {
		 	cout << "Invalid Input! Check Out date should be 1 or more days after Check In date.\n"
		 	cout << "Enter check in date(dd-mm-yyyy): ";
			cin >> customers[customersInHotel].checkInDate.dd >> customers[customersInHotel].checkInDate.mm >> customers[customersInHotel].checkInDate.yy;
			cout << "Enter check out date(dd-mm-yyyy): ";
			cin >> customers[customersInHotel].checkOutDate.dd >> customers[customersInHotel].checkOutDate.mm >> customers[customersInHotel].checkOutDate.yy;
		
		 }
		else
		{
			cout << "Reserved Successfully! Thank You for choosing us! Taking you to the home page.";
			room[--roomNum].avail == 0;
			DisplayCustomerMenu(1);
		}
	}
	else
	{
		cout << "Sorry! The room you chose is unavailable. Please choose a different room.";
		RoomChoice();
	}
}
