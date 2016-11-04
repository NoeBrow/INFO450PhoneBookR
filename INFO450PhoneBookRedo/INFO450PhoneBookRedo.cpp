// INFO450PhoneBookRedo.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include<iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

const int MAXLEN = 100;

void DisplayPhoneBook(char phonebook[][2][50], int names);
int AddEntry(char phonebook[][2][50]);

//The below displays all entries try to make the loop only go through five
void DisplayPhoneBook(char phonebook[][2][50], int names)
{
	cout << "Here are your phonebook entries" << endl;

	for (int i = 0; i < names; i++)
	{
		cout << "Entry 1: " << i + 1 << "Name: " << phonebook[i][0] << "Number: " << phonebook[i][1] << endl;
	//try inputting a while loop
	}
}
int AddEntry(char phonebook[][2][50])
{
	static int phoneValue = 0;
	char value[50];
	if (phoneValue > MAXLEN)
	{
		cout << "Looks like the phonebook is full";
		return phoneValue;
	}
	cout << "What name will you like to enter?" << endl;
		cin >> value;
		cin.clear();
		cin.ignore();
		for (int i = 0; i < MAXLEN; i++)
		{
			if (strcmp(phonebook[i][0], value) == 0)
			{
				cout << "Looks like this name already exist" << endl;
			}
		}
	strcpy_s(phonebook[phoneValue][0], value);
	cout << "What is the home number?";
	gets_s(value);
	strcpy_s(phonebook[phoneValue][1], value);
	cout << "what is the cell number?";
	gets_s(value);
	strcpy_s(phonebook[phoneValue][1], value);
	phoneValue++;
	return phoneValue;
}

// if existing all files should be read into the appliaction
//user can add additional entries into the phonebook and write them to file
//search in the phonebook by name and display by criteria with only providing portion of the name strstr()


int main()
{
	char phonebook[MAXLEN][2][50];
	char response;
	ofstream File;
	cout << "would you like to open a file?";
	cin >> response;
	if (response == 'A' || response == 'a')
	{
		
		string filename;
		cout << "What is the file?";
		cin>> filename;
		File.open(filename.c_str());
		while (!File.eof())
		{
			AddEntry(phonebook);
		}
		{
			cerr << "file couldn't open";
		}
	}
	else
	{
		cout << "Will you like to add an entry or display the book?" << endl;
		char answer;
		cin >> answer;
		do
		{
			cout << "Press A to add an enrty or D to display. If you want to exit press E" << endl;
			if(answer=='A'|| answer=='a')
			{
				AddEntry(phonebook);
			}
			if (answer == 'D' || answer == 'd')
			{
				DisplayPhoneBook;
			}
			
		} while (answer != 'E' || answer != 'e');
		return 0;
	}
	File.close();
	return 0;
}

