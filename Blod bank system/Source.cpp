#include<iostream>
#include<string>
#include <fstream>
#include "Donar.h"
#include "recip.h"
#include <sstream>
#include<unordered_map>
#include <ctime>
using namespace std;

vector<string> split(string strToSplit, char delimeter)
{
	stringstream ss(strToSplit);
	string item;
	vector<string> splittedStrings;
	while (getline(ss, item, delimeter))
	{
		splittedStrings.push_back(item);
	}
	return splittedStrings;
}
void read_file(unordered_map<int, recip>& Recipient, unordered_map<int, Donar>& Donor) {
	ifstream f;
	f.open("recipientsFile.txt");
	string line;
	while (getline(f, line))
	{
		recip temp;
		temp.add_data(split(line, ';'));
		Recipient.insert({ temp.id, temp });
	}
	f.close();

	f.open("donor.txt");
	line.clear();
	while (getline(f, line))
	{

		Donar temp;
		temp.add_data(split(line, ';'));
		Donor.insert({ temp.id, temp });
	}
	f.close();
}
void disblay(unordered_map<int, recip> Recipient) {
	unordered_map<int, recip>::iterator i;
	for (i = Recipient.begin(); i != Recipient.end(); i++) {
		i->second.display();
	}
}
void disblay(unordered_map<int, Donar>Donor) {
	unordered_map<int, Donar>::iterator i;
	for (i = Donor.begin(); i != Donor.end(); i++) {
		i->second.display();
	}
}
void update(unordered_map<int, recip>& Recipient, int x, bool edit) {

	fstream f;
	vector<string> data;
	f.open("recipientsFile.txt", ios::out | ios::trunc);
	string line;

	f.close();
	unordered_map<int, recip>::iterator i;
	for (i = Recipient.begin(); i != Recipient.end(); i++) {
		if (i->first == x && edit)
			i->second.update();
		i->second.save_data();
	}




}
void update(unordered_map<int, Donar>& Donor, int x, bool edit) {

	fstream f;
	vector<string> data;
	f.open("donor.txt", ios::out | ios::trunc);
	string line;

	f.close();
	unordered_map<int, Donar>::iterator i;
	for (i = Donor.begin(); i != Donor.end(); i++) {
		if (i->first == x && edit)
			i->second.update();
		i->second.save_data();
	}




}
void delet(unordered_map<int, Donar>& Donor, int ID)
{
	Donor.erase(ID);
	update(Donor, ID, false);
}
void delet(unordered_map<int, recip>& Recipient, int ID)
{
	Recipient.erase(ID);
	update(Recipient, ID, false);
}
void serch(unordered_map<int, recip>Recipient, int xid)
{
	try
	{
		Recipient.find(xid)->second.display();
	}
	catch (const std::exception&)
	{
		std::cout << "wrong id" << endl;
	}


	//cout << Recipient.find(xid)->first<<endl;
}
void serch(unordered_map<int, Donar>Donor, int xid)
{


	auto found = Donor.find(xid);

	if (found != Donor.end()) {
		// Found it
		Donor.find(xid)->second.display();
	}
	else {
		// Not there
		std::cout << "wrong id" << endl;
	}




	//cout << Recipient.find(xid)->first<<endl;
}
bool check(unordered_map<int, recip>Recipient, int xid, string pass)
{
	auto found = Recipient.find(xid);

	if (found != Recipient.end()) {
		// Found it
		return Recipient.find(xid)->second.check(pass);
	}
	else {
		// Not there
		std::cout << "wrong id" << endl;
	}
	return false;

}
bool check(unordered_map<int, Donar>Donor, int xid, string pass)
{
	auto found = Donor.find(xid);

	if (found != Donor.end()) {
		// Found it
		return Donor.find(xid)->second.check(pass);
	}
	else {
		// Not there
		std::cout << "wrong id" << endl;
	}
	return false;


}
int main()
{

	int choice;
	unordered_map<int, recip>Recipient;
	unordered_map<int, Donar>Donor;
	int xid;
	read_file(Recipient, Donor);
	recip recip_data;
	Donar donar_data;
	while (true)
	{
		std::cout << "\t\t\t\t\t\t welcome to blood bank mangement system\n";
		std::cout << "1: \t  DONOR \n";
		std::cout << "2: \t\RECIPIENT  \n";
		std::cout << "3: \t\To login as admin  \n";
		std::cout << "4: \t\ Exit \n";
		std::cin >> choice;
		if (choice == 1)
		{
		C:std::system("cls");
			std::cout << "1: \t\ To login as DONOR press 1 \n";
			std::cout << "2: \t\ To register as DONOR press 2 \n";
			std::cout << "3: \t\ back \n";
			std::cin >> choice;
			if (choice == 1)
			{
				std::system("cls");
				int check_id;
				string check_password;

				std::cout << "1: \t\ Enter your id \n";
				std::cin >> check_id;
				std::cout << "2: \t\ Enter your password \n";


				std::cin >> check_password;
				if (check(Donor, check_id, check_password)) {

				D:std::cout << "1: \t\show all Recipient  \n";
					std::cout << "2: \t\  request donation  \n";
					std::cout << "2: \t\  logout  \n";
					std::cin >> choice;
					if (choice == 1)
					{
						std::system("cls");
						disblay(Recipient);
						std::system("pause");
						goto D;
					}
					else if (choice == 2)
					{
						std::system("cls");
						std::cout << "request accepted" << endl;
						goto D;
					}
					else if (choice == 3)
					{
						goto C;
					}
				}
				else {
					std::cout << "wrong password or id" << endl;
					std::system("pause");
					goto C;
				}


			}
			else if (choice == 2)
			{
				std::system("cls");
				donar_data.donor_date();
				Donor.insert({ donar_data.id, donar_data });
				std::system("pause");
			}
			else if (choice == 3) {
				std::system("cls");
			}
			else
			{
				std::cout << "Unavliable choice" << endl;
				std::system("pause");
				goto C;
			}

		}
		else if (choice == 2)
		{
		F:std::system("cls");
			std::cout << "1: \t\ To login as recipient press 1 \n";
			std::cout << "2: \t\ To register as recipient press 2 \n";
			std::cout << "3: \t\ back \n";
			std::cin >> choice;
			if (choice == 1)
			{
				int check_id;
				string check_password;
				std::system("cls");
				std::cout << "1: \t\ Enter your id \n";
				std::cin >> check_id;
				std::cout << "2: \t\ Enter your password \n";


				std::cin >> check_password;

				std::system("pause");
				if (check(Recipient, check_id, check_password)) {

				E:	std::cout << "1: \t\show all donors  \n";
					std::cout << "2: \t\  check available blood  \n";
					std::cout << "3: \t\  show blood data  \n";
					std::cout << "4: \t\  logout  \n";
					std::cin >> choice;
					if (choice == 1)
					{
						std::system("cls");
						disblay(Donor);
						std::system("pause");
						goto E;
					}
					else if (choice == 2)
					{
						std::system("cls");
						std::cout << "Enter blood type" << endl;
						char b;
						bool found = false;

						std::cin >> b;
						unordered_map<int, Donar>::iterator i;
						for (i = Donor.begin(); i != Donor.end(); i++) {
							if (i->second.blood_type == b) {
								i->second.display();
								found = true;
							}
						}
						if (found)
						{
							std::cout << "1: \t\ request blood  \n";
							std::cout << "2: \t\  back  \n";
							std::cin >> choice;
							if (choice == 1)
							{
								int x;
								string s = Recipient[check_id].name_of_hospital;
								std::system("cls");
								std::cout << "is the hosbital you want the blood delivered to:" << Recipient[check_id].name_of_hospital << endl;
								std::cout << "1: \t\yes  \n";
								std::cout << "2: \t\  no  \n";
								std::cin >> choice;
								if (choice == 1) {
									std::cout << "enter the quantity you want" << endl;

									std::cin >> x;
									std::cout << "request pending";
								}
								else if (choice == 1) {

									std::cout << "enter the the name of hospital" << endl;
									std::cin >> s;
									std::cout << "enter the quantity you want" << endl;

									std::cin >> x;
									std::cout << "request pending" << endl;
								}
								fstream File("requests.txt", ios::app);

								time_t t = time(0);
								std::tm now;
								localtime_s(&now, &t);
								File << check_id << ";" << s << ";" << x << ";" << (now.tm_year + 1900) << '-'
									<< (now.tm_mon + 1) << '-'
									<< now.tm_mday << "\n";
								File.close();
								std::system("pause");
								goto E;
							}
							else if (choice == 2) {
								goto E;
							}
						}
						else
						{
							std::cout << "no donors found" << endl;
						}
						std::system("pause");

					}
					else if (choice == 3)
					{
						Recipient.find(check_id)->second.show_blood_data();
						std::system("pause");
						goto E;
					}
					else if (choice == 4)
					{
						goto F;
					}

				}
				else {
					std::cout << "wrong password or id" << endl;
					std::system("pause");
					goto F;
				}

			}
			else if (choice == 2)
			{
				std::system("cls");
				donar_data.donor_date();
				Donor.insert({ donar_data.id, donar_data });
				std::system("pause");
			}
			else if (choice == 3) {
				std::system("cls");
			}
			else
			{
				std::cout << "Unavliable choice" << endl;
				goto F;
			}


		}
		else if (choice == 3)
		{
		A:	std::system("cls");
			string un;
			std::cout << "1: \t\ Enter your username \n";
			std::cin >> un;
			std::cout << "2: \t\ Enter your password \n";
			string check_password;
			std::cin >> check_password;
			if (un != "admin" && check_password != "admin")
			{
				std::cout << "wrong password or username";
				goto A;

			}
			else
			{


			B:	std::system("cls");
				std::cout << "1: \t\show all DONOR  \n";
				std::cout << "2: \t\show all Recipient  \n";
				std::cout << "3: \t\ search  \n";
				std::cout << "4: \t\To Remove data \n";
				std::cout << "5: \t\ update data \n";
				std::cout << "6: \t\ back \n";
				std::cin >> choice;
				if (choice == 1)
				{
					std::system("cls");
					disblay(Donor);
					std::system("pause");
					goto B;
				}
				if (choice == 2)
				{
					std::system("cls");
					disblay(Recipient);
					std::system("pause");
					goto B;
				}
				else if (choice == 3)
				{
					std::cout << "1: \t\ DONOR  \n";
					std::cout << "2: \t\ Recipient  \n";
					std::cin >> choice;
					if (choice == 1)
					{
						std::system("cls");
						std::cout << "enter the id" << endl;
						std::cin >> xid;
						serch(Donor, xid);

						std::system("pause");
						goto B;
					}
					if (choice == 2)
					{
						std::system("cls");
						std::cout << "enter the id" << endl;
						std::cin >> xid;
						serch(Recipient, xid);

						std::system("pause");
						goto B;
					}
				}
				else if (choice == 4)
				{
					std::cout << "1: \t\ DONOR  \n";
					std::cout << "2: \t\ Recipient  \n";
					std::cin >> choice;
					if (choice == 1)
					{
						std::system("cls");
						std::cout << "Enter  ID " << endl;
						std::cin >> xid;
						delet(Donor, xid);
						std::cout << "done" << endl;
						std::system("pause");
						goto B;
					}
					if (choice == 2)
					{
						std::system("cls");
						std::cout << "Enter  ID " << endl;
						std::cin >> xid;
						delet(Recipient, xid);
						std::cout << "done" << endl;
						std::system("pause");
						goto B;
					}
				}
				else if (choice == 5)
				{
					std::cout << "1: \t\ DONOR  \n";
					std::cout << "2: \t\ Recipient  \n";
					std::cin >> choice;
					if (choice == 1)
					{
						std::system("cls");
						std::cout << "Enter  ID " << endl;
						std::cin >> xid;
						update(Donor, xid, true);
						goto B;
					}
					if (choice == 2)
					{
						std::system("cls");
						std::cout << "Enter  ID " << endl;
						std::cin >> xid;
						update(Recipient, xid, true);
						goto B;
					}

				}
				else if (choice == 6)
				{
					std::system("cls");


				}
			}
			std::system("cls");
		}
		else if (choice == 4)
		{
			break;
		}
		else
		{
			std::cout << " enter your one of the above choice please \n";
			std::system("pause");
			std::system("cls");


		}
	}

	return 0;

}

