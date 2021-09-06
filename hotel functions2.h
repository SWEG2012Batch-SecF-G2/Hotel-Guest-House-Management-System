#include<iostream>
#include<iomanip>
#include<string.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
//#include"hotel structures.h"

using namespace std;

void InitializeWebpage();// function declaration that display home page
void DisplayEmployeeMenu(); // declaration of function that prompts employee to input ID and password
void RoomChoice(); // function declaration for accepting room choice for reservation
void roomDescription(rooms r[]); // creats rooms, room types with AC, noAC, and room safe
void DisplayCustomerMenu();//  function declaration to display menu to prefer customer related actions
void CustomerNextPage(int NEXTPAGE); //accepts reservation/ registeration informaton from customer after their prefference of customer related actions
void AssignEmployeesInfo(employeeInfo theEmployees[numEmp]); //declaration of function that assigns information of employee
void EmployeeNextPage(int IDnumber);// declaration of function that displays assigned information of an employee
void customInfo(customerReservationInfo customers[], int i);// declaration of function that custom/ additional information of te custoner
void roomReservation(rooms room[], int roomNum); //declaration of function that used for reserving a room 
void roomStat(rooms r[]); // displays rooms with their discription and availability
void check_in_check_out(rooms r[], string NAME, int roomNo);//checks in and checks out information and invoice customers and displays total bill based on stay 
void getReservationInfo();// function declarstion that checks for reservation information

void InitializeWebpage()
{
	roomDescription(room);
	cout << setw(60) << "Welcome to " << hotel.hotelName << "\n";
	cout << "\n\n\t\t" << hotel.hotelName << " is one of the few finest Five Star Hotels in \n\t\tthe capital city Addis Ababa, Ethiopia. Located "
		<< "just minutes \n\t\taway from Bole International Airport, it is a great \n\t\t and accessible place with open main"
		<< " road to and from different parts \n\t\tof the city; thus, the hotel is an ideal location for the activities \n\t\thappening in Addis Ababa."<<endl;
		
	menu: cout << "\tIf you are a customer exploring our hotel, please press 1 \n";
	cout << "\tIf you are an employee logging in, please press 2\n\tTo exit, please press 0\n  ";
	cin >> homePage;
		if(homePage == 1) DisplayCustomerMenu();
	else if(homePage == 2) DisplayEmployeeMenu();
	else if(homePage == 0) return;
    else {cout<<"\n wrong entry! try again\n"; goto menu;}
}

void DisplayEmployeeMenu()
{
	AssignEmployeesInfo(employees);
	system("CLS");
	string password;
		int ID;
		cout << "\n\n\t\tWelcome to your hotel's log in page!\n";
		cout << "\tPlease enter your employee ID:  ";
		cin >> ID;
		cout << "\tPlease enter your password:  ";
		cin >> password;
		
			
		while(employees[ID-1].employeePassword != password)
		{
			cout << "Incorrect ID or password please try again!\n";
			cout << "Please enter your employee ID:  ";
			cin >> ID;
			cout << "Please enter your password:  ";
			cin >> password;
		}

		EmployeeNextPage(ID);

}


void DisplayCustomerMenu()
{
	system("CLS");
	cout << "\n\n\t\tWelcome to your hotel's customer page!\n";
	int nextPage;
			cout << "\n\n Please enter \n1 for Rooms and Accommodation \n2 for description of services given when you book a room in our hotel";
			cout << "\n3 for Special Offers \n4 for Review and Rating \n5 for Member Registration \n6 for check in/out \n7 for returning to home page (all saved data is lost)\n8 to exit program\n";
			cin >> nextPage;
			CustomerNextPage(nextPage);
}

