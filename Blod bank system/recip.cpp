#include "recip.h"


void recip::Recipient_login()
{
	cout << "enter your id\n";
	cin >> id;
	cout << "enter name\n";
	cin >> name;
	cout << "enter your mail\n";
	cin >> mail;
	cout << "enter your paassword\n";
	cin >> pass;
	cout << "enter your age\n";
	cin >> age;
	if (age <= 0 || age > 200)
	{
		cout << "Enter correct age, Register your information again, please" << endl;
		system("pause");
		system("cls");
		Recipient_login();
	}
	cout << "are you male or female " << endl;
	cin >> gender;
	cout << "enter your blood type you want \n";
	cin >> blood_type;
	cout << "enter the the name of hospital" << endl;
	cin >> name_of_hospital;
	cout << "enter the name of doctor who responsible of that case" << endl;
	cin >> name_of_dactor_of_the_CASE;
	cout << " \t \t\t\t thanks for helping to collect this data" << endl;
	// recipient data file
	save_data();

}

void recip::add_data(vector<string> data)
{
	id = stoi(data[0]);
	name = data[1];
	mail = data[2];
	pass = data[3];
	age = stoi(data[4]);
	gender = data[5];
	blood_type = data[6][0];
	name_of_hospital = data[7];
	name_of_dactor_of_the_CASE = data[8];
}

void recip::display()
{
	cout << "id:" << id << endl << "name:" << name << endl << "mail:" << mail << endl << "age:" << age << endl << "gender:" << gender << endl << "blood type:" << blood_type << endl << "name of hospital:" << name_of_hospital << endl << "name of doctor of the CASE:" << name_of_dactor_of_the_CASE << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
}

void recip::save_data()
{
	fstream recipientsFile("recipientsFile.txt", ios::app);
	recipientsFile << id << ";" << name << ";" << mail << ";" << pass << ";" << age << ";" << gender << ";" << blood_type << ";" << name_of_hospital << ";" << name_of_dactor_of_the_CASE << "\n";
	recipientsFile.close();
}

void recip::update()
{
	int choice;
	cout << "1: \t\  id \n";
	cout << "2: \t\ name  \n";
	cout << "3: \t\ mail \n";
	cout << "4: \t\ age \n";
	cout << "5: \t\  gender \n";
	cout << "6: \t\ blood type  \n";
	cout << "7: \t\ name of hospital \n";
	cout << "8: \t\ name of doctor of the CASE \n";
	cout << "9: \t\ password \n";
	cin >> choice;
	if (choice == 1)
	{
		cout << "Plz Enter your ID " << endl;
		cin >> id;
	}
	else if (choice == 2)
	{
		cout << "Plz Enter your name" << endl;
		cin >> name;
	}
	else if (choice == 3)
	{
		cout << "Plz Enter your mail" << endl;
		cin >> mail;
	}
	else if (choice == 4)
	{
		cout << "Plz Enter your age" << endl;
		cin >> age;
	}
	else if (choice == 5)
	{
		cout << "Plz Enter your gender" << endl;
		cin >> gender;
	}
	else if (choice == 6)
	{
		cout << "Plz Enter your blood type" << endl;
		cin >> blood_type;
	}
	else if (choice == 7) {

		cout << "Plz Enter your name of hospital" << endl;
		cin >> name_of_hospital;
	}
	else if (choice == 8)
	{
		cout << "Plz Enter your name of doctor of the CASE" << endl;
		cin >> name_of_dactor_of_the_CASE;
	}
	else if (choice == 9)
	{
		cout << "Plz Enter your password" << endl;
		cin >> pass;
	}
	else
	{
		cout << " enter your one of the choices please \n";
		system("pause");
		system("cls");
		update();

	}
	system("cls");
}

bool recip::check(string s)
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

void recip::show_blood_data()
{
	ifstream f;

	f.open("requests.txt");
	string line;
	while (getline(f, line))
	{
		stringstream ss(line);
		string item;
		vector<string> splittedStrings;
		while (getline(ss, item, ';'))
		{
			splittedStrings.push_back(item);
		}
		vector<string> date;
		stringstream s(splittedStrings[3]);

		while (getline(s, item, '-'))
		{
			date.push_back(item);
		}
		if (stoi(splittedStrings[0]) == id)
		{
			cout << "id:" << splittedStrings[0] << endl << "name of hospital:" << splittedStrings[1] << endl << "Quantity:" << splittedStrings[2] << endl << "expiration date:" << date[0] << "-" << stoi(date[1]) + 4 << "-" << date[2] << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
		}

	}
	f.close();
}


