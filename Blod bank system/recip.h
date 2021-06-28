#pragma once
#include<iostream>
#include <sstream>
#include<string>
#include<vector>
#include <fstream>
using namespace std;
class recip
{
private:
	int age;
	string name;
	string mail;
	string pass;
	string gender;
	char blood_type;

	string name_of_dactor_of_the_CASE;
public:
	int id;
	string name_of_hospital;
	void Recipient_login();
	void add_data(vector<string> data);
	void display();
	void save_data();
	void update();
	bool check(string s);
	void show_blood_data();
};