void CustomerNextPage(int NEXTPAGE)
{
	
	char backPage;
	switch(NEXTPAGE)
	{
	case 1:
			cout << "\n\n"<<setw(50) << "ROOMS AND ACCOMMODATION\n\n";
			cout << "Welcome to our hotel's accommodation center! We have 8 types of rooms.\n\n";
			RoomChoice();
			cout << "\n\n\tEnter # to get back to the main menu \n";
	        cin >> backPage;
	      if(backPage == '#')
			DisplayCustomerMenu();
			break;
	case 2:
		cout << setw(50) << "\tSERVICES\n\n";
		cout << "Our hotel offers \n\t-free wifi, \n\t-underground parking, \n\t-laundary and dry cleaning sevices. \n\t-It also provides free baggage storage.\n";
		cout << "\n\nEnter # to get back to the main menu \n";
        cin >> backPage;
      if(backPage == '#')
		DisplayCustomerMenu();
		break;
	case 3:
		cout << setw(50) << "PACKAGES AND SPECIAL OFFERS\n\n";
		cout << "\n\nEnter # to get back to the main menu \n";
        cin >> backPage;
      if(backPage == '#')
		DisplayCustomerMenu();
		break;
	
	case 4:
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
      if(backPage == '#')
		DisplayCustomerMenu();
		break;
	case 5:cout << setw(50) << "MEMBER REGISTRATION\n\n";
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
      if(backPage == '#')
		DisplayCustomerMenu();
		break;
	case 6:
		getReservationInfo();
		break;
	
	case 7:
		InitializeWebpage();
		break;    	
	case 8: return;
	}
}



void AssignEmployeesInfo(employeeInfo theEmployees[numEmp])
{
	for(int i = 0; i < numEmp; i++)
        theEmployees[i].empID = i + 1;
    
    
	string names[numEmp][15] = {"Ruth", "Ruhama", "Rediet", "Paulos", "Abebe", "Kebede", "Ayele", "Chala", "Saba", "Samrawit",
                    "Wengelawit", "Sara", "Kidus", "Spencer", "Emily", "Hannah", "Alison", "Ariel", "Mike", "Caleb"}; // employee ID will be as order of corresponding names like Ruth..ID=1,Ruhama..ID=2...
	string passWord[numEmp][8] = {"Ruth@12", "Ruhama@12", "Rediet@12", "Paulos@12", "Abebe@12", "Kebede@12", "Ayele@12", "Chala@12", "Saba@12", "Samrawit@12",
                    "Wengelawit@12", "Sara@12", "Kidus@12", "Spencer@12", "Emily@12", "Hannah@12", "Alison@12", "Ariel@12", "Mike@12", "Caleb@12"};
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
{	int staff;
	char nextPage;
	cout << "Hello " << employees[IDnumber-1].employeeName << "!\n\n";
	cout << "Welcome to your profile page!\n\n";
	
cout<<setw(4)<<"ID"<<setw(25)<<"Phone Number"<<setw(12)<<"Blood Type"<<setw(21)<<"Emergency Contact"<<setw(18)<<"work Status"<<setw(12)<<"Work Shift"<<endl;
cout<<setw(4)<<employees[IDnumber-1].empID <<setw(25)<<employees[IDnumber-1].employeePhone<<setw(12)<<employees[IDnumber-1].bloodType ;
cout<<setw(21)<<employees[IDnumber-1].emergency_contact<<setw(18)<<employees[IDnumber-1].status<<setw(12)<<employees[IDnumber-1].shift<<endl;	

	cout<<"press 1 to see the whole staff data \npress 2 to go to logout\n";
	cin>>staff;
	if(staff==1)
	{ 
	cout<<endl<<setw(4)<<"ID"<<setw(15)<<"Name"<<setw(25)<<"Phone Number"<<setw(12)<<"Blood Type"<<setw(21)<<"Emergency Contact"<<setw(18)<<"work Status"<<setw(12)<<"Work Shift"<<endl;
		for(int i=0;i<numEmp;i++)
		{
			cout<<setw(4)<<employees[i].empID<<setw(15)<<employees[i].employeeName <<setw(25)<<employees[i].employeePhone<<setw(12)<<employees[i].bloodType ;
			cout<<setw(21)<<employees[i].emergency_contact<<setw(18)<<employees[i].status<<setw(12)<<employees[i].shift<<endl;	
		}
	}
	else if(staff==2) goto logout;
	logout:
	cout << "\n\nEnter * to log out: ";
	cin >> nextPage;
	cout << "\n Log out Successful!";
	system("CLS");
	InitializeWebpage();
	
}

void roomDescription(rooms r[])
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
				r[i].avail=true;
				r[i].checkedIn=false;	
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
				r[i].avail=true;
				r[i].checkedIn=false;	
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
				r[i].avail=true;
				r[i].checkedIn=false;	
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
				
				r[i].avail=true;
				r[i].checkedIn=false;	
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
				
				r[i].avail=true;
				r[i].checkedIn=false;			
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
				r[i].avail=true;
				r[i].checkedIn=false;
		
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
					r[i].avail=true;
				r[i].checkedIn=false;	
			
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
				r[i].avail=true;
				r[i].checkedIn=false;		
		}
	}
}

