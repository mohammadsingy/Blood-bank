#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;
class Donar
{
private:
	string name;
	string pass;
	int age;
	string gender;

	int choice;
	string disese_name;
	string date;

public:
	int id;
	char blood_type;
	void donor_date();
	void add_data(vector<string> data);
	void display();
	void save_data();
	void update();
	bool check(string s);

};

