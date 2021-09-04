#include <iostream>
#include <iomanip>
#include <conio.h>
#include "structureDraft1.h"

using namespace std;

void displayHomepage (int);
void CustomerNextPage(int);
void EmployeeNextPage(int);
void EmployeeNextPage(int);
void DisplayPreviousPage(char);
void DisplayCustomerMenu(int);


int homePage;

int main()
{
	for(int i = 0; i < numEmp; i++)
        employees[i].empID = i + 1;

	for (int i = 0; i < numEmp; i++)
    	employees[i].employeeName = names[0][i];

	for(int i = 0; i < numEmp; i++)
   	    employees[i].employeePassword = passWord[0][i];



comments[numComments].review = "The cultural restaurant downstairs was amazing. I got honey wine, kocho, kifo, and shiro.\nIf you want the best experience in Addis, try  Group 2.";
comments[numComments].rating = 5;
numComments++;

comments[numComments].review = "The facility was ok considering the price. However, the hotel service was poor. \nSome of the staffs were unfriendly. I booked the meeting rooms there and one of the event managers was very unfriendly.";
comments[numComments].rating = 3;
numComments++;

comments[numComments].review = "Horrible service, specially room service, wrong order and not helpful.";
comments[numComments].rating = 1;
numComments++;



	cout << setw(90) << "Welcome to " << hotel.hotelName << "\n";
	cout << "If you are a customer exploring our hotel, please press 1 \n";
	cout << "If you are an employee logging in, please press 0:  ";
	cin >> homePage;
	displayHomepage(homePage);

}

void displayHomepage (int HOMEPAGE)
{
	if(HOMEPAGE == 1)
	{
		cout << "\n\n" << hotel.hotelName << " is one of the few finest Five Star Hotels in \nthe capital city Addis Ababa, Ethiopia. Located "
		<< "just minutes \naway from Bole International Airport, Group 2 Hotel is a great \naccessible place with open main"
		<< " road to and from different parts \nof the city; thus, the hotel is an ideal location for the activities \nhappening in Addis Ababa.";

		DisplayCustomerMenu(HOMEPAGE);

	}

	else if(HOMEPAGE == 0)
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

    else
	{
		cout << "Please enter a valid option! \nIf you are a customer exploring our hotel, please press 1 \n";
		cout << "If you are an employee please press 0 to log in: ";
		cin >> homePage;
		displayHomepage(homePage);

	}
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
void DisplayCustomerMenu(int option)
{
	int nextPage;
			cout << "\n\nEnter 1 for Bar and restaurant \n2 for Fitness and Gym \n3 for Rooms and Accommodation \n4 for Services";
			cout << "\n5 for Special Offers \n6 for Meeting and Events \n7 for Review and Rating \n8 for Member Registration\n  ";
			cin >> nextPage;
			CustomerNextPage(nextPage);

}

void EmployeeNextPage(int accountNum)
{

}