void RoomChoice() 
{	
int option;
	cout << "\n\t\tpress 0 to view all rooms \n";
	cout << "\t\tpress 1 to start reservation by displaying room using budget range:\n \t\tpress 2 to return back\n";
	cin >> option;
	
	if(option == 0)
		roomStat (room);
	else if(option == 1)
	{
		int changer,budget, roomChoice,count=0;
		int checkChoice[numRooms];
	change:	cout << "\t\t\tEnter 1 for budget range 500 - 700\n";
		cout << "\t\t\tEnter 2 for budget range 701 - 900\n";
		cout << "\t\t\tEnter 3 for budget range 901 - 1100\n";
		cout << "\t\t\tEnter 4 for seeing all of the rooms\n";
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
						checkChoice[i]=room[i].roomNo;
						cout<<"| "<<left<<setw(5)<<room[i].roomNo<<right<<" |"<<setw(24)<<room[i].type<<"|"<<right<<setw(37)<<room[i].describe<<"|"<<setw(10)<<room[i].price<<"|"<<setw(11)<<room[i].beds<<"|";
						
						if(room[i].AC==true)
							{cout<<setw(8)<<"AC|";}
			   		   	else 
							{cout<<setw(8)<<"no AC|";}
								
						if(room[i].InRoomSafe==true) 
				   		   	{cout<<setw(16)<<"available|";}
				   		else
				   		   	{cout<<setw(16)<<"not available|";}
			
			   		   	if(room[i].avail==true)
				   		   	{cout<<setw(15)<<"vacant|"<<endl;}
						else
							{cout<<setw(15)<<"reserved|"<<endl;}	
					}
					else
					{
						checkChoice[i]=0;
					}
				}
				
				cout<<"'"<<setfill('-')<<setw(8)<<"'"<<setw(25)<<"'"<<setw(38)<<"'"<<setw(11)<<"'"<<setw(12)<<"'"<<setw(8)<<"'"<<setw(16)<<"'"<<setw(15)<<"'"<<setfill(' ')<<endl;				
				cout<<"\n\t Would you like to see another budget range? \n\t press 1 for yes or \n\t press 2 to continue with the current range ";
				cin>>changer;
				if(changer==1){goto change;	}//system("cls");}
				else if(changer==2)
				{
					enter1: cout << "Enter room number for reservation: ";
					cin >> roomChoice;
					
					for(int i=0;i<numRooms;i++)
					{
						if(roomChoice==checkChoice[i] && roomChoice!=0)
						{
							roomReservation(room, roomChoice);
							
						}
						else count++;
					}
						if(count!=0)
						{
							cout<<"wrong choice! please try again "<<endl;
							goto enter1;
						}
				}
				break;
			
			case 2:
				count=0;
				for(int i = 0; i < numRooms; i++)
				{
					if(room[i].price >= 701 && room[i].price <= 900)
					{
						checkChoice[i]=room[i].roomNo;
						cout<<"| "<<left<<setw(5)<<room[i].roomNo<<right<<" |"<<setw(24)<<room[i].type<<"|"<<right<<setw(37)<<room[i].describe<<"|"<<setw(10)<<room[i].price<<"|"<<setw(11)<<room[i].beds<<"|";
						
						if(room[i].AC==true)
							{cout<<setw(8)<<"AC|";}
			   		   	else 
							{cout<<setw(8)<<"no AC|";}
								
						if(room[i].InRoomSafe==true) 
				   		   	{cout<<setw(16)<<"available|";}
				   		else
				   		   	{cout<<setw(16)<<"not available|";}
			
			   		   	if(room[i].avail==true)
				   		   	{cout<<setw(15)<<"vacant|"<<endl;}
						else
							{cout<<setw(15)<<"reserved|"<<endl;}	
					}
					else
					{
						checkChoice[i]=0;
					}
				}
				
				cout<<"'"<<setfill('-')<<setw(8)<<"'"<<setw(25)<<"'"<<setw(38)<<"'"<<setw(11)<<"'"<<setw(12)<<"'"<<setw(8)<<"'"<<setw(16)<<"'"<<setw(15)<<"'"<<setfill(' ')<<endl;				
				cout<<"\n\t Would you like to see another budget range? \n\t press 1 for yes or \n\t press 2 to continue with the current range ";
				cin>>changer;
				if(changer==1){goto change;	}
				else if(changer==2)
				{
					enter2: cout << "Enter room number for reservation: ";
					cin >> roomChoice;
					
					for(int i=0;i<numRooms;i++)
					{
						if(roomChoice==checkChoice[i] && roomChoice!=0)
						{
							roomReservation(room, roomChoice);
							break;
						}
						else count++;
					}
						if(count!=0)
						{
							cout<<"wrong choice! please try again "<<endl;
							goto enter2;
						}
				}
				break;
				
			case 3:
				count=0;
				for(int i = 0; i < numRooms; i++)
				{
					if(room[i].price >= 901 && room[i].price <= 1050)
					{
						checkChoice[i]=room[i].roomNo;
						cout<<"| "<<left<<setw(5)<<room[i].roomNo<<right<<" |"<<setw(24)<<room[i].type<<"|"<<right<<setw(37)<<room[i].describe<<"|"<<setw(10)<<room[i].price<<"|"<<setw(11)<<room[i].beds<<"|";
						
						if(room[i].AC==true)
							{cout<<setw(8)<<"AC|";}
			   		   	else 
							{cout<<setw(8)<<"no AC|";}
								
						if(room[i].InRoomSafe==true) 
				   		   	{cout<<setw(16)<<"available|";}
				   		else
				   		   	{cout<<setw(16)<<"not available|";}
			
			   		   	if(room[i].avail==true)
				   		   	{cout<<setw(15)<<"vacant|"<<endl;}
						else
							{cout<<setw(15)<<"reserved|"<<endl;}	
					}
					else
					{
						checkChoice[i]=0;
					}
				}
				
				cout<<"'"<<setfill('-')<<setw(8)<<"'"<<setw(25)<<"'"<<setw(38)<<"'"<<setw(11)<<"'"<<setw(12)<<"'"<<setw(8)<<"'"<<setw(16)<<"'"<<setw(15)<<"'"<<setfill(' ')<<endl;				
					cout<<"\n\t Would you like to see another budget range? \n\t press 1 for yes or \n\t press 2 to continue with the current range ";
				cin>>changer;
				if(changer==1){goto change;	}
				else if(changer==2)
				{
					enter: cout << "Enter room number for reservation: ";
					cin >> roomChoice;
					
					for(int i=0;i<numRooms;i++)
					{
						if(roomChoice==checkChoice[i] && roomChoice!=0)
						{
							roomReservation(room, roomChoice);
							break;
						}
						else count++;
					}
						if(count!=0)
						{
							cout<<"wrong choice! please try again "<<endl;
							goto enter;
						}
				}
				break;
				case 4:
						roomStat (room);
						cout<<"\n\t Would you like to see another budget range? \n\t press 1 for yes or \n\t press 2 to continue with the current range ";
					cin>>changer;
					if(changer==1){goto change;	}//system("cls");}
					else if(changer==2)
						{
							enter3: cout << "Enter room number for reservation: ";
							cin >> roomChoice;
							
							for(int i=0;i<numRooms;i++)
							{
								if(roomChoice>0 && roomChoice<=80)
								{
									roomReservation(room, roomChoice);
								}
								else
								{
									cout<<"wrong choice! please try again "<<endl;
									goto enter3;
								}
							}
						}
					break;
				
			}
	}
	else if(option==2){return;	}
		
}

