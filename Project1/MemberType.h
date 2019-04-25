/*
	Park, David
	CS A250
	February 10, 2015

	Project 1 A
*/

#ifndef MEMBERTYPE_H
#define MEMBERTYPE_H

#include <string>
#include <iostream>

using namespace std;

class MemberType
{
public:
	// Default Constructor
	MemberType();

	// Overloaded Constructor
	MemberType(const string& newFName, const string& newLName, 
							int newMemberID);

	// Setter Function
	void setMemberInfo(const string& newFName, const string& newLName,
							int newMemberID);
	
	// Getter Functions
	string getFirstName() const;
	string getLastName() const;
	int getMembershipNo() const;

	// Printer Functions
	void printName() const;
	void printMemberInfo() const;

	// Destructor
	~MemberType();

private:
	string fName;
	string lName;
	int memberID;
};


#endif