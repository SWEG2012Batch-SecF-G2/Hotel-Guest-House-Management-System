#include <iostream>
#include <iomanip>
#include <conio.h> 
#include<string.h>

using namespace std;

void EmployeeNextPage(int);

const int numEmp = 20;

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


           
int main()
{   	
  	 AssignEmployeesInfo(employees);
 	 
	string password;
		int ID, index;
		cout << "Welcome to your hotel's log in page!\n";
		cout << "Please enter your employee ID:  ";
		cin >> ID;
		index = --ID;
		cout << "Please enter your password:  ";
		cin >> password;
		
	while(employees[index].employeePassword != password) 
		{
			cout << "Incorrect ID or password please try again!\n";
			cout << "Please enter your employee ID:  ";
			cin >> ID;
			cout << "Please enter your password:  ";
			cin >> password;
		}
		
		EmployeeNextPage(index);
}

void EmployeeNextPage(int IDnumber)
{	
	char nextPage;
	cout << "Hello " << employees[IDnumber].employeeName << "!\n\n";
	cout << "Welcome to your profile page!\n\n";
	cout << "ID" << setw(24) << employees[IDnumber].empID << endl;
	cout << "Phone number" << setw(30) << employees[IDnumber].employeePhone << endl;
	cout << "Blood Type" << setw(15) << employees[IDnumber].bloodType << endl;
	cout << "Emergency Contact" << setw(25) << employees[IDnumber].emergency_contact << endl;
	cout << "Work Status" << setw(25) << employees[IDnumber].status << endl;
	cout << "Work Shift" << setw(17) << employees[IDnumber].shift;
	
	cout << "\n\nEnter * to log out: ";
	cin >> nextPage;
	cout << "\n Log out Successful!";
	
	
}