void roomReservation(rooms room[],int roomNum)
{
	int cus;
	if(room[roomNum-1].avail==true)
	{
			cout << "\n\nEnter your kebele ID number: ";
			cin >> customers[customersInHotel].customerID;
			cin.ignore(35,'\n');
			cout << "\nEnter your name: ";
			getline(cin, customers[customersInHotel].customerName);
			cout << "\nEnter your age: ";
			cin >> customers[customersInHotel].age;	
			if(customers[customersInHotel].age < 18)
			{
				cout << "Reservation failed! Below the allowed age limit. Taking you to the home page."; 
				DisplayCustomerMenu();
				
			}
			cout << "\nEnter reservation date(dd-mm-yyyy): ";
			cin >> customers[customersInHotel].reservationDate.dd >> customers[customersInHotel].reservationDate.mm >> customers[customersInHotel].reservationDate.yy;
			reCheck: if (customers[customersInHotel].reservationDate.dd==0 || customers[customersInHotel].reservationDate.dd > 30 ||customers[customersInHotel].reservationDate.mm==0 || customers[customersInHotel].reservationDate.mm> 12  || customers[customersInHotel].reservationDate.yy != 2021)
			{
				cout << "\nInvalid Reservation Date! Please try again.\n";
				cout << "Re-enter reservation date(dd-mm-yyyy): ";
			    cin >> customers[customersInHotel].reservationDate.dd >> customers[customersInHotel].reservationDate.mm >> customers[customersInHotel].reservationDate.yy;	
					goto reCheck;		
			}
			cout << "\nEnter check in date(dd-mm-yyyy): ";
			cin >> customers[customersInHotel].checkInDate.dd >> customers[customersInHotel].checkInDate.mm >> customers[customersInHotel].checkInDate.yy;
				reCheck1:if (customers[customersInHotel].checkInDate.dd==0 || customers[customersInHotel].checkInDate.dd > 30 ||customers[customersInHotel].checkInDate.mm==0 || customers[customersInHotel].checkInDate.mm> 12  || customers[customersInHotel].checkInDate.yy != 2021)
			{
				cout << "\nInvalid Check in Date! Please try again.\n";
				cout << "Re-enter check in date(dd-mm-yyyy): ";
			    cin >> customers[customersInHotel].checkInDate.dd >> customers[customersInHotel].checkInDate.mm >> customers[customersInHotel].checkInDate.yy;		
				goto reCheck1;	
			}
	    
			cout << "\nEnter check out date(dd-mm-yyyy): ";
			cin >> customers[customersInHotel].checkOutDate.dd >> customers[customersInHotel].checkOutDate.mm >> customers[customersInHotel].checkOutDate.yy;
				reCheck2:if(customers[customersInHotel].checkOutDate.dd==0 || customers[customersInHotel].checkOutDate.dd > 30 ||customers[customersInHotel].checkOutDate.mm==0 || customers[customersInHotel].checkOutDate.mm> 12  || customers[customersInHotel].checkOutDate.yy != 2021)
			{
				cout << "\nInvalid Check out Date! Please try again.\n";
				cout << "Re-enter check out date(dd-mm-yyyy): ";
			    cin >> customers[customersInHotel].checkOutDate.dd >> customers[customersInHotel].checkOutDate.mm >> customers[customersInHotel].checkOutDate.yy;	
				goto reCheck2;			
			}	
		cout<<"\n Would you like to enter some custom information for better service?"<<endl;
		cout<<"if yes press 1 if no press 0";
	cusInp:	cin>>cus;
		if(cus==1) {
		customInfo(customers, customersInHotel);
	
		cout << "\n\n\nReserved Successfully! Thank You for choosing us! Taking you to the home page.";
		getch();
		room[roomNum-1].avail=false;
		customers[customersInHotel].reservedRoom = roomNum;
		customers[customersInHotel].roomBill=room[roomNum-1].price;
		customersInHotel++;
		DisplayCustomerMenu();
					}
		else if(cus==0)
		{
			cout << "\n\n\nReserved Successfully! Thank You for choosing us! Taking you to the home page.";
			getch();
			room[roomNum-1].avail=false;
			customers[customersInHotel].reservedRoom=roomNum;
			customers[customersInHotel].roomBill=room[roomNum-1].price;
			customersInHotel++;
			DisplayCustomerMenu();
		}
		else {cout<<"\nwrong input. try again\n"; goto cusInp;	}
		
	}
	else
	{
		cout << "Sorry! The room you chose is unavailable. Please choose a different room.";
		RoomChoice();
	}
}


