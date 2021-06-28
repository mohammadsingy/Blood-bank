#include "Donar.h"
#include<iostream>
using namespace std;
void Donar::donor_date() {

	cout << "\t\t welcome to donor depatrment \n";
	cout << "enter your id\n";
	cin >> id;
	cout << "enter name\n";
	cin >> name;
	cout << "enter your password \n";
	cin >> pass;
	cout << "enter your age\n";
	cin >> age;
	if (age <= 0 || age > 200)
	{
		cout << "Enter correct age, Register your information again, please" << endl;
		system("pause");
		system("cls");
		donor_date();
	}
	cout << " are you male or female " << endl;
	cin >> gender;
	cout << "enter your blood type" << endl;
	cin >> blood_type;
	cout << "if you has any disease press 1 else press 2" << endl;
	cin >> choice;
	if (choice == 1) {
		cout << "enter the name of disease" << endl;
		cin >> disese_name;
		if (disese_name == """")
			cout << "\n";
		else
			cout << " sorry we cant take your blood" << endl;
	}
	else if (choice == 2)
	{
		cout << "\n";
	}
	else {
		cout << "Error Input, Register your information again, please" << endl;
		system("pause");
		system("cls");
		donor_date();
	}
	cout << " what is the lastest time you donate" << endl;
	cin >> date;
	cout << " thanks for help " << endl;
	// donor data file 
	save_data();


}

void Donar::add_data(vector<string> data)
{
	id = stoi(data[0]);
	name = data[1];
	pass = data[2];
	gender = data[3];
	blood_type = data[4][0];
	disese_name = data[5];
	date = data[6];
}

void Donar::display()
{
	cout << "id:" << id << endl << "name:" << name << endl << "age:" << age << endl << "gender:" << gender << endl << "blood type:" << blood_type << endl << "disese_name:" << disese_name << endl << "date:" << date << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
}

void Donar::save_data()
{
	fstream donorsFile("donor.txt", ios::app);
	donorsFile << id << ";" << name << ";" << pass << ";" << gender << ";" << blood_type << ";" << disese_name << ";" << date << "\n";
	donorsFile.close();

}

void Donar::update()
{
	int choice;
	cout << "1: \t\  id \n";
	cout << "2: \t\ name  \n";
	cout << "3: \t\ age \n";
	cout << "4: \t\  gender \n";
	cout << "5: \t\ blood type  \n";
	cout << "6: \t\ disese name \n";
	cout << "7: \t\ password \n";
	cin >> choice;

	if (choice == 1)
	{
		cout << "Plz Enter your ID " << endl;
		cin >> id;
	}
	else if (choice == 2)
	{
		cout << "Plz Enter your name";
		cin >> name;
	}
	else if (choice == 3)
	{
		cout << "Plz Enter your age";
		cin >> age;
	}
	else if (choice == 4)
	{
		cout << "Plz Enter your gender";
		cin >> gender;
	}
	else if (choice == 5)
	{
		cout << "Plz Enter your blood type";
		cin >> blood_type;
	}
	else if (choice == 6) {
		cout << "Plz Enter your disese name";
		cin >> disese_name;
	}
	else if (choice == 7)
	{
		cout << "Plz Enter your password";
		cin >> pass;
	}
	else
	{
		cout << " enter your one of the choices please \n";
		system("pause");
		system("cls");
		update();
	}
}

bool Donar::check(string s)
{
	if (s == pass)
	{
		return true;
	}
	else
	{
		return false;
	}
}

