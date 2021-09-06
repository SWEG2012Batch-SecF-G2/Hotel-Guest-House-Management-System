#include<iostream>
#include<cstring>


using namespace std;

struct packageInfo
{
    int packageNum;
	string packageDescription;
	string packagePrice;
	int integerPrice;
	
}hotelPackage[3];

struct paymentInfo
{
	string purchaserName;
	char creditCardNum[17]; 
	
}packageBuyer[30];

int numPackagePurchaser = 0;

int packagePayment(packageInfo packages[3], int chosenPackage);

void setPackage()
{
	for(int i = 0; i < 3; i++)
	    hotelPackage[i].packageNum = i + 1;
	
	hotelPackage[0].packageDescription = "Wedding Package in our biggest event room which can hold up to 1000 people + food and drink service for all guests.";
	hotelPackage[1].packageDescription = "Meeting Package in our second biggest event room which can hold up to 500 people with fully equiped audiovisual \n\t\tsystem + free bottled water for all attendees. Suitable for press conference and seminars.";	
	hotelPackage[2].packageDescription = "Individual Package a relaxing day at our spa with full body massage and swimming service + free lunch at our restaurant.";
	
	hotelPackage[0].packagePrice = "15,000 ETB for the event room + 300 ETB per head";
	hotelPackage[1].packagePrice = "12,000 ETB";
	hotelPackage[2].packagePrice = "3,300 ETB";	
};

void DisplayPackages()
{
	setPackage();
	
	int packageChoice;
	char packageNextPage;
	
	cout<<"\t\t\t Welcome to the package page!"<<endl;
	cout<<"Choose the corresponding number to the package of your choice: "<<endl;
	
	for(int i = 0; i < 3; i++)
		cout << "\t" << hotelPackage[i].packageNum << "\t" << hotelPackage[i].packageDescription << "\t" << hotelPackage[i].packagePrice << endl;
	
	cin >> packageChoice;

	if(packageChoice > 0 && packageChoice <= 3)
	{
		cout << "\nYou have chosen package number " << hotelPackage[packageChoice - 1].packageNum << " which is " 
		<< hotelPackage[packageChoice - 1].packageDescription << "\nwith a price of " << hotelPackage[packageChoice - 1].packagePrice << endl;
		cout << "Press # to confirm or * to choose a different package: ";
		cin >> packageNextPage;
		if (packageNextPage == '#')
		{
			cout << "\nThank You for confirming your package choice. Proceeding to payment page:\n";
			packagePayment(hotelPackage, packageChoice);
			
		}
		else if(packageNextPage == '*')
		{
			cout<<"\n\n";
			DisplayPackages();
		}
		else 
		{
			cout<<"Invalid Input! Please choose a valid option\n\n";
			cout << "Press # to confirm or * to choose a different package: ";
			cin >> packageNextPage;
			DisplayPackages();
		}
	}	
	else 
	{
		cout<<"Invalid Package number! Please choose a valid package number of your choice\n\n"<<endl;
			DisplayPackages();
	}
		
		
}

int packagePayment(packageInfo packages[3], int chosenPackage)
{
	float price;
	cout << "Enter name: ";
	cin.ignore();
	getline(cin, packageBuyer[numPackagePurchaser].purchaserName);
	cout << "Enter the 16 digits credit card number without spaces(a credit card number is required to guarantee your package booking. \nThe credit card provided will be charged by the hotel up on arrival.)";
	cin >> packageBuyer[numPackagePurchaser].creditCardNum;
	
	if(strlen(packageBuyer[numPackagePurchaser].creditCardNum) == 16)
	{
		cout << "P\n\npackage purchased succesfully!\n\n";
		numPackagePurchaser++;		
		price = packages[chosenPackage - 1].integerPrice;
	}
	else 
	{
		cout << "Invalid credit card number! Please try again.\n"; 
		packagePayment(packages, chosenPackage);
	}
		return price;
} 

int main()
{
	DisplayPackages();
	
	return 0;
}