void customInfo(customerReservationInfo customers[], int i)
{
	char choice,EmailOpt,s_mediaOpt,allergyOpt,infOpt;
	cout<<"\t   Additional information collecting page inorder to make our service more convenient"<<endl;
	
	tryagain1:
	cout<<"\n \n Enter 'Y' if you have any allergies if no enter 'N': \n";
	  cin>>allergyOpt;
	
	if((allergyOpt==121)||(allergyOpt==89))
	{
		cout<<"\n Enter what your allergies are: \n";
		cin>>customers[i].custom.Allergy;
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
		cin>>customers[i].custom.Email;
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
	    cin>>customers[i].custom.SocialMedia;
	}
	else if ((s_mediaOpt==110)||(s_mediaOpt==78))
	{
		goto tryagain4;
	}
	else{cout<<"\n wrong entry! please try again"; goto tryagain3;}
	
	tryagain4:
	/*cout<<"\n \n Enter 'A' if you want to have an air conditioner in the room, 'S' if you want a room safe,'B' if you want both, and 'N' if you don't want any enter:\n ";
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
	*/
	tryagain5:
	cout<<"\n\n Enter 'Y' if there is any additional information to add else enter 'N':  \n";
	  cin>>infOpt;
	if((infOpt==121)||(infOpt==89))
	{
		cout<<"\n \n Enter your additional information: \n";
		cin>>customers[i].custom.Comment;
	}
	else if ((infOpt==110)||(infOpt==78))
	{
		goto tryagain6;
	}
	else {cout<<" \n wrong entry! please try again"; goto tryagain5;}
	tryagain6:;
}



void roomStat(rooms r[])
{
	
	cout<<" "<<setfill('_')<<setw(140)<<"_"<<setfill(' ')<<endl;
	cout<<setw(7)<<"|Room NO|"<<setw(25)<<"Room Type|"<<setw(37)<<"   Description  |"<<setw(11)<<"price(ETB)|"<<setw(12)<<"NO of beds|"<<setw(8)<<"AC|"<<setw(16)<<"In room safe|"<<setw(13)<<"availability|"<<setw(10)<<"checked in|"<<endl;
	cout<<"|"<<setfill('=')<<setw(8)<<"|"<<setw(25)<<"|"<<setw(37)<<"|"<<setw(11)<<"|"<<setw(12)<<"|"<<setw(8)<<"|"<<setw(16)<<"|"<<setw(13)<<"|"<<setw(11)<<"|"<<setfill(' ')<<endl;
	for(int i=0;i<80;i++)
	{
		cout<<"| "<<left<<setw(5)<<room[i].roomNo<<right<<" |"<<setw(24)<<room[i].type<<"|"<<right<<setw(36)<<room[i].describe<<"|"<<setw(10)<<room[i].price<<"|"<<setw(11)<<room[i].beds<<"|";
		if(room[i].AC==true)
			{cout<<setw(8)<<"AC|";}
		else 
			{cout<<setw(8)<<"no AC|";}
			
		if(room[i].InRoomSafe==true) 
			{cout<<setw(16)<<"available|";}
		else
			{cout<<setw(16)<<"not available|";}
			
		if(room[i].avail==true){cout<<setw(13)<<"vacant|";}
		else{cout<<setw(13)<<"reserved|";}
			
		if(room[i].checkedIn==true)
			{cout<<setw(11)<<"yes|"<<endl;}
		else
			{cout<<setw(11)<<"no|"<<endl;}
	}
		cout<<"'"<<setfill('-')<<setw(8)<<"'"<<setw(25)<<"'"<<setw(37)<<"'"<<setw(11)<<"'"<<setw(12)<<"'"<<setw(8)<<"'"<<setw(16)<<"'"<<setw(13)<<"'"<<setw(11)<<"'"<<setfill(' ')<<endl;
}



void getReservationInfo()
{
	system("CLS");
	cout << "\n\n\t\tWelcome to your hotel's check in/out page!\n";
	date dateOfReservation;
    int number,count;
    count=0;
    string name;

	checkagain: cout <<"enter reserved room number: "<<endl;
    cin>>number;
        
    cout <<"enter customer name: "<<endl;
    cin >> name;

    cout <<"enter reservation date: "<<endl;
    cin >> dateOfReservation.dd >> dateOfReservation.mm >> dateOfReservation.yy;
    for(int i=0;i<customersInHotel;i++)
    {
    	if(number==customers[i].reservedRoom && name==customers[i].customerName)
    	{
			check_in_check_out(room, name, number);
			count=-1; break;
    	}
    	else count ++;
    }
    if(count>=customersInHotel)
	{
	int t;
	cout<<"this customer has not reserved a room or you have entered wrong information.\n press 1 to try again \n press 0 to leave"<<endl;   
	cin>>t;
			if(t==1){goto checkagain;}
			else if(t==0){DisplayCustomerMenu();} 
	}
    
    
    
}

void check_in_check_out(rooms r[], string NAME, int roomNo)
{
	int daysStayed, ch,i=0;
	float billAmount;
	cout<<"press 1 for check in and 2 for check out";
	inp: cin>>ch;
	if(ch==1){//check-in information based on stay
		    int count2;
		    count2=0;
		    
		   
		       for( i;i<=customersInHotel;i++) 
		       {
		        if (r[roomNo-1].avail==false && r[roomNo-1].checkedIn==false && customers[i].reservedRoom==roomNo){
		                
						r[roomNo-1].checkedIn=true;
						count2=-1; break;}
				else{	 count2=count2+1;}
			   }
		        if(count2>=customersInHotel) {
		            cout <<"you have entered wrong reservation info or the room has already been checked into."<<endl;
		            int t;
				cout<<"\n press 1 to try again or \n press 0 to leave"<<endl;   
					cin>>t;
					if(t==1){getReservationInfo();}
					else if(t==0){DisplayCustomerMenu();} 
		        }
		        else{
		        	cout<<"room checked in successfully you can go to your room. press any key..."<<endl;
		        	getch();
		        	DisplayCustomerMenu();
		        }
		    }

   	else if(ch==2)	//check-out information and invoice based on stay
	{
		    if(r[roomNo-1].avail==true || r[roomNo-1].checkedIn==false)
			{
				int t;
				cout<<"\nthis room has not been checked into \n";
				cout<<"\n press 1 to try again \n press 0 to leave"<<endl;   
				cin>>t;
			if(t==1){getReservationInfo();}
			else if(t==0){DisplayCustomerMenu();} 
				getReservationInfo();
			}
		   
		    if(customers[i].checkInDate.mm== customers[i].checkOutDate.mm) 
		     	daysStayed = customers[i].checkOutDate.dd - customers[i].checkInDate.dd;
		     else
			 	 daysStayed = customers[i].checkOutDate.dd + (30 - customers[i].checkInDate.dd);
		    
		      if (daysStayed > 30)
			    {
			        billAmount = r[roomNo-1].price * daysStayed -(30/100*(r[i].price) * (daysStayed));
			    }
		   	else
		        {
		
		            billAmount = r[roomNo-1].price * daysStayed;
		       }
		
		
		
		    cout <<"\n\t**********checkout information**********\n\n";
		    cout <<"customer name: "<< NAME << endl;
		    cout <<"room number: "<< roomNo << endl;
		    cout <<"total amount of bill: "<< billAmount<<" press any key..."<<endl;
		    getch();
		    getReservationInfo();
	}

    }
    

